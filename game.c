#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <header.h>

int main()
{
    int a[5];
    int b[4];
    int n;
    int i, j, p = 0;
    srand(time(NULL));
    /* Заполняем массив случайными числами */
    for(i = 0; i < 4; i++) {
        a[i] = (rand() % 10);
        for(j = 0; j < 4; j++) {
            /* Исключаем возможность повторения чисел. */
            if(a[i] == a[j] && i != j) {
                i--;
                break;
            }
        }
    }

    /* Debug information */
    for(i = 0; i < 4; i++) {
        printf("%d", a[i]);
    }
    printf("\n\n");

    /* Запускаем игру */
    printf("The computer made a number, let's start the game!\n");
    while(p != 1) {
        printf("Insert the number: ");
        scanf("%d", &n);
        breaking(b, n);
        p = game(a, b);
    }
    printf("You win!\n");
}
