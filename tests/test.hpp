/*
** EPITECH PROJECT, 2017
** test.hpp for cpp_nanotekspice
** File description:
** description
*/

#pragma once

#include <iostream>
#include <assert.h>

#include "Output/Output.hpp"
#include "Input/Input.hpp"
#include "4001/4001.hpp"
#include "ExecErrors.hpp"
#include "Circuit.hpp"

#define WHITE	"\e[0;97m"
#define BLACK	"\e[1;30m"
#define RED	"\e[1;31m"
#define GREEN	"\e[1;92m"
#define YELLOW	"\e[1;33m"
#define BLUE	"\e[1;34m"
#define MAGENTA	"\e[1;35m"
#define CYAN	"\e[1;36m"

#define SUCCESS		std::cout << GREEN << "Success" << WHITE << "\n"
#define FAIL		std::cout << RED << "Fail" << WHITE << "\n"

#define TEST(test) 	std::cout << #test":" << std::endl; 		\
			(test() ? SUCCESS : FAIL) << std::endl		\

bool testInput();
bool testOutput();
bool testC4001();
bool testComponentFactory();
