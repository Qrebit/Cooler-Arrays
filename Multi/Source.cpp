#include <iostream>
#include <ctime>

using namespace std;

template<typename T> void FillRand(T**& arr, const int m, const int n) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			arr[a][b] = rand() % 100;
		}
	}
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

template<typename T> T** allocate(const int m, const int n) {
	T** arr = new T * [m];
	for (int i = 0; i < n; i++) {
		arr[i] = new T[n];
	}
	return arr;
}

template<typename T> void clear(T**& arr, const int m, const int n) {
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T> void push_row_back(T**& arr, int& m,const int n) {
	T** buffer = new T * [m+1] {};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new T[n] {};
	m++;
}
template<typename T> void push_row_front(T**& arr, int& m, const int n) {
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++) {
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[0] = new T[n] {};
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
	buffer[a] = new T[n] {};
	m++;
}

template<typename T> void pop_row_back(T**& arr, int& m, const int n) {
	m--;
	T** buffer = new T * [m]{};
	for (int i = 0; i < m; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr[m];
 	delete[] arr;
	arr = buffer;
}
template<typename T> void pop_row_front(T**& arr, int& m, const int n) {
	m--;
	T** buffer = new T * [m]{};
	for (int i = 1; i < m+1; i++) {
		buffer[i - 1] = arr[i];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T> void erase_row(T**& arr, int& m, const int n) {
	T** buffer = new T * [m-1]{};
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
			buffer[b+1] = arr[a][b];
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
		T* buffer = new T[n] {};
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
			buffer[b-1] = arr[a][b];
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
		T* buffer = new T[n-1]{};
		for (int b = 0; b < n; b++) {
			if (b < a)buffer[b] = arr[i][b];
			else buffer[b - 1] = arr[i][b];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
typedef char Datatype;
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