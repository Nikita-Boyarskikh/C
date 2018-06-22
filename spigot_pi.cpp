/*
 * Алгоритм Spigot. Получение числа Pi
 *
 * http://www.pi314.net/eng/goutte.php
 */

#include <iostream>
#include <ctime>

// Counters
int startTime, endTime;
unsigned long int iterationsCounter = 0, operationsCounter = 0;

void initCounters() {
    startTime = clock();
    iterationsCounter = 0;
    operationsCounter = 0;
}

void updateCounters(const unsigned long int operations) {
    iterationsCounter++;
    operationsCounter += operations;
}

void printStatistic() {
    std::cout << std::endl << "--------------------" << std::endl;
    std::cout << "Количество итераций: " << iterationsCounter << std::endl;
    std::cout << "Количество операций: " << operationsCounter << std::endl;
    std::cout << "Время выполнения программы: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << " сек."<< std::endl;
}

void correctPiNumbers(int* const pi, const unsigned long int piSize) {
    for(unsigned long int i = 0; i < piSize; i++) {
        if(pi[i] == 10) {
            pi[i] = 0;
            unsigned long int idx = i - 1;  // 1 операция
            while(pi[idx] == 9) {
                pi[idx] = 0;
                idx--;
                operationsCounter++;
            }
            pi[idx]++;  // 1 операция
            operationsCounter += 2;
        }
    }
}

int getPiNumber(int* const array, const unsigned long int arraySize) {
    unsigned long int shift = 0;
    for(unsigned long int i = arraySize - 1; i > 0; i--) {
        // Делитель
        const unsigned long int denominator = i * 2 + 1;  // 2 операции

        // Умножаем на 10
        array[i] *= 10;  // 1 операция

        // Считаем сумму
        const unsigned long int amound = array[i] + shift;  // 1 операция

        // Считаем остаток
        array[i] = amound % denominator;  // 1 операция

        // Считаем перенос
        shift = (unsigned long int)(amound / denominator) * i;  // 2 операции

        // Итого операций за итерацию: 2 + 1 + 1 + 1 + 2 = 7
    }

    // Обновляем счётчики
    // количество операций за итерацию * количество итераций + количество операция после выхода из цикла, не считая вычисления счётчиков
    const unsigned long int operations = 7 * arraySize + 4;
    updateCounters(operations);

    // Считаем сумму
    const unsigned long int amound = array[0] * 10 + shift;  // 2 операции

    // Считаем остаток
    array[0] = amound % 10;  // 1 операция

    // Перенос от последней операции - и есть искомая цифра числа Пи
    return int(amound / 10);  // 1 операция
}

int main(int argc, char* argv[]) {
    initCounters();

    // Получаем от пользователя требуемое количество цифр числа Пи
    unsigned long int n;
    std::cout << "Введите требуемое число цифр числа Пи: ";
    std::cin >> n;

    // Проверяем корректность ввода
    if (n == 0) {
        std::cout << "Требуемое число цифр числа Пи должо быть положительным целым числом!" << std::endl;
        return 1;
    }

    // Создаём и инициализируем двойками массив длины [n * 10 / 3]
    const unsigned long int arraySize = (unsigned long int)((10 * n / 3) + 0.5);
    int array[arraySize];
    for(int i = 0; i < arraySize; i++) {
        array[i] = 2;
    }

    // Считаем первую цифру числа Пи
    const int firstNumber = getPiNumber(array, arraySize);

    // Получаем остальные n-1 цифр числа Пи
    int pi[n - 1];
    unsigned long int tenPower = 10;
    for(unsigned long int i = 0; i < n - 1; i++) {
        pi[i] = getPiNumber(array, arraySize);
        if(i + 2 == tenPower) {  // 2 из-за того, что одну цифру мы уже посчитали и сохранили в firstNumber, а отсчёт i начали с 0
            tenPower *= 10;
            endTime = clock();  // засекаем время окончания вычислений
            printStatistic();
        }
    }

    // Выводим первую цифру числа Pi и десятичный разделитель - запятую, - если нужно
    std::cout << firstNumber;
    if(n > 1) {
        std::cout << '.';
    }

    // Выводим само число Pi
    for(unsigned long int i = 1; i < n; i++) {
        std::cout << pi[i];
    }

    correctPiNumbers(pi, n);  // исправляем попорченные цифры

    // Выводим перенос строки, печатаем статистику и завершаем работу программы
    std::cout << std::endl;
    printStatistic();
    return 0;
}

