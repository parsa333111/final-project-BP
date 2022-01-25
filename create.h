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

void create_house_xy() {
    hex[0][0].yhouse = 4, hex[0][0].xhouse = 1;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 0 ; j <= 12 ; j+=2) {
            if(i == 0 && j == 0)continue;
            hex[j][i].xhouse = hex[0][0].xhouse + (8 * j);
            hex[j][i].yhouse = hex[0][0].yhouse + (4 * i);
        }
    }
    hex[1][0].yhouse = 2, hex[1][0].xhouse = 9;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 1 ; j <= 12 ; j+=2) {
            if(i == 1 && j == 0)continue;
            hex[j][i].xhouse = hex[1][0].xhouse + (8 * j) - 8;
            hex[j][i].yhouse = hex[1][0].yhouse + (4 * i);
        }
    }
}

void create_escape_xy() {
    hex[0][0].yescape = 4, hex[0][0].xescape = 1;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 0 ; j <= 12 ; j+=2) {
            if(i == 0 && j == 0)continue;
            hex[j][i].xescape = hex[0][0].xescape + (8 * j);
            hex[j][i].yescape = hex[0][0].yescape + (4 * i);
        }
    }
    hex[1][0].yescape = 2, hex[1][0].xescape = 9;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 1 ; j <= 12 ; j+=2) {
            if(i == 1 && j == 0)continue;
            hex[j][i].xescape = hex[1][0].xescape + (8 * j) - 8;
            hex[j][i].yescape = hex[1][0].yescape + (4 * i);
        }
    }
}

void create_well_xy() {
    hex[0][0].ywell = 4, hex[0][0].xwell = 1;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 0 ; j <= 12 ; j+=2) {
            if(i == 0 && j == 0)continue;
            hex[j][i].xwell = hex[0][0].xwell + (8 * j);
            hex[j][i].ywell = hex[0][0].ywell + (4 * i);
        }
    }
    hex[1][0].ywell = 2, hex[1][0].xwell = 9;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 1 ; j <= 12 ; j+=2) {
            if(i == 1 && j == 0)continue;
            hex[j][i].xwell = hex[1][0].xwell + (8 * j) - 8;
            hex[j][i].ywell = hex[1][0].ywell + (4 * i);
        }
    }
}

void create_name_xy() {
    hex[0][0].yname = 4, hex[0][0].xname = 1;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 0 ; j <= 12 ; j+=2) {
            if(i == 0 && j == 0)continue;
            hex[j][i].xname = hex[0][0].xname + (8 * j);
            hex[j][i].yname = hex[0][0].yname + (4 * i);
        }
    }
    hex[1][0].yname = 2, hex[1][0].xname = 9;
    for(int i = 0 ; i <= 8 ; i++) {
        for(int j = 1 ; j <= 12 ; j+=2) {
            if(i == 1 && j == 0)continue;
            hex[j][i].xname = hex[1][0].xname + (8 * j) - 8;
            hex[j][i].yname = hex[1][0].yname + (4 * i);
        }
    }
    for(int i = 0 ; i <= 8 ; i++ ) {
        for(int j = 0 ; j <= 12 ; j++ ) {
            hex[j][i].xname++;
            hex[j][i].yname--;
        }
    }
}

void create_neighbor_xy() {
    for(int j = 0 ; j <= 12 ; j++ ) {
        for(int i = 0 ; i <= 8 ; i++ ) {
            for(int k = 0 ; k < 6 ; k++ ) {
                hex[j][i].xnei[k] = hex[j][i].ynei[k] = -1;
            }
            int cnt = 0;
            if(in_range(j, i - 1)) {
                hex[j][i].xnei[cnt] = j;
                hex[j][i].ynei[cnt] = i - 1;
            }
            cnt++;
            if(in_range(j, i + 1)) {
                hex[j][i].xnei[cnt] = j;
                hex[j][i].ynei[cnt] = i + 1;
            }
            cnt++;
            if(j % 2 == 0) {
                if(in_range(j - 1, i)) {
                    hex[j][i].xnei[cnt] = j - 1;
                    hex[j][i].ynei[cnt] = i;
                }
                cnt++;
                if(in_range(j - 1, i + 1)) {
                    hex[j][i].xnei[cnt] = j - 1;
                    hex[j][i].ynei[cnt] = i + 1;
                }
                cnt++;
                if(in_range(j + 1, i)) {
                    hex[j][i].xnei[cnt] = j + 1;
                    hex[j][i].ynei[cnt] = i;
                }
                cnt++;
                if(in_range(j + 1, i + 1)) {
                    hex[j][i].xnei[cnt] = j + 1;
                    hex[j][i].ynei[cnt] = i + 1;
                }
                cnt++;
            }
            else {
                if(in_range(j - 1, i - 1)) {
                    hex[j][i].xnei[cnt] = j - 1;
                    hex[j][i].ynei[cnt] = i - 1;
                }
                cnt++;
                if(in_range(j - 1, i)) {
                    hex[j][i].xnei[cnt] = j - 1;
                    hex[j][i].ynei[cnt] = i;
                }
                cnt++;
                if(in_range(j + 1, i - 1)) {
                    hex[j][i].xnei[cnt] = j + 1;
                    hex[j][i].ynei[cnt] = i - 1;
                }
                cnt++;
                if(in_range(j + 1, i)) {
                    hex[j][i].xnei[cnt] = j + 1;
                    hex[j][i].ynei[cnt] = i;
                }
                cnt++;
            }
        }
    }
}

void create() {
    create_light_xy();
    create_well_xy();
    create_house_xy();
    create_escape_xy();
    create_name_xy();
    create_neighbor_xy();
}
