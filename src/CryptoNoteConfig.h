// Copyright (c) 2012-2018, The CryptoNote developers, The Bytecoin developers, The BitTube developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0xd1; // addresses start with "B"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(100000000000000000);
const uint64_t TAIL_EMISSION_REWARD                          = UINT64_C(100000000); // Sorry. My bad.
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 21;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 500; // Recommended by Zawy, Was 60 * 60 * 2, then 7xDIFFICULTY_TARGET, now just 500
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 70;
const size_t   DIFFICULTY_CUT                                = 60; // Unused in latest version
const size_t   DIFFICULTY_LAG                                = 15; // Unused in latest version
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 2; //seconds, two days
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 2;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 23000;
const uint32_t UPGRADE_HEIGHT_V3                             = 54900; // UNDEF_HEIGHT (4294967295) - 1 // 54881
const unsigned UPGRADE_VOTING_THRESHOLD                      = 80;    // percent
const uint32_t   UPGRADE_VOTING_WINDOW                       = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t   UPGRADE_WINDOW                              = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "bittube";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff000180a094a58d1d029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121015bfdea2f96583074c2fbd4092d6cd7e5e618b8eee918f321099cf24d54c52afc"; //010a01ff000180a094a58d1d029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121015bfdea2f96583074c2fbd4092d6cd7e5e618b8eee918f321099cf24d54c52afc -- 010a01ff0001ec85afd1b101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101d99e61eb613e913388d7a896f08d5f32ba936f8df68560609c9cc963fbcc6556

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  20;     //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  24181;
const int      RPC_DEFAULT_PORT                              =  24182;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 24 * 1024 * 1024; // 24 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = {
  "seed1.ipbc.io:24181",
  "seed2.ipbc.io:24181",
  "seed3.ipbc.io:24181",
  "seed4.ipbc.io:24181",
  "seed5.ipbc.io:24181",
  "seed6.ipbc.io:24181",
  "seed7.ipbc.io:24181",
  "seed8.ipbc.io:24181",
  "seed9.ipbc.io:24181"
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
  {50,   "dbfc2fce97b6c95bb130cb88c3e06a3020b144719f6660fb5d8a2b2bc847318f"},
  {200,  "3b0d7cecca432c41ef84b6ab930e859274c117c0319e34c36fbc858f7fc6255c"},
  {1000, "ab459e59b90d38f2cf370835dd5558bfd79f26f5034a58128e6aded3c611c594"},
  {1500, "3c57b653c48f1ad113b7053aea628897b636ad4f366f7ee1d3f7aae018c07549"},
  {1600, "3b5bc6181690ae31f0fae0426c02d6541af4a7d2dcc12e5c0ac53f81616e8dc1"},
  {2000, "cc9537cae496f1dfed600af2238d617cf0c7c65801ad5672ec04580c4b2438ce"},
  {5500, "53c1af87ee0d0607770e5911c0d755b882bc210bfaaf8d50091dfa32d17ac380"},
  {5515, "dcdcd66f456c9a33510d473f6a1bc293225e597e0c0ec815a1c54f72f8aa8aef"},
  {6166, "eedf1491ea2237082749e92b4c6dd3c11cfb7ef6cf52fea8c8620fc01a72e591"},
  {7000, "62dafd54e4ef7e572b3b89617007a80194a224e12396e4291447ccecb5ca598c"},
  {8000, "bd1b9b3a2e98e375fcfbb5358033adc448d347b5657a11c1c29eb7375a07f0b2"},
  {9000, "b25d9800a515eabab17e5ab9fcbec38797cf61c7406be34795f607beccc14c26"},
  {10000, "554e4fe4d7c60ac17ba4880713137973dc65a04199bdd91b363ba0a36d4b92c3"},
  {11000, "e5e4ccd719fe7f29f6e85e3a965fe33bd165fe950a3c9a9c48830c25578d85b8"},
  {12000, "0ecc1f453b184d7db6d3e3ac5ef5d41763d7e49d807420a768593a0ed0e466f5"},
  {13000, "82c47518a8ced16e408958636bfde75c22703c5b624e36692466e2712818bd41"},
  {14000, "c4ec39612d4a35b7e528b42ccc5575f021203874656c148fc36c62a46d65067d"},
  {15000, "726fc5cfc1e48740b2c77575393fdc7db299a47cc9d90d40d088c22fe3b2d129"},
  {16000, "af062ec6f9312e78f1f4824ac7059c6f58553684657c5e9cf5405dba820beaab"},
  {17000, "95cac6667df0f6e4068c9f6551198de51c7ce6c886170334a47ebb4b440633c5"},
  {18000, "0ce592e6d0059f7661193d1439d90210db4809ca6a371c2f19f694fab30d171b"},
  {19000, "1b7be4a99458c1b1d75e5adbb05dc399b234f88dd0e0ba1ba99d6f52342a26bd"},
  {20000, "1c46b80d216747c496f0df31c92c8fc25f29eae3e18c89fdb5d9de4c01de745b"},
  {30000, "e9fec8a991ecef5691223fc6474e7f23a95bf49d0327de6d946b342e2a7884b3"},
  {40000, "ee18a481e192d69a7edaeec7c25c30208309d88b5d54e68487af105aa309fa08"},
  {50000, "66d5478805fd31dc558c9d320d4a9946f46329a1fa439fcd520677572b55acf0"}
};
  
const int      TESTNET_VERSION = 3;

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
