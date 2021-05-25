#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeConstructorsUnitTests)
	{
	public:
		TEST_METHOD(ParameterlessConstructorTest)
		{
			AnyType* anyType = new AnyType();
			Assert::AreEqual(typeid(nullptr).name(), (*anyType).GetType().name());
			delete anyType;
		}
		TEST_METHOD(ConstructorBoolTest)
		{
			AnyType* anyType = new AnyType(true);
			Assert::AreEqual(typeid(bool).name(), (*anyType).GetType().name());
			delete anyType;
		}
		TEST_METHOD(ConstructorCharTest)
		{
			AnyType* anyType = new AnyType('c');
			Assert::AreEqual(typeid(char).name(), (*anyType).GetType().name());
			delete anyType;
		}
		TEST_METHOD(ConstructorIntTest)
		{
			AnyType* anyType = new AnyType(12);
			Assert::AreEqual(typeid(int).name(), (*anyType).GetType().name());
			delete anyType;
		}
		TEST_METHOD(ConstructorFloatTest)
		{
			AnyType* anyType = new AnyType(12.5f);
			Assert::AreEqual(typeid(float).name(), (*anyType).GetType().name());
			delete anyType;
		}
		TEST_METHOD(ConstructorDoubleTest)
		{
			AnyType* anyType = new AnyType(12.5);
			Assert::AreEqual(typeid(double).name(), (*anyType).GetType().name());
			delete anyType;
		}
	};
}