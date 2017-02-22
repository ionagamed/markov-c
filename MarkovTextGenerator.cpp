//
// Created by ionagamed on 22.02.17.
//

#include <random>
#include <iostream>
#include "MarkovTextGenerator.h"
#include "util.h"

void MarkovTextGenerator::train(std::string src) {
	auto words = split(src, ' ');
	int wordsQty = words.size();
	std::list <std::string> state;
	state.assign(this->depth, "#");
	for (auto word : words) {
		if (state.size() < this->depth - 1) {
			state.push_back(word);
		} else {
			this->freq[state][word]++;
			this->amount[state]++;
			state.pop_front();
			state.push_back(word);
		}
	}
}

std::string MarkovTextGenerator::generate(const int words) const {
	// todo: stub
	return "";
}

void MarkovTextGenerator::generateIntoStream(const int words, std::ostream &os) {
	// Using new fancy C++11 random generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> rnd(0, 1);

	std::list <std::string> state;
	state.assign(this->depth, "#");
	for (int i = 0; i < words; i++) {
		double choice = rnd(gen);
		double acc = 0;
		for (auto proposal : freq[state]) {
			double df = (double) proposal.second / this->amount[state];
			acc += df;
			if (acc >= choice) {
				os << proposal.first << std::string(" ");
				state.push_back(proposal.first);
				state.pop_front();
				break;
			}
		}
	}
}