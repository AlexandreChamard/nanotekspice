/*
** EPITECH PROJECT, 2017
** Parser.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <string>
#include <unordered_map>
#include "Circuit.hpp"

namespace nts {
	class Parser {
	public:
		Parser(Circuit &);
		~Parser() = default;
		Parser(Parser const &) = delete;
		Parser(Parser &&) = delete;
		Parser &operator=(Parser const &) = delete;
		Parser &operator=(Parser &&) = delete;

	public:
		void operator()(std::string const &);

	private:
		void parsInfos(std::string const &);
		void parsChipsets(std::string const &);
		void parsLinks(std::string const &);

	private:
		Circuit &_circuit;
		std::unordered_map<std::string, std::string> _chipsets;
		std::list _links;
	};
}
