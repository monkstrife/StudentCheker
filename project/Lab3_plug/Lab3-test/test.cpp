#include "pch.h"
#include "..\Lab3_plug\Point.h"
#include "..\Lab3_plug\Point.cpp"
#include "..\Lab3_plug\Triangle.h"
#include "..\Lab3_plug\Triangle.cpp"
#include "..\Lab3_plug\Rectangle.h"
#include "..\Lab3_plug\Rectangle.cpp"
#include "..\Lab3_plug\Rhomb.h"
#include "..\Lab3_plug\Rhomb.cpp"
#include "..\Lab3_plug\Square.h"
#include "..\Lab3_plug\Square.cpp"
#include "..\Lab3_plug\Trapeze.h"
#include "..\Lab3_plug\Trapeze.cpp"


// L
TEST(TestCase_L, Test1) {
	Point points[3];
	int size = 3;

	for (int i = 0; i < 3; i++)
	{
		points[i].SetPoint(i, i);
	}


	bool result = inLine(points, size);
	bool expected = true;

	EXPECT_EQ(expected, result);
}

TEST(TestCase_L, Test2) {
	Point points[5];
	int size = 5;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(1, 0);
	points[2].SetPoint(2, 0);
	points[3].SetPoint(3, 0);
	points[4].SetPoint(1, 0);

	int result = getPointsInLine(points, size);
	int expected = 4;

	EXPECT_EQ(expected, result);
}

TEST(TestCase_L, Test3) {
	Point points[5];
	int size = 5;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(1, 0);
	points[2].SetPoint(2, 0);
	points[3].SetPoint(3, 0);
	points[4].SetPoint(1, 0);

	int result = countLines(points, size);
	int expected = 4;

	EXPECT_EQ(expected, result);
}

TEST(TestCase_L, Test4) {
	Point points[6];
	int size = 6;
	Point p11;
	Point p12;
	Point p21;
	Point p22;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(1, 0);
	points[2].SetPoint(2, 0);
	points[3].SetPoint(3, 0);
	points[4].SetPoint(0, 1);
	points[5].SetPoint(3, 1);
	p11.SetPoint(0, 0);
	p12.SetPoint(0, 1);
	p21.SetPoint(3, 0);
	p22.SetPoint(3, 1);

	bool result = getParallelLines(points, size, p11, p12, p21, p22);
	bool expected = true;

	EXPECT_EQ(expected, result);
}


// P
TEST(TestCase_P, Test1) {
	Point points[5];
	int size = 5;
	int R = 1;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 2);
	points[2].SetPoint(0, 3);
	points[3].SetPoint(0, 4);
	points[4].SetPoint(0, 6);

	Point result = getMaxCirclePoint(points, size, R);
	Point expected;
	expected.SetPoint(0, 3);

	EXPECT_EQ(expected.GetX(), result.GetX());
	EXPECT_EQ(expected.GetY(), result.GetY());
}

TEST(TestCase_P, Test2) {
	Point points[5];
	int size = 5;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 1);
	points[2].SetPoint(0, 2);
	points[3].SetPoint(0, 3);
	points[4].SetPoint(0, 15);

	Point result = getFarestPoint(points, size);
	Point expected;
	expected.SetPoint(0, 15);

	EXPECT_EQ(expected.GetX(), result.GetX());
	EXPECT_EQ(expected.GetY(), result.GetY());
}

TEST(TestCase_P, Test3) {
	Point points[3];
	int size = 3;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 2);
	points[2].SetPoint(0, 3);

	Point result = getClosestPoint(points, size);
	Point expected;
	expected.SetPoint(0, 2);

	EXPECT_EQ(expected.GetX(), result.GetX());
	EXPECT_EQ(expected.GetY(), result.GetY());
}

TEST(TestCase_P, Test4) {
	Point points[5];
	int size = 5;
	int R = 2;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 1);
	points[2].SetPoint(0, 2);
	points[3].SetPoint(0, 3);
	points[4].SetPoint(0, 5);

	Point result = getMinCirclePoint(points, size, R);
	Point expected;
	expected.SetPoint(0, 5);

	EXPECT_EQ(expected.GetX(), result.GetX());
	EXPECT_EQ(expected.GetY(), result.GetY());
}

