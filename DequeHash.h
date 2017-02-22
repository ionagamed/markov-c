//
// Created by ionagamed on 22.02.17.
//

#ifndef MARKOV_C_DEQUEHASH_H
#define MARKOV_C_DEQUEHASH_H

#include <deque>
#include <string>

struct DequeHash {
	std::size_t operator()(const std::list<std::string> &v) const {
		std::size_t ret = 0;
		for (auto i : v) {
			ret ^= std::hash<std::string>()(i);
		}
		return ret;
	}
};

#endif //MARKOV_C_DEQUEHASH_H
