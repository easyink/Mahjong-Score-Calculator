#include "rapidcsv.h"
#include "Score.h"
#include "CSV_MAP.h"

#include <iostream>
#include <string.h>
#include <array>



int main(int argc, char* argv[]) 
{
	//establish maps
	std::map<int, Score> dealer_map;
	std::map<int, Score> nondealer_map;


	//read csvs
	CSV_MAP(dealer_map, nondealer_map);

	// printf("test!!\n");
	printf("num of args: %d\n", argc);
	printf("input args: |%s|\n", argv[1]);
	return 0;
}