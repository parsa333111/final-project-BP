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
int findx(int cha) {
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].character == cha) {
                return i;
            }
        }
    }
}
int findy(int cha) {
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].character == cha) {
                return j;
            }
        }
    }
}

int dis(int x1, int y1, int x2, int y2, int dep) {
    if(in_range(x1, y1) == 0 || dep > 4) return 5;
    if(hex[x1][y1].type == light || hex[x1][y1].type == house || hex[x1][y1].type == escape) return 5;
    if(x1 == x2 && y1 == y2) return dep;
    int mn = 5;
    for(int i = 0 ; i < 6 ; i++ ) {
        mn = minimum(dis(hex[x1][y1].xnei[i], hex[x1][y1].ynei[i], x2, y2, dep + 1), mn);
    }
    if(hex[x1][y1].type == well) {
        if(hex[x1][y1].on == 1) {
            for(int i = 0 ; i < 13 ; i++ ) {
                for(int j = 0 ; j < 9 ; j++ ) {
                    if(hex[i][j].type == well) {
                        if(hex[i][j].on == 1) {
                            mn = minimum(dis(i, j, x2, y2, dep + 1), mn);
                        }
                    }
                }
            }
        }
    }
    return mn;
}

void print_board_char1(char str[40][110]) {
    int x, y;
    while(true) {
        system("cls");
        print_board(str);
        printf("You choose JW you must move your character between 1-3 hexagon\n");
        printf("Enter X, Y of your destination :");
        scanf("%d%d", &x, &y);
        getchar();
        if(in_range(x, y) == 0) {
            printf("Wrong input press inter and try again");
            getchar();
            continue;
        }
        int fx = findx(1), fy = findy(1);
        //printf("%d %d %d %d\n", x, y, fx, fy);
        int dis1 = dis(x, y, fx, fy, 0);
        //printf("dis : %d\n", dis1);
        if(0 <  dis1 && dis1 < 4 && hex[x][y].type != light &&  hex[x][y].type != escape && hex[x][y].character == 0) {
            swap_str_name(x, y, fx, fy, str);
            hex[x][y].character = 1;
            hex[fx][fy].character = 0;
            hex[fx][fy].tartib = 0;
            break;
        }
        else {
            printf("Wrong input press inter and try again");
            getchar();
        }
    }
    //enum {u, d, lu, ld, ru, rd};
    while(true) {
        system("cls");
        print_board(str);
        printf("You must choose your direction of your light\n");
        printf("1)Up\n");
        printf("2)Down\n");
        printf("3)Left and Up\n");
        printf("4)Left and down\n");
        printf("5)Right and up\n");
        printf("6)Right and down\n");
        int dir;
        scanf("%d", &dir);
        getchar();
        if(0 < dir && dir < 7) {
            hex[x][y].tartib = dir;
            break;
        }
        else {
            printf("Wrong input press enter and try again\n");
            getchar();
        }
    }

}

void print_board_char2(char str[40][110]) {
    while(true) {
        int x, y;
        system("cls");
        print_board(str);
        printf("You choose IL you must move your character between 1-3 hexagon\n");
        printf("Enter X, Y of your destination :");
        scanf("%d%d", &x, &y);
        getchar();
        if(in_range(x, y) == 0) {
            printf("Wrong input press inter and try again");
            getchar();
            continue;
        }
        int fx = findx(2), fy = findy(2);
        //printf("%d %d %d %d\n", x, y, fx, fy);
        int dis1 = dis(x, y, fx, fy, 0);
        //printf("dis : %d\n", dis1);
        if(0 <  dis1 && dis1 < 4 && hex[x][y].type != light &&  hex[x][y].type != escape && hex[x][y].character == 0) {
            swap_str_name(x, y, fx, fy, str);
            hex[x][y].character = 2;
            hex[fx][fy].character = 0;
            break;
        }
        else {
            printf("Wrong input press inter and try again");
            getchar();
        }
    }
    int x1, y1;
    while(true) {
        system("cls");
        print_board(str);
        printf("You must swap close escape with open escape\n");
        printf("choose open escape enter X, y : ");
        scanf("%d%d", &x1, &y1);
        getchar();
        if(in_range(x1, y1) == 0) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else if(hex[x1][y1].type != escape) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else if(hex[x1][y1].on == 0) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else {
            break;
        }
    }

    int x2, y2;
    while(true) {
        system("cls");
        print_board(str);
        printf("choose close escape enter X, y : ");
        scanf("%d%d", &x2, &y2);
        getchar();
        if(in_range(x2, y2) == 0) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else if(hex[x2][y2].type != escape) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else if(hex[x2][y2].on == 1) {
            printf("Wrong input press inter and try again");
            getchar();
        }
        else {
            break;
        }
    }
    swap_bool(&hex[x1][y1].on, &hex[x2][y2].on);
    swap_str_type(x1, y1, x2, y2, str);
}

