#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(ExceptionTypeUnitTests)
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
		TEST_METHOD(ToBoolTest)
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
		TEST_METHOD(ToCharTest)
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
		TEST_METHOD(ToIntTest)
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
		TEST_METHOD(ToFloatTest)
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
		TEST_METHOD(ToDoubleTest)
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
		AnyType* anyType;
	};
}
