#include "LosslessDataCompression.h"
#include "fstream"
#include "array"
#include "string"

string LosslessDataCompression::CompressTextData(ifstream &fileToRead)
{
	// initialize local varabls
	string WordToCheck;
	string outputString;
	int wordIndexLength = 0;
	
	// while loop to loop through the words in the text document 
	while (fileToRead >> WordToCheck)
	{
		try
		{
			if (wordIndexLength >= maxWordIndexLength)
			{
				throw 1011;
			}
		}
		catch (int erorCode)
		{
			cout << "error: " << erorCode << " Text document has to many words";
			return "error: " + to_string(erorCode);
		}
		bool wordFound = false;
		// loop to search if the current word (WordToCheck) is already saved in the array
		for (int n = 0; n < wordIndexLength; n++)
		{
			//tempWord.compare(wordIndex[n]) == 0
			if (WordToCheck == wordIndex[n])
			{
				//assign the index value of the found word to the output string 
				outputString += to_string(n);
				outputString += " ";
				// If the word was found then set the bool to true so that the word is not added as a new item in teh next if block.
				wordFound = true;
				break;
			}
		}
		// if word was not found then add it to the sotrage array
		if (!wordFound)
		{
			//if we did not find a word -> assign a index to the word then add that index to the output string
			wordIndex[wordIndexLength] = WordToCheck;
			outputString += to_string(wordIndexLength);
			outputString += " ";
			wordIndexLength++;
		}
	}
	//set the compressed file word langth if need for other perpuses 
	compressedFileIndexLength = wordIndexLength;

	return outputString;
}

void LosslessDataCompression::CreateCompressedFileFromString(string compressedTextString)
{
	// create a output file that contains the compressed string
	ofstream compressedTextFile("Com_data1.txt");
	compressedTextFile << compressedTextString;
	compressedTextFile.close();
}
