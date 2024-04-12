#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include "HangMan.cpp"
using namespace std;



int main()
{
    HangMan game;
    char playAgain = 'n';
    cout << "\n\n";
    cout << "**************************************\n";
    cout << "          WELCOME TO HANGMAN\n";
    cout << "**************************************\n\n";
    do
    {
       if(playAgain == 'y' || playAgain == 'Y')
       {
            game.resetGame();
       }
       game.playGame();
       cout << "Would you like to play again? (y/n): ";
       cin >> playAgain; 
    } while(playAgain != 'n' && playAgain != 'N');
    
    return 0;
}
