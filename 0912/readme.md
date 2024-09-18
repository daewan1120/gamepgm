0912 레포트
===
2023664002 강대완
---

 - ### 'gamepgm.h'

```cpp
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
```
- 설명: 커서 제어와 관련된 gotoxy, move_arrow_key 함수를 제공하는 헤더 파일
1. gotoxy: 커서를 지정된 (x, y) 좌표로 이동
2. move_arrow_key: 화살표 키 입력에 따라 커서를 이동

---

 - ### 'cursor_control.cpp'

```cpp
#include "gamepgm.h"
#include <stdio.h>

int main(void) {
    gotoxy(2, 4);
    printf("Hello");

    gotoxy(40, 20);
    printf("Hello");

    return 0;
}
```
- 설명: 커서를 (2, 4), (40, 20)의 위치로 이동시켜 "Hello"를 출력하는 코드
- 실행 결과: 
---

 - ### 'times_table_3.cpp'

```cpp
#include "gamepgm.h"
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 9; i++) {
        gotoxy(35, 5 + i);
        printf("%d*%d=%2d", 3, i, 3 * i);
    }
    printf("\n");

    return 0;
}
```
- 설명: (35, 5)의 위치에서 구구단 3단을 출력하는 코드
- 실행 결과:
---

 - ### 'check_char.cpp'

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch;

    printf("문자를 입력하고 Enter>");
    scanf("%c", &ch);
    system("cls");
    printf("입력된 문자 %c\n", ch);

    return 0;
}
```
- 설명: 입력한 문자를 알려주는 코드
- 실행 결과:
---

 - ### 'times_table.cpp'

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
    int i, j;

    for (j = 1; j <= 9; j++) {
        system("cls");

        for (i = 1; i <= 9; i++) {
            printf("%d*%d=%d\n", j, i, j * i);
        }
        printf("아무키나 누르시오.\n");
        getch();
    }

    return 0;
}
```
- 설명: 구구단을 1단부터 9단까지 차례로 화면에 출력하는 코드
- 실행 결과:
---

 - ### 'check_ascii.cpp'

```cpp
#include <stdio.h>
#include <conio.h>

int main(void) {
    int chr;

    do {
        chr = getch();
        if (chr == 0 || chr == 0xe0) {
            chr = getch();
            printf("확장키 code=%d\n", chr);
        }
        else {
            printf("아스키 code=%d\n", chr);
        }
    } while (1);

    return 0;
}
```
- 설명: 입력된 키의 확장키 또는 ASCII코드를 출력하는 코드
- 실행 결과:
---

 - ### 'gamepgm.h'

```
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
```
- 설명: 
- 실행 결과:
---