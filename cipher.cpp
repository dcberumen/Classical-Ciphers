#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "CipherInterface.h"
#include "Caesar.h"
#include "Playfair.h"
#include "Railfence.h"
#include "RowTransposition.h"
#include "Vigenere.h"

using namespace std;

int main(int argc, char** argv)
{
	CipherInterface* cipher = NULL;
	string EncDec = argv[2];
	ifstream read;
	ofstream out;
	string CODE;
	read.open(argv[4]);
	while(read)
	{
		read >> CODE;
	}
	read.close();
	// Create an instance of Playfair cipher
	if( std::string(argv[1]) == "-PLF")
	{
		cipher = new Playfair();
		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		
		/* Set the encryption key */
		if(cipher->setKey(argv[3]))
		{
		/* Perform encryption */
			if(EncDec == "-E" || EncDec == "-e")
			{
				string cipherText = cipher->encrypt(CODE);
				out.open(argv[5]);
				out << cipherText;
				out.close();
			}
		
		/* Perform decryption */
			else if(EncDec == "-D" || EncDec == "-d")
			{
				string plaintext = cipher->decrypt(CODE);
				out.open(argv[5]);
				out << plaintext;
				out.close();
			}	
			else
			{
				fprintf(stderr, "ERROR: Invalid encrypt or decrypt choice\n");
				exit(-1);
			}	
		}
		else
		{
			fprintf(stderr,"ERROR: Invalid key\n");
			exit(-1);
		}
	}
	/* Create an instance of the Caesar cipher */	
	else if( std::string(argv[1]) == "-CES")
	{
		cipher = new Caesar();
		
		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		
		/* Set the encryption key */
		if(cipher->setKey(argv[3]))
		{
		/* Perform encryption */
			if(EncDec == "-E" || EncDec == "-e")
			{
				string cipherText = cipher->encrypt(CODE);
				out.open(argv[5]);
				out << cipherText;
				out.close();
			}
		
		/* Perform decryption */
			else if(EncDec == "-D" || EncDec == "-d")
			{
				string plaintext = cipher->decrypt(CODE);
				out.open(argv[5]);
				out << plaintext;
				out.close();
			}		
			else
			{
				fprintf(stderr, "ERROR: Invalid encrypt or decrypt choice\n");
				exit(-1);
			}	
		}
		else
		{
			fprintf(stderr,"ERROR: Invalid key\n");
			exit(-1);
		}
	}
	else if( std::string(argv[1]) == "-VIG")
	{
		cipher = new Vigenere();
		
		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		
		/* Set the encryption key */
		if(cipher->setKey(argv[3]))
		{
		/* Perform encryption */
			if(EncDec == "-E" || EncDec == "-e")
			{
				string cipherText = cipher->encrypt(CODE);
				out.open(argv[5]);
				out << cipherText;
				out.close();
			}
		
		/* Perform decryption */
			else if(EncDec == "-D" || EncDec == "-d")
			{
				string plaintext = cipher->decrypt(CODE);
				out.open(argv[5]);
				out << plaintext;
				out.close();
			}		
			else
			{
				fprintf(stderr, "ERROR: Invalid encrypt or decrypt choice\n");
				exit(-1);
			}	
		}
		else
		{
			fprintf(stderr,"ERROR: Invalid key\n");
			exit(-1);
		}
	}
	else if( std::string(argv[1]) == "-RTS")
	{
		cipher = new RowTransposition();
		
		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		
		/* Set the encryption key */
		if(cipher->setKey(argv[3]))
		{
		/* Perform encryption */
			if(EncDec == "-E" || EncDec == "-e")
			{
				string cipherText = cipher->encrypt(CODE);
				out.open(argv[5]);
				out << cipherText;
				out.close();
			}
		
		/* Perform decryption */
			else if(EncDec == "-D" || EncDec == "-d")
			{
				string plaintext = cipher->decrypt(CODE);
				out.open(argv[5]);
				out << plaintext;
				out.close();
			}		
			else
			{
				fprintf(stderr, "ERROR: Invalid encrypt or decrypt choice\n");
				exit(-1);
			}	
		}
		else
		{
			fprintf(stderr,"ERROR: Invalid key\n");
			exit(-1);
		}
	}
	else if( std::string(argv[1]) == "-RFC")
	{
		cipher = new Railfence();
		
		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		
		/* Set the encryption key */
		if(cipher->setKey(argv[3]))
		{
		/* Perform encryption */
			if(EncDec == "-E" || EncDec == "-e")
			{
				string cipherText = cipher->encrypt(CODE);
				out.open(argv[5]);
				out << cipherText;
				out.close();
			}
		
		/* Perform decryption */
			else if(EncDec == "-D" || EncDec == "-d")
			{
				string plaintext = cipher->decrypt(CODE);
				out.open(argv[5]);
				out << plaintext;
				out.close();
			}		
			else
			{
				fprintf(stderr, "ERROR: Invalid encrypt or decrypt choice\n");
				exit(-1);
			}

		}
		else
		{
			fprintf(stderr,"ERROR: Invalid key\n");
			exit(-1);
		}
	}
	else
	{
		fprintf(stderr,"ERROR: Invalid cipher choice\n");
		exit(-1);
	}
		
	return 0;
}
