/*
** EPITECH PROJECT, 2017
** input.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "test.hpp"

bool testInput()
{
	nts::Cinput input1;
	nts::Cinput input2;
	nts::Cinput input3{ "hello" };
	nts::IComponent &iInput1 = input1;
	nts::IComponent &iInput2 = input2;
	nts::IComponent &iInput3 = input3;

	assert(iInput1.compute(1) == nts::Tristate::UNDEFINED);
	input1.setState(nts::Tristate::TRUE);
	assert(iInput1.compute(1) == nts::Tristate::TRUE);
	input1.setState(false);
	assert(iInput1.compute(1) == nts::Tristate::FALSE);

	try {
		iInput1.setLink(1, iInput2, 1);
	} catch (nts::LinkError &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		iInput2.compute(2);
	} catch (nts::PinNExistError &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		iInput3.setLink(3, input1, 4);
	} catch (nts::PinNExistError &e) {
		std::cerr << e.what() << std::endl;
	}

	return true;
}
