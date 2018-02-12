/*
** EPITECH PROJECT, 2017
** Parsing.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <exception>
#include <string>

namespace nts {
	class CExistError: public std::exception {
	public:
		CExistError(std::string const &msg = "") throw() : _msg(msg) {}

		virtual char const *what() const throw() {
			return (std::string("Component: " + _msg + " already exist").c_str());
		}

		virtual ~CExistError() throw(){}

	private:
		std::string _msg;
	};

	class CNExistError: public std::exception {
	public:
		CNExistError(std::string const &msg = "") throw() : _msg(msg) {}

		virtual char const *what() const throw() {
			return (std::string("Component: " + _msg + " doesn't exist").c_str());
		}

		virtual ~CNExistError() throw(){}

	private:
		std::string _msg;
	};
}
