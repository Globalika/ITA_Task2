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
			Assert::AreEqual((int)AnyType::Type::NOTYPE, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(ConstructorBoolTest)
		{
			AnyType* anyType = new AnyType(true);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(ConstructorCharTest)
		{
			AnyType* anyType = new AnyType('c');
			Assert::AreEqual((int)AnyType::Type::CHAR, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(ConstructorIntTest)
		{
			AnyType* anyType = new AnyType(12);
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(ConstructorFloatTest)
		{
			AnyType* anyType = new AnyType(12.5f);
			Assert::AreEqual((int)AnyType::Type::FLOAT, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(ConstructorDoubleTest)
		{
			AnyType* anyType = new AnyType(12.5);
			Assert::AreEqual((int)AnyType::Type::DOUBLE, (int)(*(*anyType).type));
			delete anyType;
		}
		TEST_METHOD(CopyConstructorTest)
		{
			AnyType* anyType1 = new AnyType(true);
			AnyType* anyType2 = new AnyType(anyType1);
			Assert::AreEqual((int)(*(*anyType1).type), (int)(*(*anyType2).type));
			Assert::AreEqual((*(*anyType1).value).b, (*(*anyType2).value).b);
			delete anyType1;
			delete anyType2;
		}
		TEST_METHOD(MoveConstructorTest)
		{
			AnyType* anyType1 = new AnyType(true);
			AnyType anyType2 = std::move(*anyType1);
			Assert::AreEqual(true, (*(anyType2).value).b);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(anyType2).type));
			delete anyType1;
		}
	};
}
