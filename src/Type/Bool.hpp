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
		UNDEFINED = -true,
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
		operator Tristate() const { return _state; }
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

nts::Tristate operator!(nts::Tristate);
nts::Tristate operator&(nts::Tristate, nts::Tristate);
nts::Tristate operator|(nts::Tristate, nts::Tristate);
nts::Tristate operator^(nts::Tristate, nts::Tristate);
ssize_t operator+(ssize_t, nts::Tristate);
ssize_t operator+(nts::Tristate, nts::Tristate);

std::ostream &operator<<(std::ostream &, nts::Tristate);
std::ostream &operator<<(std::ostream &, nts::Bool const &);
