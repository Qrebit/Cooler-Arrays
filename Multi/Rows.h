#pragma once

#include <iostream>

using namespace std;

template<typename T> void push_row_back(T**& arr, int& m, const int n) {
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new T[n]{};
	m++;
}
template<typename T> void push_row_front(T**& arr, int& m, const int n) {
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++) {
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[0] = new T[n]{};
	m++;
}
template<typename T> void insert_row(T**& arr, int& m, const int n) {
	T** buffer = new T * [m + 1]{};
	int a;
	cout << "Enter index of row:"; cin >> a;
	cout << endl;
	bool d = 0;
	for (int i = 0; i < m; i++) {
		if (i == a) d = 1;
		if (d == 0)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[a] = new T[n]{};
	m++;
}

template<typename T> void pop_row_back(T**& arr, int& m, const int n) {
	m--;
	T** buffer = new T * [m] {};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T> void pop_row_front(T**& arr, int& m, const int n) {
	m--;
	T** buffer = new T * [m] {};
	for (int i = 1; i < m + 1; i++) {
		buffer[i - 1] = arr[i];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T> void erase_row(T**& arr, int& m, const int n) {
	T** buffer = new T * [m - 1]{};
	int a;
	cout << "Enter index of row:"; cin >> a;
	cout << endl;
	bool d = 0;
	for (int i = 0; i < m; i++) {
		if (i == a) d = 1, i++;
		if (d == 0)buffer[i] = arr[i];
		else buffer[i - 1] = arr[i];
	}
	delete[] arr[a];
	delete[] arr;
	arr = buffer;
	m--;
}