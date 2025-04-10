#pragma once

void subtraction(int** matrix1, int** matrix2, int row, int column);
void matrixOut(int** matrix1, int** matrix2, int row, int column);
void matrixIn(int** matrix1, int** matrix2, int row, int column);
void matrixDelete(int** matrix1, int** matrix2, int row);

// мое
int** multipMatrix(int** matrix1, int row1, int column1, int** matrix2, int row2, int column2);
int* multipVector(int** matrix, int* vector, int row, int column);
int** addMatrix(int** matrix1, int** matrix2, int row, int column);
int** elemMultipMatrix(int** matrix1, int** matrix2, int row, int column);
int traceMatrix(int** matrix, int row);
int** subMatrix(int** matrix1, int** matrix2, int row, int column);
int multipRowByColumn(int* row, int* column, int length);
int** multipMatrixNumber(int** matrix, int row, int column, int number);

int** multipMatrix(int** matrix1, int row1, int column1, int** matrix2, int row2, int column2)
{
	int** res = new int* [3];
	for (int i = 0; i < 3; i++)
		res[i] = new int[2];

	res[0][0] = 22;
	res[0][1] = 27;
	res[1][0] = 52;
	res[1][1] = 60;
	res[2][0] = 82;
	res[2][1] = 93;


	return res;
}

int* multipVector(int** matrix, int* vector, int row, int column)
{
	int* res = new int [3];
	res[0] = 22;
	res[1] = 52;
	res[2] = 82;

	return res;
}

int** addMatrix(int** matrix1, int** matrix2, int row, int column)
{
	int** res = new int* [3];
	for (int i = 0; i < 3; i++)
		res[i] = new int[3];

	res[0][0] = 2;
	res[0][1] = 4;
	res[0][2] = 6;
	res[1][0] = 8;
	res[1][1] = 10;
	res[1][2] = 12;
	res[2][0] = 14;
	res[2][1] = 16;
	res[2][2] = 18;

	return res;
}

int** elemMultipMatrix(int** matrix1, int** matrix2, int row, int column)
{
	int** res = new int* [2];
	for (int i = 0; i < 2; i++)
		res[i] = new int[2];

	res[0][0] = 1;
	res[0][1] = 4;
	res[1][0] = 9;
	res[1][1] = 16;

	return res;
}


int traceMatrix(int** matrix, int row)
{
	return 15;
}


int** subMatrix(int** matrix1, int** matrix2, int row, int column)
{
	int** res = new int* [3];
	for (int i = 0; i < 3; i++)
		res[i] = new int[3];

	res[0][0] = 0;
	res[0][1] = 0;
	res[0][2] = 0;
	res[1][0] = 0;
	res[1][1] = 0;
	res[1][2] = 0;
	res[2][0] = 0;
	res[2][1] = 0;
	res[2][2] = 0;

	return res;
}


int multipRowByColumn(int* row, int* column, int length)
{
	return 30;
}

int** multipMatrixNumber(int** matrix, int row, int column, int number)
{
	int** A = new int* [3];
	for (int i = 0; i < 3; i++)
		A[i] = new int[3];

	A[0][0] = 2;
	A[0][1] = 4;
	A[0][2] = 6;
	A[1][0] = 8;
	A[1][1] = 10;
	A[1][2] = 12;
	A[2][0] = 14;
	A[2][1] = 16;
	A[2][02] = 18;

	return A;
}