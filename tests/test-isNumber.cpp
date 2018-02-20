/*
** EPITECH PROJECT, 2017
** test-isNumber.cpp for cpp_nanotekspice
** File description:
** description
*/

#include "../src/Lib/Tools.hpp"
#include <assert.h>

int main()
{
	assert(lib::Tools::isNumber("123456") == true);
	assert(lib::Tools::isNumber("123456.12") == true);
	assert(lib::Tools::isNumber("123456.12", false) == false);
	assert(lib::Tools::isNumber("123456.12   ") == false);
	assert(lib::Tools::isNumber("123456,12   ") == false);
}
