#include "Hash.h"

int create_han_fu_hash(int han, int fu)
{
	//cantor pairing function
	int cantor = (((han + fu) * (han + fu + 1)) / 2 ) + fu;

	return cantor;
}

