#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeSwapUnitTests)
	{
	public:
		TEST_METHOD(Swap_Bool_And_Int_Test)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			std::unique_ptr<AnyType> anyType2 = std::make_unique<AnyType>(12);
			Assert::AreEqual(typeid(bool).name(), (*anyType1).GetType().name());
			Assert::AreEqual(typeid(int).name(), (*anyType2).GetType().name());
			(*anyType1).Swap(*anyType2);
			Assert::AreEqual(typeid(int).name(), (*anyType1).GetType().name());
			Assert::AreEqual(typeid(bool).name(), (*anyType2).GetType().name());
		}
	};
}