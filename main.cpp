#include <iostream>

#include "CustomVariables/CString/CString.h"

void SetConsoleColor(int newColor)
{
	std::cout << "\033[" << newColor << "m";
}
void ResetConsoleColor()
{
	std::cout << "\033[0m";
}

int main()
{
	// ---------------------------------------------------------------------- // 

	{
		SetConsoleColor(32);
		std::cout << "Constructor tests:" << std::endl;
		ResetConsoleColor();

		// Testing Constructor 1
		CString testString1("Hello World!");

		std::cout << "String 1 message: " << testString1.GetValue() << " (Should be 'Hello World!')" << std::endl;

		// Testing Constructor 2
		CString testString2(testString1);
		testString2 += "2";
		std::cout << "String 2 message: " << testString2.GetValue() << " (Should be 'Hello World!2')" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- // 

	{
		SetConsoleColor(32);
		std::cout << "Length tests:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString testString2("Hello World!2");

		// Testing Length
		std::cout << "Length of string 1: " << testString1.Length() << " (Should be 12)" << std::endl;
		std::cout << "Length of string 2: " << testString2.Length() << " (Should be 13)" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "Character at tests:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString testString2("Hello World!2");

		// Testing CharacterAt 1
		int positionToCheck1 = 1;
		std::cout << "String 1 - Character at position " << positionToCheck1 << " is '" << testString1.CharacterAt(positionToCheck1) << "' (Should be e)" << std::endl;

		// Testing CharacterAt 2
		int positionToCheck2 = 4;
		std::cout << "String 2 - Character at position " << positionToCheck2 << " is '" << testString2.CharacterAt(positionToCheck2) << "' (Should be o)" << std::endl;
		std::cout << std::endl;

		SetConsoleColor(32);
		std::cout << "Array[] tests:" << std::endl;
		ResetConsoleColor();

		// Testing [] 1
		int positionToCheck3 = 2;
		std::cout << "String 1 - Character at position " << positionToCheck3 << " is '" << testString1[positionToCheck3] << "' (Should be l)" << std::endl;

		// Testing [] 2
		int positionToCheck4 = 6;
		std::cout << "String 2 - Character at position " << positionToCheck4 << " is '" << testString2[positionToCheck4] << "' (Should be w)" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "Equals tests:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString testString2("Hello World!2");

		// Testing equals
		std::cout << "Does string 1 match string 2 Equals()? (Should be false!)" << std::endl;
		if (testString1.Equals(testString2))
		{
			std::cout << "True, it does match." << std::endl;
		}
		else
		{
			std::cout << "False, it does not match." << std::endl;
		}
		std::cout << std::endl;

		SetConsoleColor(32);
		std::cout << "== and != tests:" << std::endl;
		ResetConsoleColor();

		// Testing ==
		std::cout << "Does string 1 match string 2 with ==? (Should be false!)" << std::endl;
		if (testString1 == testString2)
		{
			std::cout << "True, it does match." << std::endl;
		}
		else
		{
			std::cout << "False, it does not match." << std::endl;
		}
		std::cout << std::endl;

		// Testing !=
		std::cout << "Does string 1 not match string 2 with !=? (Should be true!)" << std::endl;
		if (testString1 != testString2)
		{
			std::cout << "True, it does not match." << std::endl;
		}
		else
		{
			std::cout << "False, it does match." << std::endl;
		}
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "Append/Prepend tests:" << std::endl;
		ResetConsoleColor();

		char testing1[] = "Hello World!";
		CString testString1(testing1);

		char testing2[] = "Hello World!2";
		CString testString2(testing2);

		// Testing Append
		CString testString1Copy1(testString1);
		testString1Copy1.Append(testString2);
		std::cout << "Appended string: '" << testString1Copy1.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;

		// Testing Prepend
		CString testString1Copy2(testString1);
		testString1Copy2.Prepend(testString2);
		std::cout << "Prepended string: '" << testString1Copy2.GetValue() << "' (Should be 'Hello World!2Hello World!')" << std::endl;
		std::cout << std::endl;

		SetConsoleColor(32);
		std::cout << "+ and += operator tests:" << std::endl;
		ResetConsoleColor();

		// Testing +=
		CString concatString(testString1);
		concatString += testString2;
		std::cout << "+= string: '" << concatString.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;

		// Testing +
		CString addedString = testString1 + testString2;
		std::cout << "+ string: '" << addedString.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "ToLower and ToUpper tests:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString testString2("Hello World!2");

		// Testing to lower
		std::cout << "String 1 to lower: '" << testString1.ToLower().GetValue() << "' (Should be 'hello world!')" << std::endl;

		// Testing to upper
		std::cout << "String 1 to upper: '" << testString1.ToUpper().GetValue() << "' (Should be 'HELLO WORLD!')" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "Find tests:" << std::endl;
		ResetConsoleColor();

		CString testString("Hello World!");
		CString stringToFind("World");

		// Testing find methods
		int startPosition = testString.Find(stringToFind);
		
		if (startPosition == -1)
		{
			std::cout << "Couldn't find the target string" << std::endl;
		}
		else
		{
			std::cout << "Found the string at position: " << startPosition << " (Should be 6)" << std::endl;
		}

		int startPosition2 = testString.Find(7, stringToFind);

		if (startPosition2 == -1)
		{
			std::cout << "Couldn't find the target string" << std::endl;
		}
		else
		{
			std::cout << "Found the word at position: " << startPosition2 << std::endl;
		}
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "Replace tests:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString stringToFind("World");
		CString replacementString("There");

		testString1.Replace(stringToFind, replacementString);

		std::cout << "Replaced string: '" << testString1 << "' (Should be Hello There!)" << std::endl;
		std::cout << std::endl;
	}

	// ---------------------------------------------------------------------- //

	{
		SetConsoleColor(32);
		std::cout << "= test:" << std::endl;
		ResetConsoleColor();

		CString testString1("Hello World!");
		CString testString2 = testString1;

		std::cout << "= string value: '" << testString2 << "' (Should be Hello World!)" << std::endl;
	}

	return 0;
}