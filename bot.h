
bool is_ban(int x, int y) {
    if(in_range(x, y) == 0) return 1;
    if(hex[x][y].type == light || hex[x][y].type == house || hex[x][y].type == escape || hex[x][y].character != 0) return 1;
    return 0;
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

void move1(char str[40][110]) {
    int fx = findx(1), fy = findy(1);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            hex[hex[fx][fy].xnei[i]][hex[fx][fy].ynei[i]].tartib = 1;
            return;
        }
    }
}

void move2(char str[40][110]) {
    int fx = findx(2), fy = findy(2);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
    int xclose = 0, yclose = 0, xopen = 0, yopen = 0;
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].type == escape) {
                if(hex[i][j].on == 1) {
                    xopen = i, yopen = j;
                }
                else {
                    xclose = i, yclose = j;
                }
            }
        }
    }
    swap_str_type(xopen, yopen, xclose, yclose, str);
}

void move3(char str[40][110]) {
    int fx = findx(3), fy = findy(3);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
}

void move4(char str[40][110]) {
    int fx = findx(4), fy = findy(4);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
    int xclose = 0, yclose = 0, xopen = 0, yopen = 0;
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].type == light) {
                if(hex[i][j].on == 1) {
                    xopen = i, yopen = j;
                }
                else {
                    xclose = i, yclose = j;
                }
            }
        }
    }
    swap_str_type(xopen, yopen, xclose, yclose, str);
}

void move5(char str[40][110]) {
    int fx = findx(5), fy = findy(5);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
}

void move6(char str[40][110]) {
    int fx = findx(6), fy = findy(6);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
    int xclose = 0, yclose = 0, xopen = 0, yopen = 0;
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].type == well) {
                if(hex[i][j].on == 1) {
                    xopen = i, yopen = j;
                }
                else {
                    xclose = i, yclose = j;
                }
            }
        }
    }
    swap_str_type(xopen, yopen, xclose, yclose, str);
}

void move7(char str[40][110]) {
    int fx = findx(7), fy = findy(7);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
}

void move8(char str[40][110]) {
    int fx = findx(8), fy = findy(8);
    for(int i = 0 ; i < 6 ; i++ ) {
        if(is_ban(hex[fx][fy].xnei[i], hex[fx][fy].ynei[i]) == 0) {
            swap_str_name(fx, fy, hex[fx][fy].xnei[i], hex[fx][fy].ynei[i], str);
            break;
        }
    }
    int dp[13][9];
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            dp[i][j] = 100;
        }
    }
    dp[fx][fy] = 0;
    dfs(fx, fy, dp);
    for(int i = 0 ; i < 13 ; i++ ) {
        for(int j = 0 ; j < 9 ; j++ ) {
            if(hex[i][j].type == house || hex[i][j].type == escape || hex[i][j].type == light || hex[i][j].character != 0)continue;
            for(int k = 1 ; k <= 7 ; k++ ) {
                int fxk = findx(k), fyk = findx(k);
                int diss = dis_legal(i, j, fxk, fyk, 0);
                if(diss == 3 && dp[fxk][fyk] > dp[i][j]) {
                    swap_str_name(fx, fy, fxk, fyk, str);
                    hex[i][j].character = k;
                    hex[fxk][fyk].character = 0;
                    return;
                }
            }
        }
    }
}

int bot_move(struct node *l, char str[40][110]) {
    system("cls");
    print_board(str);
    int sec = 6;
    while(sec) {
        printf("Bot move in %ds", sec);
        delay(1);
        printf("\r");
        sec--;
    }
    system("cls");
    while(l != NULL) {
        if(l -> id != 8) {
            int idd = l -> id;
            printf("played with ");
            print_char(idd);
            printf("\n");
            if(idd == 1) {
                move1(str);
            }
            else if(idd == 2) {
                move2(str);
            }
            else if(idd == 3) {
                move3(str);
            }
            else if(idd == 4) {
                move4(str);
            }
            else if(idd == 5) {
                move5(str);
            }
            else if(idd == 6) {
                move6(str);
            }
            else if(idd == 7) {
                move7(str);
            }
            printf("Press enter and make your move");
            getchar();
            return idd;
        }
        if(l -> nex == NULL) {
            move8(str);
            return 8;
        }
        l = l -> nex;
    }
}
