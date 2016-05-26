/* Copyright 2016 ForAllSecure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

void execute_me() {
  printf("Awesome!\n");
}

WINDOW *window;
int should_exit = 0;

void curses_setup() {
	window = initscr();
	noecho();
	keypad(window, TRUE);
	curs_set(0);
}

void curses_cleanup() {
	delwin(window);
	curs_set(1);
	endwin();
	refresh();
}

char *player_name = "SNAAAAKE";

void draw(char game_grid[16][16]) {
	mvvline(1, 1, '|', 18);
	mvvline(1, 18, '|', 18);
	mvhline(1, 1, '-', 18);
	mvhline(18, 1, '-', 18);
  int r, c;
	for(r = 0; r < 16; r++) {
		for(c = 0; c < 16; c++) {
			mvaddch(r+2, c+2, game_grid[r][c]);
		}
	}
	mvaddstr(20, 1, "*WASD to play, Q to quit*");
	mvaddstr(21, 5, "**EARLY ALPHA**");
	mvaddstr(22, 6, "***HAS BUGS***");
	refresh();
}

void keyboard_move(int *r, int *c) {
	switch(getch()) {
		case KEY_UP:
		case 'W':
		case 'w':
			*r -= 1; break;
		case KEY_DOWN:
		case 'S':
		case 's':
			*r += 1; break;
		case KEY_LEFT:
		case 'A':
		case 'a':
			*c -= 1; break;
		case KEY_RIGHT:
		case 'D':
		case 'd':
			*c += 1; break;
		case 27:
		case 'Q':
		case 'q':
			should_exit = 1;
		default:
			break;
	}
}

void play_game(char game_grid[16][16]) {
	memset(&game_grid[0][0], ' ', 16*16);
	int r = 8, c = 6;
	memcpy(&game_grid[r][c], player_name, strlen(player_name));
	while(!should_exit) {
		draw(game_grid);
		keyboard_move(&r, &c);
		memset(&game_grid[0][0], ' ', 16*16);
		memcpy(&game_grid[r][c], player_name, strlen(player_name));
	}
}

void usage() {
  fprintf(stderr, "./snaaake snake_name\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  if(argc!=2) {
    usage();
  }
	char game_grid[16][16];
	if(argc >= 2) {
		player_name = argv[1];
		if(strlen(player_name) > 32) {
			player_name[32] = 0;
		}
	}
	
	curses_setup();
	play_game(game_grid);
	curses_cleanup();
	return 0;
}
