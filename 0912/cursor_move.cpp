#include "gamepgm.h"
#include <stdio.h>
#include <conio.h>

#define X_MAX 79 // 가로(열)방향의 최대값
#define Y_MAX 24 // 세로(행)방향의 최대값

int main(void) {
    char key;
    int x = 10, y = 5;

    do {
        gotoxy(x, y);
        printf("A");
        key = getch();
        move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
    } while (key != 27);
    
    return 0;
}