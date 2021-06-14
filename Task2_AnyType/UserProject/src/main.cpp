#include "..\..\Task2_AnyType\src\AnyType.h"
#include <iostream>

using namespace std;

int main()
{
	AnyType a1(2), a2('f');
	a1.Swap(a2);

	AnyType a3 = std::move(a1);



	return 0;
}