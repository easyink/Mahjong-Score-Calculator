#include "rapidcsv.h"
#include <iostream>
#include <string.h>
#include "Score.h"
#include "Hash.h"
#include <array>

/*
This is the file that handles reading the Tables csv files
interfacing with the loaded tables can be done through here.
*/

std::array<int, 3> read_cell(std::string input_cell_string)
{
	std::string tsumo_str = input_cell_string.substr(0, input_cell_string.find(" "));
	std::string ron_str = input_cell_string.substr(input_cell_string.find(" ") + 1, input_cell_string.size());

	int ron_value = std::stoi(ron_str.c_str());
	int tsumo_nondealer_amount;
	int tsumo_dealer_amount;

	if (tsumo_str.find("/") == std::string::npos)
	{
		// go here when split "/" doesn't exist
		//  printf("/ split doesn't exist\n");
		int tsumo_all = std::stoi(tsumo_str);

		tsumo_dealer_amount = tsumo_all;
		tsumo_nondealer_amount = tsumo_all;
	}
	else
	{
		int delimiter_index = tsumo_str.find("/");
		// split string and assign them to score
		tsumo_dealer_amount = std::stoi(tsumo_str.substr(delimiter_index + 1, tsumo_str.size()));
		// printf("\ttsumo_dealer_amount: |%d|\n", tsumo_dealer_amount);

		tsumo_nondealer_amount = std::stoi(tsumo_str.substr(0, delimiter_index));
	}

	std::array<int, 3> points_array{tsumo_nondealer_amount, tsumo_dealer_amount, ron_value};

	return points_array;
}

void read_table_csv(std::map<int, Score> score_map, std::string table_file)
{
	printf("Table being read: %s\n", table_file.c_str());
	rapidcsv::Document table_doc(table_file);

	for (size_t row = 0; row < table_doc.GetRowCount(); row++)
	{
		// iterate through each row
		for (size_t col = 1; col < table_doc.GetColumnCount(); col++)
		{
			// iterate through each column
			std::string table_score_cell = table_doc.GetCell<std::string>(col, row); // get the cell at that row/ col
			std::string fu_amount = table_doc.GetColumnName(col);
			int han = row + 1;

			// printf("fu: %s\n", fu_amount.c_str());
			int fu = std::stoi(fu_amount);
			// printf("fu: |%d|\n", fu);
			int hf_hash = create_han_fu_hash(han, fu);

			std::array<int, 3> cell_array = read_cell(table_score_cell);

			// printf( "%d han, %d fu: \n\tTsumo Points from Dealer: %d\n\tTsumo Points from Others: %d\n\tRon Points: %d\n", han, fu, tsumo_dealer_amount, tsumo_nondealer_amount, ron_value); //the data of the cell

			// Score cell_score = new Score(tsumo_nondealer_amount, tsumo_dealer_amount, ron_value );
			Score cell_score(cell_array[0], cell_array[1], cell_array[2]);
			std::pair<int, Score> cell_pair = std::make_pair(hf_hash, cell_score);
			score_map.insert(cell_pair);
		}
	}
}
void read_HH_table(std::map<int, Score> score_map, std::string high_hand_table_doc)
{
	printf("High Hand Table being read: %s\n", high_hand_table_doc.c_str());

	rapidcsv::Document hh_doc(high_hand_table_doc);

	for (size_t row = 0; row < hh_doc.GetRowCount(); row++)
	{																// iterate through each row
		std::string cell_str = hh_doc.GetCell<std::string>(1, row); // get the cell at that row/ col

		std::array<int, 3> hh_cell_array = read_cell(cell_str);

		Score cell_score(hh_cell_array[0], hh_cell_array[1], hh_cell_array[2]);

		int hh_hf_hash = create_han_fu_hash(row + 5, 0);
		// printf("%d Han: %s\n", row + 5, cell_str.c_str());
		std::pair<int, Score> cell_pair = std::make_pair(hh_hf_hash, cell_score);

		score_map.insert(cell_pair);
	}
}

void CSV_MAP(std::map<int, Score> dealer_map, std::map<int, Score> nondealer_map)
{
	// table strings
	std::string dealer_table_file("Dealer Table.csv");
	std::string dealer_high_hands("Dealer High Hands.csv");

	std::string nondealer_table_file("Non Dealer Table.csv");
	std::string nondealer_high_hands("Non Dealer High Hands.csv");

	// maps

	// reading
	read_table_csv(dealer_map, dealer_table_file);
	read_HH_table(dealer_map, dealer_high_hands);

	read_table_csv(nondealer_map, nondealer_table_file);
	read_HH_table(nondealer_map, nondealer_high_hands);

	// create map file from hash map
	// kind of pointless. the map is extremely small.
	//  generate_map_file(dealer_map);
	//  generate_map_file(nondealer_map);
}

void print_hand(std::array<int, 2> input_han_fu, bool input_dealership)
{
	printf("test print hand.\n");

	printf("han: %d\n", input_han_fu[0]);
	printf("fu: %d\n", input_han_fu[1]);
}
