#include "util.h"
#include "MarkovTextGenerator.h"

#include <iostream>
#include <fstream>

int main() {
	auto clock_begin = clock();
	std::ifstream input("input.txt");
	auto mtg = new MarkovTextGenerator(2);
	std::string buf, tmp;
	while (getline(input, tmp)) buf += tmp + "\n";
	mtg->train(buf);
	mtg->generateIntoStream(1000, std::cout);
	std::cerr << "\nSpent " << (double) (clock() - clock_begin) / CLOCKS_PER_SEC << " s\n";
}