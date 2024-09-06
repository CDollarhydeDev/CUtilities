#include "Logging.h"

void Logging::WriteToLog(String fileName, String dataToWrite)
{
	// Get wchar desktop
	wchar_t wideDesktopPath[MAX_PATH];
	if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, NULL, wideDesktopPath)))
	{
		return;
	}

	// Buffer for converting wchar to char
	const int desktopPathBufferSize = 200;
	char desktopPathBuffer[desktopPathBufferSize];

	// Convert wchar to char
	if (WideCharToMultiByte(CP_ACP, 0, wideDesktopPath, -1, desktopPathBuffer, desktopPathBufferSize, 0, 0) == 0)
	{
		return;
	}

	// Setup filepath with the desktop buffer retrieved
	String filePath = desktopPathBuffer;
	filePath += "\\";
	filePath += fileName;

	std::ifstream existingFile(filePath.GetValue());
	if (existingFile.is_open())
	{
		// Does exist

		char currentLine[1024];
		String combinedData;

		while (!existingFile.eof())
		{
			existingFile.getline(currentLine, 100);
			combinedData += currentLine;
			combinedData += "\n";
		}

		combinedData += dataToWrite;

		existingFile.close();

		std::ofstream myFile(filePath.GetValue());
		myFile << combinedData;

		myFile.close();
	}
	else
	{
		// File does not exist
		std::ofstream myFile(filePath.GetValue());
		myFile << dataToWrite;

		myFile.close();
	}
}
