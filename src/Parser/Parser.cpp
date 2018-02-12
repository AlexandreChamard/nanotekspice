/*
** EPITECH PROJECT, 2017
** Parser.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <fstream>
#include <sstream>
#include <exception>
#include "Parser.hpp"
#include "ParsFile.hpp"
#include "Cutline.hpp"
#include "Tools.hpp"
#include "ParsingErrors.hpp"

nts::Parser::Parser(Circuit &circuit): _circuit{ circuit } {}

void nts::Parser::operator()(std::string const &filename)
{

	lib::ParsFile file{ filename, lib::COMMENT | lib::EMPTY };

	std::string line = file.getline();
	while (!file.eof()) {
		std::cout << '[' << line << ']' << std::endl;
		switch (_parsType) {
			case CHIPSETS:
				parsChipsets(line) || parsInfos(line);
				break;
			case LINKS:
				parsLinks(line) || parsInfos(line);
				break;
			default:
				parsInfos(line);
		};
		line = file.getline();
	}
}

bool nts::Parser::parsInfos(std::string &line)
{
	lib::Cutline<':', '\0'> cutter;

	auto vec = cutter(line);
	std::cout << "Infos: " << vec << std::endl;
	if (vec.back().size() != 0) {
		throw std::invalid_argument{ "lexical or syntactic errors" };
	}
	if (vec[0] == ".chipsets") {
		_parsType = CHIPSETS;
	} else if (vec[0] == ".links") {
		_parsType = LINKS;
	} else {
		throw std::invalid_argument{ "lexical or syntactic errors" };
	}
	return true;
}

bool nts::Parser::parsChipsets(std::string line)
{
	lib::Cutline<' ', '\0'> cutter;

	auto vec = cutter(line);
	std::cout << "chipsets: " << vec << std::endl;
	if (vec.size() < 2 || vec.back().size() == 0) {
		_parsType = NONE;
		return false;
	}
	if (_chipsets.find(vec[1]) != _chipsets.end()) {
		throw nts::CExistError{ vec[1] };
	}
	_chipsets.insert(make_pair(vec[1], vec[0]));
	return true;
}

bool nts::Parser::parsLinks(std::string line)
{
	lib::Cutline<':', ' ', ':', '\0'> cutter;

	auto vec = cutter(line);
	std::cout << "link: " << vec << std::endl;
	if (vec.size() < 4 || vec.back().size() == 0) {
		_parsType = NONE;
		return false;
	}
	if (_chipsets.find(vec[0]) == _chipsets.end()) {
		throw nts::CNExistError{ vec[0] };
	}
	if (_chipsets.find(vec[2]) == _chipsets.end()) {
		throw nts::CNExistError{ vec[2] };
	}
	_links.push_back(Link{vec[0], vec[1], vec[2], vec[3]});
	return true;
}

void nts::Parser::dump()
{
	std::cout << "CHIPSETS :" << std::endl;
	for (auto elem : _chipsets) {
		std::cout << elem.first << " : " << elem.second << std::endl;
	}
	std::cout << "LINKS :"<< std::endl;
	for (auto elem : _links) {
		std::cout << elem.oname << " : " << elem.opin << " -> "
		<< elem.iname << " : " << elem.ipin << std::endl;
	}
}
