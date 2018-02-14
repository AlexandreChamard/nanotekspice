/*
** EPITECH PROJECT, 2017
** Cutline.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

namespace lib {
	/* coupe la string dans l'ordre des seps */
	template<char ...seps> struct Cutline {};

	template<char sep>
	struct Cutline<sep>
	{
		std::vector<std::string> operator()(std::string &str)
		{
			std::stringstream sstr{ str };

			std::vector<std::string> vec;
			std::string sub_str;
			std::getline(sstr, sub_str, sep);
			vec.push_back(sub_str);
			if (!sstr.eof()) {
				std::getline(sstr, sub_str, '\0');
				str = sub_str;
			} else {
				str = "";
			}
			return vec;
		}
	};


	template<>
	struct Cutline<' '>
	{
		std::vector<std::string> operator()(std::string &str)
		{
			std::stringstream sstr{ str };

			std::vector<std::string> vec;
			std::string sub_str;
			sstr >> sub_str;
			vec.push_back(sub_str);
			if (!sstr.eof()) {
				std::getline(sstr, sub_str, '\0');
				sub_str.erase(sub_str.begin(),
				std::find_if(sub_str.begin(), sub_str.end(),
				[](int ch) { return !std::isspace(ch); }));
				str = sub_str;
			} else {
				str = "";
			}
			return vec;
		}
	};

	template<char sep, char ...other>
	struct Cutline<sep, other...>
	{
		std::vector<std::string> operator()(std::string &str)
		{
			Cutline<sep> first;
			auto vec = first(str);

			Cutline<other...> second;
			auto add = second(str);

			for (auto elem : add) {
				vec.push_back(elem);
			}
			return vec;
		}
	};
}
