#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.6/Lab_12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab126
{
	TEST_CLASS(UnitTestLab126)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cherha* first = NULL;
			Cherha* last = NULL;

			ifstream file_load;
			file_load.open("E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_12.6\\Lab_12.6\\test.txt");
			int kilkist = Start(file_load, first, last);
			file_load.close();

			Cherha* T = first;
			T = first;
			Cherha* G = first;
			inversia(G, T, first, kilkist - 1);

			T = first;
			string str = T->s;
			Assert::AreEqual((char*)&str, "induk");
		}
	};
}
