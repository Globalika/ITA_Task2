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
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>();
			Assert::AreEqual(typeid(nullptr).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(ConstructorBoolTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(true);
			Assert::AreEqual(typeid(bool).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(ConstructorCharTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>('c');
			Assert::AreEqual(typeid(char).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(ConstructorIntTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12);
			Assert::AreEqual(typeid(int).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(ConstructorFloatTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5f);
			Assert::AreEqual(typeid(float).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(ConstructorDoubleTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5);
			Assert::AreEqual(typeid(double).name(), (*anyType).GetType().name());
		}
	};
}