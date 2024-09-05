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
	memcpy(characterString, other.CStr(), characterStringLength);

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
	if (strcmp(characterString, Other.CStr()))
	{
		return true;
	}

	return false;
}

CString& CString::Append(const CString& Str)
{
	// Allocate memory for copy of existing string (+1 for null char)
	int currentStringCopyLength = characterStringLength;
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
	int newStringLength = Str.Length() + currentStringCopyLength;

	// Allocate the memory for new string (+1 for null char)
	characterString = new char[newStringLength + 1];

	// Copy the copy of original string into allocated memory
	memcpy(characterString, currentStringCopy, currentStringCopyLength);

	// Copy the new string into allocated memory, offset by the size of the original string that was already copied
	memcpy(characterString + currentStringCopyLength, Str.CStr(), Str.Length());

	// Add null char
	characterString[newStringLength] = 0x00;
}

CString& CString::Prepend(const CString& Str)
{
	// Allocate memory for copy of existing string (+1 for null char)
	int currentStringCopyLength = characterStringLength;
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
	int newStringLength = Str.Length() + currentStringCopyLength;

	// Allocate the memory for new string (+1 for null char)
	characterString = new char[newStringLength + 1];

	// Copy the new string into allocated memory
	memcpy(characterString, Str.CStr(), Str.Length());

	// Copy the copy of original string into allocated memory, offset by the size of the original string that was already copied
	memcpy(characterString + Str.Length(), currentStringCopy, currentStringCopyLength);

	// Add null char
	characterString[newStringLength] = 0x00;
}

const char* CString::CStr() const
{
	return characterString;
}

CString CString::ToLower() const
{
	// Allocate memory for copy of existing string (+1 for null char)
	int currentStringCopyLength = characterStringLength;
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

	// Create local CString and return (I think it creates a copy since its not a pointer, so no need to allocate for it to stay in scope)
	CString lowerString(currentStringCopy);
	return lowerString;
}

CString CString::ToUpper() const
{
	// Allocate memory for copy of existing string (+1 for null char)
	int currentStringCopyLength = characterStringLength;
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
	for (int i = 0; i < Str.Length(); i++)
	{
		if (strcmp(characterString + i, Str.CStr()))
		{
			return i;
		}
	}

	return -1;
}

int CString::Find(size_t StartIndex, const CString& Str) const
{
	for (int i = StartIndex; i < Str.Length(); i++)
	{
		if (strcmp(characterString + i, Str.CStr()))
		{
			return i;
		}
	}

	return -1;
}

CString& CString::Replace(const CString& Find, const CString& Replace)
{
	// Already made the find method, so I will just use it here
	int startingPosition = CString::Find(Find);
	if (startingPosition == -1)
	{
		// If -1, it wasn't found, so just return this without doing anything
		return *this;
	}


}

CString CString::operator+(const CString& Other) const
{
	return CString();
}

CString& CString::operator+=(const CString& Other)
{
	// TODO: insert return statement here
}

bool CString::operator==(const CString& Other) const
{
	return false;
}

bool CString::operator!=(const CString& Other) const
{
	return false;
}

CString& CString::operator=(const CString& Str)
{
	// TODO: insert return statement here
}

char& CString::operator[](size_t Index)
{
	// TODO: insert return statement here
}

const char& CString::operator[](size_t Index) const
{
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& Stream, CString& Str)
{
	// TODO: insert return statement here
}
