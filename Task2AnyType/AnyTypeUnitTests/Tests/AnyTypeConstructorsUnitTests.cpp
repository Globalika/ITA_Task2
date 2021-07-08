#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeConstructorsUnitTests)
	{
	public:
		TEST_METHOD(Parameterless_Constructor_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>();
			Assert::AreEqual(typeid(nullptr).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Constructor_Bool_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(true);
			Assert::AreEqual(typeid(bool).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Constructor_Char_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>('c');
			Assert::AreEqual(typeid(char).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Constructor_Int_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12);
			Assert::AreEqual(typeid(int).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Constructor_Float_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5f);
			Assert::AreEqual(typeid(float).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Constructor_Double_Test)
		{
			std::unique_ptr<AnyType> anyType = std::make_unique<AnyType>(12.5);
			Assert::AreEqual(typeid(double).name(), (*anyType).GetType().name());
		}
		TEST_METHOD(Copy_Constructor_Test)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			std::unique_ptr<AnyType> anyType2 = std::make_unique<AnyType>(*anyType1);
			Assert::AreEqual((*anyType1).GetType().name(), (*anyType2).GetType().name());
		}
		TEST_METHOD(Move_Constructor_Test)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			AnyType anyType2 = std::move(*anyType1);
			Assert::AreEqual(typeid(bool).name(), anyType2.GetType().name());
		}
	};
}