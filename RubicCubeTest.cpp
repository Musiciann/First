#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\pch.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCube.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCubeGraphic.cpp"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCubeGraphic.h"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\RubicCube.cpp"
#include "C:\Users\Максим\source\repos\RubicCube\RubicCube\gtest.h"

using namespace std;

TEST(CheckColoringMessageRight, CheckColoring) {
	RubicCube Cube(0);
	Cube.ColoringCheckMessage();
	ASSERT_EQ(1, 1);
}

TEST(CheckBasicCubeColoring, CheckColoring) {
	RubicCube Cube(0);
	ASSERT_TRUE(Cube.CheckColoring());
}

TEST(CheckRandomRotationCubeColoring, CheckColoring) {
	RubicCube Cube(3);
	ASSERT_TRUE(Cube.CheckColoring());
}

TEST(CheckWrongCubeColoringFromFile, CheckColoring) {
	RubicCube Cube("wrong_colors.txt");
	ASSERT_FALSE(Cube.CheckColoring());
}

TEST(CheckWrongCubeColoringCorners, CheckColoring) {
	RubicCube Cube("wrong_corners.txt");
	ASSERT_FALSE(Cube.CheckColoring());
}

TEST(CheckWrongCubeColoringEdges, CheckColoring) {
	RubicCube Cube("wrong_edges.txt");
	ASSERT_FALSE(Cube.CheckColoring());
}

TEST(CheckWrongCubeColoringNearCorners, CheckColoring) {
	RubicCube Cube("wrong_near_corners.txt");
	ASSERT_FALSE(Cube.CheckColoring());
}

TEST(CheckWrongCubeColoringNearEdges, CheckColoring) {
	RubicCube Cube("wrong_near_edges.txt");
	ASSERT_FALSE(Cube.CheckColoring());
}

TEST(CheckRightCubeColoringFromFile, CheckColoring) {
	RubicCube Cube("right_colors.txt");
	ASSERT_TRUE(Cube.CheckColoring());
}

TEST(Equality, Operators) {
	RubicCube Cube1(0);
	RubicCube Cube2(0);
	ASSERT_TRUE(Cube1==Cube2);
}

TEST(Inequality, Operators) {
	RubicCube Cube1(0);
	RubicCube Cube2(2);
	ASSERT_TRUE(Cube1!= Cube2);
}

TEST(Assignment, Operators) {
	RubicCube Cube1(2);
	RubicCube Cube2(0);
	Cube1 = Cube2;
	ASSERT_TRUE(Cube1==Cube2);
}



int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}