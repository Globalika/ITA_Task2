#include "AnyType.h"

AnyType::AnyType()
{
	m_type = std::make_unique<Type>(Type(Type::NOTYPE));
	m_value = std::make_unique<Value>();
	(*m_value).d = 0;
}

AnyType::AnyType(bool b)
{
	m_type = std::make_unique<Type>(Type(Type::BOOL));
	m_value = std::make_unique<Value>();
	(*m_value).b = b;
}

AnyType::AnyType(char ch)
{
	m_type = std::make_unique<Type>(Type(Type::CHAR));
	m_value = std::make_unique<Value>();
	(*m_value).ch = ch;
}

AnyType::AnyType(int i)
{
	m_type = std::make_unique<Type>(Type(Type::INT));
	m_value = std::make_unique<Value>();
	(*m_value).i = i;
}

AnyType::AnyType(float f)
{
	m_type = std::make_unique<Type>(Type(Type::FLOAT));
	m_value = std::make_unique<Value>();
	(*m_value).f = f;
}

AnyType::AnyType(double d)
{
	m_type = std::make_unique<Type>(Type(Type::DOUBLE));
	m_value = std::make_unique<Value>();
	(*m_value).d = d;
}

AnyType::AnyType(AnyType& other)
{
	m_type = std::make_unique<Type>(*other.m_type);
	m_value = std::make_unique<Value>(*other.m_value);
}

AnyType::AnyType(AnyType&& other) noexcept
{
	m_type = std::move(other.m_type);
	m_value = std::move(other.m_value);
}

bool AnyType::ToBool() const
{
	if (typeid(bool) == GetType()) {
		return (*m_value).b;
	}
	else {
		throw exceptionType(GetType(), typeid(bool));
	}
}


char AnyType::ToChar() const
{
	if (typeid(char) == GetType()) {
		return (*m_value).ch;
	}
	else {
		throw exceptionType(GetType(), typeid(char));
	}
}

int AnyType::ToInt() const
{
	if (typeid(int) == GetType()) {
		return (*m_value).i;
	}
	else {
		throw exceptionType(GetType(), typeid(int));
	}
}

float AnyType::ToFloat() const
{
	if (typeid(float) == GetType()) {
		return (*m_value).f;
	}
	else {
		throw exceptionType(GetType(), typeid(float));
	}
}

double AnyType::ToDouble() const
{
	if (typeid(double) == GetType()) {
		return (*m_value).d;
	}
	else {
		throw exceptionType(GetType(), typeid(double));
	}
}

AnyType& AnyType::operator=(bool b)
{
	(*m_value).b = b;
	*m_type = Type::BOOL;
	return *this;
}

AnyType& AnyType::operator=(char ch)
{
	(*m_value).ch = ch;
	*m_type = Type::CHAR;
	return *this;
}

AnyType& AnyType::operator=(int i)
{
	(*m_value).i = i;
	*m_type = Type::INT;
	return *this;
}

AnyType& AnyType::operator=(float f)
{
	(*m_value).f = f;
	*m_type = Type::FLOAT;
	return *this;
}

AnyType& AnyType::operator=(double d)
{
	(*m_value).d = d;
	*m_type = Type::DOUBLE;
	return *this;
}

AnyType& AnyType::Swap(AnyType& other)
{
	AnyType buff = *this;
	*(this->m_type) = *other.m_type;
	*(this->m_value) = *other.m_value;
	*other.m_type = *buff.m_type;
	*other.m_value = *buff.m_value;
	return *this;
}

const type_info& AnyType::GetType() const
{
	if (m_type == nullptr) {
		return typeid(nullptr);
	}
	switch (*m_type)
	{
	case Type::BOOL:
	{
		return typeid((*m_value).b);
	}
	case Type::CHAR:
	{
		return typeid((*m_value).ch);
	}
	case Type::INT:
	{
		return typeid((*m_value).i);
	}
	case Type::FLOAT:
	{
		return typeid((*m_value).f);
	}
	case Type::DOUBLE:
	{
		return typeid((*m_value).d);
	}
	default:
		return typeid(nullptr);
	}
}