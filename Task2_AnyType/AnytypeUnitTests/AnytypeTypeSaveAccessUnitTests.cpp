#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnytypeTypeSaveAccessUnitTests)
	{
	public:

		TEST_METHOD_INITIALIZE(Init)
		{
			anyType = new AnyType();
		}
		TEST_METHOD_CLEANUP(Clean)
		{
			delete anyType;
		}
		TEST_METHOD(ToBoolSaveAccessTest)
		{
			bool expectedValue = true;
			*anyType = 12; 
			auto func = [&] { (*anyType).ToBool(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = true;
			Assert::AreEqual(expectedValue, (*anyType).ToBool());
		}
		TEST_METHOD(ToCharSaveAccessTest)
		{
			char expectedValue = 'c';
			*anyType = 12;
			auto func = [&] { (*anyType).ToChar(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = 'c';
			Assert::AreEqual(expectedValue, (*anyType).ToChar());
		}
		TEST_METHOD(ToIntSaveAccessTest)
		{
			int expectedValue = 12;
			*anyType = 'c';
			auto func = [&] { (*anyType).ToInt(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12;
			Assert::AreEqual(expectedValue, (*anyType).ToInt());
		}
		TEST_METHOD(ToFloatSaveAccessTest)
		{
			float expectedValue = 12.5f;
			*anyType = 12;
			auto func = [&] { (*anyType).ToFloat(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5f;
			Assert::AreEqual(expectedValue, (*anyType).ToFloat());
		}
		TEST_METHOD(ToDoubleSaveAccessTest)
		{
			double expectedValue = 12.5;
			*anyType = 12;
			auto func = [&] { (*anyType).ToDouble(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5;
			Assert::AreEqual(expectedValue, (*anyType).ToDouble());
		}
	private:
		AnyType* anyType;
	};
}
