#include "crypto/hash.h"
#include "Common/StringTools.h"

#include <sstream>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>

#define print(msg) {std::stringstream ss; ss << msg; std::cout << ss.str() + "\r\n"; }

std::string random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

Crypto::Hash hash_me(std::string data, int variant, bool literally) {
	Crypto::cn_context context;
	Crypto::Hash hash;
	if (literally) {
		Crypto::cn_slow_hash(context, data.c_str(), data.size(), hash, variant);
	}
	else {
		std::vector<char> data_v;
		data_v.resize(data.size() / 2);
		size_t success = Common::fromHex(data, data_v.data(), data_v.size());

		Crypto::cn_slow_hash(context, data_v.data(), data_v.size(), hash, variant);
	}
	
	return hash;
}


void avg_test(std::string data, int count, int variant) {
	long double avg = 0;
	int counter = 0;
	
	while (true) {
		auto start = std::chrono::high_resolution_clock::now();
		Crypto::Hash result = hash_me(data, variant, false);
		auto elapsed = std::chrono::high_resolution_clock::now() - start;

		long double microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		avg = (avg * 0.5) + (microseconds * 0.5);

		counter++;
		if (counter > count) {
			double d = (double)(avg / 1000.0);
			double hr = 1000.0 / d;
			printf("SpeedTest Variant: %i DataLen: %i Count: %i -- AVG Took: %f EHR: %f Hash: %s \r\n", variant, (int)data.size(), count, d, hr, Common::podToHex(result).c_str());
			//counter = 0;
			break;
		}
	}
}

void Test_Hash(std::string data, std::string expected, int variant, bool literally = false) {
	std::string result = Common::podToHex(hash_me(data, variant, literally));

	if (expected == result) {
		print("V" << std::to_string(variant) << ": " << result << " CORRECT");
	}
	else {
		print("V" << std::to_string(variant) << ": " << result << " WRONG");
	}
}

int main(int argc, char* argv[]) {
	print("Hello!");

	// Vanilla cryptonight
	Test_Hash("6162756e64616e732063617574656c61206e6f6e206e6f636574", "722fa8ccd594d40e4a41f3822734304c8d5eff7e1b528408e2229da38ba553c4", 0);
	Test_Hash("6465206f6d6e69627573206475626974616e64756d", "2f8e3df40bd11f9ac90c743ca8e32bb391da4fb98612aa3b6cdc639ee00b31f5", 0);
	Test_Hash("63617665617420656d70746f72", "bbec2cacf69866a8e740380fe7b818fc78f8571221742d729d9d02d7f8989b87", 0);
	Test_Hash("6578206e6968696c6f206e6968696c20666974", "b1257de4efc5ce28c6b40ceb1c6c8f812a64634eb3e81c5220bee9b2b76a6f05", 0);

	// MoneroV7 Tests
	Test_Hash("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "b5a7f63abb94d07d1a6445c36c07c7e8327fe61b1647e391b4c7edae5de57a3d", 1);
	Test_Hash("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "80563c40ed46575a9e44820d93ee095e2851aa22483fd67837118c6cd951ba61", 1);
	Test_Hash("8519e039172b0d70e5ca7b3383d6b3167315a422747b73f019cf9528f0fde341fd0f2a63030ba6450525cf6de31837669af6f1df8131faf50aaab8d3a7405589", "5bb40c5880cef2f739bdb6aaaf16161eaae55530e7b10d7ea996b751a299e949", 1);
	Test_Hash("37a636d7dafdf259b7287eddca2f58099e98619d2f99bdb8969d7b14498102cc065201c8be90bd777323f449848b215d2977c92c4c1c2da36ab46b2e389689ed97c18fec08cd3b03235c5e4c62a37ad88c7b67932495a71090e85dd4020a9300", "613e638505ba1fd05f428d5c9f8e08f8165614342dac419adc6a47dce257eb3e", 1);
	Test_Hash("38274c97c45a172cfc97679870422e3a1ab0784960c60514d816271415c306ee3a3ed1a77e31f6a885c3cb", "ed082e49dbd5bbe34a3726a0d1dad981146062b39d36d62c71eb1ed8ab49459b", 1);

	// V7 + 1MB
	Test_Hash("38274c97c45a172cfc97679870422e3a1ab0784960c60514d816271415c306ee3a3ed1a77e31f6a885c3cb", "4e785376ed2733262d83cc25321a9d0003f5395315de919acf1b97f0a84fbd2d", 2);

	// CryptoLIGHT
	// https://github.com/turtlecoin/node8-multi-hashing/blob/master/tests/cryptonight-tests.js
	Test_Hash("0100fb8e8ac805899323371bb790db19218afd8db8e3755d8b90f39b3d5506a9abce4fa912244500000000ee8146d49fa93ee724deb57d12cbc6c6f3b924d946127c7a97418f9348828f0f02", "28a22bad3f93d1408fca472eb5ad1cbe75f21d053c8ce5b3af105a57713e21dd", -1);

	// BitTube (Custom + V7 + 1MB)
	Test_Hash("38274c97c45a172cfc97679870422e3a1ab0784960c60514d816271415c306ee3a3ed1a77e31f6a885c3cb", "b442a2b956e63fefe81bfa8bcbc4ddd6b63f86530eeaa46588311d290afbb2c0", 3);
	Test_Hash("This is a test PAAAAAAAAAAAAAAAAAAAAAAAAAAAAADDING", "a3ed4b825247952d0e91d646a3709ba6e9f6ab06390b8181611a77b63c7d2388", 3, true);

	print("");
	// Performance
	std::string data = "0100fb8e8ac805899323371bb790db19218afd8db8e3755d8b90f39b3d5506a9abce4fa912244500000000ee8146d49fa93ee724deb57d12cbc6c6f3b924d946127c7a97418f9348828f0f02"; // random_string(200);
	int count = 10;
	avg_test(data, count, -1);
	avg_test(data, count, 0);
	avg_test(data, count, 1);
	avg_test(data, count, 2);
	avg_test(data, count, 3);

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}