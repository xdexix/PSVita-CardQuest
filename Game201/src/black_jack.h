void black_jack() {
    int given, given_pl, given_comp;
    int sum_pl = 0; int sum_comp = 0;

    card cards[sizeof(initial_cards_52) / sizeof(initial_cards_52[0])];
    copy_cards(initial_cards_52, cards, sizeof(cards) / sizeof(cards[0]));
    shuffle(cards, sizeof(cards) / sizeof(cards[0]));

    card player[] =     { {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0} };
    card computer[] =   { {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0}, {'s', 0} };

    player[0] = cards[0];
    sum_pl += black_jack_sum(player[0].nom, sum_pl);
    computer[0] = cards[1];
    sum_comp += black_jack_sum(computer[0].nom, sum_comp);
    player[1] = cards[2];
    sum_pl += black_jack_sum(player[1].nom, sum_pl);
    computer[1] = cards[3];
    sum_comp += black_jack_sum(computer[1].nom, sum_comp);

    given_pl = 2; given_comp = 2; given = 4;
    
    int i;
    for (i = 0; i < given_pl; i++) {        
        print_card(player[i].nom, player[i].suit, 90 - i * 10, 45);
    }
    for (i = 0; i < given_comp; i++) { 
        if (i == 0) print_card(computer[i].nom, 4, 90 - i * 10, 15);
        else print_card(computer[i].nom, computer[i].suit, 90 - i * 10, 15);
    }
    
    printf("\e[48;100HSum: %d", sum_pl);
    string_center("CROSS - take more, SQUARE - stop", 60);

    while(sum_pl <= 21) {   
        ctrl.buttons = 0;     
        while (!CROSS && !SQUARE) {
            sceCtrlPeekBufferPositive(0, &ctrl, 1); 
        }
        if (CROSS) {
            ctrl.buttons = 0;
            player[given_pl] = cards[given];
            sum_pl += black_jack_sum(player[given_pl].nom, sum_pl);
            given++; given_pl++;
        }

        if (SQUARE) {
            ctrl.buttons = 0;
            break;
        }
        sceKernelDelayThread(0.5 * SEC);
        printf("\e[48;100HSum: %d", sum_pl);

        for (i = 0; i < given_pl; i++) {        
            print_card(player[i].nom, player[i].suit, 90 - i * 10, 45);
        }
        for (i = 0; i < given_comp; i++) { 
            if (i == 0) print_card(computer[i].nom, 4, 90 - i * 10, 15);
            else print_card(computer[i].nom, computer[i].suit, 90 - i * 10, 15);
        }
        if (sum_pl >= 21) break;
    }

    while(sum_comp <= 21) {

        if (sum_comp < 17) {
            computer[given_comp] = cards[given];
            sum_comp += black_jack_sum(computer[given_comp].nom, sum_comp);
            given++; given_comp++;
        }  

        for (i = 0; i < given_pl; i++) {        
            print_card(player[i].nom, player[i].suit, 90 - i * 10, 45);
        }
        for (i = 0; i < given_comp; i++) { 
            print_card(computer[i].nom, computer[i].suit, 90 - i * 10, 15);
        }

        sceKernelDelayThread(1 * SEC);
        printf("\e[18;100HSum: %d", sum_comp);
        if (sum_comp >= 17) break;
    }
    
    if (sum_pl > 21) sum_pl = 0;
    if (sum_comp > 21) sum_comp = 0;
    wl_screen(sum_pl, sum_comp);
}

int black_jack_sum(char nom, int sum) {
    switch(nom){
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '0': return 10;
        case 'J': return 10;
        case 'Q': return 10;
        case 'K': return 10;
        case 'A': if (sum <= 10) return 11; else return 1;
        default: return 0;
    }
}

