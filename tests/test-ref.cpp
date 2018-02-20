/*
** EPITECH PROJECT, 2017
** test-ref.cpp for cpp_nanotekspice
** File description:
** description
*/

#include <assert.h>

int main()
{
	int a = 2;
	int &b = a;

	assert(&a == &b);
}
