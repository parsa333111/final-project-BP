#include <stdio.h>
#include <stdlib.h>
//100 dorchand turn[1,4]
int main () {
    FILE *f = fopen("back saved map1.txt", "rb");
    int endl = 0;
    while(1) {
        int x;
        if(fread(&x, 4, 1, f) ==0) break;
        printf("%d ", x);
        endl++;
        if(endl % 5 == 0) {
            printf("\n");
        }
    }
    fclose(f);
}
