#include "HangMan.hpp"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <vector>
using namespace std;

HangMan::HangMan()
{
    numErrors = 0;
    setWord(WORD);
    setLength();
    setGuessWord();
}

void HangMan::resetGame()
{
    numErrors = 0;
    setWord(WORD);
    setLength();
    setGuessWord();
    errors.clear();
}

void HangMan::playGame()
{
    while(numErrors != 6 && guessWord != WORD)
    {
        char letter;
        Drawing();
        cout << "***************" << endl;
        cout << "Incorrect Letters" << endl;
        if(!errors.empty())
        {
            for(int i = 0; i < errors.size(); i++)
                cout << errors[i] << " ";
            cout << endl;
        }
        else
            cout << endl;
        cout << "***************" << endl;
        cout << "Word: " << guessWord << "\n";
        cout << "***************" << endl;

        cout << "Enter a Letter: ";
        cin >> letter;
        cout << "\n";
        if(checkLetter(letter))
            cout << "Good Guess!!\n\n";
        else
            cout << "Not correct.\n\n";
    }

    Drawing();
    if(numErrors == 6)
    {
        cout << "You couldn't save the man! Better luck next time\n\n";
        cout << "The word was -> " << WORD << "\n\n";
    }
    else
    {
        cout << "CONGRATS!! You saved the man!!\n\n";
        cout << "The word was -> " << WORD << "\n\n";
    }


}

bool HangMan::checkLetter(char character)
{
    bool status = false;
    for(int i = 0; i < wordLen; i++)
    {
        if(i == 0)
        {
            if(toupper(character) == WORD[i])
            {
                guessWord[i] = toupper(character);
                status = true;
            }
            
        }
        else 
        {
            if(character == WORD[i])
            {
                guessWord[i] = character;
                status = true;
            }
        }
    }

    if(!status)
    {
        bool isDuplicate = false;
        for(int j = 0; j < errors.size(); j++){
            if(character == errors[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            errors.push_back(tolower(character));
            numErrors++;
        }
        else{
            cout << "You already entered that letter." << endl;
        }
    }
    
    return status;
}

void HangMan::setWord(string &x)
{
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 200);

    int index = distribution(gen);          

    ifstream file;
    file.open("wordList.txt");

    for(int i = 0; i < index; i++)
        file >> x;

    file.close();   
 
}

void HangMan::Drawing()
{
    switch(numErrors)
    {
        case 0: cout << "+-------+" << endl;
                cout << "|        " << endl;
                cout << "|        " << endl;
                cout << "|        " << endl;
                cout << "-        " << endl;
                break;

        case 1: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|        " << endl;
                cout << "|        " << endl;
                cout << "-        " << endl;
                break;

        case 2: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|       |" << endl;
                cout << "|        " << endl;
                cout << "-        " << endl;
                break;

        case 3: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|      /|" << endl;
                cout << "|        " << endl;
                cout << "-        " << endl;
                break;

        case 4: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|      /|\\" << endl;
                cout << "|        " << endl;
                cout << "-        " << endl;
                break;

        case 5: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|      /|\\" << endl;
                cout << "|      / " << endl;
                cout << "-        " << endl;
                break;

        case 6: cout << "+-------+" << endl;
                cout << "|       O" << endl;
                cout << "|      /|\\" << endl;
                cout << "|      / \\" << endl;
                cout << "-        " << endl;
                break;
    }
    cout << endl << endl;
    
}

int HangMan::getNumErors()
{
    return numErrors;
}

string HangMan::getWord()
{
    return WORD;
}

void HangMan::setLength()
{
    wordLen = WORD.size();
}

int HangMan::getLength()
{
    return wordLen;
}

void HangMan::setGuessWord()
{
    guessWord = WORD;
    for(int i = 0; i < wordLen; i++) 
        guessWord[i] = '-';
}

string HangMan::getGuessWord()
{
    return guessWord;
}
