/*
** EPITECH PROJECT, 2017
** Bool.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <iostream>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};
	class Bool {
	public:
		Bool(bool);
		Bool() = default;
		~Bool() = default;
		Bool(Bool const &) = default;
		Bool(Bool &&) = default;
		Bool &operator=(Bool const &) = default;
		Bool &operator=(Bool &&) = default;

	public:
		Bool &operator=(bool);
		Bool operator==(Bool const &) const;
		Bool operator!=(Bool const &) const;
		Bool operator||(Bool const &) const;
		Bool operator|(Bool const &) const;
		Bool operator&&(Bool const &) const;
		Bool operator&(Bool const &) const;
		Bool operator^(Bool const &) const;
		Bool operator!() const;
		Tristate getState() const;

	private:
		Tristate _state = UNDEFINED;
	};
}

std::ostream &operator<<(std::ostream &, nts::Bool const &);
