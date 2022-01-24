#include <stdio.h>
#include <stdlib.h>
//100 dorchand turn[1,4]
int main () {
    FILE *f = fopen("back default map.txt", "ab");
    while(1) {
        int x;
        scanf("%d", &x);
        if(x == -1) {
            break;
        }
        fwrite(&x, 4, 1, f);
    }
    fclose(f);
}
