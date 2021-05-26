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
			Assert::AreEqual((int)AnyType::Type::NOTYPE, (int)(*(*anyType).type));
		}
		TEST_METHOD(ConstructorBoolTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(true);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType).type));
		}
		TEST_METHOD(ConstructorCharTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>('c');
			Assert::AreEqual((int)AnyType::Type::CHAR, (int)(*(*anyType).type));
		}
		TEST_METHOD(ConstructorIntTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12);
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType).type));
		}
		TEST_METHOD(ConstructorFloatTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5f);
			Assert::AreEqual((int)AnyType::Type::FLOAT, (int)(*(*anyType).type));
		}
		TEST_METHOD(ConstructorDoubleTest)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5);
			Assert::AreEqual((int)AnyType::Type::DOUBLE, (int)(*(*anyType).type));
		}
		TEST_METHOD(CopyConstructorTest)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			std::unique_ptr<AnyType> anyType2 = std::make_unique<AnyType>(*anyType1);
			Assert::AreEqual((int)(*(*anyType1).type), (int)(*(*anyType2).type));
			Assert::AreEqual((*(*anyType1).value).b, (*(*anyType2).value).b);
		}
		TEST_METHOD(MoveConstructorTest)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			AnyType anyType2 = std::move(*anyType1);
			Assert::AreEqual(true, (*(anyType2).value).b);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(anyType2).type));
		}
	};
}
