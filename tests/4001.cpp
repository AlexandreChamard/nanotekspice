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

	{
		nts::Cinput input1;
		nts::Cinput input2;
		nts::Coutput output;
		nts::IComponent &iC4001 = c4001;
		nts::IComponent &iInput1 = input1;
		nts::IComponent &iInput2 = input2;
		nts::IComponent &iOutput = output;

		iC4001.setLink(3, iOutput, 1);
		iC4001.setLink(1, iInput1, 1);
		iC4001.setLink(2, iInput2, 1);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::UNDEFINED);
		input1.setState(true);
		input2.setState(false);
		assert(iC4001.compute(1) == nts::Tristate::TRUE);
		assert(iC4001.compute(2) == nts::Tristate::FALSE);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::FALSE);
	}
	{
		nts::Cinput input1;
		nts::Cinput input2;
		nts::Coutput output;
		nts::IComponent &iC4001 = c4001;
		nts::IComponent &iInput1 = input1;
		nts::IComponent &iInput2 = input2;
		nts::IComponent &iOutput = output;

		iC4001.setLink(4, iOutput, 1);
		iC4001.setLink(5, iInput1, 1);
		iC4001.setLink(6, iInput2, 1);
		nts::cycle_g++;
		assert(iC4001.compute(4) == nts::Tristate::UNDEFINED);
		input1.setState(true);
		input2.setState(true);
		nts::cycle_g++;
		assert(iC4001.compute(4) == nts::Tristate::FALSE);
	}
	{
		nts::Cinput input1;
		nts::Cinput input2;
		nts::Coutput output;
		nts::IComponent &iC4001 = c4001;
		nts::IComponent &iInput1 = input1;
		nts::IComponent &iInput2 = input2;
		nts::IComponent &iOutput = output;

		iC4001.setLink(10, iOutput, 1);
		iC4001.setLink(8, iInput1, 1);
		iC4001.setLink(9, iInput2, 1);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::UNDEFINED);
		input1.setState(false);
		input2.setState(false);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::TRUE);
	}
	{
		nts::Cinput input1;
		nts::Cinput input2;
		nts::Coutput output;
		nts::IComponent &iC4001 = c4001;
		nts::IComponent &iInput1 = input1;
		nts::IComponent &iInput2 = input2;
		nts::IComponent &iOutput = output;

		iC4001.setLink(11, iOutput, 1);
		iC4001.setLink(12, iInput1, 1);
		iC4001.setLink(12, iInput2, 1);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::UNDEFINED);
		input2.setState(false);
		nts::cycle_g++;
		assert(iC4001.compute(3) == nts::Tristate::UNDEFINED);
	}

	return true;
}
