#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

int k;
double sin(), cos();

int main() {
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; 6.28 > j; j += 0.07) {
            for (i = 0; 6.28 > i; i += 0.02) {
                float c = sin(i),
                      d = cos(j),
                      e = sin(A),
                      f = sin(j),
                      g = cos(A),
                      h = d + 2,
                      D = 1 / (c * h * e + f * g + 5),
                      l = cos(i),
                      m = cos(B),
                      n = sin(B),
                      t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n),
                    y = 12 + 15 * D * (l * h * n + t * m),
                    o = x + 80 * y,
                    N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        for (k = 0; 1761 > k; ++k) {
            if (k % 80 == 0) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                printf("\n");
            }
            else {
                SetConsoleTextAttribute(hConsole, 1 + (int)(15.0 * z[k]));
                printf("%c", b[k]);
            }
        }
        A += 0.04;
        B += 0.02;
        COORD cursorPos = { 0, 0 };
        SetConsoleCursorPosition(hConsole, cursorPos);
        Sleep(50);
    }
    return 0;
}

