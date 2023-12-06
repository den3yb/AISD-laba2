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
	cout << list1[0] << "\n";
	cout << list2 << "\n";
	list1.push_head(&list2);
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
	note<int> c(nullptr, nullptr, 7);
	note<int> d(nullptr, nullptr, 1);
	twolist<int> list1;
	list1.push_end(&a);
	list1.push_end(&b);
	list1.push_end(&c);
	cout << list1 << "\n";
	note<int> e(nullptr, nullptr, 4);
	note<int> f(nullptr, nullptr, 2);
	note<int> g(nullptr, nullptr, 7);
	note<int> h(nullptr, nullptr, 9);
	twolist<int> list2;
	list2.push_end(&h);
	list2.push_end(&g);
	list2.push_end(&f);
	cout << list2 << "\n";
	cout << list1 << "+ " << list2 << "= ";
	twolist<int>* p1 = sum_num(&list1, &list2);
	cout << *p1 << "\n";
	EXPECT_TRUE(true);
}