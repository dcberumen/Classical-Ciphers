all:	cipher

cipher:	cipher.o Caesar.o Playfair.o Railfence.o RowTransposition.o Vigenere.o
	g++ cipher.o Caesar.o Playfair.o Railfence.o RowTransposition.o Vigenere.o -o cipher

cipher.o:	cipher.cpp
	g++ -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -g -c Playfair.cpp

# Uncomment this code once you add the appropriate files
RowTransposition.o:	RowTransposition.cpp RowTransposition.h
	g++ -g -c RowTransposition.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -g -c Caesar.cpp

Railfence.o: Railfence.cpp Railfence.h CipherInterface.h
	g++ -g -c Railfence.cpp

Vigenere.o: Vigenere.cpp Vigenere.h CipherInterface.h
	g++ -g -c Vigenere.cpp

clean:
	rm -rf *.o cipher
