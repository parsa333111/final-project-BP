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

void create() {
    create_light_xy();
    create_well_xy();
    create_house_xy();
    create_escape_xy();
}
