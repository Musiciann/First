#include <iostream>
#include "..\RubicCube\RubicCubeGraphic.h"

/*!
\file
\brief ���� c ��������� ���������� ����������� ������������ ������ RubicCube
� ���� ���������� ������

���� �������� � ���� �������� ���������� ������� ������ RubicCube, �����������
��� ���������� ����������� ������������ ����.
*/

using namespace std;

	 void RubicCubeGameVisuals::CubeChoiceMenuGraphic() {
		cout << "			     /]==============================]\\\n";
		cout << "			  -/?|                                |?\\-\n";
		cout << "			 <==+|     �������� ����� ����:       |+==>\n";
		cout << "			   \\\\|--------------------------------|//\n";
		cout << "			    ||                                ||\n";
		cout << "			    ||     1 - ��������� �����.       ||\n";
		cout << "			    ||                                ||\n";
		cout << "			    ||       2 - ���� �����.          ||\n";
		cout << "			    ||                                ||\n";
		cout << "			    \\\\================================//\n";
	}

	void RubicCubeGameVisuals::Banner() {
		cout << "			  $$$$$   $$  $$  $$$$$   $$$$$$   $$$$    $$$$      \n";
		cout << "			  $$  $$  $$  $$  $$  $$    $$    $$  $$  $$         \n";
		cout << "			  $$$$$   $$  $$  $$$$$     $$    $$       $$$$      \n";
		cout << "			  $$  $$  $$  $$  $$  $$    $$    $$  $$      $$     \n";
		cout << "			  $$  $$   $$$$   $$$$$   $$$$$$   $$$$    $$$$      \n";
		cout << "			                                                     \n";
		cout << "			   $$$$   $$  $$  $$$$$   $$$$$     $$$   $$$   $$$  \n";
		cout << "			  $$  $$  $$  $$  $$  $$  $$        $$$   $$$   $$$  \n";
		cout << "			  $$      $$  $$  $$$$$   $$$$      $$$   $$$   $$$  \n";
		cout << "			  $$  $$  $$  $$  $$  $$  $$                         \n";
		cout << "			   $$$$    $$$$   $$$$$   $$$$$     $$$   $$$   $$$  \n\n";
	}

	 void RubicCubeGameVisuals::MenuGraphic() {
		cout << "			  ,===============================================,\n";
		cout << "			 //                                               \\\\\n";
		cout << "			||                �������� ��������!               ||\n";
		cout << "			 \\\\                                               //\n";
		cout << "			_{|+=====------------------------------------=====+|}_\n";
		cout << "			[[/                                                \\]]\n";
		cout << "			+|+          1. ��������� �������� �����.          +|+\n";
		cout << "			[|]                                                [|]\n";
		cout << "			+|+          2. ��������� ����� �����.             +|+\n";
		cout << "			[-]                                                [-]\n";
		cout << "			||/          3. ��������� ������ �����.            \\||\n";
		cout << "			||                                                  ||\n";
		cout << "			||           4. ��������� ������ �����.             ||\n";
		cout << "			||                                                  ||\n";
		cout << "			||           5. ��������� ������� �����.            ||\n";
		cout << "			||\\                                                /||\n";
		cout << "			[-]          6. ��������� ������ �����.            [-]\n";
		cout << "			+|+                                                +|+\n";
		cout << "			[|]          7. ������� �����.                     [|]\n";
		cout << "			+|+                                                +|+\n";
		cout << "			[[\\          8. �����.                             /]]\n";
		cout << "			[[\\                                                /]]\n";
		cout << "			\\=||     9. ��������� ������������ ���������.     ||=/\n";
		cout << "			\\=||                                              ||=/\n";
		cout << "			 \\=\\\\===========================================//=/\n";
	}

	 void RubicCubeGameVisuals::FileError() {
		 cout << "������! �� ������� ������� ����: " << filename << ". ����������, ������������� ������������ ����� � ��������� �������.\n";
	 }

	 void RubicCubeGameVisuals::ColoringCheckMessage() {
		 if (RubicCube::CheckColoring()) {
			 cout << "��������� ������.\n";
		 }
		 else {
			 cout << "��������� ��������.\n";
		 }
	 }

	 RubicCube RubicCubeGameVisuals::CubeChoiceMenu(RubicCube& Cube) {
		 RubicCubeGameVisuals::CubeChoiceMenuGraphic();
		 char CubeChoice_Key;
		 bool Choice = true;
		 while (Choice) {
			 cin >> CubeChoice_Key;
			 switch (CubeChoice_Key) {
			 case '1': {
				 Choice = false;
				 cout << "��� ���� ��� ������ ��������� �����.\n\n";
				 Cube = RubicCube(rand() % 20);
				 return Cube;
			 }; break;
			 case'2': {
				 Choice = false;
				 cout << "��� ���� ��� ������ ���� �����.\n\n";
				 cout << "������� ��� �����, ����������� ��������� ������.\n\n";
				 string filename;
				 cin >> filename;
				 Cube = RubicCube(filename);
				 return Cube;
			 }; break;
			 default:cout << "������ ������ ���.\n"; break;
			 }
		 }
	 }

	 bool RubicCubeGameVisuals::ExitGame() {
		 cout << "�� �������, ��� ������ ����� �� ����? [Y/N]\n";
		 char Choice_key;
		 bool KeepAsk = true;
		 bool on_work = true;
		 while (KeepAsk) {
			 cin >> Choice_key;
			 switch (Choice_key) {
			 case'Y':KeepAsk = false; on_work = false; break;
			 case'N':KeepAsk = false; break;
			 default: cout << "������ ����� �����������. ����������, ��������� �������.\n"; break;
			 }
		 }
		 return on_work;
	 }

	 void RubicCubeGameVisuals::CubeGameMenu() {
		 char key;
		 bool on_work = true;
		 while (on_work) {
			 RubicCubeGameVisuals::MenuGraphic();
			 cin >> key;
			 cout << endl;
			 switch (key) {
			 case'1':RotateCubeFace(0); break;
			 case'2':RotateCubeFace(1); break;
			 case'3':RotateCubeFace(2); break;
			 case'4':RotateCubeFace(3); break;
			 case'5':RotateCubeFace(4); break;
			 case'6':RotateCubeFace(5); break;
			 case'7':SeeCube(); break;
			 case'8':on_work = ExitGame(); break;
			 case'9':ColoringCheckMessage(); break;
			 default:cout << "������� �������� ��������. ����������, ��������� �������.\n";
			 }
		 }
	 }

	 void RubicCubeGameVisuals::SeeCube() {
		 for (int face = 0; face < 6; face++) {
			 cout << "\t\t\t ����� " << face + 1 << endl;
			 for (int row = 0; row < 3; row++) {
				 cout << "\t\t\t";
				 for (int col = 0; col < 3; col++) {
					 cout << Cube[face][row][col] << "  ";
				 }
				 cout << endl;
			 }
			 cout << endl << endl;
		 }
	 }