#include <iostream>
#include <ctime>

using namespace std;

void FillRand(int**& arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			arr[a][b] = rand() % 100;
		}
	}
}

void Print(int** arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			cout << arr[a][b] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int** allocate(const int m, const int n) {
	int** arr = new int* [m];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	return arr;
}

void clear(int**& arr, const int m, const int n) {
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void push_row_back(int**& arr, int& m,const int n) {
	int** buffer = new int* [m+1] {};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n) {
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m; i++) {
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[0] = new int[n] {};
	m++;
}
void insert_row(int**& arr, int& m, const int n) {
	int** buffer = new int* [m + 1]{};
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
	buffer[a] = new int[n] {};
	m++;
}

void pop_row_back(int**& arr, int& m, const int n) {
	m--;
	int** buffer = new int* [m]{};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr[m];
 	delete[] arr;
	arr = buffer;
}
void pop_row_front(int**& arr, int& m, const int n) {
	m--;
	int** buffer = new int* [m]{};
	for (int i = 1; i < m+1; i++) {
		buffer[i - 1] = arr[i];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void erase_row(int**& arr, int& m, const int n) {
	int** buffer = new int* [m-1]{};
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

void push_col_back(int** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		int* buffer = new int[n + 1]{};
		for (int b = 0; b < n; b++) {
			buffer[b] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n++;
}
void push_col_front(int** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		int* buffer = new int[n + 1]{};
		for (int b = 0; b < n; b++) {
			buffer[b+1] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n++;
}
void insert_col(int** arr, const int m, int& n) {
	int a;
	cout << "Enter index of col:"; cin >> a;
	cout << endl;
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n + 1]{};
		for (int b = 0; b < n; b++) {
			if (b < a)buffer[b] = arr[i][b];
			else buffer[b + 1] = arr[i][b];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

void pop_col_back(int** arr, const int m, int& n) {
	n--;
	for (int a = 0; a < m; a++) {
		int* buffer = new int[n] {};
		for (int b = 0; b < n; b++) {
			buffer[b] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
}
void pop_col_front(int** arr, const int m, int& n) {
	for (int a = 0; a < m; a++) {
		int* buffer = new int[n - 1]{};
		for (int b = 1; b < n; b++) {
			buffer[b-1] = arr[a][b];
		}
		delete[] arr[a];
		arr[a] = buffer;
	}
	n--;
}
void erase_col(int** arr, const int m, int& n) {
	int a;
	cout << "Enter index of col:"; cin >> a;
	cout << endl;
	a++;
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n-1]{};
		for (int b = 0; b < n; b++) {
			if (b < a)buffer[b] = arr[i][b];
			else buffer[b - 1] = arr[i][b];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}

void main() {
	srand(time(0));
	int a;
	int m = 5;
	int n = 5;
	int** arr = allocate(m, n);
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