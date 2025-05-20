#ifndef CSV_MAP_H
#define CSV_MAP_H

#include "rapidcsv.h"
#include "Score.h"
#include <array>

void CSV_MAP(std::map<int, Score> dealer_map, std::map<int, Score> nondealer_map);

void print_hand(std::array<int, 2> input_han_fu, bool input_dealership);

#endif
