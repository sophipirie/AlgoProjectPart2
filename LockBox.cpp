#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "LockBox.h"
#include <ctime>
using namespace std;

LockBox::LockBox(int n, int m) {
    length = n;
    range = m;
    randomCode = generateCode(length, range);
}
vector<int> LockBox::generateCode(int n, int m) {
    int value;
    srand(time(0));
    vector<int> v;
    for (int i = 0; i < n; i++) {
        value = rand() % m;
        v.push_back(value);
    }

    return v;
}

vector<int> LockBox::getCode() {
    return randomCode;
}

void LockBox::setGuess(string s) {
    vector<int> v;

    for (int i=0; i < s.size(); i++ ) {
        if (isdigit(s[i])) {
            v.push_back(s[i] - '0');
        }
    }
    guess = v;
}

vector<int> LockBox::getGuess() {
    return guess;
}

int LockBox::correctLocation(LockBox *g) {
    vector<int> x = this->getCode();
    vector<int> y = g->getGuess();
    int correct = 0;

    for (int i = 0; i < x.size(); i++) {
        if (x.at(i) == y.at(i)) {
            correct++;
        }
    }
    return correct;
}

int LockBox::incorrectLocation(LockBox *g) {

    vector<int> x = this->getCode();
    vector<int> y = g->getGuess();
    int incorrect = 0;
    vector<int> copyCode(length);
    vector<int> copyGuess(length);
    vector<int> x1;
    vector<int> y1;



    for (int j = 0; j < length; j++){
            for (int i =0; i<length; i++){
                if(x.at(j) == y.at(i) && i==j){
                    copyCode[j] = 1;
                    copyGuess[i] =1;
                }
                if(x.at(j) == y.at(i) && i!=j && copyCode.at(j)!= 1 && copyGuess.at(i) != 1){
                    copyCode[j] = 1;
                    copyGuess[i] =1;
                    incorrect ++;
                    break;
                }
            }
        }
    return incorrect;
}