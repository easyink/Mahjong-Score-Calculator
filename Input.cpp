#include "Input.h"
#include <regex>
#include <iostream>

std::array<int,2> Input::ask_for_han_fu()
{
	int han;
	int fu;
	printf("Please enter the amount of Han in the hand: ");

	std::cin >> han;

	printf("Please enter the amount of Fu in the hand: ");
	std::cin >> fu;
	

	//need to verify that these two inputs are just digits
	//TODO

	std::array<int,2> han_fu_arr= {han, fu};

	return han_fu_arr;
}

bool Input::ask_for_dealership()
{
	printf("Are you the dealer of this hand? (Y/N): ");

	std::string answer;

	std::cin >> answer;

	std::regex answer_pattern("(Y|N)", std::regex_constants::icase);

	bool valid = std::regex_match(answer, answer_pattern);

	if(valid)
	{
		return (answer == "Y" || answer == "y");
		// if(answer == "Y" || answer == "y")
		// {
		// 	return true;
		// }
		// else
		// {
		// 	return false;
		// }
	}
	else
	{
		printf("Invalid Response.\n");

		exit(0);
	}

}
