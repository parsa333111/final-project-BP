#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "character.h"
#include "menu.h"

int row = 37;

bool shelock[9];
int shelock_jack[9], shelock_detective[9], shd, shj;

void delay(int x) {
    long long int xp = 300000000LL * x;
    for(int i = 0 ; i < xp ; i++ ) {
        int t = i;
        t = t & 101;
    }
}

enum {u, d, lu, ld, ru, rd};

int minimum(int x, int y) {
    return (x < y) ? x : y;
}

void swap_int(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_bool(bool *x, bool *y) {
    bool tmp = *x;
    *x = *y;
    *y = tmp;
}

struct node {
    int id;
    struct node *nex;
};

struct hexagon {
    int xlight, ylight;
    int xhouse, yhouse;
    int xwell, ywell;
    int xescape, yescape;
    int type;
    bool on;
    int character;
    int xname, yname;
    int xnei[6], ynei[6];
    int tartib;
    int light_dir;
};

void swap_list(struct node *list, int valx, int y) {
    struct node *cpy_list = list;
    while(list -> id != valx) {
        list = list -> nex;
    }
    for(int i = 0 ; i < y ; i++ ) {
        cpy_list = cpy_list -> nex;
    }
    list -> id = cpy_list -> id;
    cpy_list -> id = valx;
}

/*
type :
1 = house
2 = light
3 = water well
4 = escape
5 = character
*/

/*
character :
1 = JW
2 = IL
3 = WG
4 = JS
5 = SH
6 = JB
7 = MS
8 = SG
*/

int JW = 1, IL = 2, WG = 3, JS = 4, SH = 5, JB = 6, MS = 7, SG = 8;

struct hexagon hex[13][9];

bool in_range(int x, int y) {
    if(x > 12 || x < 0 || y < 0 || y > 8)return 0;
    return 1;
}

void assigned() {
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            hex[i][j].character = hex[i][j].type = 0;
        }
    }
}

#include "create.h"

int house = 1, light = 2, well = 3, escape = 4, character = 5, one = 1, zero = 0, two = 2, three = 3, four = 4, five = 5, six = 6;

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

void add_in_list(int i, struct node *list) {
    while(list -> nex != NULL) {
        list = list -> nex;
    }
    struct node *new = malloc(sizeof(struct node*));
    new -> id = i;
    list -> nex = new;
    new -> nex = NULL;
}

void shuffle(struct node *list, int sz) {
    struct node *cpy_list = list;
    for(int i = 1 ; i <= 8 ; i++ ) {
        list = cpy_list;
        int size = i;
        int j = rand() % size;
        j++;
        int cpy_i = i - 1, cpy_j = j - 1;
        int val_i, val_j;
        while(cpy_i--) {
            list = list -> nex;
        }
        val_i = list -> id;
        list = cpy_list;
        while(cpy_j--) {
            list = list -> nex;
        }
        val_j = list -> id;
        list -> id = val_i;
        //
        list = cpy_list;
        cpy_i = i - 1;
        while(cpy_i--) {
            list = list -> nex;
        }
        list -> id = val_j;
    }
}

struct node* next_four(struct node *list) {
    for(int i = 0 ; i < 3 ; i++ ) {
        list = list -> nex;
    }
    struct node *list2 = list -> nex;
    list -> nex = NULL;
    return list2;
}

void print_board(char str[40][110]) {
    for(int i = 0 ; i < row ; i++ ) {
        puts(str[i]);
    }
}

void print_list(struct node *list, int x) {
    x--;
    while(x--) {
        list = list -> nex;
    }
    while(list != NULL) {
        print_char(list -> id);
        printf(" ");
        list = list -> nex;
    }
    printf("\n");
}

int give_turn(int dor, int tur) {
    if(dor % 2 == 1) {
        if(tur == 1 || tur == 4) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        if(tur == 2 || tur == 3) {
            return 1;
        }
        else {
            return 2;
        }
    }
}

void print_turn(int dor, int tur) {
    if(dor % 2 == 1) {
        if(tur == 1 || tur == 4) {
            printf("detective turn\n");
        }
        else {
            printf("mr.jack turn\n");
        }
    }
    else {
        if(tur == 2 || tur == 3) {
            printf("detective turn\n");
        }
        else {
            printf("mr.jack turn\n");
        }
    }
}

