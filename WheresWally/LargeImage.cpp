#include "stdafx.h"
#include "LargeImage.h"


//BIG PIC GOES HERE

LargeImage::LargeImage(double* input_data)
{
	Cluttered = new double[ClutteredM * ClutteredN];
	Cluttered = Matrix(ClutteredM, ClutteredN, input_data);
}

double LargeImage::NNSSSD(MatchImage MI)
{
	MoveM = 0;
	MoveN = 0;

	//move matrix a row
	for (int CompareM = 0; CompareM < ClutteredM; CompareM += WallyM)
	{
		//move matrix a column
		for (int CompareN = 0; CompareN < ClutteredN; CompareN += WallyN)
		{
			double* full = SmallMatrix(MoveM, MoveN, Cluttered);

			sum = SSD(MI.wally, full);

			//std::cout << "M = " << CompareM << " " << MoveM << " N = " << CompareN << " " << MoveN<< " Result = " << sum << std::endl;

			//calls the SSD
			MI.SSDRanking(sum, CompareM, CompareN);

			delete full;

			MoveN++;
		}
		MoveM++;
	}

	return 0;
}

double LargeImage::NNSNC(MatchImage MI)
{
	MoveM = 0;
	MoveN = 0;

	//move matrix a row
	for (int CompareM = 0; CompareM < ClutteredM; CompareM += WallyM)
	{
		//move matrix a column
		for (int CompareN = 0; CompareN < ClutteredN; CompareN += WallyN)
		{
			double* full = SmallMatrix(MoveM, MoveN, Cluttered);

			sum = NC(MI.wally, full);

			//std::cout << "M = " << CompareM << " " << MoveM << " N = " << CompareN << " " << MoveN << " Result = " << sum << std::endl;

			//calls the normalised correlation
			MI.NCRanking(sum, CompareM, CompareN);

			delete full;

			MoveN++;
		}
		MoveM++;
	}

	return 0;
}