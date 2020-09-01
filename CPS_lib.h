/*

	* Crossword Puzzle Solver
	* Version: 1.0.0
  * Author: Joie Angelo Llantero
	* Author URL: https://joiellantero.codes
	* Github: https://github.com/joiellantero/crossword-puzzle-solver
  * Crossword Puzzle Solver Copyright (c) 2020 Joie Llantero

*/

#ifndef __CPS_LIB_H__
#define __CPS_LIB_H__

void get_words(int n, char words[][16]);
void heapify(int n, int root, char words[][16]);
void heap_max(int i, char words[][16]);
void sort_words(int n, char words[][16]);
void print_words(int n, char words[][16]);
void populate_board(int m, char board[][m]);
void print_board(int m, char board[][m]);
int search2D (int m, char grid[][m], int i, int j, char word[], int n, int word_directions[n][2]);
void search_words(int m, char board[][m], int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]);
void print_solutions(int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]);
void edit_board(int m, char board[][m], int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]);

#endif
