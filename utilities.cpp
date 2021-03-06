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

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();

	if (*it == '-')
	{
		it++;
	}

	while (it != s.end() && isdigit(*it))
	{
		++it;
	}
	return !s.empty() && it == s.end();
}

int64_t string_to_integer(const char* s)
{
	uint32_t multiplier = 1;
	int32_t integer = 0;
	for (size_t i = strlen(s) - 1; i > 0; i--)
	{
		uint8_t digit = s[i] - '0';
		integer += digit * multiplier;
		multiplier *= 10;
	}

	//Handle s[0] separately
	if (s[0] == '-')
	{
		return -integer;
	}
	else
	{
		uint8_t digit = s[0] - '0';
		integer += digit * multiplier;
		return integer;
	}
}

//MATH OPERATIONS
uint64_t sum_of_n_squared(uint64_t n)
{
	return (n*(n + 1)*(2 * n + 1)) / 6;
}

int32_t evaluate_rpn(vector<string> tokens)
{
	int32_t result = 0;

	if (tokens.size() == 0)
	{
		return result;
	}

	stack<int32_t> operands;

	for (size_t i = 0; i < tokens.size(); i++)
	{
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			assert(operands.size() >= 2);

			int32_t right_op = operands.top();
			operands.pop();

			int32_t left_op = operands.top();
			operands.pop();

			if (tokens[i] == "+")
			{
				result = left_op + right_op;
			}
			else if (tokens[i] == "-")
			{
				result = left_op - right_op;
			}
			else if (tokens[i] == "*")
			{
				result = left_op * right_op;
			}
			else if (tokens[i] == "/")
			{
				result = left_op / right_op;
			}
			operands.push(result);
		}
		else if (is_number(tokens[i]))
		{
			operands.push(stoi(tokens[i], NULL, 10));
		}
		else
		{
			assert(0);
		}
	}

	assert(operands.size() == 1);
	
	return(operands.top());
}