// Triangle
TEST(TestCase_Triangle, Test1) {
	Triangle triangles[3];
	int size = 3;

	triangles[0].SetTriangle(Point(0, 0), Point(0, 1), Point(1, 0));
	triangles[0].SetTriangle(Point(10, 0), Point(12, 0), Point(11, 6));
	triangles[0].SetTriangle(Point(3, 0), Point(3, 1), Point(4, 0));

	int result = getRectTriangles(triangles, size);
	int expected = 2;

	EXPECT_EQ(expected, result);
}

TEST(TestCase_Triangle, Test2) {
	Triangle triangles[3];
	int size = 3;

	triangles[0].SetTriangle(Point(0, 0), Point(0, 1), Point(1, 0));
	triangles[0].SetTriangle(Point(10, 0), Point(12, 0), Point(11, 6));
	triangles[0].SetTriangle(Point(3, 0), Point(3, 1), Point(4, 0));

	int result = getIsoscelesTriangles(triangles, size);
	int expected = 3;

	EXPECT_EQ(expected, result);
}

TEST(TestCase_Triangle, Test3) {
	Point points[4];
	int size = 4;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(9, 0);
	points[3].SetPoint(10, 0);

	Point* result = getMaxLengthTriangle(points, size);

	
	Point expected[3];
	expected[0].SetPoint(0, 0);
	expected[1].SetPoint(0, 5);
	expected[2].SetPoint(10, 0);

	EXPECT_EQ(expected[0].GetX(), result[0].GetX());
	EXPECT_EQ(expected[0].GetY(), result[0].GetY());

	EXPECT_EQ(expected[1].GetX(), result[1].GetX());
	EXPECT_EQ(expected[1].GetY(), result[1].GetY());

	EXPECT_EQ(expected[2].GetX(), result[2].GetX());
	EXPECT_EQ(expected[2].GetY(), result[2].GetY());
}

TEST(TestCase_Triangle, Test4) {
	Point points[4];
	int size = 4;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(9, 0);
	points[3].SetPoint(100, 0);

	Point* result = getMinLengthTriangle(points, size);


	Point expected[3];
	expected[0].SetPoint(0, 0);
	expected[1].SetPoint(0, 5);
	expected[2].SetPoint(9, 0);

	EXPECT_EQ(expected[0].GetX(), result[0].GetX());
	EXPECT_EQ(expected[0].GetY(), result[0].GetY());

	EXPECT_EQ(expected[1].GetX(), result[1].GetX());
	EXPECT_EQ(expected[1].GetY(), result[1].GetY());

	EXPECT_EQ(expected[2].GetX(), result[2].GetX());
	EXPECT_EQ(expected[2].GetY(), result[2].GetY());
}

// Rect

TEST(TestCase_Rect, Test1) {
	Point points[9];
	int size = 9;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(0, 10);
	points[3].SetPoint(5, 0);
	points[4].SetPoint(5, 5);
	points[5].SetPoint(5, 10);
	points[6].SetPoint(10, 0);
	points[7].SetPoint(10, 5);
	points[8].SetPoint(10, 10);

	Rectangle* result = getMaxRectangle(points, size);

	Rectangle expected[1];
	expected[0].SetRectangle(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));

	
	EXPECT_EQ(expected[0].GetP1().GetX(), result[0].GetP1().GetX());
	EXPECT_EQ(expected[0].GetP1().GetY(), result[0].GetP1().GetY());

	EXPECT_EQ(expected[0].GetP2().GetX(), result[0].GetP2().GetX());
	EXPECT_EQ(expected[0].GetP2().GetY(), result[0].GetP2().GetY());

	EXPECT_EQ(expected[0].GetP3().GetX(), result[0].GetP3().GetX());
	EXPECT_EQ(expected[0].GetP3().GetY(), result[0].GetP3().GetY());

	EXPECT_EQ(expected[0].GetP4().GetX(), result[0].GetP4().GetX());
	EXPECT_EQ(expected[0].GetP4().GetY(), result[0].GetP4().GetY());
}

