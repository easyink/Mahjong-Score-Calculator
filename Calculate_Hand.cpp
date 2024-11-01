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

	for (size_t i = 0; i < argc; i++)
	{
		printf("input args %d: |%s|\n", i, argv[i]);
	}
	
	switch (argc)
	{
	case 1:
		/* code */
		//no hand arguments called

		break;
	
	case 2:
		//means only 1 arg
		//must check if that one arg is a hand input or not
	{
		printf("two arguments\n");
		std::string argument_1 = argv[1];

		bool valid_score = Score::is_score(argument_1);

		if (valid_score){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
		break;
	}
		
	default:
		break;
	}


	return 0;
}