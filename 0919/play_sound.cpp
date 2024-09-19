#include <stdio.h>
#include <math.h>
#include <windows.h>

int calc_frequency(int octave, int inx);

int main() {
    int index[] = {0, 2, 3, 5, 7, 9, 11, 12};
    int freq[8];

    for (int i = 0; i < 8; i++) {
        freq[i] = calc_frequency(4, index[i]);
    }
    for (int i = 0; i < 7; i++) {
        Beep(freq[i], 500);
    }
    Sleep(1000);

    for (int i = 7; i >= 0; i--) {
        Beep(freq[i], 500);
    }

    return 0;
}

int calc_frequency(int octave, int inx) {
    double do_scale = 32.7032;
    double ratio, temp;
    ratio = pow(2., 1 / 12.);
    temp = do_scale * pow(2, octave - 1);

    for (int i = 0; i < inx; i++) {
        temp = (int) (temp + 0.5);
        temp *= ratio;
    }

    return (int) temp;
}