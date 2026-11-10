#include <iostream>
#include <vector>
#include <clocale>

void task1() {
	std::cout << "задача 1\n";
	
	const int rows = 6;
	const int cols = 5;

	int matrix[rows][cols] = {
		{10, 20, 30, 40, 50},
		{15, 25, 35, 45, 55},
		{5, 12, 22, 32, 42},
		{8, 18, 28, 38, 48},
		{3, 13, 23, 33, 43},
		{9, 19, 29, 39, 49}
	};

	int* ptr = &matrix[0][0];
	int minVal = *ptr;
	int minIndex = 0;
	int totalElements = rows * cols;

	for (int i = 1; i < totalElements; ++i) {
		if (*(ptr + i) < minVal) {
			minVal = *(ptr + i);
			minIndex = i;
		}
	}

	int row = minIndex / cols;
	int col = minIndex % cols;

	std::cout << "минимальный элемент: " << minVal << "\n";
	std::cout << "номер строки: " << row << "\n";
	std::cout << "номер столбца: " << col << "\n\n";
}

void task2() {
	std::cout << "задача 2\n";
	int rows, cols;

	std::cout << "введите кол-во строк: ";
	std::cin >> rows;
	std::cout << "введите кол-во столбцов: ";
	std::cin >> cols;


	std::vector < std::vector<int>> matrix(rows, std::vector<int>(cols));

	std::cout << "введите элементы матрицы:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < rows - 1; ++i) {
		for (int j = 0; j < rows - i - 1; ++j) {
			if (matrix[j][0] > matrix[j + 1][0]) {
				std::vector<int> temp = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp;
			}
		}
	}
	
	std::cout << "отсортированная матрица:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}



int main() {
	setlocale(LC_ALL, "Russian");
	
	task1();
	task2();

	return 0;
}