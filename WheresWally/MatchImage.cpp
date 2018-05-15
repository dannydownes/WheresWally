#include "stdafx.h"
#include "MatchImage.h"

MatchImage::MatchImage()
{
	
}

MatchImage::MatchImage(double* input_wally)
{
	wally = new double(WallyM * WallyN);

	wally = Matrix(WallyM, WallyN, input_wally);
}

void MatchImage::SSDRanking(double sum, int CompareM, int CompareN)
{
	//swaps if sum is better than lowest high score
	if (sum < SSDnear6[0])
	{
		SSDnear6[0] = sum;
		SSDnear6[1] = CompareM;
		SSDnear6[2] = CompareN;

		if (SSDnear6[0] < SSDnear5[0])
		{
			Swap(SSDnear6, SSDnear5);
			if (SSDnear5[0] < SSDnear4[0])
			{
				Swap(SSDnear5, SSDnear4);
				if (SSDnear4[0] < SSDnear3[0])
				{
					Swap(SSDnear4, SSDnear3);
					if (SSDnear3[0] < SSDnear2[0])
					{
						Swap(SSDnear3, SSDnear2);
						if (SSDnear2[0] < SSDnear1[0])
						{
							//swaps to the best score
							Swap(SSDnear2, SSDnear1);
						}
					}
				}
			}
		}
	}
}

void MatchImage::NCRanking(double sum, int CompareM, int CompareN)
{
	//swaps if sum is better than lowest high score
	if (sum > NCnear6[0])
	{
		NCnear6[0] = sum;
		NCnear6[1] = CompareM;
		NCnear6[2] = CompareN;

		if (NCnear6[0] > NCnear5[0])
		{
			Swap(NCnear6, NCnear5);

			if (NCnear5[0] > NCnear4[0])
			{
				Swap(NCnear5, NCnear4);

				if (NCnear4[0] > NCnear3[0])
				{
					Swap(NCnear4, NCnear3);

					if (NCnear3[0] > NCnear2[0])
					{
						Swap(NCnear3, NCnear2);

						if (NCnear2[0] > NCnear1[0])
						{
							//swaps to the best score
							Swap(NCnear2, NCnear1);
						}
					}
				}
			}
		}
	}
}

void MatchImage::Swap(double* moveup, double* movedown)
{
	//moves x to temp
	for (int i = 0; i < sizeof(temp); i++)
	{
		temp[i] = movedown[i];
	}

	//moves y to x
	for (int i = 0; i < sizeof(temp); i++)
	{
		movedown[i] = moveup[i];
	}

	//moves x to y
	for (int i = 0; i < sizeof(temp); i++)
	{
		moveup[i] = temp[i];
	}
}

void MatchImage::PrintOut(double* arr)
{
	std::cout << "Comparison Score = " << arr[0] << "\t\tM Position = " << arr[1] << " " << "\tN Position = " << arr[2] << std::endl;
}