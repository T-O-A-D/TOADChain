// Consensus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

#include <string.h>
#include "Proof.h"
#include <thread>
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

    //DoMath().timeTwo(3);
    cout << R"(
______________________________________________________________________
______________________________________________________________________
  _______ ____          _____     _____ _    _          _____ _   _ 
 |__   __/ __ \   /\   |  __ \   / ____| |  | |   /\   |_   _| \ | |
    | | | |  | | /  \  | |  | | | |    | |__| |  /  \    | | |  \| |
    | | | |  | |/ /\ \ | |  | | | |    |  __  | / /\ \   | | | . ` |
    | | | |__| / ____ \| |__| | | |____| |  | |/ ____ \ _| |_| |\  |
    |_|  \____/_/    \_\_____/   \_____|_|  |_/_/    \_\_____|_| \_|
______________________________________________________________________                                                                
                                                                    
)";
    Proof Prover;
    while (true) {
        int selection;
        cout << "Select one of the following: \n0 - Exit  \n1 - Get Hash Info \n2 - Get Current Network Time\n3 - Get Random Nonce\n4 - Participate in validation contest" << endl;

        cin >> selection;
 
        switch (selection) {
        case 1:
            Prover.getHashInfo();
            break;
        case 2:
        {
            std::string currentTime = Prover.getCurrentTime();
            std::cout << currentTime << std::endl;
            break;
        }
            
        case 3:
        {
            std::string randomNonce = Prover.getRandomNumber();
            std::cout << randomNonce << std::endl;
            break;
        }
           
        case 4:
            Prover.enterContest();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore();
            continue;
        };
       
    }

    while (true) {
        
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
