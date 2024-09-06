#pragma once

#include <iostream>
#include <fstream>
#include <shlobj.h>

#include "../CustomVariables/String/String.h"

// ofstream: Stream class to write on files
// ifstream : Stream class to read from files
// fstream : Stream class to both read and write from / to files.

class Logging
{
public:
	void WriteToLog(String fileName, String dataToWrite);
};

