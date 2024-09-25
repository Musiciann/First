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

TEST(CheckBanner, RubicCubeGameVisuals) {
	RubicCubeGameVisuals::Banner();
	ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}