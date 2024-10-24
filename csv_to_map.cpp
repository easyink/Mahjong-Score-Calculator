#include "rapidcsv.h"
#include <iostream>
#include <string.h>

int main(){
	rapidcsv::Document dealer_table("Dealer Table.csv"); //make it skip empty lines (unnecessary)
	
	rapidcsv::Document nondealer_table("Non Dealer Table.csv");

 	// std::vector<float> dealer_col = dealer_table.GetColumn<float>(11);


	for (size_t row = 0; row < dealer_table.GetRowCount(); row++)
	{
		for (size_t col = 0; col < dealer_table.GetColumnCount(); col++)
		{
			std::string dealer_score_cell = dealer_table.GetCell<std::string>(col, row);

			if (dealer_score_cell == NULL){
				//continue
				
			}
			// string t = "test";
			// printf(dealer_score_cell);
			printf( "%d han, %d fu: %s \n", row, col, dealer_score_cell.c_str());
			// std::cout << dealer_score_cell;
		}
	}
	
}