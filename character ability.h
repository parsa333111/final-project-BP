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
        printf("%d %d %d %d\n", x, y, fx, fy);
        int dis1 = dis(x, y, fx, fy, 0);
        printf("dis : %d\n", dis1);
        getchar();
        getchar();
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
