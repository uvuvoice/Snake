#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), ������ ������� � ����������
#include <vector>
using namespace std;

int main()
{
	int iLengthSize = 20;		//�����
	int iHeightSize = 10;		//������

	int iFruitLength;		//��������� ������ �� �����
	int	iFruitHeigh;		//��������� ������ �� ������

	int iOneFruitChecking;		//�������� ������� ������ 

	int iMaxNumberOfClicks = 500;	//�������� �� �������� ����� ??? ���� ����� ������� �� ��������� 500
	int iNumberOfClicks = 0;			//������� ??? ������� ����� �������

	cout << iNumberOfClicks << endl;

	vector<int> Snake = { 0 };
	vector<int> SnakePositionX;
	vector<int> SnakePositionY;





	int iSnakeHeadChecking;

	int total = 0;

	//int iRandSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//��������� ����� ��������� ������ ����
	//int iRandSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//��������� ����� ��������� ������ ����

	int iRandSnakeHeadX = 2;
	int iRandSnakeHeadY = 1;

	SnakePositionX.insert(SnakePositionX.begin(), iRandSnakeHeadX);
	SnakePositionY.insert(SnakePositionY.begin(), iRandSnakeHeadY);

	/*
	cout << "Position X" << endl;
	for (int i = 0; i < SnakePositionX.size(); i++)
	{
		cout << SnakePositionX[i] << " ";
	}
	cout << endl;


	cout << "Position Y" << endl;
	for (int i = 0; i < SnakePositionY.size(); i++)
	{
		cout << SnakePositionY[i];
	}
	cout << endl;
	*/



	//iFruitLength = rand() % (iLengthSize - 1) + 1;	//��������� ����� ��������� ������ �� ���������
	//iFruitLength = rand() % (iHeightSize - 2) + 1;		//��������� ����� ��������� ������ �� ���������
	iFruitLength = 3;
	iFruitHeigh = 1;

	//cout << SnakePositionX.size() << endl;
	/*
	for (int k = 0; k < SnakePositionX.size(); k++)
	{
		cout << SnakePositionX[k] << " ";
	}
	*/
	cout << endl;

	while (iNumberOfClicks != iMaxNumberOfClicks)
	{
		iOneFruitChecking = 1;
		//iSnakeHeadChecking = 1;

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
					//else if(x == SnakePosition[0][0] && y == SnakePosition[0][1] && iSnakeHeadChecking == 1)		//������ ��������� ������ ���� � ��������, ��� ������ ������ ����; ������ �������� ������ �����

						//iSnakeHeadChecking = 0;

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

		// ����� ������ ��������� ����

		cout << iFruitLength << "_Fruit position_" << iFruitHeigh << endl;	//��������� ��������� ������
		cout << SnakePositionX[0] << "_Snake position_" << SnakePositionY[0] << endl;		//��������� ��������� ������ ���� (������ �������� � ���������� ������)

		int iOldValX = 0;
		int iOldValY = 0;

		int iClickTest = _getch();		//����������� ����		
		int iClicking = _getch();		//����������� ����	

		cout << "� Clicking:   " << iClickTest << endl;
		cout << "� Clicking:   " << iClicking << endl;

		//Sleep(4000);


		//int iClicking = 77;
		switch (iClicking)
		{
		case 72: //����������� ���� �����
			iOldValX = SnakePositionX[0];		//������ ��������� ������			
			iOldValY = SnakePositionY[0];		//������ ��������� ������

			SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
			SnakePositionY[0] = SnakePositionY[0] - 1;	//����� ��������� ������
			break;

		case 80:	//����������� ���� ����
			iOldValX = SnakePositionX[0];		//������ ��������� ������			
			iOldValY = SnakePositionY[0];		//������ ��������� ������

			SnakePositionX[0] = SnakePositionX[0];			//����� ��������� ������
			SnakePositionY[0] = SnakePositionY[0] + 1;	//����� ��������� ������
			break;

		case 75:	//����������� ���� �����
			iOldValX = SnakePositionX[0];		//������ ��������� ������			
			iOldValY = SnakePositionY[0];		//������ ��������� ������

			SnakePositionX[0] = SnakePositionX[0] - 1;	//����� ��������� ������
			SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������
			break;

		case 77:	//����������� ���� ������
			iOldValX = SnakePositionX[0];		//������ ��������� ������			
			iOldValY = SnakePositionY[0];		//������ ��������� ������

			SnakePositionX[0] = SnakePositionX[0] + 1;	//����� ��������� ������
			SnakePositionY[0] = SnakePositionY[0];			//����� ��������� ������
			break;
		}

		int iOldValArrX = iOldValX;
		int iOldValArrY = iOldValY;

		///////////////////////////////


		if (iOldValX == iFruitLength && iOldValY == iFruitHeigh)	//���� ���� ����������� � �������
		{
			//iFruitLength = rand() % (iLengthSize - 1) + 1;	//����� ��������� ����� ��������� ������ �� ���������
			//iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//����� ��������� ����� ��������� ������ �� ���������

			iFruitLength = 4;
			iFruitHeigh = 1;

			total++;
			Snake.push_back(total);	//���������� ������ �������� � �����
			//��������� ������� �������� SnakePositionX � SnakePositionY
			//SnakePositionX.insert(SnakePositionX.begin(), total);
			//SnakePositionY.insert(SnakePositionY.begin(), total);
			SnakePositionX.push_back(0);
			SnakePositionY.push_back(0);

		}


		///////////////////////////////

		//�������� ��������� ������ ���� ����

		for (int x = 0; x < SnakePositionX.size(); x++)
		{
			//cout << SnakePositionX[x] << " ";

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


		////////////////////////////////////////////////////////////

		cout << "NextSnakePositionX" << endl;
		for (int k = 0; k < SnakePositionX.size(); k++)
		{
			cout << SnakePositionX[k] << " ";
		}
		cout << endl;

		cout << "NextSnakePositionY" << endl;
		for (int k = 0; k < SnakePositionY.size(); k++)
		{
			cout << SnakePositionY[k] << " ";
		}
		cout << endl;

		cout << "SnakeElements" << endl;
		for (int k = 0; k < Snake.size(); k++)
		{
			cout << Snake[k] << " ";
		}

		cout << endl;
		cout << "-------------------------" << endl;

		////////////////////////////////////////////////////////////
		cout << "Old X" << iOldValX << " " << "Old Y " << iOldValY << endl;






		/*
		if (iOldValX == iFruitLength && iOldValY == iFruitHeigh)	//���� ���� ����������� � �������
		{
			//iFruitLength = rand() % (iLengthSize - 1) + 1;	//����� ��������� ����� ��������� ������ �� ���������
			//iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//����� ��������� ����� ��������� ������ �� ���������

			iFruitLength = 4;
			iFruitHeigh = 1;

			total++;
			Snake.push_back(total);	//���������� ������ �������� � �����
			//��������� ������� �������� SnakePositionX � SnakePositionY
			//SnakePositionX.insert(SnakePositionX.begin(), total);
			//SnakePositionY.insert(SnakePositionY.begin(), total);
			SnakePositionX.push_back(SnakePositionX[total-1]);
			SnakePositionY.push_back(SnakePositionY[total-1]);

		}
		*/






		cout << endl;
		cout << "After Calc" << endl;

		cout << "New Snake Arr" << endl;
		for (int x = 0; x < Snake.size(); x++)
		{
			cout << Snake[x] << " ";
		}
		cout << endl;

		cout << "New Arr of SnakePositionX" << endl;
		for (int x = 0; x < SnakePositionX.size(); x++)
		{
			cout << SnakePositionX[x] << " ";
		}
		cout << endl;

		cout << "New Arr of SnakePositionY" << endl;
		for (int x = 0; x < SnakePositionX.size(); x++)
		{
			cout << SnakePositionY[x] << " ";
		}
		cout << endl;


		iOneFruitChecking++;


		cout << "� Clicking:   " << iClicking << endl;

		//Sleep(4000);



		/*
		int iClickingTest = _getch();
		switch (iClickingTest)
		{
		case 13: //����������� ���� �����
			system("cls");
			break;
		}
		*/






		system("cls");	//������� �������, �� ����������� ��������� ����

		iNumberOfClicks++;
		cout << iNumberOfClicks << endl;	//������������ ��� ����������� �����


	}
}

	








