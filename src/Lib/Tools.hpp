/*
** EPITECH PROJECT, 2017
** Tools.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <vector>
#include <sstream>
#include <string>

namespace lib {
	struct Tools {
		/* split la string en fonction des seps */
		static std::vector<std::string> splitline(std::string const &str, std::string const &seps);
		/* split la string par le sep */
		static std::vector<std::string> splitline(std::string const &, char sep);

		static bool isNumber(std::string const &str, bool floating = true);
	};
}

std::ostream &operator<<(std::ostream &, std::vector<std::string> const &);
