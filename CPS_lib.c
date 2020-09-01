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
#include "CPS_lib.h"

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void get_words(int n, char words[][16]){

  int i, j;
  char c;

  for (i = 0; i < n; i++){
    for (j = 0; j < 16; j++){
      c = getchar();
      if (c != '\n'){
        words[i][j] = c;
      }
      else{
        break;
      }
    }
    words[i][j] = '\0';
  }

  return;

}

void heapify(int n, int root, char words[][16]){
  int largest = root; //parent or root node
  int l = 2*root + 1; //left child
  int r = 2*root + 2; //right child

  int compare = 0;

  if (l < n){
    compare = strcmp(words[largest], words[l]);
    if (compare < 0){//if words[largest] is less than words[l]
      largest = l;//replace the parent node with left child
   }
  }

  if (r < n){
    compare = strcmp(words[largest], words[r]);
    if (compare < 0){//if words[largest] is less than words[r]
       largest = r;//replace the parent node with the right child
    }
  }

  if (largest != root){
    char temp[16];
    strcpy(temp, words[root]);
    strcpy(words[root], words[largest]);
    strcpy(words[largest], temp);
    heapify(n, largest, words);
  }
}

void heap_max(int i, char words[][16]){
  int x = i/2 + 1;
  for ( ; x >= 0; x--){
    heapify(i, x, words);
  }
}

void sort_words(int n, char words[][16]){
  //heapsort
  //create a max heap
  heap_max(n, words);
  char temp[16];
  int i;
  for (i = n-1; i > 0; i--){
    //replace root or largest with the end node
    strcpy(temp, words[i]);
    strcpy(words[i], words[0]);
    strcpy(words[0], temp);

    //the heap is now reduced
    heapify(i, 0, words);
  }

  return;

}

void print_words(int n, char words[][16]){
  int i, j;
  for (i = 0; i < n; i++){
    int len = strlen(words[i]);
    for (j = 0; j < len; j++){
      printf("%c", words[i][j]);
    }
    printf("\n");
  }

  return;
}


void populate_board(int m, char board[][m]){
	int i, j;
  char c;

  for ( i = 0; i < m; i++){
      for (j = 0; j <= m; j++){
        c = getchar();
        if (c != '\n')
          board[i][j] = c;
      }
  }

	return;
}

void print_board(int m, char board[][m]){
	int i, j;

  for (i = 0; i < m; i++){
    for (j = 0; j < m; j++){
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

	return;
}

int search2D (int m, char grid[][m], int i, int j, char word[], int n, int word_directions[n][2]){
  if (grid[i][j] != word[0]){
    return 0;
  }

  int len = strlen(word);

  for (int dir = 0; dir < 8; dir++){ //direction of the word

    int k;
    int rd = i + x[dir];
    int cd = j + y[dir];

    for (k = 1; k < len; k++){
      if (rd >= m || rd < 0 || cd >= m || cd < 0){ //out of bounds of the board
        break;
      }

      if (grid[rd][cd] != word[k]){
        break;
      }

      rd += x[dir];
      cd += y[dir];
    }

    if (k == len){
      //the direction of the word found

      //right
      if (rd == i && cd > j){
        word_directions[n][0] = 1;
        word_directions[n][1] = 0;
        return 1;
      }

      //left
      if (rd == i && cd < j){
        word_directions[n][0] = -1;
        word_directions[n][1] = 0;
        return 1;
      }

      //down
      if (rd > i && cd == j){
          word_directions[n][0] = 0;
          word_directions[n][1] = -1;
          return 1;
        }

      //up
      if (rd < i && cd == j){
        word_directions[n][0] = 0;
        word_directions[n][1] = 1;
        return 1;
      }

      //right-up
      if (rd < i && cd > j){
        word_directions[n][0] = 1;
        word_directions[n][1] = 1;
        return 1;
      }

      //left-up
      if (rd < i && cd < j){
        word_directions[n][0] = -1;
        word_directions[n][1] = 1;
        return 1;
      }

      //left-down
      if (rd > i && cd < j){
        word_directions[n][0] = -1;
        word_directions[n][1] = -1;
        return 1;
      }

      //right-down
      if (rd > i && cd > j){
        word_directions[n][0] = 1;
        word_directions[n][1] = -1;
        return 1;
      }
    }
  }

  return 0;
}

void search_words(int m, char board[][m], int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]){

  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      for (int x = 0; x < n; x++){
        if (search2D (m, board, i, j, words[x], x, word_directions)){
        //save the positions in word_positions array.
          word_positions[x][0] = j;
          word_positions [x][1] = i;
        }
      }
    }
  }
  return;
}

void print_solutions(int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]){

  for (int i = 0; i < n; i++){
    if (word_directions[i][0] != 5 && word_directions[i][1] != 5){
      printf("%s: ", words[i]);

      printf("(%d ,", word_positions[i][0]);
      printf(" %d)", word_positions[i][1]);

      printf(" - ");

      if (word_directions[i][0] == 1){
          printf("right");
          }

      if (word_directions[i][0] == -1){
          printf("left");
      }

      if ((word_directions[i][0] != 0) && ((word_directions[i][1] == 1) || (word_directions[i][1] == -1))){
          printf("-");
      }

      if (word_directions[i][1] == -1){
          printf("down");
      }

      if (word_directions[i][1] == 1){
          printf("up");
      }

      printf("\n");
    }
  }
  return;
}

void edit_board(int m, char board[][m], int n, char words[n][16], int word_positions[n][2], int word_directions[n][2]){

  int i = 0;
  int j = 0;

  for (int x = 0; x < n; x++){
    //start at the coordinates where the word is found

    i = word_positions[x][0];//initial x-coordinate
    j = word_positions[x][1];//initial y-coordinate

    //get the length of the words
    int len = strlen (words[x]);

    //in which direction is the word found?
    int ctr = 0;

    for (; ctr < len; ctr++){//control variable to manipulate the coordinates of the letters of the words

      //moving in the east direction
      if (word_directions[x][0] == 1 && word_directions[x][1] == 0){
        board[j][i+ctr] = '.';
      }

      //moving in the south direction
      else if (word_directions[x][0] == 0 && word_directions[x][1] == -1){
        board[j+ctr][i] = '.';
      }

      //moving in the west direction
      else if (word_directions[x][0] == -1 && word_directions[x][1] == 0){
        board[j][i-ctr] = '.';
      }

      //moving in the north direction
      else if (word_directions[x][0] == 0 && word_directions[x][1] == 1){
        board[j-ctr][i] = '.';
      }

      //moving in the south-east direction
      else if (word_directions[x][0] == 1 && word_directions[x][1] == -1){
        board[j+ctr][i+ctr] = '.';
      }

      //moving in the north-west direction
      else if (word_directions[x][0] == -1 && word_directions[x][1] == 1){
        board[j-ctr][i-ctr] = '.';
      }

      //moving in the north-east direction
      else if (word_directions[x][0] == 1 && word_directions[x][1] == 1){
        board[j-ctr][i+ctr] = '.';
      }

      //moving in the south-west direction
      else if (word_directions[x][0] == -1 && word_directions[x][1] == -1){
        board[j+ctr][i-ctr] = '.';
        //for checking the coordinates of the letters of the words
        //printf("(i: %d, j: %d)\n", i-ctr,j+ctr);
      }
    }
  }

  //print modified board
  print_board(m, board);
  return;
}
