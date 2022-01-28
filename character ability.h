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

void dfs(int x, int y, int dp[13][9]) {
    for(int i = 0 ; i < 6 ; i++ ) {
        int x1 = hex[x][y].xnei[i], y1 = hex[x][y].ynei[i];
        if(in_range(x1, y1) == 0) continue;
        if(hex[x1][y1].type != house && hex[x1][y1].type != escape && hex[x1][y1].type != light) {
            if(dp[x1][y1] > dp[x][y] + 1) {
                dp[x1][y1] = dp[x][y] + 1;
                dfs(x1, y1, dp);
            }
        }
    }
}

int dis_legal(int x1, int y1, int x2, int y2, int dep) {
    if(in_range(x1, y1) == 0 || dep > 4) return 5;
    if(hex[x1][y1].type == light || hex[x1][y1].type == house || hex[x1][y1].type == escape) return 5;
    if(x1 == x2 && y1 == y2) return dep;
    int mn = 5;
    for(int i = 0 ; i < 6 ; i++ ) {
        mn = minimum(dis_legal(hex[x1][y1].xnei[i], hex[x1][y1].ynei[i], x2, y2, dep + 1), mn);
    }
    return mn;
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

int dis2(int x1, int y1, int x2, int y2, int dep) {
    if(in_range(x1, y1) == 0 || dep > 4) return 5;
    if(hex[x1][y1].type == light || hex[x1][y1].type == house) return 5;
    if(x1 == x2 && y1 == y2) return dep;
    int mn = 5;
    for(int i = 0 ; i < 6 ; i++ ) {
        mn = minimum(dis2(hex[x1][y1].xnei[i], hex[x1][y1].ynei[i], x2, y2, dep + 1), mn);
    }
    if(hex[x1][y1].type == well) {
        if(hex[x1][y1].on == 1) {
            for(int i = 0 ; i < 13 ; i++ ) {
                for(int j = 0 ; j < 9 ; j++ ) {
                    if(hex[i][j].type == well) {
                        if(hex[i][j].on == 1) {
                            mn = minimum(dis2(i, j, x2, y2, dep + 1), mn);
                        }
                    }
                }
            }
        }
    }
    return mn;
}

int dis_obstacle(int x1, int y1, int x2, int y2, int dep) {
    if(in_range(x1, y1) == 0 || dep > 4) return 5;
    if(hex[x1][y1].type == escape) return 5;
    if(x1 == x2 && y1 == y2) return dep;
    int mn = 5;
    for(int i = 0 ; i < 6 ; i++ ) {
        mn = minimum(dis_obstacle(hex[x1][y1].xnei[i], hex[x1][y1].ynei[i], x2, y2, dep + 1), mn);
    }
    if(hex[x1][y1].type == well) {
        if(hex[x1][y1].on == 1) {
            for(int i = 0 ; i < 13 ; i++ ) {
                for(int j = 0 ; j < 9 ; j++ ) {
                    if(hex[i][j].type == well) {
                        if(hex[i][j].on == 1) {
                            mn = minimum(dis_obstacle(i, j, x2, y2, dep + 1), mn);
                        }
                    }
                }
            }
        }
    }
    return mn;
}

int dis_obstacle2(int x1, int y1, int x2, int y2, int dep) {
    if(in_range(x1, y1) == 0 || dep > 4) return 5;
    if(x1 == x2 && y1 == y2) return dep;
    int mn = 5;
    for(int i = 0 ; i < 6 ; i++ ) {
        mn = minimum(dis_obstacle2(hex[x1][y1].xnei[i], hex[x1][y1].ynei[i], x2, y2, dep + 1), mn);
    }
    if(hex[x1][y1].type == well) {
        if(hex[x1][y1].on == 1) {
            for(int i = 0 ; i < 13 ; i++ ) {
                for(int j = 0 ; j < 9 ; j++ ) {
                    if(hex[i][j].type == well) {
                        if(hex[i][j].on == 1) {
                            mn = minimum(dis_obstacle2(i, j, x2, y2, dep + 1), mn);
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
            else if(hex[x][y].character == 0 || hex[x][y].character == 3) {
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
            sw = 1;
            continue;
        }
        printf("Wrong input press enter and try again");
        getchar();
        continue;
    }
}

void print_board_char7(char str[40][110]) {
    int x, y;
    while(true) {
        system("cls");
        print_board(str);
        printf("You choose MS you must move your character between 1-4 hexagon your character can move from obstacle\n");
        printf("Enter X, Y of your destination :");
        scanf("%d%d", &x, &y);
        getchar();
        if(in_range(x, y) == 0) {
            printf("WE\n");
            printf("Wrong input press inter and try again");
            getchar();
            continue;
        }
        int fx = findx(7), fy = findy(7);
        //printf("%d %d %d %d\n", x, y, fx, fy);
        int dis1 = dis_obstacle(x, y, fx, fy, 0);
        //printf("dis : %d\n", dis1);
        if(0 <  dis1 && dis1 < 5 && hex[x][y].type != light &&  hex[x][y].type != escape && hex[x][y].character == 0 && hex[x][y].type != house) {
            swap_str_name(x, y, fx, fy, str);
            hex[x][y].character = 7;
            hex[fx][fy].character = 0;
            break;
        }
        else {
            printf("Wrong input press inter and try again");
            getchar();
        }
    }
}

void print_board_char8(char str[40][110]) {
    bool mo1 = 0, mo2 = 0;
    while(true) {
        system("cls");
        if(mo1 == 1 && mo2 == 1) break;
        print_board(str);
        printf("You choose SG you must move him 1-3 hexagon and make 3 move to make closer other character to him\n");
        printf("1)move SG\n");
        printf("2)move other character\n");
        int op;
        scanf("%d", &op);
        getchar();
        if(op == 1 && mo1 == 1) {
            printf("Wrong input press enter and try again\n");
            getchar();
            continue;
        }
        if(op == 2 && mo2 == 1) {
            printf("Wrong input press enter and try again\n");
            getchar();
            continue;
        }
        if(op == 1) {
            int x, y;
            system("cls");
            print_board(str);
            printf("Enter your destination X, y : ");
            scanf("%d%d", &x, &y);
            getchar();
            int fx = findx(8), fy = findy(8);
            if(in_range(x, y) == 0) {
                printf("Wrong input press enter and try again\n");
                getchar();
                continue;
            }
            if(hex[x][y].character != 0 || hex[x][y].type == light || hex[x][y].type == house || hex[x][y].type == escape) {
                printf("Wrong input press enter and try again\n");
                getchar();
                continue;
            }
            int dis1 = dis(x, y, fx, fy, 0);
            if(dis1 > 0 && dis1 < 4) {
                swap_str_name(x, y, fx, fy, str);
                hex[x][y].character = 8;
                hex[fx][fy].character = 0;
                mo1 = 1;
            }
            else {
                printf("Wrong input press enter and try again\n");
                getchar();
                continue;
            }
        }
        else if(op == 2) {
            int dp[13][9];
            for(int i = 0 ; i < 13 ; i++ ) {
                for(int j = 0 ; j < 9 ; j++ ) {
                    dp[i][j] = 100;
                }
            }
            int fx = findx(8), fy = findy(8);
            dp[fx][fy] = 0;
            dfs(fx, fy, dp);
            int move_char = 3;
            while(move_char) {
                system("cls");
                print_board(str);
                printf("choose your character to make closer to SG \n");
                printf("You have %d move\n", move_char);
                print_choosing_menu2();
                int op2;
                scanf("%d", &op2);
                getchar();
                if(op2 < 1 || op2 > 8) {
                    printf("Wrong input press enter and try again\n");
                    getchar();
                    continue;
                }
                else {
                    int x, y;
                    printf("Enter Your destination X, y for ");
                    print_char(op2);
                    printf(" : ");
                    scanf("%d%d", &x, &y);
                    getchar();
                    int ffx = findx(op2), ffy = findy(op2);
                    if(in_range(x, y) == 0) {
                        printf("Wrong input press enter and try again\n");
                        getchar();
                        continue;
                    }
                    if(hex[x][y].type == house || hex[x][y].type == escape || hex[x][y].type == light || hex[x][y].character != 0) {
                        printf("Wrong input press enter and try again\n");
                        getchar();
                        continue;
                    }
                    int fas = dp[ffx][ffy] - dp[x][y];
                    int diss = dis_legal(x, y, ffx, ffy, 0);;
                    if(fas <= 0 || diss > move_char) {
                        printf("Wrong input press enter and try again\n");
                        getchar();
                        continue;
                    }
                    swap_str_name(x, y, ffx, ffy, str);
                    hex[x][y].character = op2;
                    hex[ffx][ffy].character = 0;
                    move_char -= diss;
                }
            }
            mo2 = 1;
        }
        else {
            printf("Wrong input press enter and try again\n");
            getchar();
            continue;
        }


    }
}
