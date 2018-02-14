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

	enum InfoPin {
		PIN_INPUT,
		PIN_OUTPUT,
		PIN_UNUSED
	};

	using computePin_t = std::function<Tristate()>;
	using linkPin_t = std::function<void (IComponent&, std::size_t)>;

	struct Ref {
		InfoPin info;
		computePin_t compute;
		linkPin_t link;
	};

	struct Output {
		Tristate state = Tristate::UNDEFINED;
		std::size_t cycle = 0;
		computePin_t compute; // à dégager car dans ref
	};
	struct Input {
		IComponent *component = nullptr; // a dégager car rename link
		IComponent *link = nullptr;
		std::size_t pin = -1;
	};

	#define COMPUTE(i) (i.link ? i.link->compute(i.pin) : Tristate::UNDEFINED)
}