void print_board_char3(char str[40][110]) {
    int op;
    while(true) {
        system("cls");
        print_board(str);
        printf("You choose WG you must move him 1-3 hexagon or swap him with another character for move Enter 1 for swap Enter 2 :");
        scanf("%d", &op);
        getchar();
        if(op != 1 && op != 2) {
            printf("Wrong input press enter and try again\n");
            getchar();
        }
        else break;
    }
    if(op == 1) {
        while(true) {
            int x, y;
            system("cls");
            print_board(str);
            printf("You choose to move WG between 1-3 hexagon\n");
            printf("Enter X, Y of your destination :");
            scanf("%d%d", &x, &y);
            getchar();
            if(in_range(x, y) == 0) {
                printf("Wrong input press inter and try again");
                getchar();
                continue;
            }
            int fx = findx(3), fy = findy(3);
            //printf("%d %d %d %d\n", x, y, fx, fy);
            int dis1 = dis(x, y, fx, fy, 0);
            //printf("dis : %d\n", dis1);
            if(0 <  dis1 && dis1 < 4 && hex[x][y].type != light &&  hex[x][y].type != escape && hex[x][y].character == 0) {
                swap_str_name(x, y, fx, fy, str);
                hex[x][y].character = 3;
                hex[fx][fy].character = 0;
                break;
            }
            else {
                printf("Wrong input press inter and try again");
                getchar();
            }
        }
    }
    else {
        while(true) {
            system("cls");
            print_board(str);
            int x, y;
            printf("You choose to swap WG with another character Enter X, y of another character :");
            scanf("%d%d", &x, &y);
            getchar();
            if(in_range(x, y) == 0) {
            }
            else if(hex[x][y].character == 0) {
                printf("Wrong input press inter and try again");
                getchar();
            }
            else {
                int fx = findx(3), fy = findy(3);
                swap_int(&hex[x][y].character, &hex[fx][fy].character);
                swap_str_name(x, y, fx, fy, str);
                break;
            }
        }
    }
}

void print_board_char4(char str[40][110]) {
    bool sw = 0, mo = 0;
    while(true) {
        if(mo == 1 && sw == 1) break;
        int op;
        system("cls");
        print_board(str);
        printf("You choose JS you must move him 1-3 hexagon and you must swap on light and off light\n");
        printf("choose which one do you do first\n");
        printf("1)move\n");
        printf("2)swap\n");
        scanf("%d", &op);
        getchar();
        if(op == 1 && mo == 1) {
            printf("You done that before\n");
            printf("Press enter and try again");
            getchar();
            continue;
        }
        if(op == 2 && sw == 1) {
            printf("You done that before\n");
            printf("Press enter and try again");
            getchar();
            continue;
        }
        if(op == 1) {
            int fx = findx(4), fy = findy(4);
            int x, y;
            system("cls");
            print_board(str);
            printf("Enter X, Y your destination for JS: ");
            scanf("%d%d", &x, &y);
            getchar();
            if(in_range(x, y) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x][y].type == house || hex[x][y].type == escape || hex[x][y].type == light || hex[x][y].character != 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            int dis1 = dis(x, y, fx, fy, 0);
            if(dis1 > 0 && 4 > dis1) {
                swap_str_name(x, y, fx, fy, str);
                hex[x][y].character = 4;
                hex[fx][fy].character = 0;
                hex[fx][fy].tartib = 0;
                mo = 1;
                continue;
            }
        }
        int x1, y1, x2, y2;
        if(op == 2) {
            printf("Choose your on light X, Y : ");
            scanf("%d%d", &x1, &y1);
            getchar();
            if(in_range(x1, y1) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x1][y1].type != light || hex[x1][y1].on != 1) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            printf("Choose your off light X, Y : ");
            scanf("%d%d", &x2, &y2);
            getchar();
            if(in_range(x2, y2) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x2][y2].type != light || hex[x2][y2].on != 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            swap_str_type(x1, y1, x2, y2, str);
            swap_bool(&hex[x1][y1].on, &hex[x2][y2].on);
            break;
        }
        printf("Wrong input press enter and try again");
        getchar();
        continue;
    }
}

