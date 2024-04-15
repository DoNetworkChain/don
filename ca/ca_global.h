#ifndef __CA_GLOBAL_H__
#define __CA_GLOBAL_H__
#include <unordered_set>

#include "common/global.h"
#include "proto/ca_protomsg.pb.h"
#include "utils/CTimer.hpp"



namespace global{

    namespace ca{

        // data
        #ifdef PRIMARYCHAIN
            static const std::string kInitAccountBase58Addr = "1zzF8jNBAXFTPJzhvY45zLKgQmnPLBZ93";
      
            static const uint64_t kGenesisTime = 1682208000000000;
            static const uint64_t kUnstakeTime = (uint64_t)1000000 * 60 * 60 * 24 * 30;
            static const uint64_t kDisinvestTime = (uint64_t)1000000 * 60 * 60 * 24;

           static const std::string kConfigJson = "{\"http_callback\":{\"ip\":\"\",\"path\":\"\",\"port\":0},\"rpc\":true,\"http_port\":41517,\"info\":{\"logo\":\"\",\"name\":\"\"},\"ip\":\"\",\"log\":{\"console\":false,\"level\":\"OFF\",\"path\":\"./logs\"},\"server\":[\"36.153.199.186\",\"36.154.216.186\"],\"server_port\":41516,\"version\":\"1.0.14\"}";
        #elif TESTCHAIN
            static const std::string kInitAccountBase58Addr = "1zzF8jNBAXFTPJzhvY45zLKgQmnPLBZ93";
            static const uint64_t kGenesisTime = 1682208000000000;
            static const uint64_t kUnstakeTime = (uint64_t)1000000 * 60 * 60 * 24 * 30;
            static const uint64_t kDisinvestTime = (uint64_t)1000000 * 60 * 60 * 24;
            static const std::string kConfigJson = "{\"http_callback\":{\"ip\":\"\",\"path\":\"\",\"port\":0},\"rpc\":false,\"http_port\":41517,\"info\":{\"logo\":\"\",\"name\":\"\"},\"ip\":\"\",\"log\":{\"console\":false,\"level\":\"OFF\",\"path\":\"./logs\"},\"server\":[\"36.153.199.186\",\"36.154.216.186\"],\"server_port\":41516,\"version\":\"1.0.14\"}";
        #else // DEVCHAIN
            static const std::string kInitAccountBase58Addr = "1zzF8jNBAXFTPJzhvY45zLKgQmnPLBZ93";
            static const uint64_t kGenesisTime = 1682208000000000;
            static const uint64_t kUnstakeTime = (uint64_t)(1000000 * 60);
            static const uint64_t kDisinvestTime = (uint64_t)(1000000 * 60); 

           static const std::string kConfigJson = "{\"http_callback\":{\"ip\":\"\",\"path\":\"\",\"port\":0},\"rpc\":true,\"http_port\":41517,\"info\":{\"logo\":\"\",\"name\":\"\"},\"ip\":\"\",\"log\":{\"console\":false,\"level\":\"OFF\",\"path\":\"./logs\"},\"server\":[\"36.153.199.186\",\"36.154.216.186\"],\"server_port\":41516,\"version\":\"1.0.14\"}";
        #endif 
        
        // consensus
        static const int kConsensus = 8;
        const int KSend_node_threshold = 13;

        // timer
        static CTimer kBlockPoolTimer("blockpool");
        static CTimer kSeekBlockTimer("SeekBlock");
        static CTimer kDataBaseTimer("database");
        static CTimer kBounsVersionTimer("bouns");
        // mutex
        static std::mutex kBonusMutex;
        static std::mutex kInvestMutex;
        static std::mutex kBurnMutex;
        static std::mutex kBlockBroadcastMutex;

        // ca
        const uint64_t kDecimalNum = 100000000;
        const double   kFixDoubleMinPrecision = 0.000000005;
        const uint64_t kTotalAwardAmount =  101476571.71;
        const uint64_t kM2 = 98523428.29;
        const uint64_t kMinSignAmt = (uint64_t)((double)25000 * kDecimalNum); //Investment+pledge needs 25000 to be signed
        const uint64_t kMinStakeAmt = (uint64_t)((double)2000 * kDecimalNum);  //The minimum pledge amount is 2000
        const uint64_t kMinInvestAmt = (uint64_t)((double)200 * kDecimalNum);   //The minimum investment amount is 200
        const uint64_t kMaxInvertAmt = (uint64_t)((double)250000 * kDecimalNum);    //The maximum investment amount is 250000

        const std::string kGenesisSign = "Genesis";
        const std::string kTxSign = "Tx";
        const std::string kGasSign = "Gas";
        const std::string kBurnSign = "Burn";
        const std::string kVirtualStakeAddr = "VirtualStake";
        const std::string kVirtualInvestAddr = "VirtualInvest";
        const std::string kVirtualBurnGasAddr = "VirtualBurnGas";
        const uint64_t kUpperBlockHeight = 4;
        const uint64_t kLowerBlockHeight = 1;
        const std::string kStakeTypeNet = "Net";
        const std::string kInvestTypeNormal = "Normal";
        const uint64_t kMinUnstakeHeight = 500;
        const uint64_t kMaxBlockSize = 1024 * 1024 * 1;
        const std::string kVirtualDeployContractAddr = "VirtualDeployContractBurnGas";
        const std::string kVirtualCallContractAddr = "VirtualCallContractBurnGas";
        const int KSign_node_threshold = 10;
        const int kNeed_node_threshold = 30;

        static const int KRandomNodeGroup = 8; 
        const uint64_t kMaxSendSize = 100;

        const uint64_t KtxTimeout = 10 * 1000000ull;
        const int TxTimeoutMin = 30;

        const uint64_t kVerifyRange = 600;

        const double kDividendsRate = 0.12;

        enum class StakeType
        {
            kStakeType_Unknown = 0,
            kStakeType_Node = 1
        };
        
        // Transacatione Type
        enum class TxType
        {
            kTxTypeGenesis = -1,
            kTxTypeUnknown, // unknown
            kTxTypeTx, //normal transaction
            kTxTypeStake, //stake
            kTxTypeUnstake, //unstake
            kTxTypeInvest, //invest
            kTxTypeDisinvest, //disinvest
            kTxTypeDeclaration, //declaration
            kTxTypeDeployContract,
            kTxTypeCallContract,
            kTxTypeBonus = 99//bonus
        };

        // Sync
        enum class SaveType
        {
            SyncNormal,
            SyncFromZero,
            Broadcast,
            Unknow
        };
        
        enum class BlockObtainMean
        {
            Normal,
            ByPreHash,
            ByUtxo
        };
        const uint64_t sum_hash_range = 100;
        // const std::string sync_buffer_path = "./buffer/";
         const uint64_t thousand_sum_hash_range = 1000;

        // contract
        enum VmType {
            EVM,
            WASM
        };
        //test
        static int TxNumber = 0;
        const uint32_t kInitTransactionVersion = 0;
        const uint32_t kInitBlockVersion = 0;
        const uint32_t kCurrentTransactionVersion = 0;
        const uint32_t kCurrentBlockVersion = 0;
    }
        //double spend

        namespace DoubleSpend {
            const int SingleBlock = -66;
            const int DoubleBlock = -99;
        };
}


#endif