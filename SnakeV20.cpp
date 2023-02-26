
#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), ������ ������� � ����������
#include <vector>
using namespace std;

string RandDirection(int);

int main()
{
	int iLengthSize = 20;		//�����
	int iHeightSize = 10;		//������

	int iFruitLength;		//��������� ������ �� �����
	int	iFruitHeigh;		//��������� ������ �� ������

	iFruitLength = rand() % (iLengthSize - 1) + 1;	//��������� ����� ��������� ������ �� ���������
	iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//��������� ����� ��������� ������ �� ���������

	int iOneFruitChecking;		//�������� ������� ������ 

	int iSnakeLive = 1;

	vector<int> Snake = { 0 };
	Snake[0] = 1;
	vector<int> SnakePositionX;
	vector<int> SnakePositionY;

	int total = 0;

	int iRandSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//��������� ����� ��������� ������ ����
	int iRandSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//��������� ����� ��������� ������ ����

	SnakePositionX.insert(SnakePositionX.begin(), iRandSnakeHeadX);
	SnakePositionY.insert(SnakePositionY.begin(), iRandSnakeHeadY);

	int iRandomMoving = rand() % (4 - 1 + 1) + 1;	//��������� ����������� �������� ���� � 1 - �����, 2 - ������, 3 - ����, 4 - �����

	int iTestClicking = 0; //�������� ������� �������

	cout << "Total " << total << endl;

	//////////////////////////////////////////////////////

	while (iSnakeLive == 1)
	{
		iOneFruitChecking = 1;

		for (int y = 0; y < iHeightSize; y++)		//������� �����
		{
			for (int x = 0; x < iLengthSize; x++)		//������� �������� ��� ������ y
			{
				if (y == 0 || y == iHeightSize - 1)		//��� 1 � ��������� ������� ��������� ��������� *
				{
					cout << '*';
				}
				else  //��������� �� ������ �����
				{
					if (x == 0 || x == iLengthSize - 1)		//��� 1 � ���������� ������� ������ *, ����� ������ �� ������
					{
						cout << '*';
					}

					else if (x == iFruitLength && y == iFruitHeigh && iOneFruitChecking == 1) //��������� 1 ������ � 1 ��������� �����
					{
						if (x == SnakePositionX[0] && y == SnakePositionY[0])	//�������� ����, ��� ������: ������ ��� �����
						{
							cout << Snake[0];
						}
						else
						{
							cout << 'o';
							iOneFruitChecking = 0;	//��������� �� ���� ������ ���� ���		
						}
					}

					else
					{
						int check = 0;
						for (int i = 0; i < SnakePositionX.size(); i++)
						{
							if (x == SnakePositionX[i] && y == SnakePositionY[i])		//���� ������� ���������� x � y ��������� � �����-������ ��������� �� ��������� ���� ����, �� ������ ���� �������
							{
								cout << Snake[i];
								check = 1;
							}
						}
						if (check == 0)
						{
							cout << ' ';
						}
					}
				}
			}
			cout << '\n';
		}

		//����� ������ ��������� ����

		cout << iFruitLength << "_Fruit position_" << iFruitHeigh << endl;	//��������� ��������� ������
		cout << SnakePositionX[0] << "_Snake position_" << SnakePositionY[0] << endl;		//��������� ��������� ������ ���� (������ �������� � ���������� ������)
		cout << "---------------------" << endl;
		cout << "Rand direction " << RandDirection(iRandomMoving) << endl;

		int iOldValX = 0;
		int iOldValY = 0;

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
		int iArrGetch[2];	
		
		cout << "---------------------" << endl;
		for (int i = 10; i > 0; i--)
		{
			cout << "Time to choice " << i << endl;
			Sleep(20);
		}
		cout << "---------------------" << endl;

		if (_kbhit() != 0)
		{
			iArrGetch[0] = _getch();
			iArrGetch[1] = _getch();

			if (iArrGetch[1] == 72)	//����������� ���� �����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0] - 1;	//����� ��������� ������

				iRandomMoving = 1;
			}
			else if (iArrGetch[1] == 80)	//����������� ���� ����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0] + 1;	//����� ��������� ������

				iRandomMoving = 3;
			}
			else if (iArrGetch[1] == 75)	//����������� ���� �����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0] - 1;	//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������

				iRandomMoving = 4;
			}
			else if (iArrGetch[1] == 77)	//����������� ���� ������
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0] + 1;	//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������

				iRandomMoving = 2;
			}
		}
		else
		{
			if (iRandomMoving == 1)	//��������� ����������� �������� ���� - �����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0] - 1;	//����� ��������� ������
			}
			else if (iRandomMoving == 2)	//��������� ����������� �������� ���� - ������
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0] + 1;	//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������			
			}
			else if (iRandomMoving == 3)	//��������� ����������� �������� ���� - ����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0] + 1;	//����� ��������� ������
			}
			else if (iRandomMoving == 4)	//��������� ����������� �������� ���� - �����
			{
				iOldValX = SnakePositionX[0];		//������ ��������� ������			
				iOldValY = SnakePositionY[0];		//������ ��������� ������

				SnakePositionX[0] = SnakePositionX[0] - 1;	//����� ��������� ������
				SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������
			}
		}

		for (int i = 1; i < SnakePositionX.size(); i++)	//�������� ����� ���� ����� � ���� 
		{			
			if (SnakePositionX[0] == SnakePositionX[i] && SnakePositionY[0] == SnakePositionY[i])
			{
				iSnakeLive = 0;	//Game Over		
			}
		}

		if (iSnakeLive == 1)
		{
			if (SnakePositionX[0] > 0 && SnakePositionX[0] < iLengthSize && SnakePositionY[0] > 0 && SnakePositionY[0] < iHeightSize) //�������� ����� �� ������
			{
				iSnakeLive = 1;	//Game Continues
			}
			else
			{
				iSnakeLive = 0;	//Game Over
			}
		}
		else
		{
			iSnakeLive = 0;	//Game Over
		}

		iArrGetch[0] = 0;
		iArrGetch[1] = 0;

		int iOldValArrX = iOldValX;
		int iOldValArrY = iOldValY;

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//cout << "iRandomMoving " << iRandomMoving << endl;

		///////////////////////////////

		if (iOldValX == iFruitLength && iOldValY == iFruitHeigh)	//���� ���� ����������� � �������
		{
			iFruitLength = rand() % (iLengthSize - 1) + 1;	//����� ��������� ����� ��������� ������ �� ���������
			iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//����� ��������� ����� ��������� ������ �� ���������

			total++;
			Snake.push_back(0);	//���������� ������ �������� � �����			
			SnakePositionX.push_back(0);	//����������� ������ ������� ��������� �� 1 ������
			SnakePositionY.push_back(0);	//����������� ������ ������� ��������� �� 1 ������
		}

		for (int x = 0; x < SnakePositionX.size(); x++)		//�������� ��������� ������ ���� ����
		{
			if (x < SnakePositionX.size() - 1)
			{
				int iOldArrX = SnakePositionX[x + 1];
				int iOldArrY = SnakePositionY[x + 1];

				SnakePositionX[x + 1] = iOldValArrX;
				SnakePositionY[x + 1] = iOldValArrY;

				iOldValArrX = iOldArrX;
				iOldValArrY = iOldArrY;
			}
		}

		iOneFruitChecking++;

		system("cls");	//������� �������, �� ����������� ��������� ����

		//iNumberOfClicks++;
		cout << "Total " << total << endl;	//������������ ��� ����������� �����
	}

	cout << "Game Over " << endl;
}


string RandDirection(int direction)
{
	string dir;

	switch (direction)
	{
	case 1:
		dir = "up";
		break;
	case 2:
		dir = "right";
		break;
	case 3:
		dir = "down";
		break;
	case 4:
		dir = "left";
		break;
	}
	return dir;
}








