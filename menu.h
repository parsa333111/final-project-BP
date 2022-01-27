#include <stdio.h>

void print_first_menu() {
    system("cls");
    printf("Welcome to mr.jack\n");
    printf("1)start new game\n2)load\n3)create custom map\n4)exit\nenter number: ");
}

void print_custom_map_menu() {
    system("cls");
    printf("Select your custom map number in range of 1 and 9\n");
    printf("10)back\n");
    printf("select your custom map your previous data in your selected custom map may lost: ");
}

void print_start_new_game_map() {
    system("cls");
    printf("choose your game map in range [1, 9] or enter 0 for default map\n");
    printf("10)back\n");
}

void print_load_game_map() {
    system("cls");
    printf("choose your saved game number in range [1, 9]\n");
    printf("10)back\n");
}

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

void print_ab(int x) {
    if(x == 1) {
        printf(":Move 1 to 3 hexagon and choose you light direction");
    }
    if(x == 2) {
        printf(":Move 1 to 3 hexagon and swap close and open escape");
    }
    if(x == 3) {
        printf(":Move 1 to 3 hexagon or change location with another character");
    }
    if(x == 4) {
        printf(":Move 1 to 3 hexagon and swap on light and off light");
    }
    if(x == 5) {
        printf(":Move 1 to 3 hexagon and proof one random character innocent ");
    }
    if(x == 6) {
        printf(":Move 1 to 3 hexagon and change one of manholes");
    }
    if(x == 7) {
        printf(":Move 1 to 4 hexagon ignore obstacle");
    }
    if(x == 8) {
        printf(":Move 1 to 3 hexagon and make total of three move to make closer other characters");
    }
}

void print_choosing_menu() {
    printf("choose your character to play with \n");
    for(int i = 1 ; i <= 8 ; i++ ) {
        printf("%d)", i);
        print_char(i);
        print_ab(i);
        printf("\n");
    }
    printf("0)for catch jack 10)for See card in hand 11)for see direction of watson's light 12)print jack character 13)jack escape 14)save game\n");
}


void print_choosing_menu2() {
    for(int i = 1 ; i <= 8 ; i++ ) {
        printf("%d)", i);
        print_char(i);
        print_ab(i);
        printf("\n");
    }
}

void shelock_menu() {
    system("cls");
    printf("1)detective card using shelock\n");
    printf("2)jack card using shelock\n");

}