TEST(TestCase_Rect, Test2) {
	Point points[4];
	int size = 4;
	Rectangle rect;
	Rectangle &rectRef = rect;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 10);
	points[2].SetPoint(10, 0);
	points[3].SetPoint(10, 10);

	bool result = getRectangle(points, rectRef);

	bool expected = true;
	Rectangle rectExpected = Rectangle(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected, result);

	EXPECT_EQ(rectExpected.GetP1().GetX(), rect.GetP1().GetX());
	EXPECT_EQ(rectExpected.GetP1().GetY(), rect.GetP1().GetY());

	EXPECT_EQ(rectExpected.GetP2().GetX(), rect.GetP2().GetX());
	EXPECT_EQ(rectExpected.GetP2().GetY(), rect.GetP2().GetY());

	EXPECT_EQ(rectExpected.GetP3().GetX(), rect.GetP3().GetX());
	EXPECT_EQ(rectExpected.GetP3().GetY(), rect.GetP3().GetY());

	EXPECT_EQ(rectExpected.GetP4().GetX(), rect.GetP4().GetX());
	EXPECT_EQ(rectExpected.GetP4().GetY(), rect.GetP4().GetY());
}

TEST(TestCase_Rect, Test3) {
	Rectangle rects[3];
	int size = 3;
	Rectangle r1;
	Rectangle r2;

	Rectangle& r1Ref = r1;
	Rectangle& r2Ref = r2;

	rects[0].SetRectangle(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	rects[1].SetRectangle(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));
	rects[2].SetRectangle(Point(100, 0), Point(103, 0), Point(103, 3), Point(103, 0));

	getClosestRectangles(rects,size, r1Ref, r2Ref);

	Rectangle expectedR1 = Rectangle(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	Rectangle expectedR2 = Rectangle(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));


	EXPECT_EQ(expectedR1.GetP1().GetX(), r1.GetP1().GetX());
	EXPECT_EQ(expectedR1.GetP1().GetY(), r1.GetP1().GetY());

	EXPECT_EQ(expectedR1.GetP2().GetX(), r1.GetP2().GetX());
	EXPECT_EQ(expectedR1.GetP2().GetY(), r1.GetP2().GetY());

	EXPECT_EQ(expectedR1.GetP3().GetX(), r1.GetP3().GetX());
	EXPECT_EQ(expectedR1.GetP3().GetY(), r1.GetP3().GetY());

	EXPECT_EQ(expectedR1.GetP4().GetX(), r1.GetP4().GetX());
	EXPECT_EQ(expectedR1.GetP4().GetY(), r1.GetP4().GetY());

	EXPECT_EQ(expectedR2.GetP1().GetX(), r2.GetP1().GetX());
	EXPECT_EQ(expectedR2.GetP1().GetY(), r2.GetP1().GetY());

	EXPECT_EQ(expectedR2.GetP2().GetX(), r2.GetP2().GetX());
	EXPECT_EQ(expectedR2.GetP2().GetY(), r2.GetP2().GetY());

	EXPECT_EQ(expectedR2.GetP3().GetX(), r2.GetP3().GetX());
	EXPECT_EQ(expectedR2.GetP3().GetY(), r2.GetP3().GetY());

	EXPECT_EQ(expectedR2.GetP4().GetX(), r2.GetP4().GetX());
	EXPECT_EQ(expectedR2.GetP4().GetY(), r2.GetP4().GetY());
}

TEST(TestCase_Rect, Test4) {
	Rectangle f1 = Rectangle(Point(0, 0), Point(10, 0), Point(10, 10), Point(10, 0));
	Rectangle f2 = Rectangle(Point(5, 5), Point(15, 5), Point(15, 15), Point(15, 5));

	Rectangle& f1Ref = f1;
	Rectangle& f2Ref = f2;

	bool result = checkRectangleCrossing(f1Ref, f2Ref);

	bool expected = true;

	EXPECT_EQ(expected, result);

}

