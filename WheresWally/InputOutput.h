#pragma once

class InputOutput
{
public:
	double* readTXT(char *fileName, int sizeR, int sizeC);
	void WritePGM(char* outputFileName, double *data, int sizeR, int sizeC);
private:
	// writes data back to .pgm file stored in outputFileName
	// Use Q = 255 for greyscale images and 1 for binary images.
	int Q = 255;
};