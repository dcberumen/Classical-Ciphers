#include "RowTransposition.h"

bool RowTransposition::setKey(const string& key)
{
    vector<int> KeyOrder;
    LARGEST = 0;
    string keyNum;
    for(int i = 0; i < key.length()+1; i++)
    {
        if(key[i] == ' ' || i == key.length())
        {
            int a = atoi(keyNum.c_str());
            KeyOrder.push_back(a-1);
            keyNum = "";
            if (a > LARGEST)
                LARGEST = a;
        }
        else if(isdigit(key[i]))
            keyNum += key[i];
        else
            return false;
    }
    
    KEY = KeyOrder;
    return true;
}
string RowTransposition::encrypt(const string& plaintext)
{
    vector<string> ciphertext;
    int extraX = LARGEST - plaintext.length()%LARGEST;
    for(int i = 0; i < LARGEST; i++)
    {
        ciphertext.push_back("");
    }
    for(int i = 0; i < plaintext.length(); i++)
    {
        ciphertext[i%LARGEST] += plaintext[i];
    }
    if(extraX > 0)
    {
        for(int i = plaintext.length(); i < plaintext.length() + extraX; i++)
        {
            ciphertext[i%LARGEST] += "X";
        }
    }
    for(int i = 0; i < LARGEST; i++)
    {
        int column = KEY[i];
        CIPHERTEXT += ciphertext[column];
    }
    return CIPHERTEXT;
}
string RowTransposition::decrypt(const string& ciphertext)
{
    vector<string> cipherDecrypt, cipherReorder;
    int row = ciphertext.length()/LARGEST;
    string ciphertextExtended = ciphertext;
    int a = 0;
    int larger=0;
    if(LARGEST > row)
        larger = LARGEST;
    else
        larger = row;
    for(int i = 0; i < larger; i++)
    {
        cipherDecrypt.push_back("");
        cipherReorder.push_back("");
    }
    for(int i = 0; i < ciphertext.length(); i++)
    {
        cipherDecrypt[i%row] += ciphertext[i];
    }
    for(int i = 0; i < LARGEST; i++)
    {
        a = KEY[i];
        for(int l = 0; l < row; l++)
        {
            cipherReorder[a] += cipherDecrypt[l][i];
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int l = 0; l < LARGEST; l++)
        {
            PLAINTEXT += cipherReorder[l][i];
        }
    }
    return PLAINTEXT;
}