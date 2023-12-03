#include "Spisok.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace spisok;

TEST(Func_Tests, SumStubTest1) {
	note<int> a (nullptr, nullptr, 7);
	note<int> b(nullptr, nullptr, 2);
	note<int> c(nullptr, nullptr, 5);
	note<int> d(nullptr, nullptr, 4);
	twolist<int> list1;
	list1.push_end(&a);
	list1.push_end(&b);
	list1.push_end(&c);
	twolist<int> list2 (list1);
	list1.push_head(&d);
	cout << list1<<"\n";
	cout << list2 << "\n";
	list1.push_head(list2);
	cout << list1 << "\n";
	list1.deleate(2);
	cout << list1<<"\n";
	int i = 4;
	twolist<int> list3(i);
EXPECT_TRUE(true);
}

