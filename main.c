#include <stdio.h>

#include "array.h"

#define RC_ERR_OPEN 1

int main(void)
{
    FILE *f_in = fopen(IN_FILE, "r");
    if (!f_in)
        return RC_ERR_OPEN;

    int cnt_names = 0;
    int rc = cnt_items(f_in, &cnt_names);
    if (rc)
    {
        fclose(f_in);
        return rc;
    }

    char **pointers = malloc(cnt_names * sizeof(char *));
    if (!pointers)
    {
        fclose(f_in);
        return RC_ERR_MEM;
    }

    size_t cnt_unic_names = 0;
    int *duplicates = calloc(cnt_names, sizeof(int));
    rc = fill_arr(f_in, &pointers, duplicates, cnt_names, &cnt_unic_names);
    fclose(f_in);
    if (rc)
    {
        free(pointers);
        return rc;
    }

    arr_output(pointers, duplicates, cnt_unic_names);

    free_arr(pointers, cnt_unic_names);
    free(duplicates);

    return RC_OK;
}
