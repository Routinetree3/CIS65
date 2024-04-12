#pragma once
#include <iostream>
using namespace std;

/*************************************************************************
******
* Program Name: LosslessDataCompression
* Created Date:2/8/14
* Created By: Christopher Bellavia
* Purpose: Object that contains functions to compress text data
* Acknowledgements: Caleb Curry/Micuh (fileIntup into the While loop), W3School.com, Cplusplus.com
*************************************************************************
******/
class LosslessDataCompression
{

public:

	LosslessDataCompression() = default;
	/*************************************************************************
	******
	* Function Name: CompressTextData
	* Parameters: ifstream &fileToRead
	* Return Value: string
	* Purpose: lossless compress a specified Text file.
	*************************************************************************
	******/
	string CompressTextData(ifstream &fileToRead);

	/*************************************************************************
	******
	* Function Name: CreateCompressedFileFromString
	* Parameters: string compressedTextString
	* Return Value: Text file
	* Purpose: create a text file using a string 
	*************************************************************************
	******/
	void CreateCompressedFileFromString(string compressedTextString);

private:
	// word array to save unique words.
	string wordIndex[1500];
	//other usefull varables 
	int maxWordIndexLength = 1500;
	int compressedFileIndexLength = 0;

};

