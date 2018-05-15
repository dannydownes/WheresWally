#pragma once

class BaseImage
{
public:
	double* Matrix(int sizeR, int sizeC, double* input_data);
	double Get(int M, int N, int _N, double* _data);
	double SSD(double* wally, double* cluttered);
	double NC(double* normalise1, double* normalise2);
	double* SmallMatrix(int ScrollM, int ScrollN, double* Cluttered);
	
	const int WallyM = 49;
	const int WallyN = 36;
	const int ClutteredM = 768;
	const int ClutteredN = 1024;	
	
	double* _SmallMatrix;
	double* _data;
	int _M, _N;
private:
	
};