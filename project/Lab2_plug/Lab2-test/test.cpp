#include "pch.h"
#include "..\Lab2_plug\Source.h"


// V0
TEST(TestCase_V0, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;

	int** B = new int* [3];
	for (int i = 0; i < 3; i++)
		B[i] = new int[3];

	B[0][0] = 3;
	B[0][0] = 1;
	B[0][0] = 2;
	B[0][0] = 4;
	B[0][0] = 5;
	B[0][0] = 6;

	int** result = multipMatrix(A, 3, 3, B, 3, 2);

	int expend[3][2] =
	{
		{22, 27},
		{52, 60},
		{82, 93}
	};


	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 2; y++)
		{
			EXPECT_EQ(expend[i][y], result[i][y]);
		}
	}
}

// V1
TEST(TestCase_V1, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;

	int* B = new int [3];

	B[0] = 3;
	B[1] = 2;
	B[2] = 5;

	int* result = multipVector(A, B, 3, 3);

	int expend[3] = { 22, 52, 82 };


	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(expend[i], result[i]);
	}
}

// V2
TEST(TestCase_V2, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;

	int** B = new int* [3];
	for (int i = 0; i < 3; i++)
		B[i] = new int[3];

	B[0][0] = 1;
	B[0][1] = 2;
	B[0][2] = 3;
	B[1][0] = 4;
	B[1][1] = 5;
	B[1][2] = 6;
	B[2][0] = 7;
	B[2][1] = 8;
	B[2][02] = 9;

	int** result = addMatrix(A, B, 3, 3);

	int expend[3][3] =
	{
		{2, 4, 6},
		{8, 10, 12},
		{14, 16, 18}
	};


	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			EXPECT_EQ(expend[i][y], result[i][y]);
		}
	}
}

// V3
TEST(TestCase_V3, Test1) {
	int** A = new int* [2];
	for (int i = 0; i < 2; i++)
		A[i] = new int[2];

	A[0][0] = 1;
	A[0][1] = 2;
	A[1][0] = 3;
	A[1][1] = 4;

	int** B = new int* [2];
	for (int i = 0; i < 2; i++)
		B[i] = new int[2];

	B[0][0] = 1;
	B[0][1] = 2;
	B[1][0] = 3;
	B[1][1] = 4;

	int** result = elemMultipMatrix(A, B, 2, 2);

	int expend[3][3] =
	{
		{1, 4},
		{9, 16}
	};


	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < 2; y++)
		{
			EXPECT_EQ(expend[i][y], result[i][y]);
		}
	}
}

// V4
TEST(TestCase_V4, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;


	int result = traceMatrix(A, 3);

	int expend = 15;


	EXPECT_EQ(expend, result);
}

// V5
TEST(TestCase_V5, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;

	int** B = new int* [3];
	for (int i = 0; i < 3; i++)
		B[i] = new int[3];

	B[0][0] = 1;
	B[0][1] = 2;
	B[0][2] = 3;
	B[1][0] = 4;
	B[1][1] = 5;
	B[1][2] = 6;
	B[2][0] = 7;
	B[2][1] = 8;
	B[2][02] = 9;

	int** result = subMatrix(A, B, 3, 3);

	int expend[3][3] =
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};


	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			EXPECT_EQ(expend[i][y], result[i][y]);
		}
	}
}

// V6
TEST(TestCase_V6, Test1) {
	int* A = new int[3];

	A[0] = 1;
	A[1] = 2;
	A[2] = 3;

	int* B = new int[3];

	B[0] = 1;
	B[1] = 4;
	B[2] = 7;

	int result = multipRowByColumn(A, B, 3);

	int expend = 30;

	EXPECT_EQ(expend, result);
}

// V7
TEST(TestCase_V7, Test1) {
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][02] = 9;

	
	int** result = multipMatrixNumber(A, 3, 3, 2);

	int expend[3][3] =
	{
		{2, 4, 6},
		{8, 10, 12},
		{14, 16, 18}
	};


	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			EXPECT_EQ(expend[i][y], result[i][y]);
		}
	}
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}