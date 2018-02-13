/*
** EPITECH PROJECT, 2017
** Parser.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <fstream>
#include <string>
#include <unordered_map>
#include "Circuit.hpp"

namespace nts {

	struct Link {
		std::string iname;
		std::string ipin;
		std::string oname;
		std::string opin;
	};

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
		void dump();

	private:
		std::string gnl();
		bool parsInfos(std::string &);
		bool parsChipsets(std::string);
		bool parsLinks(std::string);


	private:
		Circuit &_circuit;
		std::unordered_map<std::string, std::string> _chipsets;
		std::vector<Link> _links;

		enum parsType_e { NONE, CHIPSETS, LINKS };
		parsType_e _parsType = NONE;
	};

}
