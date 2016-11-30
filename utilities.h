#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

uint32_t reverse_integer(uint32_t num);

//STRING MANIPULATIONS
void split_string(string s, vector<string>& words, char delimiter);

//MATH OPERATIONS
string infix_to_rpn(string s);