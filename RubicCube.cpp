#include <iostream>
#include <string>
#include <fstream>
#include "..\RubicCube\RubicCubeGraphic.h"
#include "..\RubicCube\RubicCube.h"

/*!
\file
\brief ���� c ��������� ������� ������

���� �������� � ���� �������� ���������� ������� ������ RubicCube, �����������
��� ���������� ����������� � ������ ����.
*/

const char Colors[6] = { 'R','G','B','Y','W','O' };

char Cube[6][3][3];

void RubicCube::Colorize() {
		char ColorsAll[54];
		for (int face = 0; face < 6; face++) {
			for (int tile = 0; tile < 9; tile++) {
				ColorsAll[face * 9 + tile] = Colors[face];
			}
		}
		int Counter = 0;
		for (int face = 0; face < 6; face++) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++) {
					Cube[face][row][col] = ColorsAll[Counter];
					Counter++;
				}
			}
		}
	};

	//������� �� ������� �������
	void RubicCube::RotateFace(int FaceNumber) {
		//���������� ���� ������� ������� � ���� �����
		char temp_corner_edge[2];
		for (int tile = 0; tile < 2; tile++) {
			temp_corner_edge[tile] = Cube[FaceNumber][0][tile];
		}
		//������������ ������� ����� 
		Cube[FaceNumber][0][0] = Cube[FaceNumber][2][0];
		Cube[FaceNumber][2][0] = Cube[FaceNumber][2][2];
		Cube[FaceNumber][2][2] = Cube[FaceNumber][0][2];
		Cube[FaceNumber][0][2] = temp_corner_edge[0];
		//������������ ������� ����
		Cube[FaceNumber][0][1] = Cube[FaceNumber][1][0];
		Cube[FaceNumber][1][0] = Cube[FaceNumber][2][1];
		Cube[FaceNumber][2][1] = Cube[FaceNumber][1][2];
		Cube[FaceNumber][1][2] = temp_corner_edge[1];
	};

	void RubicCube::RotateNearFrontFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[1][tile][2];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[1][tile][2] = Cube[4][0][tile];
			Cube[4][0][tile] = Cube[2][tile][0];
			Cube[2][tile][0] = Cube[3][2][tile];
			Cube[3][2][tile] = temp_side[tile];
		}
	}

	void RubicCube::RotateNearLeftFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[3][tile][0];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[3][tile][0] = Cube[5][tile][0];
			Cube[5][tile][0] = Cube[4][tile][0];
			Cube[4][tile][0] = Cube[0][tile][0];
			Cube[0][tile][0] = temp_side[tile];
		}
	}

	void RubicCube::RotateNearRightFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[0][tile][2];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[0][tile][2] = Cube[4][tile][2];
			Cube[4][tile][2] = Cube[5][tile][2];
			Cube[5][tile][2] = Cube[3][tile][2];
			Cube[3][tile][2] = temp_side[tile];
		}
	}

	void RubicCube::RotateNearUpFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[0][2][tile];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[0][2][tile] = Cube[1][2][tile];
			Cube[1][2][tile] = Cube[5][0][tile];
			Cube[5][0][tile] = Cube[2][2][tile];
			Cube[2][2][tile] = temp_side[tile];
		}
	}

	void RubicCube::RotateNearDownFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[0][0][tile];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[0][0][tile] = Cube[2][0][tile];
			Cube[2][0][tile] = Cube[5][2][tile];
			Cube[5][2][tile] = Cube[1][0][tile];
			Cube[1][0][tile] = temp_side[tile];
		}
	}

	void RubicCube::RotateNearBackFace() {
		char temp_side[3];
		for (int tile = 0; tile < 3; tile++) {
			temp_side[tile] = Cube[1][tile][0];
		}
		for (int tile = 0; tile < 3; tile++) {
			Cube[1][tile][0] = Cube[3][0][tile];
			Cube[3][0][tile] = Cube[2][tile][2];
			Cube[2][tile][2] = Cube[4][2][tile];
			Cube[4][2][tile] = temp_side[tile];
		}
	}

	bool RubicCube::CheckCentresColoring() {
		for (int face = 0; face < 6; face++) {
			for (int check_face = 0; check_face < 6; check_face++) {
				if (face == check_face) {
					continue;
				}
				else {
					if (Cube[face][1][1] == Cube[check_face][1][1]) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool RubicCube::CheckCornersColoringCount() {
		for (int Color = 0; Color < 6; Color++) {
			int Counter = 0;
			for (int face = 0; face < 6; face++) {
				if (Cube[face][0][0] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][0][2] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][2][0] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][2][2] == Colors[Color]) {
					Counter++;
				}
			}
			if (Counter > 4) {
				return false;
			}
		}
		return true;
	}

	bool RubicCube::CheckEdgesColoringCount() {
		for (int Color = 0; Color < 6; Color++) {
			int Counter = 0;
			for (int face = 0; face < 6; face++) {
				if (Cube[face][0][1] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][1][0] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][1][2] == Colors[Color]) {
					Counter++;
				}
				if (Cube[face][2][1] == Colors[Color]) {
					Counter++;
				}
			}
			if (Counter > 4) {
				return false;
			}
		}
		return true;
	}


	bool RubicCube::CheckNearCornersColoring() {
		if (Cube[0][0][0] == Cube[3][2][0] || Cube[0][0][0] == Cube[1][0][2] || Cube[3][2][0] == Cube[1][0][2]) {
			return false;
		}
		else if (Cube[0][0][2] == Cube[3][2][2] || Cube[0][0][2] == Cube[2][0][0] || Cube[2][0][0] == Cube[3][2][2]) {
			return false;
		}
		else if (Cube[0][2][0] == Cube[4][0][0] || Cube[0][2][0] == Cube[1][2][2] || Cube[1][2][2] == Cube[4][0][0]) {
			return false;
		}
		else if (Cube[0][2][2] == Cube[4][0][2] || Cube[0][2][2] == Cube[2][2][0] || Cube[0][2][2] == Cube[4][0][2]) {
			return false;
		}
		else if (Cube[5][2][0] == Cube[1][0][0] || Cube[5][2][0] == Cube[3][0][0] || Cube[2][0][0] == Cube[1][0][0]) {
			return false;
		}
		else if (Cube[5][2][2] == Cube[3][0][2] || Cube[5][2][2] == Cube[2][0][2] || Cube[2][0][2] == Cube[3][0][2]) {
			return false;
		}
		else if (Cube[5][0][0] == Cube[4][2][0] || Cube[5][0][0] == Cube[1][2][0] || Cube[1][2][0] == Cube[4][2][0]) {
			return false;
		}
		else if (Cube[5][0][2] == Cube[4][2][2] || Cube[5][0][2] == Cube[2][2][2] || Cube[2][2][2] == Cube[4][2][2]) {
			return false;
		}
		else return true;
	}

	bool RubicCube::CheckNearEdgesColoring() {
		if (Cube[0][0][1] == Cube[3][2][1]) {
			return false;
		}
		else if (Cube[0][1][0] == Cube[1][1][2]) {
			return false;
		}
		else if (Cube[0][1][2] == Cube[2][1][0]) {
			return false;
		}
		else if (Cube[0][2][1] == Cube[4][0][1]) {
			return false;
		}
		else if (Cube[1][0][1] == Cube[3][1][0]) {
			return false;
		}
		else if (Cube[1][2][1] == Cube[4][1][0]) {
			return false;
		}
		else if (Cube[2][0][1] == Cube[3][1][2]) {
			return false;
		}
		else if (Cube[2][2][1] == Cube[4][1][2]) {
			return false;
		}
		else if (Cube[5][2][1] == Cube[3][0][1]) {
			return false;
		}
		else if (Cube[5][0][1] == Cube[4][2][1]) {
			return false;
		}
		else if (Cube[5][1][0] == Cube[1][1][0]) {
			return false;
		}
		else if (Cube[5][1][2] == Cube[2][1][2]) {
			return false;
		}
		else return true;
	}

	bool RubicCube::CheckColoring() {
		return (CheckCentresColoring() &&
			CheckCornersColoringCount() &&
			CheckEdgesColoringCount() &&
			CheckNearCornersColoring() &&
			CheckNearEdgesColoring());
	}

	void RubicCube::RotateCubeFace(int FaceNumber) {
		RotateFace(FaceNumber);
		switch (FaceNumber) {
		case 0: {
			RotateNearFrontFace();
		}; break;
		case 1: {
			RotateNearLeftFace();
		}; break;
		case 2: {
			RotateNearRightFace();
		}; break;
		case 3: {
			RotateNearDownFace();
		}; break;
		case 4: {
			RotateNearUpFace();
		}; break;
		case 5: {
			RotateNearBackFace();
		}; break;
		}
	}

	void RubicCube::RandomRotation(int rotation_num) {
		int* Rotations = new int[rotation_num];
		for (int i = 0; i < rotation_num; i++) {
		}
		for (int i = 0; i < rotation_num; i++) {
			Rotations[i] = rand() % 5;
		}
		for (int i = 0; i < rotation_num; i++) {
			RotateCubeFace(Rotations[i]);
		}
		delete[] Rotations;
	}

	RubicCube::RubicCube(int rotation_num) {
		Colorize();
		RandomRotation(rotation_num);
	}

	RubicCube::RubicCube(const string& filename) {
		ifstream file(filename);
		if (!file.is_open()) {
			RubicCubeGameVisuals::FileError();
		}
		for (int face = 0; face < 6; face++) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; ++col) {
					file >> Cube[face][row][col];
				}
			}
		}
		file.close();
	}

	bool RubicCube::operator == (const RubicCube& Cube){
		for (int face = 0; face < 6; face++) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; ++col) {
					if (this->Cube[face][row][col] != Cube.Cube[face][row][col]) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool RubicCube::operator != (const RubicCube& Cube) {
		for (int face = 0; face < 6; face++) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; ++col) {
					if (this->Cube[face][row][col] != Cube.Cube[face][row][col]) {
						return true;
					}
				}
			}
		}
	}

	RubicCube& RubicCube::operator = (const RubicCube& Cube){
		for (int face = 0; face < 6; face++) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; ++col) {
					this->Cube[face][row][col] = Cube.Cube[face][row][col];
				}
			}
		}
		return *this;  
	}
