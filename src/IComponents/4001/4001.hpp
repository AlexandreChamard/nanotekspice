/*
** EPITECH PROJECT, 2017
** 4001.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

namespace nts {
	class C4001 : public IComponent {
	public:
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin);
		void dump();
	private:
		std::array<std::size_t, 4> _cycles;
		std::array<std::pair<nts::Tristate, nts::Tristate(*compute)()> ,4> _output;
		std::array<std::pair<IComponent&, std::size_t>, 8> _input;
	};
}
