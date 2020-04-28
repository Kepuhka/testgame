#include <stdio.h>
#include <header.h>

/** Обрабатывает ввод числа.
 *
 * Возвращает: целое число
*/
int number(int n)
{
    printf("Enter a four-digit number without repetition!\n");
    printf("Insert the number: ");
    scanf("%d", &n);
    return n;
}

/** Разбиваем число на цифры и исключаем возможность повторения этих цифр.
 *
 * Возвращает: Ничего.
*/
void breaking(int b[], int n)
{
    int i = 3, j, count = 0;
    n = n < 0 ? -n : n;
    /* Разбиваем цифры на числа и считаем их количество */
    do {
        b[i--] = n % 10;
        count++;
    } while(n /= 10);

    /* Проверяем количество введёных цифр. */
    if(count > 4 || count < 4) {
        breaking(b, number(n));
    }

    /* Проверяем цифры на повторение. */
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            while(b[i] == b[j] && i != j) {
                n = number(n);
                breaking(b, n);
            }
        }
    }
}

/** Функция самой игры. Считает сколько коров и быков.
 *
 * Возвращает: целое число, соответствующее выигрышу 1 или продолжению игры 0.
*/
int game(int a[], int b[])
{
    int i, j, cow = 0, bull = 0;
    /* Считаем коров и быков. */
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(a[i] == b[j] && i == j) {
                bull++;
            }
            if(a[i] == b[j] && i != j) {
                cow++;
            }
        }
    }
    printf("Cow = %d, bull = %d\n", cow, bull);
    if(bull == 4) {
        return 1;
    } else {
        return 0;
    }
}
