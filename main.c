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
    int xescape, yescape;
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

bool in_range(int x, int y) {
    if(x > 12 || x < 0 || y < 0 || y > 8)return 0;
    return 1;
}

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

void swap(char *c1, char *c2) {
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

char ret[20];

char *add_number_end(char *c, int add) {
    strcpy(ret, c);
    ret[strlen(c)] = add + '0';
    ret[strlen(c) + 1] = '\0';
    return ret;
}

char *add_number_before_type(char *c, int add) {
    strcpy(ret, c);
    int sz = strlen(c);
    for(int i = sz ; i > sz - 4 ; i--) {
        swap(&ret[i], &ret[i-1]);
    }
    ret[sz - 4] = add + '0';
    ret[strlen(c) + 1] = '\0';
    return ret;
}

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
                if(op2 < 10 && op2 > 0) {
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
                    FILE *map = fopen(add_number_before_type("back_map.txt", op2), "wb");
                    int mande;
                    mande = 2;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d open escape\n", mande);
                        printf("Enter X, y for add open escape : ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&escape, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&one, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = escape;
                            hex[x][y].on = one;
                            change(str[hex[x][y].yescape], "es open", hex[x][y].xescape);
                            mande--;
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
                        printf("You must add %d \n", mande);
                        printf("Enter X, y for add close escape : ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&escape, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = escape;
                            hex[x][y].on = zero;
                            change(str[hex[x][y].ylight], "es close", hex[x][y].xlight);
                            mande--;
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
                    }
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
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&light, 4, 1, map);//type x y use tartib
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&one, 4, 1, map);
                            fwrite(give_pointer(7 - mande), 4, 1, map);
                            hex[x][y].type = light;
                            hex[x][y].on = one;
                            change(str[hex[x][y].ylight], add_number_end("lamp on", 7 - mande), hex[x][y].xlight);
                            mande--;
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
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&light, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = light;
                            hex[x][y].on = zero;
                            change(str[hex[x][y].ylight], "lamp off", hex[x][y].xlight);
                            mande--;
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
                    }
                    mande = 6;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d open well water\n", mande);
                        printf("Enter X, y for add %d open well water : ", 7 - mande);
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&well, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&one, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = well;
                            hex[x][y].on = one;
                            mande--;
                            change(str[hex[x][y].ywell], "ww open", hex[x][y].xwell);
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
                        printf("You must add %d close well water\n", mande);
                        printf("Enter X, y for add close well water : ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&well, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = well;
                            hex[x][y].on = zero;
                            mande--;
                            change(str[hex[x][y].ywell], "ww close", hex[x][y].xwell);
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
                    }
                    while(true) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You can add infinity house\n");
                        printf("Enter X, y for add house or enter -1 -1 for finish this part: ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(x == -1 && y == -1) break;
                        if(!in_range(x, y)) {
                            printf("Wrong input\n");
                            printf("press enter and try again\n");
                            getchar();
                            getchar();
                            continue;
                        }
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            fwrite(&house, 4, 1, map);
                            fwrite(&x, 4, 1, map);
                            fwrite(&y, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            fwrite(&zero, 4, 1, map);
                            hex[x][y].type = house;
                            change(str[hex[x][y].yhouse], "  house ", hex[x][y].xhouse);
                        }
                        getchar();
                        printf("press enter for continue build ,ap\n");
                        getchar();
                    }
                }
                else if(op2 == 10) {
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
