/*
** EPITECH PROJECT, 2017
** Bool.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

namespace nts {
	class Bool {
	public:
		enum State {
			UNDEFINED = -1,
			FALSE,
			TRUE
		};

		Bool() = default;
		Bool(bool);
		~Bool() = default;
		Bool(Bool const &) = default;
		Bool(Bool &&) = default;
		Bool &operator=(Bool const &) = default;
		Bool &operator=(Bool &&) = default;

		Bool &operator=(bool);
		State getState() const;

	private:
		State _state = UNDEFINED;
	};
}
