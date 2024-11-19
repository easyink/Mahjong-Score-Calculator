#include "Score.h"
#include <regex>

Score::Score( int tsumo_nondealer_value,int tsumo_dealer_value, int ron_value)
{
	ron_points = ron_value;
	tsumo_nondealer_points = tsumo_nondealer_value;
	tsumo_dealer_points = tsumo_dealer_value;

}

int Score::getRon()
{
	return ron_points;
}

int Score::getTsumo_dealer()
{
	return tsumo_dealer_points; 
}

int Score::getTsumo_nondealer()
{
	return tsumo_nondealer_points; 
}

bool Score::is_score(std::string input_string)
{
	//assembles regex pattern from string 
	std::regex pattern(string_pattern);


	// bool has_han = input_string.find("h") != std::string::npos;

	// bool has_fu = input_string.find('f') != std::string::npos;

	// bool valid = has_han && has_fu;
	
	//returns true or false if the input string matches the pattern (duh)
	bool valid = std::regex_match(input_string,pattern);

	return valid;
}

bool Score::has_digit(std::string input_string)
{
	std::regex digit_pattern("(\\d+)");

	bool valid_digits = std::regex_match(input_string, digit_pattern);

	return valid_digits;
}
