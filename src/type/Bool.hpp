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
		enum Type {
			FALSE,
			TRUE,
			UNDEFINED
		};

		Bool();
		~Bool();
		Bool(Bool const &) = default;
		Bool(Bool &&) = default;
		Bool &operator=(Bool const &) = default;
		Bool &operator=(Bool &&) = default;
	private:
		int state = UNDEFINED;

	};
}
