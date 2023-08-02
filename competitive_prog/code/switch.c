#include <stdio.h>
int main () {
    // Color could be:
    // RED == 1
    // GREEN == 2
    // BLUE == 3
    int color = 2;
    switch (color) {
        case 1: printf("red\n"); break;
        case 2: printf("green\n"); break;
        case 3: printf("blue\n"); break;
    }
    return 0;
}
