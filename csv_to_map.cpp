#include "rapidcsv.h"
#include <iostream>
#include <string.h>
// #include "Score.cpp"
#include "Score.h"


int create_han_fu_hash(int han, int fu)
{
	//64 bit number
	//32 bit hash for each number

	//cantor pairing function
	int cantor = (((han + fu) * (han + fu + 1)) / 2 ) + fu;

	return cantor;
}
void read_table_csv(std::map<int, Score> score_map, std::string table_file) {
	printf("Table being read: %s\n", table_file.c_str());
	rapidcsv::Document table_doc(table_file);

	for (size_t row = 0; row < table_doc.GetRowCount(); row++) { 
		//iterate through each row
		for (size_t col = 1; col < table_doc.GetColumnCount(); col++) { 
			//iterate through each column
			std::string table_score_cell = table_doc.GetCell<std::string>(col, row); //get the cell at that row/ col
			std::string fu_amount = table_doc.GetColumnName(col);
			int han = row + 1;

			// printf("fu: %s\n", fu_amount.c_str());
			int fu = std::stoi(fu_amount);
			// printf("fu: |%d|\n", fu);
			int hf_hash = create_han_fu_hash(han, fu);
			

			std::string tsumo_str 	= table_score_cell.substr(0, table_score_cell.find(" "));
			std::string ron_str 	= table_score_cell.substr(table_score_cell.find(" ") + 1, table_score_cell.size());
			
			printf("tsumo str: |%s|\nron str: |%s|\n", tsumo_str.c_str(), ron_str.c_str());
			
			int ron_value;
			if (ron_str == ("NULL"))
			{
				ron_value = 0;
			}
			else{
				ron_value = std::stoi(ron_str.c_str());
			}
			int tsumo_nondealer_amount;
			int tsumo_dealer_amount;
			
			if (tsumo_str.find("NULL") != std::string::npos)
			{
				//this means that null is found
				tsumo_dealer_amount = 0;
				tsumo_nondealer_amount = 0;

			}
			else{


				if (tsumo_str.find("/") != std::string::npos)
				{
					int tsumo_all = std::stoi(tsumo_str);

					tsumo_dealer_amount = tsumo_all;
					tsumo_nondealer_amount = tsumo_all;
				}
				else{
					int delimiter_index = tsumo_str.find("/");
					//split string and assign them to score
					tsumo_dealer_amount = std::stoi(tsumo_str.substr(delimiter_index + 1, tsumo_str.size()));
					tsumo_nondealer_amount = std::stoi(tsumo_str.substr(0, delimiter_index));
				
				}

			}
			printf( "%d han, %d fu: \n\tTsumo Points from Dealer: %d\n\tTsumo Points from Others: %d\n\tRon Points: %d\n", han, fu, tsumo_dealer_amount, tsumo_nondealer_amount, ron_value); //the data of the cell


			// Score cell_score = new Score(tsumo_nondealer_amount, tsumo_dealer_amount, ron_value );
			Score cell_score(tsumo_nondealer_amount, tsumo_dealer_amount, ron_value);
			std::pair<int, Score> cell_pair = std::make_pair(hf_hash, cell_score);
			score_map.insert(cell_pair);

			// score_map.insert(std::make_pair(han_fu_hash, cell_score));
			// printf("tsumo: %d\n", tsumo_val);
			// printf("ron: %d\n", ron_val);


			// Score score();


		}
	}
}
void read_HH_table(std::map<int, Score> score_map, std::string high_hand_table_doc) {
	printf("High Hand Table being read: %s\n", high_hand_table_doc.c_str());

	rapidcsv::Document hh_doc(high_hand_table_doc);

	for (size_t row = 0; row < hh_doc.GetRowCount(); row++) { //iterate through each row
		std::string score_cell = hh_doc.GetCell<std::string>(1, row); //get the cell at that row/ col

		printf("%d Han: %s\n", row, score_cell.c_str());

	}
}


int main(){
	//table strings
	std::string dealer_table_file("Dealer Table.csv");
	std::string dealer_high_hands("Dealer High Hands.csv");

	std::string nondealer_table_file("Non Dealer Table.csv");
	std::string nondealer_high_hands("Non Dealer High Hands.csv");


	//maps
	std::map<int, Score> dealer_map;
	std::map<int, Score> nondealer_map;




	//reading
	read_table_csv(dealer_map, dealer_table_file);
	read_HH_table(dealer_map, dealer_high_hands);

	read_table_csv(nondealer_map, nondealer_table_file);
	read_HH_table(nondealer_map, nondealer_high_hands);


	return 0;
}