bool exist_list(struct node* list, int find, int ign) {
    while(ign--) list = list -> nex;
    while(list != NULL) {
        if(list -> id == find) return 1;
        list = list -> nex;
    }
    return 0;
}

void swap_hexagon(int x1, int y1, int x2, int y2) {
    swap_int(&hex[x1][y1].tartib, &hex[x2][y2].tartib);
    swap_int(&hex[x1][y1].character, &hex[x2][y2].character);
    swap_int(&hex[x1][y1].type, &hex[x2][y2].type);
    swap_bool(&hex[x1][y1].on, &hex[x2][y2].on);
}


#include "change string.h"
#include "character ability.h"

int main () {
    srand(time(0));
    create();
    while(true) {
        print_first_menu();
        int op;
        scanf("%d", &op);
        getchar();
        if(op == 1 || op == 2) {
            //type x y use tartib
            //100 dorchand turn[1,4]
            assigned();
            int dor, turn, vis, char_on_table[8] = {-1,-1,-1,-1,-1,-1,-1,-1}, jack = 0;
            bool char_on_board = 0;
            char str[40][110];
            if(op == 1) {
                while(true) {
                    print_start_new_game_map();
                    int op2;
                    scanf("%d", &op2);
                    if(op2 == 10)break;
                    getchar();
                    FILE *back_map, *front_map;
                    if(op2 < 0 || op2 > 9) {
                        printf("Wrong input press enter and try again\n");
                        getchar();
                        continue;
                    }
                    else if(op2 == 0) {
                        back_map = fopen("back default map.txt", "rb");
                        front_map = fopen("front default map.txt", "r");
                    }
                    else {
                        back_map = fopen(add_number_before_type("back map.txt", op2), "rb");
                        front_map = fopen(add_number_before_type("front map.txt", op2), "r");
                    }
                    for(int i = 0 ; i < row ; i++ ) {
                        char ch;
                        int cl = 0;
                        while((ch = fgetc(front_map)) != EOF) {
                            if(ch == '\n') break;
                            str[i][cl] = ch;
                            cl++;
                        }
                        str[i][cl] = '\0';
                    }
                    int p;
                    int stack[5], cnt = 0;
                    while(fread(&p, 4, 1, back_map) != 0) {
                        if(cnt > 0) {
                            stack[cnt] = p;
                            cnt++;
                        }
                        else if(cnt == 0) {
                            if(p != 100) {
                                stack[cnt] = p;
                                cnt++;
                            }
                            else {
                                break;
                            }
                        }
                        if(cnt == 5) {            //type x y use tartib
                            int type = stack[0];
                            int x = stack[1];
                            int y = stack[2];
                            int use = stack[3];
                            int tar = stack[4];
                            cnt = 0;
                            if(type != character) hex[x][y].type = type;
                            if(type != character)hex[x][y].on = use;
                            else hex[x][y].character = use;
                            hex[x][y].tartib = tar;
                        }
                    }
                    fread(&dor, 4, 1, back_map);
                    fread(&turn, 4, 1, back_map);
                    fread(&vis, 4, 1, back_map);
                    cnt = 0;
                    while(fread(&char_on_table[cnt], 4, 1, back_map) != 0) {
                        cnt++;
                        char_on_board = 1;
                    }
                    if(0 == fread(&jack, 4, 1, back_map)) jack = 0;
                    break;
                }
            }
            else {
                while(true) {
                    assigned();
                    print_load_game_map();
                    int op2;
                    scanf("%d", &op2);
                    if(op2 == 10)break;
                    getchar();
                    FILE *back_map, *front_map;
                    if(op2 < 1 || op2 > 9) {
                        printf("Wrong input press enter and try again\n");
                        getchar();
                    }
                    else {
                        back_map = fopen(add_number_before_type("back saved map.txt", op2), "rb");
                        front_map = fopen(add_number_before_type("front saved map.txt", op2), "r");
                    }
                    for(int i = 0 ; i < row ; i++ ) {
                        char ch;
                        int cl = 0;
                        while((ch = fgetc(front_map)) != EOF) {
                            if(ch == '\n') break;
                            str[i][cl] = ch;
                            cl++;
                        }
                        str[i][cl] = '\0';
                    }
                    int p;
                    int stack[5], cnt = 0;
                    while(fread(&p, 4, 1, back_map) != 0) {
                        if(cnt > 0) {
                            stack[cnt] = p;
                            cnt++;
                        }
                        else if(cnt == 0) {
                            if(p != 100) {
                                stack[cnt] = p;
                                cnt++;
                            }
                            else {
                                break;
                            }
                        }
                        if(cnt == 5) {            //type x y use tartib
                            int type = stack[0];
                            int x = stack[1];
                            int y = stack[2];
                            int use = stack[3];
                            int tar = stack[4];
                            cnt = 0;
                            if(type != character) hex[x][y].type = type;
                            if(type != character)hex[x][y].on = use;
                            else hex[x][y].character = use;
                            hex[x][y].tartib = tar;
                        }
                    }
                    fread(&dor, 4, 1, back_map);
                    fread(&turn, 4, 1, back_map);
                    fread(&vis, 4, 1, back_map);
                    cnt = 0;
                    while(fread(&char_on_table[cnt], 4, 1, back_map) != 0) {
                        cnt++;
                        char_on_board = 1;
                    }
                    if(0 == fread(&jack, 4, 1, back_map)) jack = 0;
                    break;
                }
            }
            //group 1, group 2
            system("cls");
            {
                struct node *list1 = NULL, *list2 = NULL;
                for(; dor <= 8 ; dor++) {
                     //change list and free them if(dor % 2 == 1) list1 = list2 = NULL;
                    for(int tur = turn ; tur <= 4 ; tur++ ) {
                        if(char_on_board) {
                            char_on_board = 0;
                            for(int i = 1 ; i <= 8 ; i++ ) {
                                if(i == 1) {
                                    list1 = malloc(sizeof(struct node*));
                                    list1 -> nex = NULL;
                                    list1 -> id = char_on_table[i-1];
                                }
                                else {
                                    add_in_list(char_on_table[i-1], list1);
                                }
                            }
                            list2 = next_four(list1);
                         }
                        else if (tur == 1 && dor % 2 == 1) {
                            if(jack == 0) {
                                jack = rand() % 8;
                                jack++;
                                shelock[jack] = 1;
                                int sec = 2;
                                while(sec) {
                                    printf("only jack must see screen, jack character reveal in %d second", sec);
                                    delay(1);
                                    printf("\r");
                                    sec--;
                                }
                                sec = 2 ;
                                while(sec) {
                                    printf("only jack must see screen, jack character is ");
                                    print_char(jack);
                                    printf(" jack character disappear in %d second", sec);
                                    delay(1);
                                    printf("\r");
                                    sec--;
                                }
                            }
                            for(int i = 1 ; i <= 8 ; i++ ) {
                                if(i == 1) {
                                    list1 = malloc(sizeof(struct node*));
                                    list1 -> nex = NULL;
                                    list1 -> id = i;
                                }
                                else {
                                    add_in_list(i, list1);
                                }
                            }

                            shuffle(list1, 8);
                            list2 = next_four(list1);
                        }
                        while(true) {
                            system("cls");
                            print_board(str);
                            print_turn(dor, tur);
                            print_choosing_menu();
                            if(dor % 2 == 1) print_list(list1, tur);
                            else print_list(list2, tur);
                            struct node *list = (dor % 2 == 0) ? list2 : list1;
                            int choose_char;
                            scanf("%d", &choose_char);
                            getchar();
                            {
                                if(choose_char == 10) {
                                     while(true) {
                                        shelock_menu();
                                        int op;
                                        scanf("%d", &op);
                                        getchar();
                                        if(op == 1) {
                                            if(shd == 0) {
                                                printf("No card yet\n");
                                            }
                                            for(int i = 0 ; i < shd ; i++ ) {
                                                print_char(shelock_detective[i]);
                                                printf(" can't be jack\n");
                                            }
                                            printf("Press enter for continue");
                                            getchar();
                                            break;
                                        }
                                        else if(op == 2) {
                                            if(shj == 0) {
                                                printf("No card yet\n");
                                            }
                                            for(int i = 0 ; i < shj ; i++ ) {
                                                print_char(shelock_jack[i]);
                                                printf(" can't be jack\n");
                                            }
                                            printf("Press enter for continue");
                                            getchar();
                                            break;
                                        }
                                        else {
                                            printf("Wrong input press enter and try again");
                                            getchar();
                                        }
                                    }
                                    continue;
                                }
                            }
                            if(exist_list(list, choose_char, tur - 1)) {
                                swap_list(list, choose_char, tur - 1);
                                if(choose_char == 1) {
                                    print_board_char1(str);
                                }
                                else if(choose_char == 2) {
                                    print_board_char2(str);
                                }
                                else if(choose_char == 3) {
                                    print_board_char3(str);
                                }
                                else if(choose_char == 4) {
                                    print_board_char4(str);
                                }
                                else if(choose_char == 5) {
                                    print_board_char5(str, dor, tur);
                                }
                                else if(choose_char == 6) {
                                    print_board_char6(str);
                                }
                                else if(choose_char == 7) {
                                    print_board_char7(str);
                                }
                                else if(choose_char == 8) {

                                }
                                break;
                            }
                            else {
                                printf("Wrong input press Enter and try again\n");
                                getchar();
                            }
                        }
                    }
                    turn = 1;
                }
            }
        }
        else if(op == 3) {
            while(true) {
                assigned();
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
                        printf("press enter for continue build map\n");
                        getchar();
                    }
                    mande = 2;
                    while(mande) {
                        system("cls");
                        printf("current map\n");
                        for(int i = 0 ; i < row ; i++ ) {
                            puts(str[i]);
                        }
                        printf("You must add %d close escape\n", mande);
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
                        printf("press enter for continue build map\n");
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
                        printf("Enter X, y for add %dth light on : ", 7 - mande);
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
                        printf("press enter for continue build map\n");
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
                        printf("press enter for continue build map\n");
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
                        printf("Enter X, y for add open well water : ");
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
                        printf("press enter for continue build map\n");
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
                        printf("press enter for continue build map\n");
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
                        printf("press enter for continue build map\n");
                        getchar();
                    }
                    for(int i = 1 ; i <= 8 ; i++ ) {
                        mande = 1;
                        while(mande) {
                            system("cls");
                            printf("current map\n");
                            for(int i = 0 ; i < row ; i++ ) {
                                puts(str[i]);
                            }
                            printf("You must add ");
                            print_char(i);
                            printf("\n");
                            printf("Enter X, y for add ");
                            print_char(i);
                            printf(": ");
                            int x, y;
                            scanf("%d%d", &x, &y);
                            if(!in_range(x, y)) {
                                printf("Wrong input\n");
                                printf("press enter and try again\n");
                                getchar();
                                getchar();
                                continue;
                            }
                            if(hex[x][y].character != 0 || hex[x][y].type == light || hex[x][y].type == escape || hex[x][y].type == house) {
                                printf("this position isn't empty try again\n");
                            }
                            else {
                                int dir;
                                printf("You must choose your direction of your light\n");
                                printf("1)Up\n");
                                printf("2)Down\n");
                                printf("3)Left and Up\n");
                                printf("4)Left and down\n");
                                printf("5)Right and up\n");
                                printf("6)Right and down\n");
                                scanf("%d", dir);
                                fwrite(&character, 4, 1, map);
                                fwrite(&x, 4, 1, map);
                                fwrite(&y, 4, 1, map);
                                fwrite(&i, 4, 1, map);
                                if(i == 1) {
                                    fwrite(&dir, 4, 1, map);
                                }
                                else {
                                    fwrite(&zero, 4, 1, map);
                                }
                                    //hex[x][y].type = character;

                                hex[x][y].character = i;
                                change(str[hex[x][y].yname], char_name_sus(i), hex[x][y].xname);
                                mande--;
                            }
                            getchar();
                            printf("press enter for continue build map\n");
                            getchar();
                        }
                    }
                    fclose(map);
                    map = fopen(add_number_before_type("front_map.txt", op2), "w");
                    for(int i = 0 ; i < row ; i++ ) {
                        fputs(str[i], map);
                        fputc('\n', map);
                    }
                    fclose(map);
                    printf("successfully saved press enter to back in menu\n");
                    getchar();
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