// Rhomb

TEST(TestCase_Rhomb, Test1) {
	Point points[9];
	int size = 9;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(0, 10);
	points[3].SetPoint(5, 0);
	points[4].SetPoint(5, 5);
	points[5].SetPoint(5, 10);
	points[6].SetPoint(10, 0);
	points[7].SetPoint(10, 5);
	points[8].SetPoint(10, 10);

	Rhomb* result = getMaxRhomb(points, size);

	Rhomb expected[1];
	expected[0].SetRhomb(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected[0].GetP1().GetX(), result[0].GetP1().GetX());
	EXPECT_EQ(expected[0].GetP1().GetY(), result[0].GetP1().GetY());

	EXPECT_EQ(expected[0].GetP2().GetX(), result[0].GetP2().GetX());
	EXPECT_EQ(expected[0].GetP2().GetY(), result[0].GetP2().GetY());

	EXPECT_EQ(expected[0].GetP3().GetX(), result[0].GetP3().GetX());
	EXPECT_EQ(expected[0].GetP3().GetY(), result[0].GetP3().GetY());

	EXPECT_EQ(expected[0].GetP4().GetX(), result[0].GetP4().GetX());
	EXPECT_EQ(expected[0].GetP4().GetY(), result[0].GetP4().GetY());
}

TEST(TestCase_Rhomb, Test2) {
	Point points[4];
	int size = 4;
	Rhomb rect;
	Rhomb& rectRef = rect;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 10);
	points[2].SetPoint(10, 0);
	points[3].SetPoint(10, 10);

	bool result = getRhomb(points, rectRef);

	bool expected = true;
	Rhomb rectExpected = Rhomb(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected, result);

	EXPECT_EQ(rectExpected.GetP1().GetX(), rect.GetP1().GetX());
	EXPECT_EQ(rectExpected.GetP1().GetY(), rect.GetP1().GetY());

	EXPECT_EQ(rectExpected.GetP2().GetX(), rect.GetP2().GetX());
	EXPECT_EQ(rectExpected.GetP2().GetY(), rect.GetP2().GetY());

	EXPECT_EQ(rectExpected.GetP3().GetX(), rect.GetP3().GetX());
	EXPECT_EQ(rectExpected.GetP3().GetY(), rect.GetP3().GetY());

	EXPECT_EQ(rectExpected.GetP4().GetX(), rect.GetP4().GetX());
	EXPECT_EQ(rectExpected.GetP4().GetY(), rect.GetP4().GetY());
}

TEST(TestCase_Rhomb, Test3) {
	Rhomb rects[3];
	int size = 3;
	Rhomb r1;
	Rhomb r2;

	Rhomb& r1Ref = r1;
	Rhomb& r2Ref = r2;

	rects[0].SetRhomb(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	rects[1].SetRhomb(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));
	rects[2].SetRhomb(Point(100, 0), Point(103, 0), Point(103, 3), Point(103, 0));

	getClosestRhombs(rects, size, r1Ref, r2Ref);

	Rhomb expectedR1 = Rhomb(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	Rhomb expectedR2 = Rhomb(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));


	EXPECT_EQ(expectedR1.GetP1().GetX(), r1.GetP1().GetX());
	EXPECT_EQ(expectedR1.GetP1().GetY(), r1.GetP1().GetY());

	EXPECT_EQ(expectedR1.GetP2().GetX(), r1.GetP2().GetX());
	EXPECT_EQ(expectedR1.GetP2().GetY(), r1.GetP2().GetY());

	EXPECT_EQ(expectedR1.GetP3().GetX(), r1.GetP3().GetX());
	EXPECT_EQ(expectedR1.GetP3().GetY(), r1.GetP3().GetY());

	EXPECT_EQ(expectedR1.GetP4().GetX(), r1.GetP4().GetX());
	EXPECT_EQ(expectedR1.GetP4().GetY(), r1.GetP4().GetY());

	EXPECT_EQ(expectedR2.GetP1().GetX(), r2.GetP1().GetX());
	EXPECT_EQ(expectedR2.GetP1().GetY(), r2.GetP1().GetY());

	EXPECT_EQ(expectedR2.GetP2().GetX(), r2.GetP2().GetX());
	EXPECT_EQ(expectedR2.GetP2().GetY(), r2.GetP2().GetY());

	EXPECT_EQ(expectedR2.GetP3().GetX(), r2.GetP3().GetX());
	EXPECT_EQ(expectedR2.GetP3().GetY(), r2.GetP3().GetY());

	EXPECT_EQ(expectedR2.GetP4().GetX(), r2.GetP4().GetX());
	EXPECT_EQ(expectedR2.GetP4().GetY(), r2.GetP4().GetY());
}

