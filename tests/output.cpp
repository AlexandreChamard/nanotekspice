/*
** EPITECH PROJECT, 2017
** output.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "test.hpp"

bool testOutput()
{
	nts::Coutput output1;
	nts::Cinput input1;
	nts::IComponent &iInput1 = input1;
	nts::Coutput output2;
	nts::Coutput output3{ "hello" };
	nts::IComponent &iOutput1 = output1;
	nts::IComponent &iOutput2 = output2;
	nts::IComponent &iOutput3 = output3;

	assert(iOutput1.compute(1) == nts::Tristate::UNDEFINED);
	assert(output1.getState() == nts::Tristate::UNDEFINED);
	output1.setLink(1, iInput1, 1);
	assert(output1.getState() == nts::Tristate::UNDEFINED);
	input1.setState(true);
	assert(output1.getState() == nts::Tristate::TRUE);
	input1.setState(false);
	assert(output1.getState() == nts::Tristate::FALSE);

	try {
		iOutput2.compute(2);
	} catch (nts::PinNExistError &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		iOutput3.setLink(3, output1, 4);
	} catch (nts::PinNExistError &e) {
		std::cerr << e.what() << std::endl;
	}

	return true;
}
