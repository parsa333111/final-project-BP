#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "change string.h"

int row = 37;

struct hexagon {
    int xlight, ylight;
    int xhouse, yhouse;
    int xwell, ywell;
    int type;
    bool on;
    bool open;
    int character;
};
/*
type :
1 = house
2 = light
3 = water well
4 = escape
*/
struct hexagon hex[13][9];

void assigned() {
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            hex[i][j].type = 0;
        }
    }
    hex[1][0].type = hex[1][8].type = hex[11][0].type = hex[11][8].type = 4;
}

#include "create.h"

int house = 1, light = 2, well = 3, escape = 4, one = 1, zero = 0, two = 2, three = 3, four = 4, five = 5, six = 6;

int *give_pointer(int x) {
    switch (x) {
        case 1:
            return &one;
        case 2:
            return &two;
        case 3:
            return &three;
        case 4:
            return &four;
        case 5:
            return &five;
        case 6:
            return &six;
    }
}

int main () {
    assigned();
    create();
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
                    FILE *map1 = fopen("map1.txt", "wb");
                    int mande;
                    mande = 6;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d light on\n", mande);
                        printf("Enter X, y for add %d light on : ", 7 - mande);
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&light, 4, 1, map1);
                            fwrite(&x, 4, 1, map1);
                            fwrite(&y, 4, 1, map1);
                            fwrite(&one, 4, 1, map1);
                            fwrite(give_pointer(7 - mande), 4, 1, map1);
                            hex[x][y].type = 2;
                            hex[x][y].on = 1;
                            mande--;
                            change(str[hex[x][y].ylight], "lamp on", hex[x][y].xlight);
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
                    }
                    mande = 2;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d light off\n", mande);
                        printf("Enter X, y for add light off : ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&light, 4, 1, map1);
                            fwrite(&x, 4, 1, map1);
                            fwrite(&y, 4, 1, map1);
                            fwrite(&zero, 4, 1, map1);
                            fwrite(give_pointer(7 - mande), 4, 1, map1);
                            hex[x][y].type = 2;
                            hex[x][y].on = 1;
                            mande--;
                            change(str[hex[x][y].ylight], "lamp off", hex[x][y].xlight);
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
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
