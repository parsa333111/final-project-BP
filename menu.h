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

void print_map_option() {
    printf("1)house\n");
    printf("2)lamp\n");
    printf("3)hole\n");
}
