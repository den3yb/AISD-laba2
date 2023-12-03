#include "Spisok.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace spisok;

TEST(Func_Tests, SumStubTest1) {
	note<int> a (nullptr, nullptr, 5);
	note<int> b(nullptr, nullptr, 2);
	note<int> c(nullptr, nullptr, 4);
	twolist<int> list;
	list.push_end(&c);
	list.push_end(&c);
	list.push_end(&c);
	cout << list;
EXPECT_TRUE(true);
}

