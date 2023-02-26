
#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), чтение символа с клавиатуры
#include <vector>
using namespace std;

string RandDirection(int);

int main()
{
	int iLengthSize = 20;		//длина
	int iHeightSize = 10;		//высота

	int iFruitLength;		//положение фрукта по длине
	int	iFruitHeigh;		//положение фрукта по высоте

	iFruitLength = rand() % (iLengthSize - 1) + 1;	//случайное место появления фрукта из диапазона
	iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//случайное место появления фрукта из диапазона

	int iOneFruitChecking;		//проверка наличия фрукта 

	int iSnakeLive = 1;

	vector<int> Snake = { 0 };
	Snake[0] = 1;
	vector<int> SnakePositionX;
	vector<int> SnakePositionY;

	int total = 0;

	int iRandSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//случайное место появления головы змеи
	int iRandSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//случайное место появления головы змеи

	SnakePositionX.insert(SnakePositionX.begin(), iRandSnakeHeadX);
	SnakePositionY.insert(SnakePositionY.begin(), iRandSnakeHeadY);

	int iRandomMoving = rand() % (4 - 1 + 1) + 1;	//случайное направление движения змеи — 1 - вверх, 2 - вправо, 3 - вниз, 4 - влево

	int iTestClicking = 0; //проверка нажатия клавиши

	cout << "Total " << total << endl;

	//////////////////////////////////////////////////////

	while (iSnakeLive == 1)
	{
		iOneFruitChecking = 1;

		for (int y = 0; y < iHeightSize; y++)		//счетчик строк
		{
			for (int x = 0; x < iLengthSize; x++)		//счетчик столбцов для строки y
			{
				if (y == 0 || y == iHeightSize - 1)		//для 1 и последней строчки полностью заполняем *
				{
					cout << '*';
				}
				else  //отрисовка на пустом месте
				{
					if (x == 0 || x == iLengthSize - 1)		//для 1 и последнего столбца рисуем *, иначе ничего не рисуем
					{
						cout << '*';
					}

					else if (x == iFruitLength && y == iFruitHeigh && iOneFruitChecking == 1) //появление 1 фрукта в 1 случайном месте
					{
						if (x == SnakePositionX[0] && y == SnakePositionY[0])	//проверка того, что рисуем: голову или фрукт
						{
							cout << Snake[0];
						}
						else
						{
							cout << 'o';
							iOneFruitChecking = 0;	//появление за цикл только один раз		
						}
					}

					else
					{
						int check = 0;
						for (int i = 0; i < SnakePositionX.size(); i++)
						{
							if (x == SnakePositionX[i] && y == SnakePositionY[i])		//если текущие координаты x и y совпадают с каким-нибудь значением из координат тела змеи, то рисуем этот элемент
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

		//после полной отрисовки поля

		cout << iFruitLength << "_Fruit position_" << iFruitHeigh << endl;	//выведение положения фрукта
		cout << SnakePositionX[0] << "_Snake position_" << SnakePositionY[0] << endl;		//выведение положения головы змеи (должно совпасть с положением фрукта)
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

			if (iArrGetch[1] == 72)	//перемещение змеи вверх
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
				SnakePositionY[0] = SnakePositionY[0] - 1;	//новое положение головы

				iRandomMoving = 1;
			}
			else if (iArrGetch[1] == 80)	//перемещение змеи вниз
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
				SnakePositionY[0] = SnakePositionY[0] + 1;	//новое положение головы

				iRandomMoving = 3;
			}
			else if (iArrGetch[1] == 75)	//перемещение змеи влево
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0] - 1;	//новое положение головы
				SnakePositionY[0] = SnakePositionY[0];			//новое положение головы

				iRandomMoving = 4;
			}
			else if (iArrGetch[1] == 77)	//перемещение змеи вправо
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0] + 1;	//новое положение головы
				SnakePositionY[0] = SnakePositionY[0];			//новое положение головы

				iRandomMoving = 2;
			}
		}
		else
		{
			if (iRandomMoving == 1)	//случайное направление движения змеи - вверх
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
				SnakePositionY[0] = SnakePositionY[0] - 1;	//новое положение головы
			}
			else if (iRandomMoving == 2)	//случайное направление движения змеи - вправо
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0] + 1;	//новое положение головы
				SnakePositionY[0] = SnakePositionY[0];			//новое положение головы			
			}
			else if (iRandomMoving == 3)	//случайное направление движения змеи - вниз
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
				SnakePositionY[0] = SnakePositionY[0] + 1;	//новое положение головы
			}
			else if (iRandomMoving == 4)	//случайное направление движения змеи - влево
			{
				iOldValX = SnakePositionX[0];		//старое положение головы			
				iOldValY = SnakePositionY[0];		//старое положение головы

				SnakePositionX[0] = SnakePositionX[0] - 1;	//новое положение головы
				SnakePositionY[0] = SnakePositionY[0];			//новое положение головы
			}
		}

		for (int i = 1; i < SnakePositionX.size(); i++)	//проверка удара змеи самой в себя 
		{			
			if (SnakePositionX[0] == SnakePositionX[i] && SnakePositionY[0] == SnakePositionY[i])
			{
				iSnakeLive = 0;	//Game Over		
			}
		}

		if (iSnakeLive == 1)
		{
			if (SnakePositionX[0] > 0 && SnakePositionX[0] < iLengthSize && SnakePositionY[0] > 0 && SnakePositionY[0] < iHeightSize) //проверка удара со стеной
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

		if (iOldValX == iFruitLength && iOldValY == iFruitHeigh)	//если змея поравнялась с фруктом
		{
			iFruitLength = rand() % (iLengthSize - 1) + 1;	//новое случайное место появления фрукта из диапазона
			iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//новое случайное место появления фрукта из диапазона

			total++;
			Snake.push_back(0);	//добавление нового элемента в конец			
			SnakePositionX.push_back(0);	//увеличиваем размер вектора координат на 1 ячейку
			SnakePositionY.push_back(0);	//увеличиваем размер вектора координат на 1 ячейку
		}

		for (int x = 0; x < SnakePositionX.size(); x++)		//смещение координат частей тела змеи
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

		system("cls");	//очистка консоли, но запоминание положения змеи

		//iNumberOfClicks++;
		cout << "Total " << total << endl;	//приспособить под отображение очков
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








