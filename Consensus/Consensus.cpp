// Consensus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cryptlib.h"
#include "sha.h"
#include "filters.h"
#include "hex.h"
#include "files.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <random>
#include <string>
int main(int argc, char* argv[])
{
    using namespace std;
    //using namespace CryptoPP;

   /* SHA256 hash;

    string tx;
    string digest;
    string hashResult;

    HexEncoder encoder;*/

    //srand(time(NULL));
    while (true) {
        string initial;
        cout << "Input msg : ";
        cin >> initial;

        int difficulty;
        char zero = '0';
        cout << "Input Difficulty : ";
        cin >> difficulty;
        string required(difficulty, zero);
        cout << required << endl;
        int i = 0;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<unsigned long long> dis(0, 100000);
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
            string source, hash;
            //string nonce = to_string(rand());
            string nonce = to_string(dis(gen));
            source = initial + nonce;
            CryptoPP::StringSource(source, true, new CryptoPP::HashFilter(sha256, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));

            cout << "\r" << "Iteration :" << i << " , Nonce : " << nonce << " , Digest : " << hash;
            string testResult = hash.substr(0, difficulty);
            if (testResult == required) {
                cout << endl;
                cout << "Found answer" << endl;
                break;
            }
        }
        cout << "Continue ?" << endl;
        string cont;
        cin >> cont;
    }
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
