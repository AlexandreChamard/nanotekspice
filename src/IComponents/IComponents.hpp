/*
** EPITECH PROJECT, 2017
** IComponents.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <functional>
#include <memory>
#include "Bool.hpp"
#include "ExecErrors.hpp"
#include "Pin.hpp"

namespace  nts {
	extern std::size_t cycle_g;

	class IComponent {
	public:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t pin = 0) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}
