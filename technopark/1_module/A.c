#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Задача A-3. Задача о максимальном подотрезке.
 * Time limit:      14 s
 * Memory limit:    64 M
 *
 * Составить программу определения такого максимального подотрезка среди элементов заданного целочисленного массива,
 * элементы которого увеличиваются по порядку на 1.
 * Подотрезок массива - это часть ("кусок") массива, который включает в себя все элементы исходного массива от
 * некоторого начального индекса до некоторого другого конечного индекса без изменения порядка следования элементов.
 * Элементы подотрезка функция должна вернуть через указатель-параметр, а ее длину — через возвращаемый результат.
 *
 * Формат входных данных:
 * N - длина входного массива
 * A1 ... An - целочисленный массив
 *
 * Формат выходных данных:
 * N - длинна найденного подотрезка
 * A1 ... An - подотрезок
 * 
 * Гарантируется, что все значения помещаются в 32-битный целый тип (int). Если заданный подотрезок не найден,
 * или если найден только вырожденный подотрезок (длиной 1), необходимо вывести только длину - 0.
 * Если подходящих подотрезков несколько, то необходимо вывести информацию (длину, подотрезок) про первый из них.
 *
 * Программа должна уметь обрабатывать ошибки во входных данных (отрицательное количество элементов и др.).
 * В случае возникновения ошибки нужно вывести в поток стандартного вывода сообщение "[error]" (без кавычек)
 * и завершить выполнение программы.
 *
 * ВАЖНО! Программа в любом случае должна возвращать 0. Не пишите return -1, exit(1) и т.п. Даже если обнаружилась какая-то ошибка,
 * все равно необходимо вернуть 0! (и напечатать [error] в stdout).
 * 
 * Examples
 *   Input          |  Output
 * -----------------+----------------
 *   7              |  4
 *   1 2 3 4 6 7 8  |  1 2 3 4
 */

// Cтрока ошибки
const char ERR_STR[] = "[error]\n";

/*
 * Функция нахождения непрерывного участка наибольшей длины из массива входных данных input длиной size.
 * Найденную непрерывную последовательность функция записывает в память размером size, начиная с адреса result.
 * Возвращает размер найденной последовательности.
 */
int max_length_continous_subarray(int *input, int *result, size_t size);

// Ввод длины входных данных и её валидация
int input_data_size();

// Ввод массива данных и его валидация, параметр - количество данных
int *input_data(int n);

int main()
{
    // Ввод длины массива входных данных и его валидация
    int n = input_data_size();

    // Ввод массива данных и его валидация
    int *input = input_data();

    // Выделение памяти под выходной массив данных

    // Нахождение непрерывного участка наибольшей длины из массива входных данных и проверка успешности выполнения
    int result_length = max_length_continous_subarray(input, result, n);
    if(result_length < 0) {
        free(input);
        free(result);
        printf(ERR_STR);
        return 0;
    }

    // Нас не интересует вырожденный отрезок из 1 элемента
    if(result_length == 1) {
        result_length = 0;
    }

    // Попытка вывода результатов и его проверка на успешность
    if(printf("%d\n", result_length) < 2) {
        free(input);
        free(result);
        printf(ERR_STR);
        return 0;
    }
    for(size_t i=0; i<result_length; i++) {
        if(printf("%d ", result[i]) < 2) {
            free(input);
            free(result);
            printf(ERR_STR);
            return 0;
        }
    }
    if(result_length > 0) {
        if(printf("\n") < 1) {
            free(input);
            free(result);
            printf(ERR_STR);
            return 0;
        }
    }

    // Освобождение выделенной памяти
    free(input);
    free(result);

    return 0;
}

int max_length_continous_subarray(int *input, int *result, size_t size) {
    if(result == NULL || input == NULL) {
        return -1;
    }

    // Если нет отрезков, удовлетворяющих условиям задачи, вернём 0
    if(size < 2) {
        return size;
    }

    size_t temp_size = 0;
    size_t max_len = 0;
    for(size_t i=0; i<size-1; i++) {
        if(input[i+1] - input[i] != 1) {
            if(temp_size > max_len) {
                max_len = temp_size;
                // max_len - количество ПАР ЭЛЕМЕНТОВ, идущих подряд, поэтому количество ЭЛЕМЕНТОВ, идущих подряд = max_len + 1.
                // Копируем max_len + 1 элементов в массив-ответ result из массива-источника input, начиная со следующей позиции
                // после последней удачной проверки: начинаем с (i + 1) - (max_len + 1) = i - max_len
                if(!memmove(result, &input[i - max_len], (max_len + 1)*sizeof(int))) {
                    return -1;
                }
            }
            temp_size = 0;
        } else {
            temp_size++;
        }
    }
    // Проверяем, а не в конце ли массива находится самый длинный подотрезок
    if(temp_size > max_len) {
        max_len = temp_size;
        // max_len - количество ПАР ЭЛЕМЕНТОВ, идущих подряд, поэтому количество ЭЛЕМЕНТОВ, идущих подряд = max_len + 1.
        // Копируем max_len + 1 элементов в массив-ответ result из массива-источника input, начиная со следующей позиции
        // после последней удачной проверки: начинаем с (i + 1) - (max_len + 1), где i = n - 1.
        // (n - 1 + 1) - (max_len + 1) = n - 1 - max_len
        if(!memmove(result, &input[size - 1 - max_len], (max_len + 1)*sizeof(int))) {
            return -1;
        }
    }
    // max_len - количество ПАР ЭЛЕМЕНТОВ, идущих подряд, поэтому количество ЭЛЕМЕНТОВ, идущих подряд = max_len + 1.
    return max_len + 1;
}

// Ввод массива данных и его валидация, параметр - длина массива входных данных
int *input_data(int n) {
    int *input = (int *)malloc(sizeof(int) * n);
    if(input == NULL) {
        printf(ERR_STR);
        return 0;
    }
    for(size_t i=0; i<n; i++) {
        if(scanf("%d", &input[i]) != 1) {
            free(input);
            printf(ERR_STR);
            return 0;
        }
    }
    return input;
}

// Ввод количества входных данных и её валидация
int input_data_size() {
    int n;
    if(scanf("%d", &n) < 1) {
        printf(ERR_STR);
        return 0;
    }
    if(n < 0) {
        printf(ERR_STR);
        return 0;
    }
    if(n == 0) {
        printf("0\n");
        return 0;
    }
    return n;
}

int *alloc(int n) {
    int *result = (int *)malloc(sizeof(int) * n);
    if(result == NULL) {
        free(input);
        printf(ERR_STR);
        return 0;
    }
