/*
** EPITECH PROJECT, 2017
** Parsing.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <sstream>

namespace nts {
	class SyntaxError : public std::exception {
	public:
		SyntaxError(std::string const &msg = "") throw() :
		_msg("Lexical or syntactic errors: \"" + msg + '\"') {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~SyntaxError() throw(){}

	private:
		std::string _msg;
	};

	class NoChipSecError : public std::exception {
	public:
		NoChipSecError() throw() {}

		char const *what() const throw() override {
			return ("No chipset section.");
		}

		virtual ~NoChipSecError() throw(){}
	};

	class NoLinkSecError : public std::exception {
	public:
		NoLinkSecError() throw() {}

		char const *what() const throw() override {
			return ("No links section.");
		}

		virtual ~NoLinkSecError() throw(){}
	};

	class ComponentExistError : public std::exception {
	public:
		ComponentExistError(std::string const &msg = "") throw() :
		_msg("Component: \"" + msg + "\" already exists") {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~ComponentExistError() throw(){}

	private:
		std::string _msg;
	};

	class ComponentNExistError : public std::exception {
	public:
		ComponentNExistError(std::string const &msg = "") throw() :
		_msg("Component: \"" + msg + "\" doesn't exist") {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~ComponentNExistError() throw(){}

	private:
		std::string _msg;
	};
}
