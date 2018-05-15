#include "stdafx.h"
#include "InputOutput.h"
#include <iostream> // cout, cerr
#include <sstream>	// stringstream
#include <fstream>	// ifstream
#include <istream>

using namespace std;

double* InputOutput::readTXT(char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i>sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			//cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	//cout << i;

	return data;
}
void InputOutput::WritePGM(char* outputFileName, double *data, int sizeR, int sizeC)
{
	int i, j;
	unsigned char *image;
	ofstream myfile;

	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i<sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myfile.open(outputFileName, ios::out | ios::binary | ios::trunc);

	if (!myfile) {
		cout << "Can't open file: " << outputFileName << endl;
		exit(1);
	}

	myfile << "P5" << endl;
	myfile << sizeC << " " << sizeR << endl;
	myfile << Q << endl;

	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));

	if (myfile.fail()) {
		cout << "Can't write image " << outputFileName << endl;
		exit(0);
	}

	myfile.close();

	delete[] image;
}