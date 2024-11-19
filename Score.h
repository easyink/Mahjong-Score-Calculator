#ifndef SCORE_H
#define SCORE_H

#include <iostream>

class Score 
{
private:
	/* data */
	int tsumo_nondealer_points;
	int tsumo_dealer_points;

	int ron_points;
	static inline const std::string string_pattern = "(\\d+)h\\w*(\\d+)f\\w*";

public:
	Score( int tsumo_nondealer_value,int tsumo_dealer_value, int ron_value);
	int getTsumo_dealer();
	int getTsumo_nondealer();
	int getRon();

	static bool is_score(std::string input_string);

	static bool has_digit(std::string input_string);
};




#endif