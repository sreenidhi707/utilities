#pragma once

#include <cassert>
#include <stdint.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

uint32_t reverse_integer(uint32_t num);

//STRING MANIPULATIONS
void split_string(string s, vector<string>& words, char delimiter);
bool is_number(const std::string& s);

//MATH OPERATIONS
string infix_to_rpn(string s);
int32_t evaluate_rpn(vector<string> tokens);