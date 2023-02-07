#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "SmartClient.h"

SmartClient::SmartClient() {
    n = 5; m = 10;
    LockBox l1(n,m);
    LockBox* l2 = new LockBox(n, m);
    lockbox = l2;
}
SmartClient::SmartClient(int n1, int m1) {
    n = n1;
    m = m1;
    LockBox* l1 = new LockBox(n, m);
    lockbox = l1;



}
void SmartClient::printCode() {

    for (int i = 0; i< n; i++){
        cout << lockbox->getCode().at(i) << " ";
    }
    cout << " "<< endl;
}

LockBox SmartClient::clientGuess() {
    LockBox guess(n, m);
    cout << "Enter Guess Seperated by commas: ";
    string strGuess;
    cin >> strGuess;
    guess.setGuess(strGuess);
    return guess;
}

ClientFeedback SmartClient::getFeedback(LockBox guess) {
    int cor = lockbox->correctLocation(&guess);
    int incor = lockbox->incorrectLocation(&guess);
    ClientFeedback feedback;
    feedback.setFeedback(cor, incor);
    return feedback;
}

bool SmartClient::isOpened(ClientFeedback &x) {
    ClientFeedback checkOpen;
    checkOpen.setFeedback(n, 0);
    if(checkOpen == x){
        return true;
    }
    else{
        return false;
    }
}

void SmartClient::openLockBox() {
    bool isGuessing = true;
    printCode();
    while(isGuessing){
        LockBox b1 = clientGuess();
        ClientFeedback c1 = getFeedback(b1);
        if(isOpened(c1)){
            cout << c1 << endl;
            isGuessing = false;
        }
        else{
            cout << c1 << endl;
        }
    }
}