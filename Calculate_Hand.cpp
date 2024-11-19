#include "rapidcsv.h"
#include "Score.h"
#include "CSV_MAP.h"
#include "Input.h"

#include <iostream>
#include <string.h>
#include <array>


int main(int argc, char* argv[]) 
{
	Score fetched_score();
	//establish maps
	std::map<int, Score> dealer_map;
	std::map<int, Score> nondealer_map;

	std::array<int,2> han_and_fu;
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
		//query for an input??

		han_and_fu = ask_for_han_fu();
		//then query about dealer or nondealer
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

		//now we need to ask about dealer or nondealer

		break;
	}

	case 3:
	{
		//if we are at here, it should be two numbers
		//check if the two inputs are just numbers
		//argv 1 = han
		std::string han_string = argv[1];
		//argv 2 = fu
		std::string fu_string = argv[2];

		bool han_value = Score::has_digit(han_string);
		
		bool fu_value = Score::has_digit(fu_string);

		if (han_value && fu_value)
		{
			//pass strings to further computation
			
		}
		else
		{
			printf("Invalid input!\n");
		}

		//query for dealer or nondealer
		break;
	}


		
	default:
		printf("Missing or Invalid Input.\n");
		break;
	}


	return 0;
}