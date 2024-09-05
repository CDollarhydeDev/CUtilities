#include <iostream>

#include "Testing.h"



int main()
{
	Testing perform;

	// Tests that the constructors work
	perform.ConstructorTests();

	// Tests that String.Length() works
	perform.LengthTests();

	// Tests that String.CharacterAt and String[] both return proper characters
	perform.CharacterAtTests();

	// Tests that String.Equals as well as the == and != operators work
	perform.EqualsTests();

	// Tests that String.Append() and String.Prepend() works. Also tests the += an + operators
	perform.AppendPrependTests();

	// Tests that String.ToUpper and String.ToLower work
	perform.ToUpperAndLowerTests();

	// Tests that both String.Find() methods return the correct indexes
	perform.FindTests();

	// Checks that String.Replace works
	perform.ReplaceTests();

	// Checks that the = operator works
	perform.AssigmentTests();

	return 0;
}