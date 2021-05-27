#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeAssigmentOperatorsUnitTests)
	{
	public:

		TEST_METHOD_INITIALIZE(Init)
		{
			anyType = std::make_unique<AnyType>();
		}
		TEST_METHOD(AssigmentOperatorBoolTest)
		{
			bool expectedValue = true;
			*anyType = true;
			Assert::AreEqual(expectedValue, (*anyType).ToBool());
		}
		TEST_METHOD(AssigmentOperatorCharTest)
		{
			char expectedValue = 'c';
			*anyType = 'c';
			Assert::AreEqual(expectedValue, (*anyType).ToChar());
		}
		TEST_METHOD(AssigmentOperatorIntTest)
		{
			int expectedValue = 12;
			*anyType = 12;
			Assert::AreEqual(expectedValue, (*anyType).ToInt());
		}
		TEST_METHOD(AssigmentOperatorFloatlTest)
		{
			float expectedValue = 12.5f;
			*anyType = 12.5f;
			Assert::AreEqual(expectedValue, (*anyType).ToFloat());
		}
		TEST_METHOD(AssigmentOperatorDoubleTest)
		{
			double expectedValue = 12.5;
			*anyType = 12.5;
			Assert::AreEqual(expectedValue, (*anyType).ToDouble());
		}
	private:
		std::unique_ptr<AnyType> anyType;
	};
}
