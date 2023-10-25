void game() {
    switch(game_switcher) 
    {
        case 0:
            black_jack();
            break;

        default: break;
    }
    
}

void shuffle(card* cards, int size) {
    int i, j, rand; card copy_card;
    for (i = size - 1; i >= 1; i--) {
        sceKernelGetRandomNumber(&rand, sizeof(rand));
        if (rand < 0) rand *= -1;
        j = rand % i + 1; 

        copy_card = cards[j];
        cards[j] = cards[i];
        cards[i] = copy_card;
    }
}

void copy_cards(card source[], card destination[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void switch_game() {
    int selected = 0;
    string_center("UP and DOWN to navigate, CROSS to select", 60);

    while(1) {            
        if (selected != 0) printf("\e[30;1H\e[90m"); string_center("21 Royale", 30); printf("\e[0m");
        if (selected != 1) printf("\e[31;1H\e[90m"); string_center("Roga i kopyta", 31); printf("\e[0m");
        if (selected != 2) printf("\e[32;1H\e[90m"); string_center("Lorem ipsum", 32); printf("\e[0m");

        ctrl.buttons = 0;

        while (!CROSS && !DOWN && !UP) {
            sceCtrlPeekBufferPositive(0, &ctrl, 1); 
        }

        if (CROSS) {
            ctrl.buttons = 0;
            break;
        }
        if (DOWN) {
            ctrl.buttons = 0;
            sceKernelDelayThread(0.2 * SEC); selected++;
            if (selected > (all_games)) selected--;
        }
        if (UP) {
            ctrl.buttons = 0;
            sceKernelDelayThread(0.2 * SEC); selected--;
            if (selected < 0) selected++;
        }
    }
    game_switcher = selected;
    clear_screen();
}

void rules() {
    rules_screen();
    switch(game_switcher) 
    {
        case 0:
            string_center("At the start of the game, the dealer deals you and themselves 2 cards.", 30);
            string_center("You can choose to hit for another card or stand as is.", 31);
            string_center("Card values: 2 to 10 - face value; jack, queen, and king - 10; ace - 1 or 11.", 32);
            string_center("The closest to 21 wins. Going over 21 results in a loss.", 33);
            break;

        default: 
            string_center("This game are not ready!", 30);
            string_center("Sorry!", 31);
            break;
    }
    string_center("Press SQUARE to continue", 60);

    ctrl.buttons = 0; 
    while(1) {   
        ctrl.buttons = 0; 
        sceCtrlPeekBufferPositive(0, &ctrl, 1);  
        if (SQUARE) {
            ctrl.buttons = 0;
            break;
        }
    }
    sceKernelDelayThread(0.5 * SEC);
}

void waitForFrontPanelTouch() {
    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, 1);
    sceTouchEnableTouchForce(SCE_TOUCH_PORT_FRONT);
    
	SceTouchData touch[SCE_TOUCH_PORT_MAX_NUM];
    touch[0].report[0].x = 0; touch[0].report[0].y = 0;
    while (1) {
        sceTouchPeek(0, &touch[0], 1);
        
        if (touch[0].report[0].y > 500 && touch[0].report[0].y < 750 && touch[0].report[0].x > 478 && touch[0].report[0].x < 1428) {
            break;
        }
    }

    touch[0].report[0].x = 0; touch[0].report[0].y = 0;
    sceKernelDelayThread(0.5 * SEC);
}
