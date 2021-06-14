#include "..\..\AnyType\src\AnyType.h"
#include <iostream>

using namespace std;

int main()
{
	AnyType a1(true);
	AnyType a2('f');
	AnyType a3(2);
	AnyType a4(2.5f);
	AnyType a5(2.5);

	std::cout << "a1 hold bool : " << a1.ToBool() << " | type : " << a1.GetType().name() << "\n\n";
	std::cout << "a2 hold char : " << a2.ToChar() << " | type : " << a2.GetType().name() << "\n\n";
	std::cout << "a3 hold int : " << a3.ToInt() << " | type : " << a3.GetType().name() << "\n\n";
	std::cout << "a4 hold float : " << a4.ToFloat() << " | type : " << a4.GetType().name() << "\n\n";
	std::cout << "a5 hold double : " << a5.ToDouble() << " | type : " << a5.GetType().name() << "\n\n";

	a1 = 'f';
	std::cout << "assign char to a1, now a1 holds char \'f\' and type is : " << a1.GetType().name() << "\n\n";
	a1 = 2;
	std::cout << "assign int to a1, now a1 holds integer 2 and type is : " << a1.GetType().name() << "\n\n";
	a1 = 2.5f;
	std::cout << "assign float to a1, now a1 holds float 2.5f and type is : " << a1.GetType().name() << "\n\n";
	a1 = 2.5;
	std::cout << "assign double to a1, now a1 holds double 2.5 and type is : " << a1.GetType().name() << "\n\n";
	a1 = true;
	std::cout << "assign bool to a1, now a1 holds bool true and type is : " << a1.GetType().name() << "\n\n";

	AnyType a6 = a2;
	std::cout << "a6 copy constructor get a2 with char value : " << a6.GetType().name() << "\n\n";
	AnyType a7 = std::move(a2);
	std::cout << "a7 move constructor get a2 with char value : " << a6.GetType().name() << "\n\n";
	std::cout << "a2 now empty and type : " << a2.GetType().name() << "\n\n";
	AnyType a8;
	std::cout << "a8 default constructor hold nothing : " << a8.GetType().name() << "\n\n";

	try {
		a1.ToChar();
	}
	catch (exceptionType& ex) {
		cout << ex.what() << "\n\n";
	}
	try {
		a1.ToInt();
	}
	catch (exceptionType& ex) {
		cout << ex.what() << "\n\n";
	}
	try {
		a1.ToFloat();
	}
	catch (exceptionType& ex) {
		cout << ex.what() << "\n\n";
	}
	try {
		a1.ToDouble();
	}
	catch (exceptionType& ex) {
		cout << ex.what() << "\n\n";
	}

	return 0;
}