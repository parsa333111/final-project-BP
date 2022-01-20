#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "menu.h"


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
                if(op2 == 1) {

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
