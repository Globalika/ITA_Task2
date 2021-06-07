#include "AnyType.h"

AnyType::AnyType()
{
	type = std::make_unique<Type>(Type(Type::NOTYPE));
	value = std::make_unique<Value>();
	(*value).d = 0;
}

AnyType::AnyType(bool b)
{
	type = std::make_unique<Type>(Type(Type::BOOL));
	value = std::make_unique<Value>();
	(*value).b = b;
}

AnyType::AnyType(char ch)
{
	type = std::make_unique<Type>(Type(Type::CHAR));
	value = std::make_unique<Value>();
	(*value).ch = ch;
}

AnyType::AnyType(int i)
{
	type = std::make_unique<Type>(Type(Type::INT));
	value = std::make_unique<Value>();
	(*value).i = i;
}

AnyType::AnyType(float f)
{
	type = std::make_unique<Type>(Type(Type::FLOAT));
	value = std::make_unique<Value>();
	(*value).f = f;
}

AnyType::AnyType(double d)
{
	type = std::make_unique<Type>(Type(Type::DOUBLE));
	value = std::make_unique<Value>();
	(*value).d = d;
}

AnyType::AnyType(AnyType& other)
{
	type = std::make_unique<Type>(*other.type);
	value = std::make_unique<Value>(*other.value);
}

AnyType::AnyType(AnyType&& other) noexcept
{
	type = std::move(other.type);
	value = std::move(other.value);
}

bool AnyType::ToBool() const
{
	if (typeid(bool) == GetType()) {
		return (*value).b;
	}
	else {
		throw exceptionType(GetType(), typeid(bool));
	}
}


char AnyType::ToChar() const
{
	if (typeid(char) == GetType()) {
		return (*value).ch;
	}
	else {
		throw exceptionType(GetType(), typeid(char));
	}
}

int AnyType::ToInt() const
{
	if (typeid(int) == GetType()) {
		return (*value).i;
	}
	else {
		throw exceptionType(GetType(), typeid(int));
	}
}

float AnyType::ToFloat() const
{
	if (typeid(float) == GetType()) {
		return (*value).f;
	}
	else {
		throw exceptionType(GetType(), typeid(float));
	}
}

double AnyType::ToDouble() const
{
	if (typeid(double) == GetType()) {
		return (*value).d;
	}
	else {
		throw exceptionType(GetType(), typeid(double));
	}
}

AnyType& AnyType::operator=(bool b)
{
	(*value).b = b;
	*type = Type::BOOL;
	return *this;
}

AnyType& AnyType::operator=(char ch)
{
	(*value).ch = ch;
	*type = Type::CHAR;
	return *this;
}

AnyType& AnyType::operator=(int i)
{
	(*value).i = i;
	*type = Type::INT;
	return *this;
}

AnyType& AnyType::operator=(float f)
{
	(*value).f = f;
	*type = Type::FLOAT;
	return *this;
}

AnyType& AnyType::operator=(double d)
{
	(*value).d = d;
	*type = Type::DOUBLE;
	return *this;
}

AnyType& AnyType::Swap(AnyType& other)
{
	AnyType buff = *this;
	*(this->type) = *other.type;
	*(this->value) = *other.value;
	*other.type = *buff.type;
	*other.value = *buff.value;
	return *this;
}

const type_info& AnyType::GetType() const
{
	if (type == nullptr) {
		return typeid(nullptr);
	}
	switch (*type)
	{
	case Type::BOOL:
	{
		return typeid((*value).b);
	}
	case Type::CHAR:
	{
		return typeid((*value).ch);
	}
	case Type::INT:
	{
		return typeid((*value).i);
	}
	case Type::FLOAT:
	{
		return typeid((*value).f);
	}
	case Type::DOUBLE:
	{
		return typeid((*value).d);
	}
	default:
		return typeid(nullptr);
	}
}