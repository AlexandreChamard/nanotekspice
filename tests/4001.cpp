/*
** EPITECH PROJECT, 2017
** input.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "test.hpp"

bool testC4001()
{
	nts::C4001 c4001;
	nts::Cinput input1;
	nts::Cinput input2;
	nts::Coutput output;
	nts::IComponent &iC4001 = c4001;
	nts::IComponent &iInput1 = input1;
	nts::IComponent &iInput2 = input2;
	nts::IComponent &iOutput = output;

	std::cout << "1" << std::endl;
	iC4001.setLink(3, iOutput, 1);
	std::cout << "2" << std::endl;
	iC4001.setLink(1, iInput1, 1);
	std::cout << "3" << std::endl;
	iC4001.setLink(2, iInput2, 1);
	std::cout << "4" << std::endl;
	nts::cycle_g++;
	assert(iC4001.compute(3) == nts::Tristate::UNDEFINED);
	input1.setState(true);
	input2.setState(false);
	assert(iC4001.compute(1) == nts::Tristate::TRUE);
	assert(iC4001.compute(2) == nts::Tristate::FALSE);
	nts::cycle_g++;
	assert(iC4001.compute(3) == nts::Tristate::FALSE);
	input1.setState(false);
	input2.setState(false);
	nts::cycle_g++;
	assert(iC4001.compute(3) == nts::Tristate::TRUE);
	// input1.setState(nts::Tristate::TRUE);
	// assert(iInput1.compute(1) == nts::Tristate::TRUE);
	// input1.setState(false);
	// assert(iInput1.compute(1) == nts::Tristate::FALSE);
        //
	// try {
	// 	iInput1.setLink(1, iInput2, 1);
	// } catch (nts::LinkError &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	iInput2.compute(2);
	// } catch (nts::PinNExistError &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	iInput3.setLink(3, input1, 4);
	// } catch (nts::PinNExistError &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	return true;
}
