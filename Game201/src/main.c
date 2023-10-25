#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/rng.h> 
#include <psp2/touch.h>
#include <psp2/ctrl.h>
#include <stdio.h>
#include <string.h>
#include "debugScreen.h"

#define SEC     1000000
#define UP      (ctrl.buttons & (1<<4))  // 00000010
#define DOWN    (ctrl.buttons & (1<<6))  // 00000040
#define CROSS   (ctrl.buttons & (1<<14)) // 00004000
#define SQUARE  (ctrl.buttons & (1<<15)) // 00008000
#define printf  psvDebugScreenPrintf

int game_switcher = 0;
int all_games = 2;
SceCtrlData ctrl;

typedef struct {
    char nom;
    int suit; 
} card;

card initial_cards_52[] = {
    {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}, {'0', 0}, {'J', 0}, {'Q', 0}, {'K', 0}, {'A', 0},
    {'2', 1}, {'3', 1}, {'4', 1}, {'5', 1}, {'6', 1}, {'7', 1}, {'8', 1}, {'9', 1}, {'0', 1}, {'J', 1}, {'Q', 1}, {'K', 1}, {'A', 1},
    {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'0', 2}, {'J', 2}, {'Q', 2}, {'K', 2}, {'A', 2},
    {'2', 3}, {'3', 3}, {'4', 3}, {'5', 3}, {'6', 3}, {'7', 3}, {'8', 3}, {'9', 3}, {'0', 3}, {'J', 3}, {'Q', 3}, {'K', 3}, {'A', 3}
};

void clear_screen();
void string_center(char* str, int line);

void start_screen();
void rules_screen();
void wl_screen(int player, int comp);
void print_card(char nom, int suit, int pos_x, int pos_y);

void game();
void shuffle(card* cards, int size);
void copy_cards(card source[], card destination[], int size);
void switch_game();
void rules();
void waitForFrontPanelTouch();

void black_jack();
int black_jack_sum(char nom, int sum);

#include "format.h"
#include "sprites.h"
#include "game.h"

#include "black_jack.h"

int main(int argc, char *argv[]) {
	psvDebugScreenInit();
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    start_screen();
    waitForFrontPanelTouch();

    while(1) {
        clear_screen();
        switch_game();

        clear_screen();
        rules();

        clear_screen();
        game();
    }

	sceKernelExitProcess(0);
	return 0;
}




