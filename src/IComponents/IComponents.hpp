/*
** EPITECH PROJECT, 2017
** IComponents.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include "Bool.hpp"

namespace  nts {
	class IComponent {
	public:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t pin = 0) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};

	using computePin_t = Tristate (*)();
	struct Output {
		Tristate state;
		std::size_t cycle;
		computePin_t compute;
	};
	struct Input {
		IComponent &component;
		std::size_t pin;
	};
}
