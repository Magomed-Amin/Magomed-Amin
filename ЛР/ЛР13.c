#include <stdio.h>
#include <wchar.h>
#define GLAS 3892855585

typedef long long Set;
// а = 160
// А = 128
// я = 229
// Я = 159
void AddInMass(Set* m, int c) {  
    if (c >= 160 && c <= 229) {
        *m |= 1llu << (c - 160);
    } else if (c >= 128 && c <= 159) {
        *m |= 1llu << (c - 128);
    }
}

int IsSeparator(int c) {
    return (c == ' ') || (c == ',') || (c == '\n') || (c == '\t') || (c == WEOF);
}

int main() {
    int end = 0;
    Set m = 0;
    while (1) {
        wchar_t c = getwchar();
        if (c == WEOF) {
            break;
        }
        if (!IsSeparator(c)) {
            Set prevm = m;
            AddInMass(&m, c);
            m = m & GLAS;
            if (m == prevm && m != 0) {
                printf("%s", "YES");
                end = 1;
                break;
            }
        } else {
            Set m = 0;
        }
    }
    if (end == 0) {
        printf("%s", "NO");
        }
    return 0;
}