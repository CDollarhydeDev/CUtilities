#include "CString.h"

CString::CString() : characterString(nullptr), characterStringLength(0)
{
}
CString::CString(const char* str) : characterString(nullptr), characterStringLength(0)
{
	// Get length of input string
	size_t strSize = strlen(str);
	characterStringLength = strSize;

	// Allocate memory for string (+1 for null character)
	characterString = new char[characterStringLength + 1];

	// Copy input string to member string
	memcpy(characterString, str, characterStringLength);

	// Add Null Character
	characterString[characterStringLength] = 0x00;
}
CString::CString(const CString& other) : characterString(nullptr), characterStringLength(0)
{
	// Get length of input string
	size_t otherSize = other.Length();
	characterStringLength = otherSize;

	// Allocate memory for string (+1 for null character)
	characterString = new char[characterStringLength + 1];

	// Copy input string to member string
	memcpy(characterString, other.GetValue(), characterStringLength);

	// Add Null Character
	characterString[characterStringLength] = 0x00;
}
CString::~CString()
{
	if (characterString != nullptr)
	{
		delete[] characterString;
		characterString = nullptr;
		characterStringLength = 0;
	}
}

size_t CString::Length() const
{
	return characterStringLength;
}

char& CString::CharacterAt(size_t Index)
{
	return characterString[Index];
}
const char& CString::CharacterAt(size_t Index) const
{
	return characterString[Index];
}

bool CString::Equals(const CString& Other) const
{
	if (strcmp(characterString, Other.GetValue()) >= 0)
	{
		return true;
	}

	return false;
}

CString& CString::Append(const CString& Str)
{
	// Allocate memory for copy of existing string (+1 for null char)
	size_t currentStringCopyLength = characterStringLength;
	char* currentStringCopy = new char[currentStringCopyLength + 1];
	
	// Copy current string into the allocated memory
	memcpy(currentStringCopy, characterString, currentStringCopyLength);

	// Set null character
	currentStringCopy[currentStringCopyLength] = 0x00;

	// Delete current string and reset pointer/length
	delete[] characterString;
	characterString = nullptr;
	characterStringLength = 0;

	// Reallocate current string to fit the copy string + new string (+1 for null char)
	size_t newStringLength = Str.Length() + currentStringCopyLength;
	characterStringLength = newStringLength;

	// Allocate the memory for new string (+1 for null char)
	characterString = new char[characterStringLength + 1];

	// Copy the copy of original string into allocated memory
	memcpy(characterString, currentStringCopy, currentStringCopyLength);

	// Copy the new string into allocated memory, offset by the size of the original string that was already copied
	memcpy(characterString + currentStringCopyLength, Str.GetValue(), Str.Length());

	// Add null char
	characterString[characterStringLength] = 0x00;

	return *this;
}
CString& CString::Prepend(const CString& Str)
{
	// Allocate memory for copy of existing string (+1 for null char)
	size_t currentStringCopyLength = characterStringLength;
	char* currentStringCopy = new char[currentStringCopyLength + 1];

	// Copy current string into the allocated memory
	memcpy(currentStringCopy, characterString, currentStringCopyLength);

	// Set null character
	currentStringCopy[currentStringCopyLength] = 0x00;

	// Delete current string and reset pointer/length
	delete[] characterString;
	characterString = nullptr;
	characterStringLength = 0;

	// Reallocate current string to fit the copy string + new string (+1 for null char)
	size_t newStringLength = Str.Length() + currentStringCopyLength;
	characterStringLength = newStringLength;

	// Allocate the memory for new string (+1 for null char)
	characterString = new char[characterStringLength + 1];

	// Copy the new string into allocated memory
	memcpy(characterString, Str.GetValue(), Str.Length());

	// Copy the copy of original string into allocated memory, offset by the size of the original string that was already copied
	memcpy(characterString + Str.Length(), currentStringCopy, currentStringCopyLength);

	// Add null char
	characterString[characterStringLength] = 0x00;

	return *this;
}

const char* CString::Str() const
{
	return characterString;
}
const char* CString::GetValue() const
{
	return characterString;
}

CString CString::ToLower() const
{
	// Allocate memory for copy of existing string (+1 for null char)
	size_t currentStringCopyLength = characterStringLength;
	char* currentStringCopy = new char[currentStringCopyLength + 1];

	for (int i = 0; i < characterStringLength; i++)
	{
		// if it is uppercase, convert to lowercase by adding 0x20
		if (characterString[i] >= 0x41 && characterString[i] <= 0x5A)
		{
			currentStringCopy[i] = characterString[i] + 0x20;
		}

		// Anything else, copy directly
		else
		{
			currentStringCopy[i] = characterString[i];
		}
	}

	// Add null term
	currentStringCopy[currentStringCopyLength] = 0x00;

	// Create local CString and return copy of it
	CString lowerString(currentStringCopy);
	return lowerString;
}
CString CString::ToUpper() const
{
	// Allocate memory for copy of existing string (+1 for null char)
	size_t currentStringCopyLength = characterStringLength;
	char* currentStringCopy = new char[currentStringCopyLength + 1];

	for (int i = 0; i < characterStringLength; i++)
	{
		// if it is lowercase, convert to lowercase by subtracting 0x20
		if (characterString[i] >= 0x61 && characterString[i] <= 0x7A)
		{
			currentStringCopy[i] = characterString[i] - 0x20;
		}

		// Anything else, copy directly
		else
		{
			currentStringCopy[i] = characterString[i];
		}
	}

	// Add null term
	currentStringCopy[currentStringCopyLength] = 0x00;

	// Create local CString and return (I think it creates a copy since its not a pointer, so no need to allocate for it to stay in scope)
	CString upperString(currentStringCopy);
	return upperString;
}

