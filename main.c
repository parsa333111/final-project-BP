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

void create_light_xy() {
    hex[0][0].ylight = 4, hex[0][0].xlight = 1;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 0 ; j <= 12 ; j+=2) {
            if(i == 0 && j == 0)continue;
            hex[j][i].xlight = hex[0][0].xlight + (8 * j);
            hex[j][i].ylight = hex[0][0].ylight + (4 * i);
        }
    }
    hex[1][0].ylight = 2, hex[1][0].xlight = 9;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 1 ; j <= 12 ; j+=2) {
            if(i == 1 && j == 0)continue;
            hex[j][i].xlight = hex[1][0].xlight + (8 * j) - 8;
            hex[j][i].ylight = hex[1][0].ylight + (4 * i);
        }
    }
}

int main () {
    assigned();
    create_light_xy();
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
                    int mande;
                    mande = 6;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d light on\n", mande);
                        printf("Enter X, y for add light on : ");
                        int x, y;
                        scanf("%d%d", &x, &y);
                        if(hex[x][y].type != 0) {
                            printf("this position isn't empty try again\n");
                        }
                        else {
                            printf("%d %d\n", hex[x][y].ylight, hex[x][y].xlight);
                            hex[x][y].type = 2;
                            hex[x][y].on = 1;
                            mande--;
                            change(str[hex[x][y].ylight], "lamp on", hex[x][y].xlight);
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
