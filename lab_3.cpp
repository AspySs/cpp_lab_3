// программа подсчитывает количество отрицательных чисел после максимального числа в массиве
// на вход: длина массива и данные о массивах в файле data.txt
// выход: количество отрицательных чисел
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdexcept>
#pragma warning(disable : 4996) // чтобы freopen не ругался

int counting(const int N, int* array);
void init_array(int len, int* array);
void printArray(int size, const int* arr);
int input_int(std::string out);



int main()
{
	setlocale(LC_ALL, "Ru");
	const int N = 10;
	int array_1[N] = { 1, 4, 44, -3, 5, -9, 8, -1, -22, -12 };
	printArray(N, array_1);
	counting(N, array_1);

	srand(76); // генерация случайных чисел 76 - cид генерации
	int lenght = input_int("длину генерируемого массива: ");;

	int* array_2 = new int[lenght]; // динамический массив
	init_array(lenght, array_2);
	printArray(lenght, array_2);
	counting((lenght - 1), array_2);

	try {
		freopen("data.txt", "r", stdin); // это как ifstream но круче
		int n;
		while (std::cin >> n) {
			if (std::cin.fail()) {
				throw 666;
			}
			int* arr = new int[n];
			for (int i = 0; i < n; i++) {
				if (!(std::cin >> arr[i])) {
					throw 666;
				}
			}
			printArray(n, arr);
			counting(n, arr);
			delete[]arr;
		}

	}
	catch (...) {
		std::cerr << "\n Ошибка при чтении файла, данные некорректны! \n";
		return 666;
	}



}


void init_array(int len, int* array) {
	for (int i = 0; i <= len; i++) {
		array[i] = rand() % 9 - 5;
	}
}

int counting(const int len, int* array) {
	int count = 0;
	int max = array[0];
	int place = 0;

	for (int i = 0; i < len; i++) {
		if (max < array[i]) {
			max = array[i]; // максимальное число в массиве
			place = i;
		}

	}

	int num = 0;
	for (int i = (len - 1); i > place; i--) { // поиск отрицательных чисел
		if (array[i] < 0) {
			count++;
			num = array[i];
		}
	}
	if (count > 0) {
		std::cout << "Количество отрицательных элементов стоящих после максимального: " << count << std::endl;
	}
	else {
		std::cout << "Отрицательных элементов массива, находящихся после максимального не найдено!" << std::endl;
	}
	return 0;
}

void printArray(int size, const int* arr) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
}

int input_int(std::string out) {
	int inp;
	std::cout << "Введите " + out;

	bool correct = false;
	while (!correct) {
		std::cin >> inp;
		if ((std::cin.fail()) || (inp <= 0)) {
			std::cin.clear();

			while (std::cin.get() != '\n'); //std::cin.ignore();

			std::cout << "Некорректное значение переменной, попробуйте ввести положительное целочисленное значение: " << std::endl;
			correct = false;
			std::cin.clear();
			continue;
		}
		else {
			//std::cin.ignore();
			correct = true;
		}
	}
	return inp;
}