#pragma once

#include <iostream>
#include <cassert>
#include <ctime>

#include "../Logging/Logging.h"
#include "../CustomVariables/String/String.h"

class Testing
{
public:
	Testing();
	~Testing();

	enum TestType
	{
		Length = 0,
		CharacterAt = 1,
		Equals = 2,
		Append = 3,
		Prepend = 4,
		ToLower = 5,
		ToUpper = 6,
		Find = 7,
		Replace = 8,
		Operators = 9
	};

	/**
	* @brief Runs all 10 method tests, including their corresponding operators
	*/
	void PerformTests();

private:

	/**
	* @brief Runs a test for the specified test type
	* 
	* @param testToRun | The test type to run
	* @param percentageTracker | Pointer to the percentage tracker, increments by 10 if test is successful
	* 
	* @return A status message indicating success or failure
	*/
	String RunTest(TestType testToRun, int* percentageTracker);

	/**
	* @brief Tests the Length() method
	* 
	* @return true if outputs as expected
	* @return false if not
	*/
	bool LengthTest();

	/**
	* @brief Tests the CharacterAt() method and the '[]' operator
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool CharacterAtTest();

	/**
	* @brief Tests the Equals() method and the '!=' '==' operators
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool EqualsTest();

	/**
	* @brief Tests the Append() method and the '+' '+=' operators
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool AppendTest();

	/**
	* @brief Tests the Prepend() method
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool PrependTest();

	/**
	* @brief Tests the ToUpper() method
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool ToUpperTest();

	/**
	* @brief Tests the ToLower() method
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool ToLowerTest();

	/**
	* @brief Tests the Find() method
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool FindTest();

	/**
	* @brief Tests the Replace() method
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool ReplaceTest();

	/**
	* @brief Tests the '=' operator
	*
	* @return true if outputs as expected
	* @return false if not
	*/
	bool AssignmentTest();

	Logging logManager;
};

