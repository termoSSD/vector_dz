#include "pch.h"
#include "CppUnitTest.h"
#include "../fucn.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(test)
    {
    public:

        // Тест для сортування за зростанням
        TEST_METHOD(TestSortAsc)
        {
            vector<int> v = { 5, 1, 4, 2, 8 };
            vector<int> expected = { 1, 2, 4, 5, 8 };

            sortAsc(v);

            for (size_t i = 0; i < v.size(); i++)
                Assert::AreEqual(expected[i], v[i]);
        }

        // Тест для суми елементів
        TEST_METHOD(TestSumOfElements)
        {
            vector<int> v = { 10, 20, 30 };
            int expectedSum = 60;

            int actualSum = sumOfElements(v);

            Assert::AreEqual(expectedSum, actualSum);
        }

        // Тест для видалення дублікатів
        TEST_METHOD(TestRmDuplicates)
        {
            vector<int> v = { 1, 2, 2, 3, 1, 4 };
            vector<int> unique;
            vector<int> expected = { 1, 2, 3, 4 };

            rmDuplicates(v, unique);

            Assert::AreEqual(expected.size(), unique.size(), L"Розмір масиву унікальних значень не збігається");
            for (size_t i = 0; i < unique.size(); i++)
                Assert::AreEqual(expected[i], unique[i]);
        }
	};
}
