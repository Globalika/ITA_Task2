#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnyTypeExceptionTypeUnitTests)
	{
	public:

		TEST_METHOD_INITIALIZE(Init)
		{
			anyType = std::make_unique<AnyType>();
		}
		TEST_METHOD(ToBool_Test)
		{
			auto func = [&] { (*anyType).ToBool(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = 'c';
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5f;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5;
			Assert::ExpectException<exceptionType>(func);
		}
		TEST_METHOD(ToChar_Test)
		{
			auto func = [&] { (*anyType).ToChar(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = true;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5f;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5;
			Assert::ExpectException<exceptionType>(func);
		}
		TEST_METHOD(ToInt_Test)
		{
			auto func = [&] { (*anyType).ToInt(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = true;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 'c';
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5f;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5;
			Assert::ExpectException<exceptionType>(func);

		}
		TEST_METHOD(ToFloat_Test)
		{
			auto func = [&] { (*anyType).ToFloat(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = true;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 'c';
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5;
			Assert::ExpectException<exceptionType>(func);
		}
		TEST_METHOD(ToDouble_Test)
		{
			auto func = [&] { (*anyType).ToDouble(); };
			Assert::ExpectException<exceptionType>(func);
			*anyType = true;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 'c';
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12;
			Assert::ExpectException<exceptionType>(func);
			*anyType = 12.5f;
			Assert::ExpectException<exceptionType>(func);
		}
	private:
		std::unique_ptr<AnyType> anyType;
	};
}
