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

void create() {
    create_light_xy();
}
