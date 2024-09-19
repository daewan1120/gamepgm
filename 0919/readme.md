0919 레포트
===
2023664002 강대완
---

### trump.cpp

#### - main
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//트럼프 구조체
struct trump
{
    char order;
    char shape[4];
    char number;
};

//함수 호출
void make_card(trump m_card[]);
void display_card(trump m_card[]);
void shuffle_card(trump m_card[]);

int main() {
    trump card[52];
    make_card(card);
    display_card(card);
    printf("\n\n\n");
    shuffle_card(card);
    display_card(card);

    return 0;
}
```
#### make_card
```cpp
//카드 생성
void make_card(trump m_card[]) {
    char shape[4][4] = {"♠", "◆", "♥", "♣"};

    for (int i = 0; i < 4; i++) {
        for (int j = i * 13; j < (i * 13) + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = (j % 13) + 1;

            switch (m_card[j].number) {
            case 1:
                m_card[j].number = 'A';
                break;
            case 11:
                m_card[j].number = 'J';
                break;
            case 12:
                m_card[j].number = 'Q';
                break;
            case 13:
                m_card[j].number = 'K';
                break;
            default:
                break;
            }
        }
    }
}
```
#### display_card
```cpp
// 카드 출력
void display_card(trump m_card[]) {
    int count = 0;

    for (int i = 0; i < 52; i++) {
        printf("%s", m_card[i].shape);

        if (10 < m_card[i].number) {
            printf("%-2c", m_card[i].number);
        }
        else {
            printf("%-2d", m_card[i].number);
        }
        count ++;

        if ((i % 13) + 1 == 13) {
            printf("\n");
            count = 0;
        }
    }
}
```
- 설명: 커서 제어와 관련된 gotoxy, move_arrow_key 함수를 제공하는 헤더 파일
1. gotoxy: 커서를 지정된 (x, y) 좌표로 이동
2. move_arrow_key: 화살표 키 입력에 따라 커서를 이동

#### shuffle_card
```cpp
//카드 섞기
void shuffle_card(trump m_card[]) {
    int rnd;
    trump temp;
    srand(time(NULL));

    for (int i = 0; i < 52; i++) {
        rnd = rand() % 52;
        temp = m_card[rnd];
        m_card[rnd] = m_card[i];
        m_card[i] = temp;
    }
}
```
- 설명: 커서 제어와 관련된 gotoxy, move_arrow_key 함수를 제공하는 헤더 파일
1. gotoxy: 커서를 지정된 (x, y) 좌표로 이동
2. move_arrow_key: 화살표 키 입력에 따라 커서를 이동


\*asdasd
---