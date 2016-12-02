#pragma once

#include "helper_includes.h"

class helper_string
{
public:
	string data;
	uint32_t key;

	helper_string()
	{
		data = "";
		key = -INT32_MIN;
	}
};