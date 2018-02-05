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

nts::Parser::Parser(Circuit &circuit): _circuit{ circuit } {}

void nts::Parser::operator()(std::string const &filename)
{
	std::ifstream file{ filename };
	std::string line;

	if (file.is_open() == false) {
		throw std::invalid_argument{ "no such file or directory" };
	}
	while (!file.eof()) {
		std::getline(file, line);
		std::size_t found = line.find("#");
		if (found != std::string::npos) {
			line.erase();
		}
		if (line.size() == 0) continue;
		parsInfos(line);
	}
}

void nts::Parser::parsInfos(std::string const &line)
{
	std::stringstream l{ line };
	std::string info;
	char end = 0;

	l >> info >> end;

	std::cout << info << "  ";
	if (end != 0 || end == ':') {
		throw std::invalid_argument{ "lexical or syntactic errors" };
	}
	std::cout << std::endl;
}

void nts::Parser::parsChipsets(std::string const &line)
{
	auto it = std::find_if( std::begin( myList ),
	std::end( myList ),
	[&]( const int v ){ return 0 == ( v % 17 ); } );
}

void nts::Parser::parsLinks(std::string const &line)
{

}
