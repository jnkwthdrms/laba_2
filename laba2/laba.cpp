#include <iostream>
#include <clocale>

void task1() {
    std::cout << "задача 1 (статич матрица)\n";
    const int ROWS = 6;
    const int COLS = 5;

    int matrix[ROWS][COLS] = {
        {10, 20, 30, 40, 50},
        {15, 25, 35, 45, 55},
        {5,  12, 22, 32, 42},
        {8,  18, 28, 38, 48},
        {3,  13, 23, 33, 43},
        {9,  19, 29, 39, 49}
    };

    std::cout << "исходная матрица:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    int* ptr = &matrix[0][0];
    int minVal = *ptr;
    int minIndex = 0;
    int totalElements = ROWS * COLS;

    for (int i = 1; i < totalElements; ++i) {
        if (*(ptr + i) < minVal) {
            minVal = *(ptr + i);
            minIndex = i;
        }
    }

    int row = minIndex / COLS;
    int col = minIndex % COLS;

    std::cout << "минимальн элемент: " << minVal << "\n";
    std::cout << "номер строки: " << row << "\n";
    std::cout << "нмер столбца: " << col << "\n";
}

void task2() {
    std::cout << "задача 2 (динамич матрица)\n";
    int rows, cols;

    std::cout << "введите колво строк: ";
    std::cin >> rows;
    std::cout << "введите колво столбцов: ";
    std::cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "введите элементы матрицы (" << rows * cols << " чисел):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "исходная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            if (matrix[j][0] > matrix[j + 1][0]) {
                int* temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    }

    std::cout << "отсортиров матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice = 0;
    while (choice != 3) {
        std::cout << "\nменю\n";
        std::cout << "1. задача 1 (статическая матрица)\n";
        std::cout << "2. задача 2 (динамическая матрица)\n";
        std::cout << "3. выйти\n";
        std::cout << "ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            std::cout << "программа завершена\n";
            break;
        default:
            std::cout << "неверный ввод попробуйте снова\n";
        }
    }

    return 0;
}
