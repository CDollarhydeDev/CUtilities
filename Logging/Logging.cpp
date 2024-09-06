#include "Logging.h"

void Logging::WriteToLog(String filePath, String DataToWrite)
{
	std::ofstream myFile("C:\\Users\\s249026\\Desktop\\TestFolder\\TestFile.txt");
	myFile << DataToWrite;

	myFile.close();
}