void print_board_char5(char str[40][110], int dor, int tur) {
    int x, y;
    while(true) {
        system("cls");
        print_board(str);
        printf("You choose SH you must move your character between 1-3 hexagon\n");
        printf("Enter X, Y of your destination :");
        scanf("%d%d", &x, &y);
        getchar();
        if(in_range(x, y) == 0) {
            printf("Wrong input press inter and try again");
            getchar();
            continue;
        }
        int fx = findx(5), fy = findy(5);
        //printf("%d %d %d %d\n", x, y, fx, fy);
        int dis1 = dis(x, y, fx, fy, 0);
        //printf("dis : %d\n", dis1);
        if(0 <  dis1 && dis1 < 4 && hex[x][y].type != light &&  hex[x][y].type != escape && hex[x][y].character == 0) {
            swap_str_name(x, y, fx, fy, str);
            hex[x][y].character = 5;
            hex[fx][fy].character = 0;
            hex[fx][fy].tartib = 0;
            break;
        }
        else {
            printf("Wrong input press inter and try again");
            getchar();
        }
    }
    while(true) {
        system("cls");
        print_board(str);
        int rd = rand() % 8;
        rd++;
        if(shelock[rd] == 0) {
            if(give_turn(dor, tur) == 1) {
                shelock_detective[shd++] = rd;
            }
            else {
                shelock_jack[shj++] = rd;
            }
            shelock[rd] = 1;
            printf("Only player who play shelock must see screen\n");
            int sec = 5;
            while(sec) {
                printf("card reveal in %d second", sec);
                sec--;
                delay(1);
                printf("\r");
            }
            sec = 5;
            while(sec) {
                print_char(rd);
                printf(" isn't jack ");
                printf("card disappear in %d second", sec);
                delay(1);
                sec--;
                printf("\r");
            }
            break;
        }
    }
}

void print_board_char6(char str[40][110]) {
    bool sw = 0, mo = 0;
    while(true) {
        if(mo == 1 && sw == 1) break;
        int op;
        system("cls");
        print_board(str);
        printf("You choose JB you must move him 1-3 hexagon and you must move manhole cover \n");
        printf("choose which one do you do first\n");
        printf("1)move him\n");
        printf("2)move manhole\n");
        scanf("%d", &op);
        getchar();
        if(op == 1 && mo == 1) {
            printf("You done that before\n");
            printf("Press enter and try again");
            getchar();
            continue;
        }
        if(op == 2 && sw == 1) {
            printf("You done that before\n");
            printf("Press enter and try again");
            getchar();
            continue;
        }
        if(op == 1) {
            int fx = findx(6), fy = findy(6);
            int x, y;
            system("cls");
            print_board(str);
            printf("Enter X, Y your destination for JB: ");
            scanf("%d%d", &x, &y);
            getchar();
            if(in_range(x, y) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x][y].type == house || hex[x][y].type == escape || hex[x][y].type == light || hex[x][y].character != 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            int dis1 = dis(x, y, fx, fy, 0);
            if(dis1 > 0 && 4 > dis1) {
                swap_str_name(x, y, fx, fy, str);
                hex[x][y].character = 6;
                hex[fx][fy].character = 0;
                hex[fx][fy].tartib = 0;
                mo = 1;
                continue;
            }
        }
        int x1, y1, x2, y2;
        if(op == 2) {
            printf("Choose your well with cover X, Y : ");
            scanf("%d%d", &x1, &y1);
            getchar();
            if(in_range(x1, y1) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x1][y1].type != well || hex[x1][y1].on != 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            printf("Choose your open well X, Y : ");
            scanf("%d%d", &x2, &y2);
            getchar();
            if(in_range(x2, y2) == 0) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            if(hex[x2][y2].type != well || hex[x2][y2].on != 1) {
                printf("Wrong input press enter and try again");
                getchar();
                continue;
            }
            swap_str_type(x1, y1, x2, y2, str);
            swap_bool(&hex[x1][y1].on, &hex[x2][y2].on);
            break;
        }
        printf("Wrong input press enter and try again");
        getchar();
        continue;
    }
}

void print_board_char7(char str[40][110]) {

}
