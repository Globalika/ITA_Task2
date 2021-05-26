#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeSwapUnitTests)
	{
	public:
		TEST_METHOD(SwapBoolAndIntTest)
		{
			std::unique_ptr<AnyType> anyType1 = std::make_unique<AnyType>(true);
			std::unique_ptr<AnyType> anyType2 = std::make_unique<AnyType>(12);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType1).type));
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType2).type));
			(*anyType1).Swap(*anyType2);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType2).type));
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType1).type));
		}
	};
}
