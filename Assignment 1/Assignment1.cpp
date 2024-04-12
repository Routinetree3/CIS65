// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LosslessDataCompression.h"
#include "fstream"

int main()
{
    //create our objetc that we will use to compress the data
    class LosslessDataCompression compressionModual;

    //create the streamed file object
    ifstream textFile;
    // Open the text data file ( data1.txt | data2.txt | data3.txt -> has to many words to text try/cetch statement)
    textFile.open("data1.txt");
    //compress that data then create a output file containing the compressed data
    compressionModual.CreateCompressedFileFromString(compressionModual.CompressTextData(textFile));

}