/*
** EPITECH PROJECT, 2017
** main.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <iostream>
#include "Shell.hpp"
#include "Bool.hpp"

// int main()
// {
// 	nts::Bool b;
// 	nts::Bool t{true};
// 	nts::Bool f{false};
// 	nts::Bool u{};
//
// 	std::cout << b << std::endl;
// 	b = true;
// 	std::cout << b << std::endl;
// 	b = false;
// 	std::cout << b << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "t || t = " << (t || t) << std::endl;
// 	std::cout << "t || f = " << (t || f) << std::endl;
// 	std::cout << "t && t = " << (t && t) << std::endl;
// 	std::cout << "t && f = " << (t && f) << std::endl;
// }

int main()
{
	nts::Shell shell;

	shell.loop();
	return 0;
}
