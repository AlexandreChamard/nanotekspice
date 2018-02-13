/*
** EPITECH PROJECT, 2017
** ParsFile.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <sys/stat.h>

#include "Cutline.hpp"
#include "ParsFile.hpp"

lib::ParsFile::ParsFile(std::string const &filename, int flags):
_file { filename }, _flags{ flags }
{
	if (isOpen() == false) {
		throw FileError{ "File not found" };
	}
}

std::string lib::ParsFile::getline()
{
	std::string str;

	std::getline(_file, str);
	if (str.size() > 0 && _flags | COMMENT) {
		Cutline<'#', '\0'> cutter;
		auto vec = cutter(str);
		str = vec[0];
	}
	if (str.size() == 0 && eof() == false && _flags | EMPTY) {
		return getline();
	}
	return str;
}

bool lib::ParsFile::isOpen() const
{
	return _file.is_open();
}

bool lib::ParsFile::eof() const
{
	return _file.eof();
}

bool fileExist(std::string const &pathName)
{
	struct stat *stats = NULL;

	return (stat(pathName.c_str(), stats) == 0);
}
