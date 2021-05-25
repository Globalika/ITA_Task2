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
			AnyType* anyType1 = new AnyType(true);
			AnyType* anyType2 = new AnyType(12);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType1).type));
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType2).type));
			(*anyType1).Swap(*anyType2);
			Assert::AreEqual((int)AnyType::Type::BOOL, (int)(*(*anyType2).type));
			Assert::AreEqual((int)AnyType::Type::INT, (int)(*(*anyType1).type));
			delete anyType1;
			delete anyType2;
		}
	};
}
