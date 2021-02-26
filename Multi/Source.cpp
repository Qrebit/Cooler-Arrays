#include <iostream>
#include <ctime>

#include "ArrayManage.h"
#include "Rows.h"
#include "Cols.h"

using namespace std;

template<typename T> void Random(T& variable);
void FillRand(int** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(float** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n);
template<typename T> void Print(T** arr, const int m, const int n);
template<typename T> T** allocate(const int m, const int n);
template<typename T> void clear(T**& arr, const int m, const int n);

template<typename T> void push_row_back(T**& arr, int& m, const int n);
template<typename T> void push_row_front(T**& arr, int& m, const int n);
template<typename T> void insert_row(T**& arr, int& m, const int n);

template<typename T> void pop_row_back(T**& arr, int& m, const int n);
template<typename T> void pop_row_front(T**& arr, int& m, const int n);
template<typename T> void erase_row(T**& arr, int& m, const int n);

template<typename T> void push_col_back(T** arr, const int m, int& n);
template<typename T> void push_col_front(T** arr, const int m, int& n);
template<typename T> void insert_col(T** arr, const int m, int& n);

template<typename T> void pop_col_back(T** arr, const int m, int& n);
template<typename T> void pop_col_front(T** arr, const int m, int& n);
template<typename T> void erase_col(T** arr, const int m, int& n);

typedef int Datatype;

void main() {
	srand(time(0));
	int a;
	int m = 5;
	int n = 5;
	Datatype** arr = allocate<Datatype>(m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);
	push_row_back(arr, m, n);
	Print(arr, m, n);
	push_row_front(arr, m, n);
	Print(arr, m, n);
	insert_row(arr, m, n);
	Print(arr, m, n);
	pop_row_back(arr, m, n);
	Print(arr, m, n);
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	erase_row(arr, m, n);
	Print(arr, m, n);
	push_col_back(arr, m, n);
	Print(arr, m, n);
	push_col_front(arr, m, n);
	Print(arr, m, n);
	insert_col(arr, m, n);
	Print(arr, m, n);
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	erase_col(arr, m, n);
	Print(arr, m, n);
	clear(arr, m, n);
}