#ifndef SCORE_H
#define SCORE_H

class Score 
{
private:
	/* data */
	int tsumo_nondealer_points;
	int tsumo_dealer_points;

	int ron_points;

public:
	Score( int tsumo_nondealer_value,int tsumo_dealer_value, int ron_value);
	int getTsumo_dealer();
	int getTsumo_nondealer();
	int getRon();
};




#endif