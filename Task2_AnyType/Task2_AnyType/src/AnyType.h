#pragma once
#ifndef MY_ANY_TYPE_CLASS
#define MY_ANY_TYPE_CLASS

#include <string>
#include <typeinfo> 
#include <exception>
#include <memory>

class exceptionType
{
public:
	std::string whatStr = "", msg = "Bad cast from ";
	exceptionType(const type_info& type1, const type_info& type2) noexcept
	{
		whatStr = msg + type1.name() + " to " + type2.name() + "!";
	}
	const std::string what() { return whatStr.c_str(); }
};

class AnyType
{
public:
	AnyType();
	AnyType(bool b);
	AnyType(char ch);
	AnyType(int i);
	AnyType(float f);
	AnyType(double d);
	AnyType(AnyType& other);
	AnyType(AnyType&& other) noexcept;
	~AnyType() {}

	bool ToBool() const;
	char ToChar() const;
	int ToInt() const;
	float ToFloat() const;
	double ToDouble() const;

	AnyType& operator=(bool value);
	AnyType& operator=(char value);
	AnyType& operator=(int value);
	AnyType& operator=(float value);
	AnyType& operator=(double value);

	AnyType& Swap(AnyType& otherValue);
	const type_info& GetType() const;

	enum class Type {
		BOOL,
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NOTYPE
	};
	union Value {
		bool b;
		char ch;
		int i;
		float f;
		double d;
	};

	std::unique_ptr<Type> type;
	std::unique_ptr<Value> value;
};

#endif MY_ANY_TYPE_CLASS