#include "Playfair.h"

bool Playfair::setKey(const string& key)
{
	bool valid = true;
	bool inKey = false;
	string tempKey = key;
	for (int i = 0; i < key.length();i++)
	{
		if (!isalpha(key[i]))
		{
			valid = false;
			return valid;
		}
	}
	if (valid)
	{
		for (int i = 0; i < tempKey.length();i++)
		{
			tempKey[i] = toupper(tempKey[i]);
			if (tempKey[i] == 'J')
			{
				tempKey[i] = 'I';
			}
		}
		for (int i = 0; i < tempKey.length(); i++)
		{
			inKey = false;
			for (int l = 0; l < KEY.length(); l++)
			{
				if (tempKey[i] == KEY[l])
					inKey = true;
			}
			if (!inKey)
				KEY += tempKey[i];
		}
	}
	return valid;
}

string Playfair::encrypt(const string& plaintext)
{
	string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	string matrix = KEY;
	string cipherText = plaintext;
	string pfmatrix[5][5];
	string a, b;
	int ax, ay, bx, by, aPosition, bPosition;
	bool inMatrix;
	for (int i = 0; i < cipherText.length(); i++)
	{
		cipherText[i] = toupper(cipherText[i]);
	}
	for (int i = 0; i < 25; i++)
	{
		inMatrix = false;
		for (int l = 0; l < KEY.length(); l++)
		{
			if (alphabet[i] == matrix[l])
				inMatrix = true;
		}
		if (!inMatrix)
			matrix += alphabet[i];
	}
	for (int i = 0; i < 25; i++)
	{
		pfmatrix[i / 5][i % 5] = matrix[i];
	}
	for (int i = 0; i < cipherText.length() - 1; i+=2)
	{
		if (cipherText[i] == cipherText[i + 1])
			cipherText.insert(i+1, "X");
	}
	if ((cipherText.length()) % 2 == 1)
		cipherText.append("X");
	for (int i = 0; i < cipherText.length() - 1; i += 2)
	{
		a = cipherText[i];
		b = cipherText[i + 1];
		aPosition = matrix.find(a);
		bPosition = matrix.find(b);
		ax = aPosition / 5;
		ay = aPosition % 5;
		bx = bPosition / 5;
		by = bPosition % 5;
		if (ax == bx)
		{
			ay++;
			by++;
			if (ay > 4)
				ay -= 5;
			if (by > 4)
				by -= 5;
			cipherText.replace(i, 1, pfmatrix[ax][ay]);
			cipherText.replace(i + 1, 1, pfmatrix[bx][by]);
		}
		else if (ay == by)
		{
			ax++;
			bx++;
			if (ax > 4)
				ax -= 5;
			if (bx > 4)
				bx -= 5;
			cipherText.replace(i, 1, pfmatrix[ax][ay]);
			cipherText.replace(i + 1, 1, pfmatrix[bx][by]);
		}
		else
		{
			cipherText.replace(i, 1, pfmatrix[ax][by]);
			cipherText.replace(i + 1, 1, pfmatrix[bx][ay]);
		}
		
	}
	
	return cipherText;

}
string Playfair::decrypt(const string& ciphertext)
{
	string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	string matrix = KEY;
	string plaintext = ciphertext;
	string pfmatrix[5][5];
	string a, b;
	int ax, ay, bx, by, aPosition, bPosition;
	bool inMatrix;
	for (int i = 0; i < plaintext.length(); i++)
	{
		plaintext[i] = toupper(plaintext[i]);
	}
	for (int i = 0; i < 25; i++)
	{
		inMatrix = false;
		for (int l = 0; l < KEY.length(); l++)
		{
			if (alphabet[i] == matrix[l])
				inMatrix = true;
		}
		if (!inMatrix)
			matrix += alphabet[i];
	}
	for (int i = 0; i < 25; i++)
	{
		pfmatrix[i / 5][i % 5] = matrix[i];
	}
	for (int i = 0; i < plaintext.length(); i += 2)
	{
		if (plaintext[i] == plaintext[i + 1])
			plaintext.insert(i + 1, "X");
	}
	if ((plaintext.length()) % 2 == 1)
		plaintext.append("X");
	
	for (int i = 0; i < plaintext.length() - 1; i += 2)
	{
		a = plaintext[i];
		b = plaintext[i + 1];
		aPosition = matrix.find(a);
		bPosition = matrix.find(b);
		ax = aPosition / 5;
		ay = aPosition % 5;
		bx = bPosition / 5;
		by = bPosition % 5;
		if (ax == bx)
		{
			ay--;
			by--;
			if (ay < 0)
				ay += 5;
			if (by < 0)
				by += 5;
			plaintext.replace(i, 1, pfmatrix[ax][ay]);
			plaintext.replace(i + 1, 1, pfmatrix[bx][by]);
		}
		else if (ay == by)
		{
			ax--;
			bx--;
			if (ax < 0)
				ax += 5;
			if (bx < 0)
				bx += 5;
			plaintext.replace(i, 1, pfmatrix[ax][ay]);
			plaintext.replace(i + 1, 1, pfmatrix[bx][by]);
		}
		else
		{
			plaintext.replace(i, 1, pfmatrix[ax][by]);
			plaintext.replace(i + 1, 1, pfmatrix[bx][ay]);
		}
	}
	return plaintext;
}

