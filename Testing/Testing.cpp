#include "Testing.h"

void SetConsoleColor(int newColor)
{
	std::cout << "\033[" << newColor << "m";
}
void ResetConsoleColor()
{
	std::cout << "\033[0m";
}
String PercentToString(size_t Int)
{
	if (Int == 0)
	{
		return String("0");
	}
	else if (Int == 10)
	{
		return String("10");
	}
	else if (Int == 20)
	{
		return String("20");
	}
	else if (Int == 30)
	{
		return String("30");
	}
	else if (Int == 40)
	{
		return String("40");
	}
	else if (Int == 50)
	{
		return String("50");
	}
	else if (Int == 60)
	{
		return String("60");
	}
	else if (Int == 70)
	{
		return String("70");
	}
	else if (Int == 80)
	{
		return String("80");
	}
	else if (Int == 90)
	{
		return String("90");
	}
	else if (Int == 100)
	{
		return String("100");
	}
	else
	{
		return String("");
	}
}

Testing::Testing() : logManager()
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

	// Get the timestamp for the current date and time
	time_t timestamp = time(NULL);
	char timeStampBuffer[100];
	ctime_s(timeStampBuffer, sizeof(timeStampBuffer), &timestamp);

	String timeStampString = timeStampBuffer;
	timeStampString.Replace("\n", "");
	timeStampString.Replace("  ", " ");

	// Add it to the message header
	messageHeader += timeStampString + " | Successful Percentage: ";
	messageHeader += PercentToString(percentageTracker);
	messageHeader += ".00%\n";

	String dataToWrite = messageHeader + messageBody;

	logManager.WriteToLog("Tests_Summary.txt", dataToWrite);
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
		if (ToLowerTest())
		{
			String resultMessage = "Test 5 | ToLower | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 5 | ToLower | Failed\n";
			return resultMessage;
		}

	case ToUpper:
		if (ToUpperTest())
		{
			String resultMessage = "Test 6 | ToUpper | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 6 | ToUpper | Failed\n";
			return resultMessage;
		}

	case Find:
		if (FindTest())
		{
			String resultMessage = "Test 7 | Find | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 7 | Find | Failed\n";
			return resultMessage;
		}

	case Replace:
		if (ReplaceTest())
		{
			String resultMessage = "Test 8 | Replace | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 8 | Replace | Failed\n";
			return resultMessage;
		}

	case Operators:
		if (AssignmentTest())
		{
			String resultMessage = "Test 9 | Assignment | Successful\n";
			*percentageTracker += 10;
			return resultMessage;
		}
		else
		{
			String resultMessage = "Test 9 | Assignment | Failed\n";
			return resultMessage;
		}
	}
}

bool Testing::LengthTest()
{
	char testMessage[] = "iulfodxVGPUSPPPsdfaswpdlpaWKPOAWFJG0P";
	size_t testMessageLength = strlen(testMessage);

	String testString(testMessage);
	size_t testStringLength = testString.Length();

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
	assert(testString.CharacterAt(positionToCheck) == 'e');
	assert(!(testString.CharacterAt(positionToCheck) != 'e'));
	assert(testString[positionToCheck] == 'e');
	assert(!(testString[positionToCheck] != 'e'));

	// Check the method
	if (testString.CharacterAt(positionToCheck) != 'e')
	{
		allSucceeded = false;
	}

	// Check the operators
	if (!(testString[positionToCheck] == 'e'))
	{
		allSucceeded = false;
	}
	if (testString[positionToCheck] != 'e')
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
	testString3 = testString3 + stringToAppend3;

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
bool Testing::ToUpperTest()
{
	String testString("asdfgh");
	String expectedOutcome = "ASDFGH";
	String toUpperString = testString.ToUpper();

	// Assert expected outcome
	assert(toUpperString == expectedOutcome);

	if (toUpperString == expectedOutcome)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Testing::ToLowerTest()
{
	String testString("ASDFGH");
	String expectedOutcome = "asdfgh";
	String toLowerString = testString.ToLower();

	// Assert expected outcome
	assert(toLowerString == expectedOutcome);

	if (toLowerString == expectedOutcome)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Testing::FindTest()
{
	bool allSucceeded = true;

	String testString("Hello World!");
	String stringToFind("World");

	// Testing find methods
	int startPosition = testString.Find(stringToFind);
	int startPosition2 = testString.Find(7, stringToFind);

	// Assert expected outcomes
	assert(startPosition == 6);
	assert(startPosition2 == -1);

	if (startPosition == -1)
	{
		allSucceeded = false;
	}

	if (startPosition2 != -1)
	{
		allSucceeded = false;
	}

	return allSucceeded;
}
bool Testing::ReplaceTest()
{
	String testString("ThereWasThat");
	String stringToFind("That");
	String replacementString("There");
	String expectedOutcome = "ThereWasThere";

	testString.Replace(stringToFind, replacementString);

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
bool Testing::AssignmentTest()
{
	bool allSucceeded = true;

	String testString1 = "Hello World!";
	String testString2 = testString1;

	// Assert expected outcomes
	assert(testString1 == "Hello World!");
	assert(testString2 == testString1);
	assert(testString2 == "Hello World!");

	if (testString1 != "Hello World!")
	{
		allSucceeded = false;
	}

	if (testString2 != testString1)
	{
		allSucceeded = false;
	}

	if (testString2 != "Hello World!")
	{
		allSucceeded = false;
	}

	return allSucceeded;
}