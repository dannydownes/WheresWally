#include "stdafx.h"
#include <iostream>
#include "BaseImage.h"
#include "MatchImage.h"
#include "LargeImage.h"
#include "InputOutput.h"

using namespace std;

int main()
{	
	//size of cluttered and wally arrays
	const int cM = 768;		const int cN = 1024;
	const int wM = 49;		const int wN = 36;

	//initialises input and output class, the arrays and the file locations for big and wally image
	InputOutput IO;
	
	double* input_data = 0;
	char* inputFileName = "..\\Input\\Cluttered_scene.txt";

	double* input_wally = 0;
	char* inputWally = "..\\Input\\Wally_grey.txt";

	//info for user whilst importing data
	cout << "Importing data from text files . . ." << endl;

	input_data = IO.readTXT(inputFileName, cM, cN);
	input_wally = IO.readTXT(inputWally, wM, wN);
	
	//succesful or not
	if (input_data != nullptr && input_wally != nullptr)
	{
		cout << "Data successfully imported . . ." << endl;
	}
	else
	{
		cout << "There was an error importing the data from the file" << endl;
	}
	
	//creating objects needed for the nearest neigbor searches
	BaseImage BI;
	LargeImage LI(input_data);
	MatchImage SSD(input_wally);
	MatchImage NC(input_wally);

	// Nearest Neighbor Search using Sum of Squared Differences and results
	LI.NNSSSD(SSD);

	std::cout << std::endl;
	std::cout << "\t\t------------SSD Nearest Results------------" << std::endl;
	std::cout << std::endl;
	SSD.PrintOut(SSD.SSDnear1);
	SSD.PrintOut(SSD.SSDnear2);
	SSD.PrintOut(SSD.SSDnear3);
	SSD.PrintOut(SSD.SSDnear4);
	SSD.PrintOut(SSD.SSDnear5);
	SSD.PrintOut(SSD.SSDnear6);
	std::cout << std::endl;

	//Nearest Neighbor Search using Normalised Correlation and results
	LI.NNSNC(NC);

	std::cout << std::endl;
	std::cout << "\t\t------------NC  Nearest Results------------" << std::endl;
	std::cout << std::endl;
	NC.PrintOut(NC.NCnear1);
	NC.PrintOut(NC.NCnear2);
	NC.PrintOut(NC.NCnear3);
	NC.PrintOut(NC.NCnear4);
	NC.PrintOut(NC.NCnear5);
	NC.PrintOut(NC.NCnear6);
	std::cout << std::endl;

	//output of the nearest matches to files for both NC and SSD
	char* SSD1 = "..\\Output\\SSD\\1.pgm";
	char* SSD2 = "..\\Output\\SSD\\2.pgm";
	char* SSD3 = "..\\Output\\SSD\\3.pgm";
	char* SSD4 = "..\\Output\\SSD\\4.pgm";
	char* SSD5 = "..\\Output\\SSD\\5.pgm";
	char* SSD6 = "..\\Output\\SSD\\6.pgm";

	char* NC1 = "..\\Output\\NC\\1.pgm";
	char* NC2 = "..\\Output\\NC\\2.pgm";
	char* NC3 = "..\\Output\\NC\\3.pgm";
	char* NC4 = "..\\Output\\NC\\4.pgm";
	char* NC5 = "..\\Output\\NC\\5.pgm";
	char* NC6 = "..\\Output\\NC\\6.pgm";

	IO.WritePGM(SSD1, BI.SmallMatrix(SSD.SSDnear1[1], SSD.SSDnear1[2], LI.Cluttered), wM, wN);
	IO.WritePGM(SSD2, BI.SmallMatrix(SSD.SSDnear2[1], SSD.SSDnear2[2], LI.Cluttered), wM, wN);
	IO.WritePGM(SSD3, BI.SmallMatrix(SSD.SSDnear3[1], SSD.SSDnear3[2], LI.Cluttered), wM, wN);
	IO.WritePGM(SSD4, BI.SmallMatrix(SSD.SSDnear4[1], SSD.SSDnear4[2], LI.Cluttered), wM, wN);
	IO.WritePGM(SSD5, BI.SmallMatrix(SSD.SSDnear5[1], SSD.SSDnear5[2], LI.Cluttered), wM, wN);
	IO.WritePGM(SSD6, BI.SmallMatrix(SSD.SSDnear6[1], SSD.SSDnear6[2], LI.Cluttered), wM, wN);

	IO.WritePGM(NC1, BI.SmallMatrix(NC.NCnear1[1], NC.NCnear1[2], LI.Cluttered), wM, wN);
	IO.WritePGM(NC2, BI.SmallMatrix(NC.NCnear2[1], NC.NCnear2[2], LI.Cluttered), wM, wN);
	IO.WritePGM(NC3, BI.SmallMatrix(NC.NCnear3[1], NC.NCnear3[2], LI.Cluttered), wM, wN);
	IO.WritePGM(NC4, BI.SmallMatrix(NC.NCnear4[1], NC.NCnear4[2], LI.Cluttered), wM, wN);
	IO.WritePGM(NC5, BI.SmallMatrix(NC.NCnear5[1], NC.NCnear5[2], LI.Cluttered), wM, wN);
	IO.WritePGM(NC6, BI.SmallMatrix(NC.NCnear6[1], NC.NCnear6[2], LI.Cluttered), wM, wN);

	//clean up
	delete[] input_data, input_wally;

	return 0;
}

