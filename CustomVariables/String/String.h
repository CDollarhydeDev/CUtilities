#pragma once

// Optional - Remove if not implementing support for std::ostream <<
#include <iostream>

/**
 * @brief A managed string that grows as needed with basic text manipulation
 *		  methods, such as Length and Append.
*/
class String
{
public:
	/**
	 * @brief Initializes to an empty string.
	 *
	 * @details Allocates enough memory for an empty string.
	 *
	 * Default constructor.
	 */
	String();

	/**
	 * @brief Initializes itself as a copy of the given c-string.
	 *
	 * @param The c-string to copy from.
	 *
	 * @details Specialized constructor.
	 */
	String(const char* str);

	/**
	 * @brief Initializes itself as a copy of the given string.
	 *
	 * @param The other string to copy from.
	 *
	 * @details Copy constructor.
	 *
	 */
	String(const String& other);

	/**
	 * @brief Deallocates all memory used.
	 */
	~String();

public:

	/**
	 * @brief Returns the number of characters in this string
	 *
	 * @return Number of characters in this string
	 */
	size_t Length() const;

	/**
	 * @brief Returns the character at a specific index of the string
	 *
	 * @param The index to return from
	 * @return Reference to the character in the string
	 */
	char& CharacterAt(size_t Index);
	/**
	 * @brief Returns a const-qualified character a specific index of the string.
	 * @param The index to return from
	 * @return Const-qualified reference to the character in the string
	 */
	const char& CharacterAt(size_t Index) const;
	/**
	 * @brief Compares two strings for lexicographical equality
	 * @param The string to compare against
	 * @return True if equal, false if not
	 * @details Two strings are considered lexicographically equal if they would
				be at the same position when sorted with consideration for content
				and the case of each letter of the string.
	 */
	bool Equals(const String& Other) const;

	/**
	 * @brief Concatenates the other string onto the end of this string (i.e., a = a + b)
	 * @param The contents to be added to the end
	 * @return Reference to this string. May reallocate if current string is too small
	 *		   to store full string.
	 */
	String& Append(const String& Str);

	/**
	 * @brief Adds other string onto the beginning of this string (i.e., a = b + a)
	 * @param The contents to be added to the beginning
	 * @return Reference to this string. May reallocate if current string is too small
	 *		   to store full string.
	 */
	String& Prepend(const String& Str);

	/**
	 * @brief Returns a const-qualified pointer to beginning of this string. No additional allocation.
	 * @return Const-qualified pointer to beginning of this string
	 */
	const char* Str() const;

		/**
	 * @brief Returns a const-qualified pointer to beginning of this string. No additional allocation.
	 * @return Const-qualified pointer to beginning of this string
	 */
	const char* GetValue() const;

	/**
	 * @brief Create a copy of this string with all letters set to lowercase
	 * @return New copy of this string in all lowercase
	 */
	String ToLower() const;
	/**
	 * @brief Create a copy of this string with all letters set to uppercase
	 * @return New copy of this string in all uppercase
	 */
	String ToUpper() const;

	/**
	 * @brief Find the first occurrance of the given substring
	 * @param The substring to find (must be lexicographically equivalent)
	 * @return Index of the first occurance of the substring, or -1 if not found
	 */
	int Find(const String& Str) const;
	/**
	 * @brief Find the first occurrance of the given substring at or after the given start index
	 * @param StartIndex The index to begin finding from
	 * @param Str The substring to find (must be lexicographically equivalent)
	 * @return Index of the first occurance of the substring, or -1 if not found
	 */
	int Find(size_t StartIndex, const String& Str) const;

	/**
	 * @brief Replace all occurrances of the string to search for with the replacement string
	 * @param Find The string to find (must be lexicographically equivalent)
	 * @param Replace The string it will be replaced with
	 * @return Reference to this string
	 * @details The string may reallocate memory if the string's capacity will be
				exceeded when replacing the string. It will not reallocate if
				there is enough capacity to do it in-place.
	 */
	String& Replace(const String& Find, const String& Replace);

public:
	/**
	 * @brief Creates a new string, concatenates the other string onto the end of this string.
	 * @param Other The other string.
	 * @return A new string object with "this string" appended with "Other".
	 * @details Optional. Remove if not implemented.
	*/
	String operator+(const String& Other) const;
	/**
	 * @brief Concatenates the other string onto the end of this string (a += b)
	 * @param The contents to be added to the end
	 * @return Reference to this string
	 */
	String& operator+=(const String& Other);

	/**
	 * @brief Tests for lexicographical equality
	 * @param Other The other string to test against
	 * @return True if lexicographically equal, otherwise false
	*/
	bool operator==(const String& Other) const;
	/**
	 * @brief Tests for lexicographical inequality.
	 * @param Other The other string to test against.
	 * @return True if lexicographically inequal, otherwise false.
	 */
	bool operator!=(const String& Other) const;

	/**
	 * @brief Copies the contents of the other string, overwriting this string.
	 * @param Str The other string to copy from.
	 * @return Reference to this string.
	 * @details May reallocate if current string capacity is insufficient to
	 *			copy the contents of the other string. Otherwise, should
	 *			avoid reallocation.
	*/
	String& operator=(const String& Str);

	/**
	 * @brief Zero-based subscript access to character at index.
	 * @param Index The index of the character referenced.
	 * @return Reference to character in string.
	*/
	char& operator[](size_t Index);
	/**
	 * @brief Zero-based subscript const-qualified access to character at index.
	 * @param Index The index of the character referenced.
	 * @return Const-qualified reference to character in string.
	*/
	const char& operator[](size_t Index) const;

	/**
	 * @brief Support printing to ostream objects, like cout.
	 * @param Stream The stream to write to.
	 * @param Str The string being written.
	 * @return Reference to the stream that was written to.
	 * @details Optional. Remove if not implemented.
	*/
	friend std::ostream& operator<<(std::ostream& Stream, String& Str);

private:
	char* characterString;
	size_t characterStringLength;
};