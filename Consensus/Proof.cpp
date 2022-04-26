#include "Proof.h"
#include "cryptlib.h"
#include "sha.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include "cryptlib.h"
#include "sha.h"
#include "filters.h"
#include "hex.h"
#include "files.h"
#include "croncpp.h"
#include "Scheduler.h"
#include <thread>
void Proof::enterContest() {
    while (true) {
        int until;
        
        try
        {
            auto cron = cron::make_cron("1 * * * * ?");

            std::time_t now = std::time(0);
            std::time_t next = cron::cron_next(cron, now);
            until = next - now;
            //std::cout << until << std::endl;
            //std::cout << next;
            std::cout << "Waiting to enter ..." << std::endl;
        }
        catch (cron::bad_cronexpr const& ex)
        {
            std::cerr << ex.what() << '\n';
        }
        std::this_thread::sleep_for(std::chrono::seconds(until));
        std::cout << "Entering Contest" << std::endl;
        findAnswer();
    }
    

}

void Proof::getHashInfo() {
    using namespace CryptoPP;
    SHA256 hash;
    std::cout << "Name: " << hash.AlgorithmName() << std::endl;
    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
    std::cout << "Block size: " << hash.BlockSize() << std::endl;
};

std::string Proof::getCurrentTime() {
    auto start = std::chrono::system_clock::now();
    auto legacyStart = std::chrono::system_clock::to_time_t(start);
    std::string currentTime = std::ctime(&legacyStart);
    return currentTime;
}
std::string Proof::getRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis(0, 2147483646);
    std::string nonce = std::to_string(dis(gen));
    return nonce;
}

void Proof::findAnswer() {
    std::string initial = "Test Messageeeee";
    std::cout << "Input msg : ";
    //std::cin >> initial;

    int difficulty;
    char zero = '0';
    std::cout << "Input Difficulty : ";
    //std::cin >> difficulty;
    difficulty = 4;
    std::string required(difficulty, zero);
    //std::cout << required << std::endl;
    int i = 0;


    while (true) {
        i += 1;
        //std::cout << "Enter msg: ";
        //cin >> tx;
        /*string txWithNonce = tx + "2";
        hash.Update((const byte*)txWithNonce.data(), txWithNonce.size());
        digest.resize(hash.DigestSize());
        hash.Final((byte*)&digest[0]);

        cout << "Message: " << txWithNonce << endl;
        cout << "Digest: "  <<endl;

        StringSource(digest, true, new Redirector(encoder));
        cout << endl;*/

        CryptoPP::SHA256 sha256;
        std::string source, hash;
        //string nonce = to_string(rand());
        std::string nonce = getRandomNumber();
        source = initial + nonce;
        CryptoPP::StringSource(source, true, new CryptoPP::HashFilter(sha256, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));

        std::cout << "\r" << "Iteration :" << i << " , Nonce : " << nonce;
        std::string testResult = hash.substr(0, difficulty);
        if (testResult == required) {
            std::cout << std::endl;
            std::string timeFound = getCurrentTime();
            std::cout << "Found answer on " << timeFound;
            std::cout << "TX hash : 0x" << hash << std::endl;
            std::cout << "Broadcasting to network.. \n";
            break;
        }
    }
}
