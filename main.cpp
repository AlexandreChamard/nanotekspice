/*
** EPITECH PROJECT, 2017
** main.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <iostream>
#include "Bool.hpp"

int main()
{
	nts::Bool b;

	std::cout << b.getState();
	b = true;
	std::cout << b.getState();
	b = false;
	std::cout << b.getState();
}
