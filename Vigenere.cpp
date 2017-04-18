#include "Vigenere.h"

bool Vigenere::setKey(const string& key)
{
    bool valid = true;
    for(int i =0; i < key.length(); i++)
    {
        if(isalpha(key[i]))
            KEY += toupper(key[i]);
        else
            valid = false;
    }
    return valid;
}

string Vigenere::encrypt(const string& plaintext)
{
    string CIPHERTEXT = "";
    for(int i = 0; i < plaintext.length(); i++)
    {
        CIPHERTEXT += toupper(plaintext[i]);
    }
    if(plaintext.length() > KEY.length())
    {
        int a = plaintext.length() - KEY.length();
        for(int i = 0; i < a; i++)
        {
            KEY += KEY[i];
        }
    }
    for(int i = 0; i < CIPHERTEXT.length(); i++)
    {
        CIPHERTEXT[i] += (int(KEY[i])%26);
        if (CIPHERTEXT[i] > 90)
            CIPHERTEXT[i] -= 26;
    }
    return CIPHERTEXT;
}
string Vigenere::decrypt(const string& ciphertext)
{
    string PLAINTEXT = "";
    for(int i = 0; i < ciphertext.length(); i++)
    {
        PLAINTEXT += toupper(ciphertext[i]);
    }
    if(ciphertext.length() > KEY.length())
    {
        int a = ciphertext.length() - KEY.length();
        for(int i = 0; i < a; i++)
        {
            KEY += KEY[i];
        }
    }
    for(int i = 0; i < PLAINTEXT.length(); i++)
    {
        PLAINTEXT[i] -= (int(KEY[i]%26));
        if (PLAINTEXT[i] < 65)
            PLAINTEXT[i] += 26;
    }
    return PLAINTEXT;
    
}