#pragma once
#include "BaseImage.h"
#include "LargeImage.h"
#include "MatchImage.h"
#include <iostream>

class LargeImage: public BaseImage
{
public:		
	LargeImage(double* input_data);
	double NNSSSD(MatchImage MI);
	double NNSNC(MatchImage MI);

	double* Cluttered;
	int MoveM;
	int MoveN;
	double sum = 0;
	double SSDSum = 0;
	double NCSum = 0;
private:

};