TEST(TestCase_Rhomb, Test4) {
	Rhomb f1 = Rhomb(Point(0, 0), Point(10, 0), Point(10, 10), Point(10, 0));
	Rhomb f2 = Rhomb(Point(5, 5), Point(15, 5), Point(15, 15), Point(15, 5));

	Rhomb& f1Ref = f1;
	Rhomb& f2Ref = f2;

	bool result = checkRhombCrossing(f1Ref, f2Ref);

	bool expected = true;

	EXPECT_EQ(expected, result);

}

// Square

TEST(TestCase_Square, Test1) {
	Point points[9];
	int size = 9;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(0, 10);
	points[3].SetPoint(5, 0);
	points[4].SetPoint(5, 5);
	points[5].SetPoint(5, 10);
	points[6].SetPoint(10, 0);
	points[7].SetPoint(10, 5);
	points[8].SetPoint(10, 10);

	Square* result = getMaxSquare(points, size);

	Square expected[1];
	expected[0].SetSquare(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected[0].GetP1().GetX(), result[0].GetP1().GetX());
	EXPECT_EQ(expected[0].GetP1().GetY(), result[0].GetP1().GetY());

	EXPECT_EQ(expected[0].GetP2().GetX(), result[0].GetP2().GetX());
	EXPECT_EQ(expected[0].GetP2().GetY(), result[0].GetP2().GetY());

	EXPECT_EQ(expected[0].GetP3().GetX(), result[0].GetP3().GetX());
	EXPECT_EQ(expected[0].GetP3().GetY(), result[0].GetP3().GetY());

	EXPECT_EQ(expected[0].GetP4().GetX(), result[0].GetP4().GetX());
	EXPECT_EQ(expected[0].GetP4().GetY(), result[0].GetP4().GetY());
}

TEST(TestCase_Square, Test2) {
	Point points[4];
	int size = 4;
	Square rect;
	Square& rectRef = rect;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 10);
	points[2].SetPoint(10, 0);
	points[3].SetPoint(10, 10);

	bool result = getSquare(points, rectRef);

	bool expected = true;
	Square rectExpected = Square(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected, result);

	EXPECT_EQ(rectExpected.GetP1().GetX(), rect.GetP1().GetX());
	EXPECT_EQ(rectExpected.GetP1().GetY(), rect.GetP1().GetY());

	EXPECT_EQ(rectExpected.GetP2().GetX(), rect.GetP2().GetX());
	EXPECT_EQ(rectExpected.GetP2().GetY(), rect.GetP2().GetY());

	EXPECT_EQ(rectExpected.GetP3().GetX(), rect.GetP3().GetX());
	EXPECT_EQ(rectExpected.GetP3().GetY(), rect.GetP3().GetY());

	EXPECT_EQ(rectExpected.GetP4().GetX(), rect.GetP4().GetX());
	EXPECT_EQ(rectExpected.GetP4().GetY(), rect.GetP4().GetY());
}

