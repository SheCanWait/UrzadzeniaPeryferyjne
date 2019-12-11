#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

char ESC = 27;
char carriageReturn = 13;
char backSpace = 8;

void waitForInput() {
	int x;
	cin >> x;
}

int carSymbol[] = {0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 60, 0 ,0 , 3, 0 , 0, 252, 128 , 0, 3, 64, 1, 252, 128, 2, 3,
64, 5, 124, 128, 10, 3,0, 20, 124, 0, 40, 0,0,80,126,0,32,0,0,64,126,0,63,128,0,64,126,0,63,128,0,64,124,0,32,
3,0,64,124,128,32,3,64,64,124,128,48,3,64,76,124,128,51,3,0,12,252,0,3,0,0,0,254,0,0,0,0};

int telephoneSymbol[] = { 0, 0, 0, 7, 0, 0, 8, 0, 0, 23, 0, 0, 40, 0, 0, 19, 15, 192, 140, 16, 0, 80, 47, 192, 
32, 80, 0, 80, 175, 192, 47, 80, 0, 80, 175, 192, 47, 80, 0, 80, 163, 192, 33, 64, 0, 80,   
163, 192, 33, 64, 0, 80, 163, 192, 47, 80, 0, 80, 175, 192, 47, 80, 0, 80, 175, 192, 32, 80,  
0, 80, 47, 192, 40, 16, 0, 19, 15, 192, 40, 0, 0, 23, 0, 0, 8, 0, 0, 7, 0, 0, 0, 0, 0 }; 

int main()
{
	cout << "Program starting..." << endl;
	fstream stream;
	stream.open("LPT3", ios::out);
	cout << "Is port open: " << stream.is_open() << endl;

	stream << ESC << "h" << char(0);
	stream << ESC << "l" << (char)0;
	
	stream << ESC << "x0" << "Select draft quality characters - manual 55" << endl;
	stream << ESC << "x1" << "Select LQ characters - manual 56" << endl;
	stream << ESC << "k0" << "Select LQ font - Roman - manual 56" << endl; 
	stream << ESC << "k1" << "Select LQ font - Sanserif - manual 56" << endl;
	stream << ESC << "k2" << "Select LQ font - Courier - manual 56" << endl;
	stream << ESC << "k3" << "Select LQ font - Prestige - manual 56" << endl;
	stream << ESC << "k4" << "Select LQ font - script - manual 56" << endl;
	stream << ESC << "k5" << "Select LQ font - OCR-B - manual 56" << endl;
	stream << ESC << "k6" << "Select LQ font - OCR-A - manual 56" << endl;
	stream << ESC << "k7" << "Select LQ font -  Orator - manual 56" << endl;
	stream << ESC << "k8" << "Select LQ font - Orator2 - manual 56" << endl;

	stream << ESC << "4" << "Causes subsequent charactem to be printed in italics." << endl;
	stream << ESC << "G" << "Double-strike mode text" << ESC << "H" << endl;
	stream << ESC << "-1" << "Underlining mode text" << ESC << "-0" << endl;

	stream << ESC << "l55" << "Left margin set to 55" << endl;
	stream << ESC << "l152" << "Left margin set to 152" << endl;
	stream << ESC << "l0" << "Left margin set to 0" << endl;
	stream << ESC << "Q55" << "Right margin set to 55" << endl;
	stream << ESC << "Q160" << "Right margin set to 160" << endl;

	stream << carriageReturn << endl;
	stream << ESC << "Backspace test" << backSpace << backSpace << backSpace << backSpace << "Another test" << endl;
	stream << ESC << ":" << (char)0 << (char)0 << (char)0; //manual 87
	stream << ESC << "x1";
	stream << ESC << "&" << (char)0; //manual 85
	stream << (char)56 << (char)56; 
	stream << (char)3 << (char)31 << (char)2;

	for (int i = 0; i < 1000; i++) {
		stream << (char)telephoneSymbol[i];
	}
	stream <<  ESC<< "xxxxxxxxxx  ";
	stream << (char)56 << endl;
	stream << ESC << "  yyyyyyyyyy";
	for (int i = 0; i < 93; i++) {
		stream << (char)carSymbol[i];
	}


	stream << ESC << ":" << (char)0 << (char)0 << (char)0; //manual 87
	stream << ESC << "&" << (char)0; //manual 85
	stream << (char)127 << (char)127; //delete = 127
	stream << (char)3 << (char)31 << (char)2;


	stream << endl << endl;


	cout << "End of the program" << endl;
	stream.close();
	waitForInput();
}

