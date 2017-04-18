#ifndef RAILFENCE_H
#define RAILFENCE_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "CipherInterface.h"

using namespace std;

class Railfence: public CipherInterface
{
    public:
        virtual bool setKey(const string& key);

        virtual string encrypt(const string& plaintext);

        virtual string decrypt(const string& ciphertext);

        //void printCipher(file* fp);
    protected:
    private:
        int KEY;
        string PLAINTEXT, CIPHERTEXT;
    
};


#endif
