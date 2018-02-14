/*
** EPITECH PROJECT, 2017
** input.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <array>
#include "IComponents.hpp"

namespace nts {
	class Cinput : public IComponent {
	public:
		Cinput(std::string const &value = "");
		~Cinput() override = default;
		Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, IComponent &other,
			std::size_t otherPin) override;
		void dump() const override;
		void setState(Tristate state);

	private:
		static unsigned int id;

		std::string _id;
		nts::Bool _state;
	};
}
