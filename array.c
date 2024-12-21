#include "array.h"

int cnt_items(FILE *f, int *cnt_items)
{
    *cnt_items = 0;
    char str[MAX_LEN_STR];

    while (fscanf(f, "%s", str) == 1)
    {
        (*cnt_items)++;
    }

    if ((*cnt_items) == 0)
        return RC_ERR_EMPTY_FILE;

    fseek(f, 0, SEEK_SET);

    return RC_OK;
}

static int is_in_arr(char **pointers, size_t cnt, char str[MAX_LEN_STR])
{
    int in_arr = -1;

    for (size_t i = 0; i < cnt; i++)
        if (strcmp(str, pointers[i]) == 0)
            return i;
    return in_arr;
}

int fill_arr(FILE *f, char ***pointers, int *duplicates, size_t cnt, size_t *cnt_unic)
{
    char *str = malloc(MAX_LEN_STR);
    *cnt_unic = 0;

    for (size_t i = 0; i < cnt; i++)
    {

        if (fscanf(f, "%s", str) != 1)
            return RC_ERR_DATA;

        int pos = is_in_arr(*pointers, *cnt_unic, str);
        if (pos == -1)
        {
            (*pointers)[i] = str;
            (*cnt_unic)++;
            str = malloc(MAX_LEN_STR);
        }
        else
        {
            duplicates[pos] += 1;
        }
    }

    return RC_OK;
}

void free_arr(char **pointers, size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
        free(pointers[i]);
    free(pointers);
}

void arr_output(FILE *f, char **pointers, int *duplicates, size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
        fprintf(f, "%s %d\n", pointers[i], duplicates[i] + 1);
}
