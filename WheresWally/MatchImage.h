#pragma once
#include "BaseImage.h"
#include "InputOutput.h"
#include <limits>
#include <iostream>

class MatchImage : public BaseImage
{
public:
	//constructors
	MatchImage();
	MatchImage(double* input_wally);

	//functions
	void SSDRanking(double sum, int CompareM, int CompareN);
	void NCRanking(double sum, int CompareM, int CompareN);
	void Swap(double* moveup, double* movedown);
	void PrintOut(double* arr);

	//min and max for SSD and NC respectively
	double SSDMax = DBL_MAX;
	double NCMin = -1;

	//storage for wally
	double* wally;

	//used for ranking/scoring SSD
	double* SSDnear1 = new double[3]{SSDMax ,-1,-1 };
	double* SSDnear2 = new double[3]{ SSDMax,-1,-1 };
	double* SSDnear3 = new double[3]{ SSDMax,-1,-1 };
	double* SSDnear4 = new double[3]{ SSDMax,-1,-1 };
	double* SSDnear5 = new double[3]{ SSDMax,-1,-1 };
	double* SSDnear6 = new double[3]{ SSDMax,-1,-1 };

	//used for ranking/scoring NC
	double* NCnear1 = new double[3]{ NCMin ,-1,-1 };
	double* NCnear2 = new double[3]{ NCMin,-1,-1 };
	double* NCnear3 = new double[3]{ NCMin,-1,-1 };
	double* NCnear4 = new double[3]{ NCMin,-1,-1 };
	double* NCnear5 = new double[3]{ NCMin,-1,-1 };
	double* NCnear6 = new double[3]{ NCMin,-1,-1 };

	//temporary storage for both
	double* temp = new double[3];
private:
};