#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Задача B-1. Калькулятор для числовых множеств
 * Time limit:      14 s
 * Memory limit:    64 M
 *
 * Разработайте программу-калькулятор, умеющую вычислять арифметические выражения над множествами натуральных чисел.
 * Входные данные (выражение с описанием множеств и производимых над ними операций) подаются на стандартный поток ввода программы,
 * результат вычислений должен подаваться на стандартный поток вывода.
 *
 * Поддерживаемые операции: 'U' - объединение, '^' - пересечение, '\' - разность множеств, '()' - задание приоритета вычислений.
 * Множества задаются в виде [ el1, el2, ... ], где элементами являются обычные натуральные числа.
 * Множества могут быть пустыми.
 * Между операциями, множествами и элементами множеств может быть любое количество пробелов.
 *
 * При вычислениях должны учитываться приоритеты операций (в том числе, заданные вручную при помощи круглых скобочек).
 * 
 * Результирующее множество должно выводиться без пробелов, в отсортированном порядке.
 * В случае, если введенное выражение содержит ошибку, необходимо вывести в поток стандартного вывода сообщение "[error]"
 * и завершить выполнение программы.
 *
 * ВАЖНО! Программа в любом случае должна возвращать 0. Не пишите return -1, exit(1) и т.п.
 * Даже если обнаружилась какая-то ошибка, все равно необходимо вернуть 0! (и напечатать [error] в stdout).
 *
 * Examples
 *   Input                                             |  Output
 * ----------------------------------------------------+-----------
 *   ([1,     2  , 3 ] U [1,2,42,8] U[])^[1, 8, 3,13]  |  [1,3,8]
 */

/* 
 * Приоритеты операций:
 *     1) пересечения
 *     2) объединения и разности
 */

enum tok_type {
    operand,
    operation
};

struct set {
    int *elems;
    size_t set_size;
};

struct token {
    enum tok_type type;
    union {
        struct set set;
        char operator;
    };
};

int main(int argc, char **argv)
{
    const char ENABLED_CHARS[] = "()[],U^\\0123456789\n";
    const char ERR_STR[] = "[error]\n";

    char success_input = 0;  // false

//    char *input;
    size_t input_size = 0;

    size_t buffer_size = 255;
    char *tokens = (char*)malloc(sizeof(char)*buffer_size);

    char ch = EOF;
    while( (ch = getc(stdin)) != EOF ) {
        if(strchr(ENABLED_CHARS, ch)) {
            tokens[input_size++] = ch;
        }
        else if(ch != EOF || ch != ' ') {
            printf(ERR_STR);
            return 0;
        }
        success_input = 1;  // true
    }
    if(!success_input) {
        printf(ERR_STR);
        return 0;
    }

//    struct tokens tokens = tokenize(*tokens, input_size); 

    return 0;
}
