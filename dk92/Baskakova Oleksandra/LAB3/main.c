#include "tools.h"
#include "stdlib.h"
#include "quick.h"

int main(int argc, char const *argv[])
{
    srand(time(0));
    int size = getUnsignedInt("Enter size of array: \n");
    int searchingNumber = getUnsignedInt("What number are you looking for?\n");
    int *arr = createArray(size);

    time_t t0 = time(0);
    int beforeSortInex = linearSearch(arr, size, searchingNumber);
    time_t t1 = time(0);
    int beforeSortSearchingTimeEllapsed = difftime(t1, t0);

    t0 = time(0);
    quickSort(arr, 0, size - 1);
    t1 = time(0);
    int sortingTimeEllapsed = difftime(t1, t0);

    t0 = time(0);
    int afterSortIndex = linearSearch(arr, size, searchingNumber);
    t1 = time(0);
    int afterSortSearchingTimeEllapsed = difftime(t1, t0);

    char label[300];
    snprintf(label, 300,
             "size: %d; searching number: %d;\n index of searching number before sort: %d;\n index of searching number after sort: %d;\n sorting time ellapsed: %d;\n searching time before search ellapsed: %d;\n searching time after search ellapsed: %d;\n",
             size,
             searchingNumber,
             beforeSortInex,
             afterSortIndex,
             sortingTimeEllapsed,
             beforeSortSearchingTimeEllapsed,
             afterSortSearchingTimeEllapsed);
    FILE *file = fopen("result.txt", "w");
    fprintResult(file, label, arr, size);
    printf("Sorting and searching finished...\n");
    printf(label);
    fclose(file);
    free(arr);
    return 0;
}
