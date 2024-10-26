#include "Score.h"


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