#pragma once

#include "helper_string.h"

using namespace std;

uint32_t reverse_integer(uint32_t num);

//STRING MANIPULATIONS
void split_string(string s, vector<string>& words, char delimiter);
int64_t string_to_integer(const char* s);
bool is_number(const std::string& s);

//MATH OPERATIONS
uint64_t sum_of_n_squared(uint64_t n);
string infix_to_rpn(string s);
int32_t evaluate_rpn(vector<string> tokens);

//SORTING
