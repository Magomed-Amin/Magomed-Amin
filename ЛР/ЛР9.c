#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Mod(int x, int y) {
    int k = ((x % y) + y) % y;
    return k;
}
int main() {
    int i = 11, j = 13, l = 10;  // Начальные значения
    int k;

    for (k = 0; k < 50; k++) {
        // Рекуррентные соотношения
        int new_i = abs(k - 15) - fmin(j / 3, Mod((j + l), 10)) - 20;
        int new_j = -(j + k) / 5 + abs(Mod((j * l), 8));
        int new_l = fmax(Mod((i + k), 15), Mod(l, 14));
        int newI = abs(k - 15) - fmin(j / 3, Mod((j + l), 10)) - 20;
        int newJ = -(j + k) / 5 + abs(Mod((j * l), 8));
        int newL = fmax(Mod((i + k), 15), Mod(l, 14));

        // Переопределение координат
        i = new_i;
        j = new_j;
        l = new_l;
        i = newI;
        j = newJ;
        l = newL;

        // Проверка на попадание в заданную область
        if (i >= 5 && i <= 15 && j >= -15 && j <= -5) {
            printf("YES %d\n", k);
            break;
        }
    }
    if (k == 50) {
        printf("NO\n");
    }
    return 0;
}