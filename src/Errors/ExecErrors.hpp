/*
** EPITECH PROJECT, 2017
** ExecErrors.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <sstream>

namespace nts {
	class PinNExistError : public std::exception {
	public:
		PinNExistError(std::string const &name, std::size_t pin) throw()
		{
			std::stringstream sstr;

			sstr << "Pin: " << pin << " of component \"" <<
				name << "\" doesn't exist";
			_msg = sstr.str();
		}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~PinNExistError() throw(){}

	private:
		std::string _msg;
	};

	class LinkError : public std::exception {
	public:
		LinkError() throw()
		{
			std::stringstream sstr;

			sstr << "Link between 2 inputs is impossible";
			_msg = sstr.str();
		}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~LinkError() throw(){}

	private:
		std::string _msg;
	};
}
