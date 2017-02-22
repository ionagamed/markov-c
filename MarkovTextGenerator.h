//
// Created by ionagamed on 22.02.17.
//

#ifndef MARKOV_C_MARKOVTEXTGENERATOR_H
#define MARKOV_C_MARKOVTEXTGENERATOR_H

#include <unordered_map>
#include <deque>
#include <string>
#include <map>
#include <list>
#include "DequeHash.h"


class MarkovTextGenerator {
	int depth;
	std::map <
			std::list <std::string>,
			std::unordered_map <
			        std::string,
					int
			>,
			DequeHash
	> freq;
	std::map <
			std::list <std::string>,
			int,
			DequeHash
	> amount;

public:

	MarkovTextGenerator(int depth) : depth(depth) {}

	void train(std::string src);
	std::string generate(const int words) const;
	void generateIntoStream(const int words, std::ostream &os);
};


#endif //MARKOV_C_MARKOVTEXTGENERATOR_H
