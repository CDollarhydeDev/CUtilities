#include "Testing.h"

void SetConsoleColor(int newColor)
{
	std::cout << "\033[" << newColor << "m";
}
void ResetConsoleColor()
{
	std::cout << "\033[0m";
}

Testing::Testing() : logManager(), logFolderPath("C:\\Users\\s249026\Desktop\\LoggingTest\\"), messageToLog()
{
}

Testing::~Testing()
{
}

void Testing::PerformTests()
{
	int testCount = 10;
	int percentageTracker = 0;

	String messageHeader;
	String messageBody;

	for (int i = 0; i < testCount; i++)
	{
		String runResult = RunTest(TestType(i), &percentageTracker);
		messageBody += runResult;
	}
}
String Testing::RunTest(TestType testToRun, int* percentageTracker)
{
	switch (testToRun)
	{

	case Length:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	case CharacterAt:
		if (CharacterAtTest())
		{
			String resultMessage = "Test 1 | CharacterAt | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 1 | CharacterAt | Failed\n";
			return resultMessage;
		}

	case Equals:
		if (EqualsTest())
		{
			String resultMessage = "Test 2 | Equals | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 2 | Equals | Failed\n";
			return resultMessage;
		}

	case Append:
		if (AppendTest())
		{
			String resultMessage = "Test 3 | Append | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 3 | Append | Failed\n";
			return resultMessage;
		}

	case Prepend:
		if (PrependTest())
		{
			String resultMessage = "Test 4 | Prepend | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 4 | Prepend | Failed\n";
			return resultMessage;
		}

	case ToLower:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	case ToUpper:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	case Find:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	case Replace:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	case Operators:
		if (LengthTest())
		{
			String resultMessage = "Test 0 | Length | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 0 | Length | Failed\n";
			return resultMessage;
		}

	default:
		break;
	}
}

