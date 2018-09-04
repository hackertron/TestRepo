// triplet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>
#include <iostream>
#include "FindTriplet.h"
#include <vector>
#include <cstdio>

int main(int argc, char* argv[])
{
	if (argc >= 2 && std::string(argv[1]) == "--tests")
	{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	else
	{
		// Application logic goes here
		std::cout << "Enter the array size \n";
		int size;
		std::cin >> size;
		std::vector<float> arr;
		std::cout << "Enter elements in array \n";
		for (int i = 0; i < size; i++)
		{
			float element; 
			std::cin >> element;
			 arr.push_back(element);
		}
		std::cout << "Enter the sum \n";
		float sum;
		std::cin >> sum;
		FindTriplet FindTriplet_obj;
		int array_size = arr.size();
		FindTriplet_obj.find_triplet(arr, array_size, sum);
		std::getchar();
	
	}
}

/*
Positive Test
*/
TEST(TestCase_PositiveInteger, Positive)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 1, 2, 3, 4, 5 };
	const float sum = 9;
	int size = TestVec.size();
	std::vector<float> check{ 1,3,5 };
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
Multiple Test
*/
TEST(TestCase_MultipleOutput, Multiple)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 0, 0, 0, -10, 10 };
	const float sum = 0;
	int size = TestVec.size();
	std::vector<float> check{ -10,0,10 };
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
Floating Numbers Test
*/
TEST(TestCase_FloatingPoint, Floating)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 2, 3, 4.5, -10, 10 };
	const float sum = 9.5;
	int size = TestVec.size();
	std::vector<float> check{ 2,3,4.5 };
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
Negative Test
*/
TEST(TestCase_NegativeNumber, Negative)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ -2, 0, 2, -10, 10 };
	const float sum = -12;
	int size = TestVec.size();
	std::vector<float> check{ -10, -2,0 };
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
PositiveNegative Test
*/
TEST(TestCase_PositiveNegative, PositiveNegative)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ -1, 3, 0, -3, -4.5 };
	const float sum = 13;
	int size = TestVec.size();
	std::vector<float> check{};
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
TooSMall Test
*/
TEST(TestCase_TooSmall, Small)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ -1, 4.5 };
	const float sum = 13;
	int size = TestVec.size();
	std::vector<float> check{};
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
PositiveNoTriplet Test
*/
TEST(TestCase_PositiveNoTriplet, PositiveNoTriplet)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 1, 3, 10, 3, 45 };
	const float sum = 5;
	int size = TestVec.size();
	std::vector<float> check{};
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
Large Test
*/
TEST(TestCase_Large, Large)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 12, 35, 134, 46236, 5632, -983, 23794, 123 };
	const float sum = 23952;
	int size = TestVec.size();
	std::vector<float> check{ 35, 123, 23794 };
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
NegativeSUm Test
*/
TEST(TestCase_NegativeSum, Nsum)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{ 55, 34, 98, 23, 12, 90 };
	const float sum = -100;
	int size = TestVec.size();
	std::vector<float> check{};
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}

/*
Empty Test
*/
TEST(TestCase_EmptyTest, Empty)
{
	FindTriplet triplet;
	const std::vector<float> TestVec{};
	const float sum = 11;
	int size = TestVec.size();
	std::vector<float> check{};
	EXPECT_EQ(check, triplet.find_triplet(TestVec, size, sum));

}