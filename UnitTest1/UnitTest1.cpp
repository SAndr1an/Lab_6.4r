#include <sstream>
#include <string>
#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab__6.4r/Lab_6.4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(UnitTest)
{
public:
    TEST_METHOD(TestCreateArrayRecursive)
    {
        const int size = 5;
        int a[size] = { 1, -2, 3, 4, 5 };
        std::stringstream ss;

        for (int i = 0; i < size; ++i) {
            ss << "a[" << i << "] = " << a[i] << "; ";
        }

        std::ostringstream result;
        std::streambuf* original = std::cout.rdbuf(result.rdbuf());

        PrintArray(a, size);

        std::cout.rdbuf(original);

        std::string expected = ss.str();
        std::string actual = result.str();

        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        actual.erase(actual.find_last_not_of(" \n\r\t") + 1);

        Assert::AreEqual(expected.c_str(), actual.c_str());
    }
};