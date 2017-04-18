#include "Railfence.h"

bool Railfence::setKey(const string& key)
{
	bool isNumber = true;
	char c;

	for (int i = 0;i < key.length();i++)
	{
		c = key[i];
		if (!isdigit(c))
			isNumber = false;
	}
	if (isNumber)
	{
		KEY = atoi(key.c_str());
		if (KEY < 1)
			isNumber = false;
	}
	return isNumber;
}

string Railfence::encrypt(const string& plaintext)
{
	vector<string> ciphertext;
	for(int i = 0; i < KEY; i++)
	{
		ciphertext.push_back("");
	}
	for (int i = 0; i < plaintext.length(); i++)
	{
		int depth = i % KEY;
		ciphertext.at(depth) += plaintext[i];
	}
	for (int i = 0; i < KEY; i++)
	{
		CIPHERTEXT += ciphertext[i];
	}
	return CIPHERTEXT;
}
string Railfence::decrypt(const string& ciphertext)
{
	int length = ciphertext.length();
	int a = length/ KEY;
	int b = length % KEY;
	int position = 0;
	vector<int> c;
	vector<string> plaintext;
	for (int i = 0; i < KEY; i++)
	{
		plaintext.push_back("");
		c.push_back(a);
		if (b > 0)
			{
				c.at(i) = a+1;
				b--;
			}
	}
	for (int i = 0; i < KEY; i++)
	{
		for(int l = 0; l < c.at(i); l++)
		{
			plaintext[i] += ciphertext[position];
			position++;
		}
	}
	a = length / KEY;
	b = length % KEY;
	for (int i = 0; i < a+b; i++)
	{
		if(b > 1)
		{
			if(i > a)
				b--;
		}
		for(int l = 0; l < KEY; l++)
		{
			PLAINTEXT += plaintext[l][i];
		}
	}
	return PLAINTEXT;
}