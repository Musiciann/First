#include <iostream>
#include "..\RubicCube\RubicCubeGraphic.h"
#include "..\RubicCube\RubicCube.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	RubicCube Cube(0);
	
	Cube.CubeChoiceMenu(Cube);
	Cube.CubeGameMenu();


	return 0;
}