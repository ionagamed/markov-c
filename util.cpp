//
// Created by ionagamed on 22.02.17.
//

#include "util.h"

std::vector <std::string> split(std::string src, char sep) {
	std::string tmp;
	std::vector <std::string> ret;
	bool word = false;
	for (char i : src) {
		if (i == sep) {
			if (word) {
				ret.push_back(tmp);
				tmp = "";
				word = false;
			}
		} else {
			tmp.push_back(i);
			word = true;
		}
	}
	ret.push_back(tmp);
	return ret;
}