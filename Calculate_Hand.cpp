#include "rapidcsv.h"
#include "Score.h"
#include "CSV_MAP.h"
#include "Input.h"

#include <iostream>
#include <string.h>
#include <array>


int main(int argc, char* argv[]) 
{
	//Score fetched_score();
	//establish maps
	std::map<int, Score> dealer_map;
	std::map<int, Score> nondealer_map;

	std::array<int,2> han_and_fu;
	bool dealership; //TRUE = dealer, FALSE = nondealer

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
	case 2:
	{
		
		//means only 1 arg given
		//I think this is just an annoying and bad input. should just do the same as case 1. 

		//query for han, fu and then dealership
		han_and_fu = Input::ask_for_han_fu();

		dealership = Input::ask_for_dealership();

		break;
	}
	case 3:
	{

		//if we are at here, it should be two numbers
		//check if the two inputs are just numbers

		//also annoying because what if some idiot just puts fu and then dealership.

		//argv 1 = han
		std::string han_string = argv[1];
		//argv 2 = fu
		std::string fu_string = argv[2];

		bool han_value = Score::has_digit(han_string);
		
		bool fu_value = Score::has_digit(fu_string);

		if (han_value && fu_value)
		{
			//pass strings to further computation
			int han = std::stoi(han_string);
			int fu = std::stoi(fu_string);
			han_and_fu = {han, fu};
		}
		else
		{
			printf("Invalid input!\n");

			//redo inputs:
			han_and_fu = Input::ask_for_han_fu();
			dealership = Input::ask_for_dealership();

		}
		break;
	}

		case 4:
	{

		//assuming all 3 fields are han, fu, and then dealership
		//need to verify that they are correct.
		bool arg1 = Score::has_digit(argv[1]);
		bool arg2 = Score::has_digit(argv[2]);

		int arg3 = Score::has_dealership(argv[3]);

		if(arg1 && arg2 && (arg3 > -1) )
		{
			printf("TEST: all fields valid\n");

			int han = std::stoi(argv[1]);
			int fu = std::stoi(argv[2]);

			han_and_fu = {han, fu};

			dealership = (arg3 == 1);

		}
	}
		
	default:
	{
		printf("Missing or Invalid Input.\n");
		break;
	}
}


	return 0;
}