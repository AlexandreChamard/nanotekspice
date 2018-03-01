/*
** EPITECH PROJECT, 2017
** Pin.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <functional>

#include "Bool.hpp"

namespace nts {
	class IComponent;

	enum InfoPin {
		PIN_INPUT,
		PIN_OUTPUT,
		PIN_UNUSED
	};
	extern InfoPin linker_g;

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

	#define COMPUTE_REF(i) ((i).link ? (i).link->compute((i).pin) : Tristate::UNDEFINED)
	#define COMPUTE(i) ((i).compute ? (i).compute() : Tristate::UNDEFINED)
	#define BIT(n, i) (((n) >> (i - 1)) & 1)
	// #define BIT(n, i) (((n) & (1 << (i - 1))) >> (i - 1))
}
