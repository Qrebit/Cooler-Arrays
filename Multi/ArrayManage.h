#pragma once

#include <iostream>
using namespace std;

template<typename T> void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else
		if (typeid(variable) == typeid(float) or typeid(variable) == typeid(double))
		{
			variable = double(rand() % 10000) / 100;
		}
		else
		{
			if (typeid(variable) == typeid(char))
			{
				variable = rand() % 255;
			}
			else
			{
				variable = T();
			}
		}
}

void FillRand(int** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			//arr[a][b] = rand() % 100;
			Random(arr[a][b]);
		}
	}
}
void FillRand(double** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			//arr[a][b] = (double)rand() / 100;
			Random(arr[a][b]);
		}
	}
}
void FillRand(float** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			//arr[a][b] = (float)rand() / 100;
			Random(arr[a][b]);
		}
	}
}
void FillRand(char** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			//arr[a][b] = rand() % 255;
			Random(arr[a][b]);
		}
	}
}

template<typename T> T** allocate(const int m, const int n) {
	T** arr = new T * [m];
	for (int i = 0; i < n; i++) {
		arr[i] = new T[n];
	}
	return arr;
}

template<typename T> void Print(T** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			cout << arr[a][b] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T> void clear(T**& arr, const int m, const int n) {
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}