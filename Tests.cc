#include "Spisok.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace spisok;

TEST(Tests1, twolist1) {
	twolist<int> list1;
	list1.push_end(7);
	list1.push_end(2);
	list1.push_end(5);
	list1.push_head(4);
	cout << list1 << "\n";
	list1.pop_end();
	cout << list1 << "\n";
	list1.pop_head();
	cout << list1<<"\n";
	EXPECT_TRUE(true);
}

TEST(Tests2, twolist2) {
	twolist<int> list1;
	list1.push_end(1);
	list1.push_end(2);
	list1.push_end(3);
	list1.push_end(4);
	list1.push_head(1);
	twolist<int> list2;
	list2.push_end(6);
	list2.push_end(7);
	list2.push_end(8);
	list2.push_end(9);
	cout << list1 << "\n";
	cout << list2 << "\n";
	list1.push_end(&list2);
	cout << list1 << "\n";
	EXPECT_TRUE(true);
}

TEST(Tests3, twolist3) {
	twolist<int> list1;
	list1.push_end(1);
	list1.push_end(2);
	list1.push_end(3);
	list1.push_end(4);
	twolist<int> list2;
	list2.push_end(6);
	list2.push_end(7);
	list2.push_end(8);
	list2.push_end(9);
	cout << list1 << "\n";
	cout << list2 << "\n";
	list1.push_head(&list2);
	cout << list1 << "\n";
	EXPECT_TRUE(true);
}

TEST(Tests4, sum1) {
	twolist<int> list1;
	list1.push_end(1);
	list1.push_end(2);
	list1.push_end(3);
	list1.push_end(4);
	twolist<int> list2;
	list2.push_end(6);
	list2.push_end(7);
	list2.push_end(8);
	list2.push_end(9);
	cout << list1 << "\n";
	cout << list2 << "\n";
	twolist<int> list_s = sum_num(&list1, &list2);
	cout << list_s;
	EXPECT_TRUE(true);
}

TEST(Tests5, sum2) {
	twolist<int> list1;
	list1.push_end(1);
	list1.push_end(2);
	list1.push_end(3);
	twolist<int> list2;
	list2.push_end(6);
	list2.push_end(7);
	list2.push_end(8);
	list2.push_end(9);
	cout << list1 << "\n";
	cout << list2 << "\n";
	twolist<int> list_s = sum_num(&list1, &list2);
	cout << list_s;
	EXPECT_TRUE(true);
}


TEST(Tests6, sum3) {
	twolist<int> list1;
	list1.push_end(1);
	list1.push_end(2);
	list1.push_end(3);
	twolist<int> list2;
	list2.push_end(6);
	list2.push_end(7);
	list2.push_end(8);
	list2.push_end(9);
	cout << list2 << "\n";
	cout << list1 << "\n";
	twolist<int> list_s = sum_num(&list2, &list1);
	cout << list_s;
	EXPECT_TRUE(true);
}

TEST(Tests7, mul) {
	twolist<int> list1;
	list1.push_end(8);
	list1.push_end(9);
	list1.push_end(4);
	twolist<int> list2;
	list2.push_end(4);
	list2.push_end(5);
	list2.push_end(6);
	list2.push_end(8);
	cout << list2 << "\n";
	cout << list1 << "\n";
	twolist<int> list_m = mul_num(&list1, &list2);
	cout << list_m;
	EXPECT_TRUE(true);
}