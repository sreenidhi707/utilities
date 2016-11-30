//#include "afxwin.h"
#include "stdafx.h"
#include "utilities.h"

uint32_t reverse_integer(uint32_t num)
{
	uint32_t multiplier = 1;
	uint32_t rev = 0;
	stack<uint32_t> digits;

	while (num)
	{
		uint8_t digit = num % 10;
		digits.push(digit);
		num /= 10;
	}

	while (digits.size() > 0)
	{
		uint8_t digit = digits.top();
		rev = digit * multiplier + rev;
		
		multiplier *= 10;
		digits.pop();
	}

	return rev;
}

//STRING MANIPULATIONS
void split_string(string s, vector<string>& words, char delimiter)
{
	string word = "";
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == delimiter)
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word += s[i];
		}
	}
	words.push_back(word);
}

//MATH OPERATIONS
