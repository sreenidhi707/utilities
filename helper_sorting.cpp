//#include "afxwin.h"
#include "stdafx.h"
#include "utilities.h"

#include "helper_sorting.h"

void key_indexed_sorting_string(vector<helper_string>& list, uint32_t radix)
{
	vector<uint32_t> freq_counts(radix, 0);
	vector<uint32_t> starting_positions(radix, 0);

	//Compute frequency counts
	for (size_t i = 0; i < list.size(); i++)
	{
		freq_counts[list[i].key]++;
	}

	//Compute starting positions
	for (size_t i = 1; i < radix; i++) //Note starting index is 1
	{
		starting_positions[i] = starting_positions[i - 1] + freq_counts[i - 1];
	}

	//Redistribute
	vector<helper_string> sorted_list(list.size());
	for (size_t i = 0; i < list.size(); i++)
	{
		sorted_list[starting_positions[list[i].key]++] = list[i];
	}

	//Copy back
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i] = sorted_list[i];
	}
}