int CString::Find(const CString& Str) const
{
	if (characterStringLength < Str.Length())
	{
		return -1;
	}

	for (int i = 0; i < characterStringLength; i++)
	{
		char* currentPosition = new char[Str.Length() + 1];
		memcpy(currentPosition, characterString + i, Str.Length());
		currentPosition[Str.Length()] = 0x00;

		if (strcmp(currentPosition, Str.GetValue()) == 0)
		{
			delete[] currentPosition;
			return i;
		}

		delete[] currentPosition;
	}

	return -1;
}
int CString::Find(size_t StartIndex, const CString& Str) const
{
	if ((characterStringLength - (int)StartIndex) < Str.Length())
	{
		return -1;
	}

	for (int i = (int)StartIndex; i < characterStringLength; i++)
	{
		char* currentPosition = new char[Str.Length() + 1];
		memcpy(currentPosition, characterString + i, Str.Length());
		currentPosition[Str.Length()] = 0x00;

		if (strcmp(currentPosition, Str.GetValue()) == 0)
		{
			delete[] currentPosition;
			return i;
		}

		delete[] currentPosition;
	}

	return -1;
}

CString& CString::Replace(const CString& Find, const CString& Replace)
{
	// Already made the find method, so I will just use it here to get the index
	int startingPosition = CString::Find(Find);
	if (startingPosition == -1)
	{
		// If -1, it wasn't found, so just return this without doing anything
		return *this;
	}

	// New string size would be the size of the original string, minus the size of the string to find (since its being removed) and then plus the Replace length to fit it
	size_t newCharacterStringLength = (characterStringLength - Find.Length()) + Replace.Length();

	// Allocate memory
	char* newCharacterString = new char[newCharacterStringLength + 1];

	// Copy original string up to the index of the located string
	memcpy(newCharacterString, characterString, startingPosition);

	// Offset for tracking copied memory
	int amountCopied = startingPosition;

	// Copy the replace part of the string, offsetting by the amount already copied
	memcpy(newCharacterString + amountCopied, Replace.GetValue(), Replace.Length());

	// Add amount of memory copied
	amountCopied += Replace.Length();

	// How many characters to skip from the original string
	int charactersToIgnore = startingPosition + Find.Length();

	// How many characters are left after ignoring the start position and removed string
	int remainingCharacters = characterStringLength - startingPosition - Find.Length();

	// Copy any values after the located string, offset by the already copied amount
	memcpy(newCharacterString + amountCopied, characterString + charactersToIgnore, remainingCharacters);

	// Set null term
	newCharacterString[newCharacterStringLength] = 0x00;

	// Delete original string
	delete[] characterString;
	characterString = nullptr;
	characterStringLength = newCharacterStringLength;

	// Reallocate
	characterString = new char[characterStringLength + 1];

	// Copy the new string into original string (Or can I just assign it directly as characterString = newCharacterString?
	memcpy(characterString, newCharacterString, characterStringLength);
	characterString[characterStringLength] = 0x00;

	delete[] newCharacterString;
	newCharacterString = nullptr;

	return *this;
}

CString CString::operator+(const CString& Other) const
{
	CString newString(*this);
	return newString.Append(Other);
}
CString& CString::operator+=(const CString& Other)
{
	return Append(Other);
}
bool CString::operator==(const CString& Other) const
{
	return Equals(Other);
}
bool CString::operator!=(const CString& Other) const
{
	return !Equals(Other);
}

CString& CString::operator=(const CString& Str)
{
	// Delete original if needed
	if (characterString != nullptr)
	{
		delete[] characterString;
		characterString = nullptr;
		characterStringLength = 0;
	}

	// New size
	size_t newCharacterSize = Str.Length();
	characterStringLength = newCharacterSize;

	// Reallocate
	characterString = new char[characterStringLength + 1];

	// Copy to allocation
	memcpy(characterString, Str.GetValue(), characterStringLength);

	// Add null term
	characterString[characterStringLength] = 0x00;

	return *this;
}

char& CString::operator[](size_t Index)
{
	return CharacterAt(Index);
}
const char& CString::operator[](size_t Index) const
{
	return CharacterAt(Index);
}

std::ostream& operator<<(std::ostream& Stream, CString& Str)
{
	return Stream << Str.GetValue();
}
