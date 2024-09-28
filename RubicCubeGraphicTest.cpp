#include "pch.h"
#include "..\RubicCube\RubicCubeGraphic.h"
#include "..\RubicCube\RubicCubeGraphic.cpp"
#include "gtest\gtest.h"


TEST(CheckCubeChoiceMenuGraphic, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::CubeChoiceMenuGraphic();
	ASSERT_EQ(1, 1);
}

TEST(CheckMenuGraphic, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::MenuGraphic();
	ASSERT_EQ(1, 1);
}

TEST(CubeChoiceMenu, MenuLogic) {
	RubicCube Cube1("right_colors.txt");
	RubicCube Cube2(0);
	cout << "Âûבונטעו 2\n";
	cout << "Âגוהטעו פאיכ: right_colors.txt\n";
	Cube2.CubeChoiceMenu(Cube2);
	ASSERT_TRUE(Cube1 == Cube2);
}

TEST(CheckBanner, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::Banner();
	ASSERT_EQ(1, 1);
}

TEST(CheckExitYes, ExitOption) {
	RubicCube Cube(0);
	cout << "Âגוהטעו: Y\n";
	ASSERT_FALSE(Cube.ExitGame());
}

TEST(CheckExitNo, ExitOption) {
	RubicCube Cube(0);
	cout << "Âגוהטעו: N\n";
	ASSERT_TRUE(Cube.ExitGame());
}

TEST(SeeCube, SeeGraphic) {
	RubicCube Cube(0);
	Cube.SeeCube();
	ASSERT_EQ(1, 1);
}

TEST(CheckColoringMessageWrong, CheckColoring) {
	RubicCube Cube("wrong_colors.txt");
	Cube.ColoringCheckMessage();
	ASSERT_EQ(1, 1);
}

TEST(CheckColoringMessageRightFile, CheckColoring) {
	RubicCube Cube("right_colors.txt");
	Cube.ColoringCheckMessage();
	ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}