/*
** EPITECH PROJECT, 2017
** Parser.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "Parser.hpp"
#include "ParsFile.hpp"
#include "Cutline.hpp"
#include "ParsingErrors.hpp"
#include "Tools.hpp"

nts::Parser::Parser(ComponentFactory &factory): _factory{ factory } {}

void nts::Parser::operator()(std::string const &filename)
{
	lib::ParsFile file{ filename, lib::COMMENT | lib::EMPTY };
	unsigned int nbC = 0;
	unsigned int nbL = 0;

	std::string line = file.getline();
	while (file.eof() == false) {
		switch (_parsType) {
			case CHIPSETS:
				(parsChipsets(line) && ++nbC) || parsInfos(line);
				break;
			case LINKS:
				(parsLinks(line) && ++nbL) || parsInfos(line);
				break;
			default:
				parsInfos(line);
		};
		line = file.getline();
	}
	if (nbC == 0) throw nts::NoChipSecError{};
	if (nbL == 0) throw nts::NoLinkSecError{};
}

bool nts::Parser::parsInfos(std::string &line)
{
	lib::Cutline<':', '\0'> cutter;
	std::string line_cut = line;
	auto vec = cutter(line_cut);

	if (vec.back().size() != 0) {
		throw nts::SyntaxError{ line };
	}
	if (vec[0] == ".chipsets") {
		_parsType = CHIPSETS;
	} else if (vec[0] == ".links") {
		_parsType = LINKS;
	} else {
		throw nts::SyntaxError{ line };
	}
	return true;
}

bool nts::Parser::parsChipsets(std::string line)
{
	lib::Cutline<' ', '\0'> cutter;
	auto vec = cutter(line);

	if (vec.size() < 2 || vec.back().size() == 0) {
		_parsType = NONE;
		return false;
	}
	if (_chipsets.find(vec[1]) != _chipsets.end()) {
		throw nts::ComponentExistError{ vec[1] };
	}
	_factory.componentFactory(vec[0], vec[1]);
	_chipsets.insert(make_pair(vec[1], vec[0]));
	return true;
}

bool nts::Parser::parsLinks(std::string line)
{
	lib::Cutline<':', ' ', ':', '\0'> cutter;
	auto vec = cutter(line);

	if (vec.size() < 4 || vec.back().size() == 0) {
		_parsType = NONE;
		return false;
	}
	if (_chipsets.find(vec[0]) == _chipsets.end()) {
		throw nts::ComponentNExistError{ vec[0] };
	}
	if (_chipsets.find(vec[2]) == _chipsets.end()) {
		throw nts::ComponentNExistError{ vec[2] };
	}
	if (lib::Tools::isNumber(vec[1]) == false) {
		throw nts::NNumberError{ vec[1] };
	}
	if (lib::Tools::isNumber(vec[3]) == false) {
		throw nts::NNumberError{ vec[3] };
	}
	_factory.linkComponent(vec[0], std::atoi(vec[1].c_str()), vec[2], std::atoi(vec[3].c_str()));
	_links.push_back(Link{ vec[0], vec[1], vec[2], vec[3] });
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
