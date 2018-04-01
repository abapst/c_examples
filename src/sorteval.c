/******************************************************************************
 * sorteval.c
 * Aleksander Bapst
 * February 2017
 *
 * This benchmark runs six commonly taught sorting algorithms on a set of
 * randomly generated floating point lists of increasing length. The sorted
 * lists are checked for correctness and timed for performance comparison.
 * The test lists are separated in length by an order of magnitude and range
 * from 10 - 100,000. All algorithms sort the lists in-place, with the exception
 * of mergesort. Quicksort is implemented using the naive method of the pivot
 * in last place.
 *
 * Sorting algorithms |  Worst-case | Best-case | Space complexity
 * -------------------|-------------|-----------|-------------------
 *        Bubble Sort |    O(n^2)   |    O(n)   | O(1) aux
 *     Insertion Sort |    O(n^2)   |    O(n)   | O(1) aux
 *     Selection Sort |    O(n^2)   |   O(n^2)  | O(1) aux
 *          Quicksort |    O(n^2)   |  O(nlogn) | O(n) aux (naive)
 *          Mergesort |   O(nlogn)  |  O(nlogn) | O(n) aux
 *           Heapsort |   O(nlogn)  |  O(nlogn) | O(1) aux
 * -----------------------------------------------------------------
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sortalgs.h"


#define BUFSIZE 256
#define NTESTS  5
#define NALGS   6
#define TEST(p)    ( p==1 ? "PASS" : "FAIL" )


int main()
{
    int ii, jj;
    char filename[BUFSIZE];
    double start;
    list *unsorted,*sorted;
    double times[NALGS][NTESTS];
    int correct[NALGS][NTESTS];
    sortAlgPtr sortalgs[NALGS];

    sortalgs[0] = &bubble_sort;
    sortalgs[1] = &selection_sort;
    sortalgs[2] = &insertion_sort;
    sortalgs[3] = &quicksort;
    sortalgs[4] = &mergesort;
    sortalgs[5] = &heapsort;

    for (ii = 0; ii < NTESTS; ii++) {
        /* Read the unsorted list */
        strcpy(filename,"data/1E");
        sprintf(filename + strlen(filename),"%d",ii+1);
        strcat(filename,".list");
        printf("Testing list: %s\n",filename);
        unsorted = read_list(filename);

        sorted = create_list(unsorted->n);

        for (jj = 0; jj < NALGS; jj++) {
            copy_list(unsorted,sorted);
            start = get_time_sec();
            (*sortalgs[jj])(sorted);
            times[jj][ii] = get_time_sec() - start;
            correct[jj][ii] = !check_list_sorted(sorted) ? 1 : 0;
        }

        /* Cleanup */
        delete_list(unsorted);
        delete_list(sorted);
    }

    printf("+----------------------------------------------------+\n");
    printf("|                    Test Results                    |\n");
    printf("+---------------+------------------------------------+\n");
    printf("|   List length | 1E1    1E2    1E3    1E4    1E5    |\n");
    printf("+---------------+------------------------------------+\n");
    printf("|   Bubble sort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[0][0]),\
        TEST(correct[0][1]),\
        TEST(correct[0][2]),\
        TEST(correct[0][3]),\
        TEST(correct[0][4]));
    printf("|Selection sort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[1][0]),\
        TEST(correct[1][1]),\
        TEST(correct[1][2]),\
        TEST(correct[1][3]),\
        TEST(correct[1][4]));
    printf("|Insertion sort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[2][0]),\
        TEST(correct[2][1]),\
        TEST(correct[2][2]),\
        TEST(correct[2][3]),\
        TEST(correct[2][4]));
    printf("|     Quicksort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[3][0]),\
        TEST(correct[3][1]),\
        TEST(correct[3][2]),\
        TEST(correct[3][3]),\
        TEST(correct[3][4]));
    printf("|     Mergesort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[4][0]),\
        TEST(correct[4][1]),\
        TEST(correct[4][2]),\
        TEST(correct[4][3]),\
        TEST(correct[4][4]));
    printf("|      Heapsort | %-6s %-6s %-6s %-6s %-6s |\n",\
        TEST(correct[5][0]),\
        TEST(correct[5][1]),\
        TEST(correct[5][2]),\
        TEST(correct[5][3]),\
        TEST(correct[5][4]));
    printf("+---------------+------------------------------------+\n");
    printf("|                      Time (s)                      |\n");
    printf("+---------------+------------------------------------+\n");
    printf("|   List length | 1E1    1E2    1E3    1E4    1E5    |\n");
    printf("+---------------+------------------------------------+\n");
    printf("|   Bubble sort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[0][0],times[0][1],times[0][2],times[0][3],times[0][4]);
    printf("|Selection sort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[1][0],times[1][1],times[1][2],times[1][3],times[1][4]);
    printf("|Insertion sort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[2][0],times[2][1],times[2][2],times[2][3],times[2][4]);
    printf("|     Quicksort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[3][0],times[3][1],times[3][2],times[3][3],times[3][4]);
    printf("|     Mergesort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[4][0],times[4][1],times[4][2],times[4][3],times[4][4]);
    printf("|      Heapsort | %-6.3f %-6.3f %-6.3f %-6.3f %-6.3f |\n",\
            times[5][0],times[5][1],times[5][2],times[5][3],times[5][4]);
    printf("+---------------+------------------------------------+\n");

    return 0;
}
