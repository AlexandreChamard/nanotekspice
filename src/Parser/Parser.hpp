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
#include <vector>
#include "ComponentFactory.hpp"

namespace nts {

	struct Link {
		std::string iname;
		std::string ipin;
		std::string oname;
		std::string opin;
	};

	class Parser {
	public:
		Parser(ComponentFactory &);
		~Parser() = default;
		Parser(Parser const &) = delete;
		Parser(Parser &&) = delete;
		Parser &operator=(Parser const &) = delete;
		Parser &operator=(Parser &&) = delete;

	public:
		void operator()(std::string const &);
		void operator()(int n, char **applies);
		void dump();

	private:
		bool parsInfos(std::string &);
		bool parsChipsets(std::string);
		bool parsLinks(std::string);


	private:
		ComponentFactory &_factory;
		std::unordered_map<std::string, std::string> _chipsets;
		std::vector<Link> _links;

		enum parsType_e { NONE, CHIPSETS, LINKS };
		parsType_e _parsType = NONE;
	};

}
