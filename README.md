# Crossword Puzzle Solver

*DISCLAIMER: The usage of this software requires some basic knowledge in C programming.*

The main function of this software is to automatically find words in a symmetrical crossword puzzle. The additional features are sorting out (using heapsort) the given words in alphabetical order and removing the letters of the searched words from the crossword puzzle.

---
## Features

The example shown below utilized the text file from `test-cases/test_3x3.txt`

> Sorting the words using heap sort

```shell
Input n:
Sorted Words:
dew
rar
raw
red
rod
row
war
```
- Note that the `Input n:` has no number next to it as the imported text file doesn't get displayed on the terminal. But this doesn't mean that the program wasn't able to read the integer from the text file.

> Input the crossword puzzle

```shell
Input m:
Board:
r a r
a o e
w e d
```
- 'Input m' takes in a single integer, i.e., the number of rows or columns; since, crossword puzzles are always assumed symmetrical so providing either the height or width would suffice.

> View the solutions

```shell
Solutions:
dew: (2 , 2) - left
rar: (2 , 0) - left
raw: (0 , 0) - down
red: (2 , 0) - down
rod: (0 , 0) - right-down
row: (2 , 0) - left-down
war: (0 , 2) - up
```
- The program is able to provide you the coordinates (using indices) and the direction of the word.

> View the board wihtout the letters of the search words

```shell
Modified Board:
. . .
. . .
. . .
```

---
## Downloading the software

- All the `code` required to get started

### Clone

- Clone this repo to your local machine using `https://github.com/joiellantero/crossword-puzzle-solver.git`

### Setup

- If you haven't, install the gcc compiler using `https://gcc.gnu.org/install/`

> Compile the program

```shell
$ make cps
```

> Setup your crossword puzzle

I have included some samples in the `test-cases` folder and feel free to use the sample crossword puzzles in the `test-cases` folder.

If you want to provide your own crossword puzzle, you need to create your own text file that contains the words to be searched and the symmetrical crossword puzzle itself. I have included a template in the `crossword-puzzle` folder named `cp.txt` to serve as a guide in creating the required text files. You must strictly follow the formatting of the text files for the program to function properly. Check out my samples in the `test-cases` folder to checkout how I made my text files.

### Run

> Run the code below to deploy the program in your terminal

```shell
$ ./cps < crossword-puzzle/cp.txt
```

---
## Author
- [Joie Angelo Llantero](https://joiellantero.codes)

---
## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
