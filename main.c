#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "menu.h"

int row = 37;

struct hexagon {
    int x, y;
    int type;
    bool on_open;

};
/*
type :
1 = house
2 = lamp
3 = water well
4 = escape
*/
int main () {
    while(true) {
        print_first_menu();
        int op;
        scanf("%d", &op);
        getchar();
        if(op == 1) {

        }
        else if(op == 2) {

        }
        else if(op == 3) {
            while(true) {
                print_custom_map_menu();
                int op2;
                scanf("%d", &op2);
                getchar();
                FILE *fp = fopen("row board.txt", "r");
                char str[40][110];
                for(int i = 0 ; i < row ; i++ ) {
                    char ch;
                    int cl = 0;
                    while((ch = fgetc(fp)) != EOF) {
                        if(ch == '\n') break;
                        str[i][cl] = ch;
                        cl++;
                    }
                    str[i][cl] = '\0';
                }
                fclose(fp);
                getchar();
                if(op2 == 1) {
                    while(true) {
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }

                    }
                }
                else if(op2 == 2) {

                }
                else if(op2 == 3) {


                }
                else if(op2 == 4) {
                    break;
                }
                else {
                    printf("Wrong input\npress enter and try again\n");
                    getchar();
                }
            }
        }
        else if(op == 4) {
            break;
        }
        else {
            printf("Wrong input\npress enter and try again\n");
            getchar();
        }
    }
    return 0;
}
