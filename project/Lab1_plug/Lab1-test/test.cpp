#include "pch.h"
#include "..\Lab1_plug\Source.h"

// minValueInt
TEST(TestCase_minValueInt, Test1) {
	int x = 10;
	int y = 20;
	int expected;

	expected = x;
	EXPECT_EQ(minValue((int)x, (int)y), expected);
}

TEST(TestCase_minValueInt, Test2) {
	int x = 20;
	int y = 10;
	int expected;

	expected = y;
	EXPECT_EQ(minValue((int)x, (int)y), expected);
}

TEST(TestCase_minValueInt, Test3) {
	int x = -10;
	int y = 10;
	int expected;

	expected = x;
	EXPECT_EQ(minValue((int)x, (int)y), expected);
}

// minValueFloat
TEST(TestCase_minValueFloat, Test1) {
	float x = 10.3;
	float y = 20.565;
	float expected;

	expected = x;
	EXPECT_EQ(minValue((float)x, (float)y), expected);
}

TEST(TestCase_minValueFloat, Test2) {
	float x = 20.1245;
	float y = 10;
	float expected;

	expected = y;
	EXPECT_EQ(minValue((float)x, (float)y), expected);
}

TEST(TestCase_minValueFloat, Test3) {
	float x = 10.2345;
	float y = 10.23;
	float expected;

	expected = y;
	EXPECT_EQ(minValue((float)x, (float)y), expected);
}

// belongsToInterval
TEST(TestCase_belongsToInterval, Test1) {
	int x = 10;
	int top = 20;
	int bottom = 0;
	bool expected;

	expected = true;
	EXPECT_EQ(belongsToInterval(x, top, bottom), expected);
}

TEST(TestCase_belongsToInterval, Test2) {
	int x = 10;
	int top = 0;
	int bottom = 20;
	bool expected;

	expected = false;
	EXPECT_EQ(belongsToInterval(x, top, bottom), expected);
}

TEST(TestCase_belongsToInterval, Test3) {
	int x = 10;
	int top = 10;
	int bottom = 10;
	bool expected;

	expected = true;
	EXPECT_EQ(belongsToInterval(x, top, bottom), expected);
}

TEST(TestCase_belongsToInterval, Test4) {
	int x = 10;
	int top = 10;
	int bottom = 0;
	bool expected;

	expected = true;
	EXPECT_EQ(belongsToInterval(x, top, bottom), expected);
}

TEST(TestCase_belongsToInterval, Test5) {
	int x = 10;
	int top = 20;
	int bottom = 10;
	bool expected;

	expected = true;
	EXPECT_EQ(belongsToInterval(x, top, bottom), expected);
}

// order
TEST(TestCase_order, Test1) {
	long long x = 9123495214543563453;
	short expected;

	expected = 19;
	EXPECT_EQ(order(x), expected);
}

TEST(TestCase_order, Test2) {
	long long x = 0;
	short expected;

	expected = 1;
	EXPECT_EQ(order(x), expected);
}

TEST(TestCase_order, Test3) {
	long long x = -9123495214543563453;
	short expected;

	expected = 19;
	EXPECT_EQ(order(x), expected);
}

// getLetterCode
TEST(TestCase_getLetterCode, Test1) {
	char c;
	int expected;

	for (int i = 0; i < 100; i++)
	{
		c = i;
		expected = (int)c;
		EXPECT_EQ(getLetterCode(c), expected);
		i++;
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}