bool Testing::LengthTest()
{
	char testMessage[] = "iulfodxVGPUSPPPsdfaswpdlpaWKPOAWFJG0P";
	int testMessageLength = strlen(testMessage);

	String testString(testMessage);
	int testStringLength = testString.Length();

	// Assert expected outcome
	assert(testStringLength == testMessageLength);

	if (testStringLength == testMessageLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Testing::CharacterAtTest()
{
	bool allSucceeded = true;

	String testString("qwdAQWRAFadsCsaegerfgaqWDasdcefqwdsadafqwqwdas");
	int positionToCheck = 15;

	// Assert expected outcomes
	assert(!(testString.CharacterAt(positionToCheck) != 'a'));
	assert(testString[positionToCheck] == 'a');
	assert(!(testString[positionToCheck] == 'a'));

	// Check the method
	if (testString.CharacterAt(positionToCheck) != 'a')
	{
		allSucceeded = false;
	}

	// Check the operators
	if (!testString[positionToCheck] == 'a')
	{
		allSucceeded = false;
	}
	if (testString[positionToCheck] != 'a')
	{
		allSucceeded = false;
	}

	return allSucceeded;
}
bool Testing::EqualsTest()
{
	bool allSucceeded = true;

	String testString("hjiodrdsiugjiISDUGHISUw");
	String testStringCopy = testString;

	// Assert expected outcomes
	assert(testString.Equals(testStringCopy));
	assert(testString == testStringCopy);
	assert(!(testString != testStringCopy));

	// Check method
	if (!testString.Equals(testStringCopy))
	{
		allSucceeded = false;
	}

	// Check operators
	if (!(testString == testStringCopy))
	{
		allSucceeded = false;
	}
	if (testString != testStringCopy)
	{
		allSucceeded = false;
	}

	return allSucceeded;
}
bool Testing::AppendTest()
{
	bool allSucceeded = true;

	// For method test
	String testString1("firstMessage");
	String stringToAppend1("ForTesting");
	String expectedOutcome1("firstMessageForTesting");

	// For += test
	String testString2("secondMessage");
	String stringToAppend2("ForTesting");
	String expectedOutcome2("secondMessageForTesting");

	// For + test
	String testString3("thirdMessage");
	String stringToAppend3("ForTesting");
	String expectedOutcome3("thirdMessageForTesting");

	// Appl operators
	testString1.Append(stringToAppend1);
	testString2 += stringToAppend2;
	String testString3 = testString3 + stringToAppend3;

	// Assert expected outcome
	assert(testString1 == expectedOutcome1);
	assert(testString2 == expectedOutcome2);
	assert(testString3 == expectedOutcome3);

	// Check method result
	if (testString1 != expectedOutcome1)
	{
		allSucceeded = false;
	}

	// Check operator results
	if (testString2 != expectedOutcome2)
	{
		allSucceeded = false;
	}
	if (testString3 != expectedOutcome3)
	{
		allSucceeded = false;
	}

	return allSucceeded;
}
bool Testing::PrependTest()
{
	bool allSucceeded = true;

	String testString("hjghkjzrds");
	String stringToPrepend("yjgghjgfd");
	String expectedOutcome = "yjgghjgfdhjghkjzrds";

	testString.Prepend(stringToPrepend);

	// Assert expected outcome
	assert(testString == expectedOutcome);

	if (testString == expectedOutcome)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void Testing::ConstructorTests()
//{
//	SetConsoleColor(32);
//	std::cout << "Constructor tests:" << std::endl;
//	ResetConsoleColor();
//
//	// Testing Constructor 1
//	String testString1("Hello World!");
//
//	std::cout << "String 1 message: " << testString1.GetValue() << " (Should be 'Hello World!')" << std::endl;
//
//	// Testing Constructor 2
//	String testString2(testString1);
//	testString2 += "2";
//	std::cout << "String 2 message: " << testString2.GetValue() << " (Should be 'Hello World!2')" << std::endl;
//	std::cout << std::endl;
//}
//void Testing::LengthTests()
//{
//	SetConsoleColor(32);
//	std::cout << "Length tests:" << std::endl;
//	ResetConsoleColor();
//
//	String testString1("Hello World!");
//	String testString2("Hello World!2");
//
//	// Testing Length
//	std::cout << "Length of string 1: " << testString1.Length() << " (Should be 12)" << std::endl;
//	std::cout << "Length of string 2: " << testString2.Length() << " (Should be 13)" << std::endl;
//	std::cout << std::endl;
//}
//void Testing::CharacterAtTests()
//{
//	SetConsoleColor(32);
//	std::cout << "Character at tests:" << std::endl;
//	ResetConsoleColor();
//
//	String testString1("Hello World!");
//	String testString2("Hello World!2");
//
//	// Testing CharacterAt 1
//	int positionToCheck1 = 1;
//	std::cout << "String 1 - Character at position " << positionToCheck1 << " is '" << testString1.CharacterAt(positionToCheck1) << "' (Should be e)" << std::endl;
//
//	// Testing CharacterAt 2
//	int positionToCheck2 = 4;
//	std::cout << "String 2 - Character at position " << positionToCheck2 << " is '" << testString2.CharacterAt(positionToCheck2) << "' (Should be o)" << std::endl;
//	std::cout << std::endl;
//
//	SetConsoleColor(32);
//	std::cout << "Array[] tests:" << std::endl;
//	ResetConsoleColor();
//
//	// Testing [] 1
//	int positionToCheck3 = 2;
//	std::cout << "String 1 - Character at position " << positionToCheck3 << " is '" << testString1[positionToCheck3] << "' (Should be l)" << std::endl;
//
//	// Testing [] 2
//	int positionToCheck4 = 6;
//	std::cout << "String 2 - Character at position " << positionToCheck4 << " is '" << testString2[positionToCheck4] << "' (Should be w)" << std::endl;
//	std::cout << std::endl;
//}
//void Testing::EqualsTests()
//{
//	SetConsoleColor(32);
//	std::cout << "Equals tests:" << std::endl;
//	ResetConsoleColor();
//
//	String testString1("Hello World!");
//	String testString2("Hello World!2");
//
//	// Testing equals
//	std::cout << "Does string 1 match string 2 Equals()? (Should be false!)" << std::endl;
//	if (testString1.Equals(testString2))
//	{
//		std::cout << "True, it does match." << std::endl;
//	}
//	else
//	{
//		std::cout << "False, it does not match." << std::endl;
//	}
//	std::cout << std::endl;
//
//	SetConsoleColor(32);
//	std::cout << "== and != tests:" << std::endl;
//	ResetConsoleColor();
//
//	// Testing ==
//	std::cout << "Does string 1 match string 2 with ==? (Should be false!)" << std::endl;
//	if (testString1 == testString2)
//	{
//		std::cout << "True, it does match." << std::endl;
//	}
//	else
//	{
//		std::cout << "False, it does not match." << std::endl;
//	}
//	std::cout << std::endl;
//
//	// Testing !=
//	std::cout << "Does string 1 not match string 2 with !=? (Should be true!)" << std::endl;
//	if (testString1 != testString2)
//	{
//		std::cout << "True, it does not match." << std::endl;
//	}
//	else
//	{
//		std::cout << "False, it does match." << std::endl;
//	}
//	std::cout << std::endl;
//}
//void Testing::AppendPrependTests()
//{
//	SetConsoleColor(32);
//	std::cout << "Append/Prepend tests:" << std::endl;
//	ResetConsoleColor();
//
//	char testing1[] = "Hello World!";
//	String testString1(testing1);
//
//	char testing2[] = "Hello World!2";
//	String testString2(testing2);
//
//	// Testing Append
//	String testString1Copy1(testString1);
//	testString1Copy1.Append(testString2);
//	std::cout << "Appended string: '" << testString1Copy1.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;
//
//	// Testing Prepend
//	String testString1Copy2(testString1);
//	testString1Copy2.Prepend(testString2);
//	std::cout << "Prepended string: '" << testString1Copy2.GetValue() << "' (Should be 'Hello World!2Hello World!')" << std::endl;
//	std::cout << std::endl;
//
//	SetConsoleColor(32);
//	std::cout << "+ and += operator tests:" << std::endl;
//	ResetConsoleColor();
//
//	// Testing +=
//	String concatString(testString1);
//	concatString += testString2;
//	std::cout << "+= string: '" << concatString.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;
//
//	// Testing +
//	String addedString = testString1 + testString2;
//	std::cout << "+ string: '" << addedString.GetValue() << "' (Should be 'Hello World!Hello World!2')" << std::endl;
//	std::cout << std::endl;
//}
void Testing::ToUpperAndLowerTests()
{
	SetConsoleColor(32);
	std::cout << "ToLower and ToUpper tests:" << std::endl;
	ResetConsoleColor();

	String testString1("Hello World!");
	String testString2("Hello World!2");

	// Testing to lower
	std::cout << "String 1 to lower: '" << testString1.ToLower().GetValue() << "' (Should be 'hello world!')" << std::endl;

	// Testing to upper
	std::cout << "String 1 to upper: '" << testString1.ToUpper().GetValue() << "' (Should be 'HELLO WORLD!')" << std::endl;
	std::cout << std::endl;
}
void Testing::FindTests()
{
	SetConsoleColor(32);
	std::cout << "Find tests:" << std::endl;
	ResetConsoleColor();

	String testString("Hello World!");
	String stringToFind("World");

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
void Testing::ReplaceTests()
{
	SetConsoleColor(32);
	std::cout << "Replace tests:" << std::endl;
	ResetConsoleColor();

	String testString1("Hello World!");
	String stringToFind("World");
	String replacementString("There");

	testString1.Replace(stringToFind, replacementString);

	std::cout << "Replaced string: '" << testString1 << "' (Should be Hello There!)" << std::endl;
	std::cout << std::endl;
}
void Testing::AssigmentTests()
{
	SetConsoleColor(32);
	std::cout << "= test:" << std::endl;
	ResetConsoleColor();

	String testString1("Hello World!");
	String testString2 = testString1;

	std::cout << "= string value: '" << testString2 << "' (Should be Hello World!)" << std::endl;
}
