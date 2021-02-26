#pragma once

#include <iostream>

using namespace std;

template<typename T> void push_col_back(T** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		T* buffer = new T[n + 1]{};
		for (int b = 0; b < n; b++) {
			buffer[b] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n++;
}
template<typename T> void push_col_front(T** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		T* buffer = new T[n + 1]{};
		for (int b = 0; b < n; b++) {
			buffer[b + 1] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n++;
}
template<typename T> void insert_col(T** arr, const int m, int& n) {
	int a;
	cout << "Enter index of col:"; cin >> a;
	cout << endl;
	for (int i = 0; i < m; i++) {
		T* buffer = new T[n + 1]{};
		for (int b = 0; b < n; b++) {
			if (b < a)buffer[b] = arr[i][b];
			else buffer[b + 1] = arr[i][b];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template<typename T> void pop_col_back(T** arr, const int m, int& n) {
	n--;
	for (int a = 0; a < m; a++) {
		T* buffer = new T[n]{};
		for (int b = 0; b < n; b++) {
			buffer[b] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
}
template<typename T> void pop_col_front(T** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		T* buffer = new T[n - 1]{};
		for (int b = 1; b < n; b++) {
			buffer[b - 1] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n--;
}
template<typename T> void erase_col(T** arr, const int m, int& n) {
	int a;
	cout << "Enter index of col:"; cin >> a;
	cout << endl;
	a++;
	for (int i = 0; i < m; i++) {
		T* buffer = new T[n - 1]{};
		for (int b = 0; b < n; b++) {
			if (b < a)buffer[b] = arr[i][b];
			else buffer[b - 1] = arr[i][b];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}