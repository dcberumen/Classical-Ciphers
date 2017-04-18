#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "CipherInterface.h"

using namespace std;

class RowTransposition: public CipherInterface
{
    public:
        virtual bool setKey(const string& key);

        virtual string encrypt(const string& plaintext);

        virtual string decrypt(const string& ciphertext);

        //void printCipher(file* fp);
    protected:
    private:
        vector<int> KEY;
        int LARGEST;
        string PLAINTEXT, CIPHERTEXT;
    
};


#endif