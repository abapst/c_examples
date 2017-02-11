#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "sortalgs.h"

#define BUFSIZE 256
#define NLISTS 5

#define TEST(p)    (1 ? "PASS" : "FAIL")

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
        fprintf(stderr,"Testing list: %s\n",filename);
        strcat(filename,".list");
        unsorted = read_list(filename);

        /* Read the ground truth list */
        strcpy(filename,"data/1E");
        sprintf(filename + strlen(filename),"%d",ii+1);
        strcat(filename,".truth");
        truth = read_list(filename);

        sorted = create_list(unsorted->n);
        
        /* Bubble sort */
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        bubble_sort(sorted);
        times[0][ii] = get_time_ms() - start;
        correct[0][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        
        /* Selection sort */
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        selection_sort(sorted);
        times[1][ii] = get_time_ms() - start;
        correct[1][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        
        /* Insertion sort */
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        insertion_sort(sorted);
        times[2][ii] = get_time_ms() - start;
        correct[2][ii] = !compare_lists(sorted,truth) ? 1 : 0;
        
        /* Quicksort */
        copy_list(unsorted, sorted);
        start = get_time_ms(); 
        quicksort(sorted);
        times[3][ii] = get_time_ms() - start;
        correct[3][ii] = !compare_lists(sorted,truth) ? 1 : 0;

        /* Mergesort */
        start = get_time_ms(); 
        mergesort(unsorted, sorted);
        times[4][ii] = get_time_ms() - start;
        correct[4][ii] = !compare_lists(sorted,truth) ? 1 : 0;
    }

    fprintf(stderr,"+----------------------------------------------------+\n");
    fprintf(stderr,"|                    Test Results                    |\n");
    fprintf(stderr,"+---------------+------------------------------------+\n");
    fprintf(stderr,"|   List length |  1E1   1E2   1E3   1E4   1E5       |\n");
    fprintf(stderr,"+---------------+------------------------------------+\n");
    fprintf(stderr,"|   Bubble sort | %s  %s  %s  %s  %s       |\n",\
        TEST(correct[0][0]),\
        TEST(correct[0][1]),\
        TEST(correct[0][2]),\
        TEST(correct[0][3]),\
        TEST(correct[0][4]));
    fprintf(stderr,"|Selection sort | %s  %s  %s  %s  %s       |\n",\
        TEST(correct[1][0]),\
        TEST(correct[1][1]),\
        TEST(correct[1][2]),\
        TEST(correct[1][3]),\
        TEST(correct[1][4]));
    fprintf(stderr,"|Insertion sort | %s  %s  %s  %s  %s       |\n",\
        TEST(correct[2][0]),\
        TEST(correct[2][1]),\
        TEST(correct[2][2]),\
        TEST(correct[2][3]),\
        TEST(correct[2][4]));
    fprintf(stderr,"|     Quicksort | %s  %s  %s  %s  %s       |\n",\
        TEST(correct[3][0]),\
        TEST(correct[3][1]),\
        TEST(correct[3][2]),\
        TEST(correct[3][3]),\
        TEST(correct[3][4]));
    fprintf(stderr,"|     Mergesort | %s  %s  %s  %s  %s       |\n",\
        TEST(correct[4][0]),\
        TEST(correct[4][1]),\
        TEST(correct[4][2]),\
        TEST(correct[4][3]),\
        TEST(correct[4][4]));
    fprintf(stderr,"+---------------+------------------------------------+\n");
    fprintf(stderr,"|                      Time (s)                      |\n");
    fprintf(stderr,"+---------------+------------------------------------+\n");
    fprintf(stderr,"|   List length |  1E1   1E2   1E3   1E4   1E5       |\n");
    fprintf(stderr,"+---------------+------------------------------------+\n");
    fprintf(stderr,"|   Bubble sort | %2.3f %2.3f %2.3f %2.3f %2.3f     |\n",\
            times[0][0],times[0][1],times[0][2],times[0][3],times[0][4]);
    fprintf(stderr,"|Selection sort | %2.3f %2.3f %2.3f %2.3f %2.3f     |\n",\
            times[1][0],times[1][1],times[1][2],times[1][3],times[1][4]);
    fprintf(stderr,"|Insertion sort | %2.3f %2.3f %2.3f %2.3f %2.3f     |\n",\
            times[2][0],times[2][1],times[2][2],times[2][3],times[2][4]);
    fprintf(stderr,"|     Quicksort | %2.3f %2.3f %2.3f %2.3f %2.3f     |\n",\
            times[3][0],times[3][1],times[3][2],times[3][3],times[3][4]);
    fprintf(stderr,"|     Mergesort | %2.3f %2.3f %2.3f %2.3f %2.3f     |\n",\
            times[4][0],times[4][1],times[4][2],times[4][3],times[4][4]);
    fprintf(stderr,"+---------------+------------------------------------+\n");
    
    /* Cleanup */
    delete_list(unsorted);
    delete_list(sorted);
    delete_list(truth);
    return 0;
}
