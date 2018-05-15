#include "stdafx.h"
#include "BaseImage.h"
#include <iostream>

double* BaseImage::Matrix(int sizeR, int sizeC, double* input_data)
{
	//std::cout << "BaseImage::Matrix(int sizeR, int sizeC, double* input_data) was invoked." << std::endl;

	_M = sizeR;
	_N = sizeC;

	_data = new double[_M*_N];

	for (int i = 0; i < _M*_N; i++)
	{
		_data[i] = input_data[i];

		//std::cout << _data[i] << std::endl;
	}

	return _data;
}

double BaseImage::SSD(double* wally, double* cluttered)
{ 
	double sum = 0;

	//move down rows
	for (int M = 0; M < WallyM; M++)
	{
		//move along columns
		for (int N = 0; N < WallyN; N++)
		{
			//difference
			double temp = Get(M, N, WallyN, cluttered) - Get(M, N, WallyN, wally);

			//square
			temp = temp * temp;

			//sum
			sum += temp;
		}
	}
	return sum;
}

double BaseImage::NC(double* wally, double* full)
{
	double* normalise1 = new double[WallyM*WallyN];
	double* normalise2 = new double[WallyM*WallyN];

	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			normalise1[M*WallyN + N] = wally[M*WallyN + N];
			normalise2[M*WallyN + N] = full[M*WallyN + N];
		}
	}

	//compute mean
	double sum1 = 0;
	double sum2 = 0;

	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			sum1 += Get(M, N, WallyN, normalise1);
			sum2 += Get(M, N, WallyN, normalise2);
		}
	}

	sum1 = sum1 * (1/(49 * 36));
	sum2 = sum2 * (1/(49 * 36));

	
	//subtract mean from each element
	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			normalise1[M * WallyN + N] = normalise1[M * WallyN + N] - sum1;
			normalise2[M * WallyN + N] = normalise2[M * WallyN + N] - sum2;
		}
	}

	double sum3 = 0;
	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			sum3 += Get(M, N, WallyN, normalise1) * Get(M, N, WallyN, normalise2);
		}
	}

	//compute the normalised correlation
	double sum4 = 0;
	double sum5 = 0;

	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			sum4 += (Get(M, N, WallyN, normalise1) * Get(M, N, WallyN, normalise1));
			sum5 += (Get(M, N, WallyN, normalise2) * Get(M, N, WallyN, normalise2));
		}
	}

	double sum6 = sum4 * sum5;
	sum6 = sqrt(sum6);

	double sum7 = sum3 / sum6;

	return sum7;
}

double BaseImage::Get(int M, int N, int _N, double*_data)
{
	//get function is the same as [M][N]
	return _data[M * _N + N];
}

double* BaseImage::SmallMatrix(int ScrollN, int ScrollM, double* Cluttered)
{
	//builds a wally size matrix
	_SmallMatrix = new double[WallyM*WallyN];

	//using the numbers passed on from for loop, allows the SSD to scroll through the whole cluttered scene
	for (int M = 0; M < WallyM; M++)
	{
		for (int N = 0; N < WallyN; N++)
		{
			_SmallMatrix[M * WallyN + N] = Get((M + ScrollM), (N + ScrollN), ClutteredN, Cluttered);
		}
	}
	return _SmallMatrix;
}