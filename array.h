#ifndef DOTS_H
#define DOTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RC_OK 0
#define RC_ERR_EMPTY_FILE 2
#define RC_ERR_DATA 3
#define RC_ERR_MEM 4
#define RC_ERR_EMPTY_FILTR_ARR 5

#define MAX_LEN_STR 50

#define IN_FILE "in.txt"


int cnt_items(FILE *f, int *cnt_items);
int fill_arr(FILE *f, char ***pointers, int *duplicates, size_t cnt, size_t *cnt_unic);
void arr_output(char **pointers, int *duplicates, size_t cnt);
void free_arr(char **pointers, size_t cnt);

#endif
