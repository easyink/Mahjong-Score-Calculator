#include "rapidcsv.h"
#include <iostream>
#include <string.h>


void read_table_csv(std::string table_file)
{
	printf("Table being read: %s\n", table_file.c_str());
	rapidcsv::Document table_doc(table_file);

	for (size_t row = 0; row < table_doc.GetRowCount(); row++) { //iterate through each row
		for (size_t col = 1; col < table_doc.GetColumnCount(); col++) { //iterate through each column
		
			std::string table_score_cell = table_doc.GetCell<std::string>(col, row); //get the cell at that row/ col

			std::string fu_amount = table_doc.GetColumnName(col);

			printf( "%d han, %s fu: %s \n", row + 1, fu_amount.c_str(), table_score_cell.c_str()); //the data of the cell
		}
	}
}
// void read_high_hands_table(rapidcsv::Document high_hand_table_doc){

// }

int main(){

	std::string dealer_table_file("Dealer Table.csv");
	std::string dealer_high_hands("Dealer Table.csv");

	// rapidcsv::Document dealer_table("Dealer Table.csv");
	// rapidcsv::Document dealer_high_hands("Dealer High Hands.csv");

	std::string nondealer_table_file("Non Dealer Table.csv");
	std::string nondealer_high_hands("Non Dealer High Hands.csv");


	// rapidcsv::Document nondealer_table("Non Dealer Table.csv");
	// rapidcsv::Document nondealer_high_hands("Non Dealer High Hands.csv");

	read_table_csv(dealer_table_file);

	read_table_csv(nondealer_table_file);

}