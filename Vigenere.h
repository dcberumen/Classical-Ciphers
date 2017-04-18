#ifndef VIGENERE_H
#define VEGENERE_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "CipherInterface.h"

using namespace std;

class Vigenere: public CipherInterface
{
    public:
        virtual bool setKey(const string& key);

        virtual string encrypt(const string& plaintext);

        virtual string decrypt(const string& ciphertext);

        //void printCipher(file* fp);
    protected:
    private:
        string KEY;
    
};
#endif