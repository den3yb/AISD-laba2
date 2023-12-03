#include "Spisok.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <complex>


using namespace std;
using namespace spisok;

TEST(Func_Tests, SumStubTest1) {
	note<int> a (nullptr, nullptr, 5);
	std::cout << a;
EXPECT_TRUE(true);
}

