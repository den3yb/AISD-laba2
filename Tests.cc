#include "Spisok.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace spisok;

TEST(Tests1, twolist1) {
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
	twolist<int> list3(i, 1, 10);
	cout << list3;
	EXPECT_TRUE(true);
}

TEST(Tests2, summ) {
	note<int> a(nullptr, nullptr, 9);
	note<int> b(nullptr, nullptr, 2);
	note<int> c(nullptr, nullptr, 9);
	twolist<int> list1;
	list1.push_end(&a);
	list1.push_end(&b);
	list1.push_end(&c);
	twolist<int> list2(list1);
	cout << list1 << "\n";
	cout << list2 << "\n";
	sum_num(&list1, &list2);
	cout << list2 << "\n";
	cout << list1 << "\n";
	EXPECT_TRUE(true);
}