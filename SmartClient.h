#ifndef SMART_CLIENT
#define SMART_CLIENT

#include <iostream>
#include "LockBox.h"
#include "ClientFeedback.h"
using namespace std;

class SmartClient {
private:
    LockBox* lockbox;
    int n;
    int m;
public:
    SmartClient();
    SmartClient(int n, int m);
    void printCode();
    LockBox clientGuess();
    ClientFeedback getFeedback(LockBox guess);
    bool isOpened(ClientFeedback &x);
    void openLockBox();
};
#endif