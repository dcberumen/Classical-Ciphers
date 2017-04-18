#ifndef CAESAR_H
#define CAESAR_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "CipherInterface.h"

using namespace std;

class Caesar: public CipherInterface
{
    public:
        virtual bool setKey(const string& key);

        virtual string encrypt(const string& plaintext);

        virtual string decrypt(const string& ciphertext);

        //void printCipher(file* fp);
    protected:
    private:
        string PLAINTEXT, CIPHERTEXT;
        int KEY;
    
};

#endif