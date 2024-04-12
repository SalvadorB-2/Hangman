#ifndef HANGMAN_H
#define HANGMAN_H
#include <vector>
using namespace std;

class HangMan
{
private:
    int numErrors;
    int wordLen;
    string WORD;
    string guessWord;
    vector<char> errors;
public:
    HangMan();
    void resetGame();
    void playGame();
    void Drawing();
    void setWord(string &);
    void setLength();
    void setGuessWord();
    bool checkLetter(char);
    string getGuessWord();
    int getLength();
    int getNumErors();
    string getWord();
};
#endif