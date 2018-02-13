/*
** EPITECH PROJECT, 2017
** Tools.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Tools.hpp"

std::vector<std::string> lib::Tools::splitline(std::string const &str, char sep)
{
		std::stringstream sstr{ str };

		std::vector<std::string> vec;
		std::string sub_str;
		while (std::getline(sstr, sub_str, sep)) {
			vec.push_back(sub_str);
		}
		return vec;
}

std::vector<std::string> lib::Tools::splitline(std::string const &s, std::string const &seps)
{
	std::vector<std::string> vec{ s };

	for (auto sep : seps) {
		std::vector<std::string> new_vec;
		for (auto str : vec) {
			auto add_vec = splitline(str, sep);
			for (auto elem : add_vec) {
				new_vec.push_back(elem);
			}
		}
		vec = new_vec;
	}
	return vec;
}

std::ostream &operator<<(std::ostream &os, std::vector<std::string> const &vec)
{
	for (auto elem : vec) {
		os << "[" << elem << "]" << " ";
	}
	return os;
}
