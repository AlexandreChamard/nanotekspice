/*
** EPITECH PROJECT, 2017
** IComponents.hpp for cpp_nanotekspice
** File description:
** description
*/

#ifndef ICOMPONENTS_HPP
#define ICOMPONENTS_HPP

namespace  nts
{
	class IComponent {
	apublic:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}

#endif