TEST(TestCase_Square, Test3) {
	Square rects[3];
	int size = 3;
	Square r1;
	Square r2;

	Square& r1Ref = r1;
	Square& r2Ref = r2;

	rects[0].SetSquare(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	rects[1].SetSquare(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));
	rects[2].SetSquare(Point(100, 0), Point(103, 0), Point(103, 3), Point(103, 0));

	getClosestSquares(rects, size, r1Ref, r2Ref);

	Square expectedR1 = Square(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	Square expectedR2 = Square(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));


	EXPECT_EQ(expectedR1.GetP1().GetX(), r1.GetP1().GetX());
	EXPECT_EQ(expectedR1.GetP1().GetY(), r1.GetP1().GetY());

	EXPECT_EQ(expectedR1.GetP2().GetX(), r1.GetP2().GetX());
	EXPECT_EQ(expectedR1.GetP2().GetY(), r1.GetP2().GetY());

	EXPECT_EQ(expectedR1.GetP3().GetX(), r1.GetP3().GetX());
	EXPECT_EQ(expectedR1.GetP3().GetY(), r1.GetP3().GetY());

	EXPECT_EQ(expectedR1.GetP4().GetX(), r1.GetP4().GetX());
	EXPECT_EQ(expectedR1.GetP4().GetY(), r1.GetP4().GetY());

	EXPECT_EQ(expectedR2.GetP1().GetX(), r2.GetP1().GetX());
	EXPECT_EQ(expectedR2.GetP1().GetY(), r2.GetP1().GetY());

	EXPECT_EQ(expectedR2.GetP2().GetX(), r2.GetP2().GetX());
	EXPECT_EQ(expectedR2.GetP2().GetY(), r2.GetP2().GetY());

	EXPECT_EQ(expectedR2.GetP3().GetX(), r2.GetP3().GetX());
	EXPECT_EQ(expectedR2.GetP3().GetY(), r2.GetP3().GetY());

	EXPECT_EQ(expectedR2.GetP4().GetX(), r2.GetP4().GetX());
	EXPECT_EQ(expectedR2.GetP4().GetY(), r2.GetP4().GetY());
}

TEST(TestCase_Square, Test4) {
	Square f1 = Square(Point(0, 0), Point(10, 0), Point(10, 10), Point(10, 0));
	Square f2 = Square(Point(5, 5), Point(15, 5), Point(15, 15), Point(15, 5));

	Square& f1Ref = f1;
	Square& f2Ref = f2;

	bool result = checkSquareCrossing(f1Ref, f2Ref);

	bool expected = true;

	EXPECT_EQ(expected, result);

}

// Trapeze

TEST(TestCase_Trapeze, Test1) {
	Point points[9];
	int size = 9;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 5);
	points[2].SetPoint(0, 10);
	points[3].SetPoint(5, 0);
	points[4].SetPoint(5, 5);
	points[5].SetPoint(5, 10);
	points[6].SetPoint(10, 0);
	points[7].SetPoint(10, 5);
	points[8].SetPoint(10, 10);

	Trapeze* result = getMaxTrapeze(points, size);

	Trapeze expected[1];
	expected[0].SetTrapeze(Point(0, 0), Point(0, 10), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected[0].GetP1().GetX(), result[0].GetP1().GetX());
	EXPECT_EQ(expected[0].GetP1().GetY(), result[0].GetP1().GetY());

	EXPECT_EQ(expected[0].GetP2().GetX(), result[0].GetP2().GetX());
	EXPECT_EQ(expected[0].GetP2().GetY(), result[0].GetP2().GetY());

	EXPECT_EQ(expected[0].GetP3().GetX(), result[0].GetP3().GetX());
	EXPECT_EQ(expected[0].GetP3().GetY(), result[0].GetP3().GetY());

	EXPECT_EQ(expected[0].GetP4().GetX(), result[0].GetP4().GetX());
	EXPECT_EQ(expected[0].GetP4().GetY(), result[0].GetP4().GetY());
}

