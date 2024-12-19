#include <iostream>
#include <iomanip>
using namespace std;

// Функция получает указатель на двумерный массив и его размер, 
// и заполняет массив случайными числами
void Init(int ptr[][5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ptr[i][j] = rand() % 50;
		}
	}
}

// Функция получает указатель на двумерный массив и его размер, 
// и выводит массив на экран
void Print(int(*ptr)[5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(5) << *(*(ptr + i) + j);
		}
		cout << endl;
	}
}

// Функция получает адрес нулевого элемента двумерного массива
// (элемента с индексами [0][0]), число строк и столбцов,
// и выводит массив на экран
void Print(int *ptr, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << setw(5) << ptr[i * column + j];
		}
		cout << endl;
	}
}

//  функция создания двумерного динамического массива
int **Allocate(int rows, int cols)
{
	int **ptr = new int *[rows];
	for (int i = 0; i < rows; i++)
		ptr[i] = new int[cols];
	return ptr;
}

// функция удаления двумерного динамического массива
void Free(int **p, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] p[i];
	delete[] p;
}

// функция инициализации массива
void Init(int **p, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			p[i][j] = rand() % 41 - 20;
	}
}
 
// функция печати массива
void Print(int **p, int rows, int cols)
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << setw(5) << *(*(p + i) + j); // p[i][j]
		cout << endl;
	}
	cout << endl;
}


