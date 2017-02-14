#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "sortalgs.h"

#define BUFSIZE 256
#define NLISTS 5

#define TEST(p)    ( p==1 ? "PASS" : "FAIL" )

int main()
{
    int ii;
    char filename[BUFSIZE];
    double start;
    list *unsorted,*sorted,*truth;
    double times[5][5];
    int correct[5][5];

    for (ii = 0; ii < NLISTS; ii++) {
        /* Read the unsorted list */
        strcpy(filename,"data/1E");
        sprintf(filename + strlen(filename),"%d",ii+1);
        printf("Testing list: %s\n",filename);
        strcat(filename,".list");
        unsorted = read_list(filename);

        /* Read the ground truth list */
        strcpy(filename,"data/1E");
        sprintf(filename + strlen(filename),"%d",ii+1);
        strcat(filename,".truth");
        truth = read_list(filename);

        sorted = create_list(unsorted->n);
        
        /* Bubble sort */
        printf("  bubble sort...");
        fflush(stdout);
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        bubble_sort(sorted);
        times[0][ii] = get_time_ms() - start;
        correct[0][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        printf("done\n");
        
        /* Selection sort */
        printf("  selection sort...");
        fflush(stdout);
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        selection_sort(sorted);
        times[1][ii] = get_time_ms() - start;
        correct[1][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        printf("done\n");
        
        /* Insertion sort */
        printf("  insertion sort...");
        fflush(stdout);
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        insertion_sort(sorted);
        times[2][ii] = get_time_ms() - start;
        correct[2][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        printf("done\n");
        
        /* Quicksort */
        printf("  quicksort...");
        fflush(stdout);
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        quicksort(sorted);
        times[3][ii] = get_time_ms() - start;
        correct[3][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        printf("done\n");

        /* Mergesort */
        printf("  mergesort...");
        fflush(stdout);
        start = get_time_ms(); 
        mergesort(unsorted, sorted);
        times[4][ii] = get_time_ms() - start;
        correct[4][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        printf("done\n");
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
    printf("+---------------+------------------------------------+\n");
    
    /* Cleanup */
    delete_list(unsorted);
    delete_list(sorted);
    delete_list(truth);
    return 0;
}
