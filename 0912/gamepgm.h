#ifndef GAMEPGM_H
#define GAMEPGM_H

#include <windows.h>

// 함수 선언
void gotoxy(int x, int y);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);

// 커서 위치 제어
void gotoxy(int x, int y) {
    COORD Pos = {(short)(x - 1), (short)(y - 1)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 커서 위치 이동
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b) {
    switch (key) {
    case 72: // 위쪽(상) 방향의 화살표 키 입력
        *y1 = *y1 - 1;
        if (*y1 < 1)
            *y1 = 1; // y좌표의 최소값
        break;
    case 75: // 왼쪽(좌) 방향의 화살표 키 입력
        *x1 = *x1 - 1;
        if (*x1 < 1)
            *x1 = 1; // x좌표의 최소값
        break;
    case 77: // 오른쪽(우) 방향의 화살표 키 입력
        *x1 = *x1 + 1;
        if (*x1 > x_b)
            *x1 = x_b; // x좌표의 최대값
        break;
    case 80: // 아래쪽(하) 방향의 화살표 키 입력
        *y1 = *y1 + 1;
        if (*y1 > y_b)
            *y1 = y_b; // y좌표의 최대값
        break;
    default:
        return;
    }
}

#endif