TEST(TestCase_Trapeze, Test2) {
	Point points[4];
	int size = 4;
	Trapeze rect;
	Trapeze& rectRef = rect;

	points[0].SetPoint(0, 0);
	points[1].SetPoint(0, 10);
	points[2].SetPoint(10, 0);
	points[3].SetPoint(10, 10);

	bool result = getTrapeze(points, rectRef);

	bool expected = true;
	Trapeze rectExpected = Trapeze(Point(0, 0), Point(10, 0), Point(10, 10), Point(0, 10));


	EXPECT_EQ(expected, result);

	EXPECT_EQ(rectExpected.GetP1().GetX(), rect.GetP1().GetX());
	EXPECT_EQ(rectExpected.GetP1().GetY(), rect.GetP1().GetY());

	EXPECT_EQ(rectExpected.GetP2().GetX(), rect.GetP2().GetX());
	EXPECT_EQ(rectExpected.GetP2().GetY(), rect.GetP2().GetY());

	EXPECT_EQ(rectExpected.GetP3().GetX(), rect.GetP3().GetX());
	EXPECT_EQ(rectExpected.GetP3().GetY(), rect.GetP3().GetY());

	EXPECT_EQ(rectExpected.GetP4().GetX(), rect.GetP4().GetX());
	EXPECT_EQ(rectExpected.GetP4().GetY(), rect.GetP4().GetY());
}

TEST(TestCase_Trapeze, Test3) {
	Trapeze rects[3];
	int size = 3;
	Trapeze r1;
	Trapeze r2;

	Trapeze& r1Ref = r1;
	Trapeze& r2Ref = r2;

	rects[0].SetTrapeze(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	rects[1].SetTrapeze(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));
	rects[2].SetTrapeze(Point(100, 0), Point(103, 0), Point(103, 3), Point(103, 0));

	getClosestTrapezes(rects, size, r1Ref, r2Ref);

	Trapeze expectedR1 = Trapeze(Point(0, 0), Point(3, 0), Point(3, 3), Point(3, 0));
	Trapeze expectedR2 = Trapeze(Point(10, 0), Point(13, 0), Point(13, 3), Point(13, 0));


	EXPECT_EQ(expectedR1.GetP1().GetX(), r1.GetP1().GetX());
	EXPECT_EQ(expectedR1.GetP1().GetY(), r1.GetP1().GetY());

	EXPECT_EQ(expectedR1.GetP2().GetX(), r1.GetP2().GetX());
	EXPECT_EQ(expectedR1.GetP2().GetY(), r1.GetP2().GetY());

	EXPECT_EQ(expectedR1.GetP3().GetX(), r1.GetP3().GetX());
	EXPECT_EQ(expectedR1.GetP3().GetY(), r1.GetP3().GetY());

	EXPECT_EQ(expectedR1.GetP4().GetX(), r1.GetP4().GetX());
	EXPECT_EQ(expectedR1.GetP4().GetY(), r1.GetP4().GetY());

	EXPECT_EQ(expectedR2.GetP1().GetX(), r2.GetP1().GetX());
	EXPECT_EQ(expectedR2.GetP1().GetY(), r2.GetP1().GetY());

	EXPECT_EQ(expectedR2.GetP2().GetX(), r2.GetP2().GetX());
	EXPECT_EQ(expectedR2.GetP2().GetY(), r2.GetP2().GetY());

	EXPECT_EQ(expectedR2.GetP3().GetX(), r2.GetP3().GetX());
	EXPECT_EQ(expectedR2.GetP3().GetY(), r2.GetP3().GetY());

	EXPECT_EQ(expectedR2.GetP4().GetX(), r2.GetP4().GetX());
	EXPECT_EQ(expectedR2.GetP4().GetY(), r2.GetP4().GetY());
}

TEST(TestCase_Trapeze, Test4) {
	Trapeze f1 = Trapeze(Point(0, 0), Point(10, 0), Point(10, 10), Point(10, 0));
	Trapeze f2 = Trapeze(Point(5, 5), Point(15, 5), Point(15, 15), Point(15, 5));

	Trapeze& f1Ref = f1;
	Trapeze& f2Ref = f2;

	bool result = checkTrapezeCrossing(f1Ref, f2Ref);

	bool expected = true;

	EXPECT_EQ(expected, result);

}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}