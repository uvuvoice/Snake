#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), чтение символа с клавиатуры
#include <vector>
using namespace std;

int main()
{
	int iLengthSize = 20;		//длина
	int iHeightSize = 10;		//высота

	int iFruitLength;		//положение фрукта по длине
	int	iFruitHeigh;		//положение фрукта по высоте

	iFruitLength = rand() % (iLengthSize - 1) + 1;	//случайное место появления фрукта из диапазона
	iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//случайное место появления фрукта из диапазона

	int iOneFruitChecking;		//проверка наличия фрукта 

	int iMaxNumberOfClicks = 500;	//заменить на проверку удара ??? пока число нажатий не достигнет 500
	int iNumberOfClicks = 0;			//удалить ??? счетчик числа нажатий

	cout << iNumberOfClicks << endl;

	vector<int> Snake = { 0 };
	vector<int> SnakePositionX;
	vector<int> SnakePositionY;
	
	int total = 0;

	int iRandSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//случайное место появления головы змеи
	int iRandSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//случайное место появления головы змеи
		
	SnakePositionX.insert(SnakePositionX.begin(), iRandSnakeHeadX);
	SnakePositionY.insert(SnakePositionY.begin(), iRandSnakeHeadY);	

	while (iNumberOfClicks != iMaxNumberOfClicks)
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

		// после полной отрисовки поля

		cout << iFruitLength << "_Fruit position_" << iFruitHeigh << endl;	//выведение положения фрукта
		cout << SnakePositionX[0] << "_Snake position_" << SnakePositionY[0] << endl;		//выведение положения головы змеи (должно совпасть с положением фрукта)

		int iOldValX = 0;
		int iOldValY = 0;

		int iClickTest = _getch();		//перемещение змеи		
		int iClicking = _getch();		//перемещение змеи	
				
		switch (iClicking)
		{
		case 72: //перемещение змеи вверх
			iOldValX = SnakePositionX[0];		//старое положение головы			
			iOldValY = SnakePositionY[0];		//старое положение головы

			SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
			SnakePositionY[0] = SnakePositionY[0] - 1;	//новое положение головы
			break;

		case 80:	//перемещение змеи вниз
			iOldValX = SnakePositionX[0];		//старое положение головы			
			iOldValY = SnakePositionY[0];		//старое положение головы

			SnakePositionX[0] = SnakePositionX[0];			//новое положение головы
			SnakePositionY[0] = SnakePositionY[0] + 1;	//новое положение головы
			break;

		case 75:	//перемещение змеи влево
			iOldValX = SnakePositionX[0];		//старое положение головы			
			iOldValY = SnakePositionY[0];		//старое положение головы

			SnakePositionX[0] = SnakePositionX[0] - 1;	//новое положение головы
			SnakePositionY[0] = SnakePositionY[0];			//новое положение головы
			break;

		case 77:	//перемещение змеи вправо
			iOldValX = SnakePositionX[0];		//старое положение головы			
			iOldValY = SnakePositionY[0];		//старое положение головы

			SnakePositionX[0] = SnakePositionX[0] + 1;	//новое положение головы
			SnakePositionY[0] = SnakePositionY[0];			//новое положение головы
			break;
		}

		int iOldValArrX = iOldValX;
		int iOldValArrY = iOldValY;

		///////////////////////////////


		if (iOldValX == iFruitLength && iOldValY == iFruitHeigh)	//если змея поравнялась с фруктом
		{
			iFruitLength = rand() % (iLengthSize - 1) + 1;	//новое случайное место появления фрукта из диапазона
			iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//новое случайное место появления фрукта из диапазона

			total++;
			Snake.push_back(total);	//добавление нового элемента в конец			
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

		iNumberOfClicks++;
		cout << iNumberOfClicks << endl;	//приспособить под отображение очков
	}
}










