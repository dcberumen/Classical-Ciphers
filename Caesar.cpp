#include "Caesar.h"

bool Caesar::setKey(const string& key)
{
    //assume key is valid
    bool isNumber = true;
    int value;
    char c;
    for(int i=0;i<key.length();i++)
    {
        //look at every value in string to see if its a number
        c = key[i];
        if(!isdigit(c))
            isNumber=false;
    }

    if(isNumber)
    {
        //if key amounts to 0 or movement of 26 then no change occur
        //and the key is invalid
        value = atoi(key.c_str())%26;
        if(value == 0)
            isNumber = false;
        else
            KEY = atoi(key.c_str())%26;
    }
    return isNumber;
}

string Caesar::encrypt(const string& plaintext)
{
    string ciphertext = plaintext;
    for(int i = 0; i < ciphertext.length(); i++)
    {
        ciphertext[i] = toupper(ciphertext[i]);
        ciphertext[i] += KEY;
        //loop from Z to A
        if(ciphertext[i] > 90)
            ciphertext[i] -= 26;
    }
    CIPHERTEXT = ciphertext;
    return CIPHERTEXT;
}
string Caesar::decrypt(const string& ciphertext)
{
    string plaintext = ciphertext;
    for(int i = 0; i < plaintext.length(); i++)
    {
        plaintext[i] = toupper(plaintext[i]);
        plaintext[i] -= KEY;
        //go from A to Z
        if(plaintext[i] < 65)
            plaintext[i] += 26;
    }
    PLAINTEXT = plaintext;
    return PLAINTEXT;
}
/*void Caesar::printCipher(file* fp)
{
    fp.open("out.txt");
    fp << ciphertext;
    fp.close();
}*/