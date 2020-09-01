/*

	* Crossword Puzzle Solver
	* Version: 1.0.0
  * Author: Joie Angelo Llantero
	* Author URL: https://joiellantero.codes
	* Github: https://github.com/joiellantero/crossword-puzzle-solver
  * Crossword Puzzle Solver Copyright (c) 2020 Joie Llantero

*/


#include<stdio.h>
#include<string.h>
#include"CPS_lib.h"

int main (){

//sorting the words inn alphabetical (ascending) order
int num_words = 0;//the number of words to be entered by the user.

printf("Input n: ");
scanf("%d ", &num_words);
char words[num_words][16];//this is the words array
get_words(num_words, words);

//sorting words using heap sort (or bubble sort)
sort_words(num_words, words);
puts("\nSorted Words:");
print_words(num_words, words);

//searching for words
int m = 0;
printf("\nInput m: ");//the number of rows and columns for the board
scanf("%d", &m);
getchar();

//declaration of the board variable
char board[m][m];

//enter the characters in the board
populate_board(m, board);


//print the board
puts("\nBoard:");
print_board(m, board);

//now searching for the words in the board
int wp[num_words][2];//this is the word_positions array
int wd[num_words][2];//this is the word_directions array

for (int i = 0; i < num_words; i++){
	for (int j = 0; j < 1; j++){
		wd[i][j] = 5;
	}
}

puts("");
search_words(m, board, num_words, words, wp, wd);


//print the found words
puts("Solutions:");
print_solutions(num_words, words, wp, wd);

//board modification
puts("\nModified Board: ");
edit_board(m, board, num_words, words, wp, wd);
return 0;
}
