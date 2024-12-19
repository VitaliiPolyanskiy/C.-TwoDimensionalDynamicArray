#include <iostream>
#include <ctime>
#include "TwoDimensionalArray.h"

using namespace std;

void main()
{
	srand(time(0));
	// локальный двумерный массив фиксированной размерности
	const int ROW = 4, COLUMN = 5;
	int arr[ROW][COLUMN];
	Init(arr, ROW);
	Print(arr, ROW);

	// двумерный динамический массив
	int **ptr, rows, cols, index;
	cout << "\nEnter quantity of rows and cols: ";
	cin >> rows >> cols;
	ptr = Allocate(rows, cols);
	Init(ptr, rows, cols);
	Print(ptr, rows, cols);	

	cout << endl;
	// Строки двумерного массива фиксированной размерности 
	// располагаются в памяти последовательно, строка за строкой
	// Поэтому такой массив можно обрабатывать как одномерный
	Print(&arr[0][0], ROW, COLUMN);

	cout << endl;
	// Строки двумерного динамического массива 
	// располагаются в памяти произвольно!
	// Поэтому такой массив нельзя обрабатывать как одномерный
	Print(&ptr[0][0], rows, cols);

	Free(ptr, rows);
}