/*
** EPITECH PROJECT, 2017
** Gnl.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <fstream>
#include <string>

namespace lib {

	enum ParsFlags {
		COMMENT = 1, /* remove all comment // # */
		EMPTY = 2 /* remove all empty line */
	};

	class ParsFile {
	public:
		ParsFile(std::string const &filename, int flags = 0);
		~ParsFile() = default;
		ParsFile(ParsFile const &) = delete;
		ParsFile(ParsFile &&) = delete;
		ParsFile &operator=(ParsFile const &) = delete;
		ParsFile &operator=(ParsFile &&) = delete;

		std::string getline();
		bool isOpen() const;
		bool eof() const;

	private:
		std::string _filename;
		std::ifstream _file;
		int _flags;
		bool _eof = false;
	};

	class FileError : public std::exception {
	public:
		FileError(std::string const &msg = "") throw() :
		_msg(msg) {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~FileError() throw() {}

	private:
		std::string _msg;
	};

	class EofError : public std::exception {
	public:
		EofError(std::string const &msg = "") throw() :
		_msg(msg + ": has reach eof") {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~EofError() throw() {}

	private:
		std::string _msg;
	};

	bool fileExist(std::string const &pathName);
}
