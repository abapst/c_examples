#include <stdio.h>

#define MAXPRICE 9999

/* Function declarations */
int array_max(int *prices,int start, int end);
int array_min(int *prices,int start, int end);
int max_profit(int *prices,int start, int end);
/*************************/

int array_max(int *prices,int start, int end)
{
    int ii;
    int max = 0;

    if (start == end)
        return prices[start];

    for (ii = start; ii < end; ii++) {
        if (prices[ii] > max)
        max = prices[ii];    
    } 
    return max;
}

int array_min(int *prices,int start, int end)
{
    int ii;
    int min = MAXPRICE;

    if (start == end)
        return prices[start]; 

    for (ii = start; ii < end; ii++) {
        if (prices[ii] < min)
        min = prices[ii];    
    } 
    return min;
}

int max_profit(int *prices, int start, int end)
{
    int middle, bestLeft, bestRight, minLeft, maxRight;
    int best[3];

    if (end-start < 2)
        return 0;

    middle = start + (end-start)/2; 

    /* Recurse on left and right sides */
    bestLeft = max_profit(prices,start,middle);
    bestRight = max_profit(prices,middle,end); 

    minLeft = array_min(prices,start,middle);
    maxRight = array_max(prices,middle,end);

    best[0] = bestLeft;
    best[1] = bestRight; 
    best[2] = maxRight - minLeft;

    return array_max(best,0,3); 
}

int main()
{
    int prices[] = {5,4,3,9,14,2,1,12,0,4,7,23,42,18,17,52,1,3,3,8};
    int n = sizeof(prices)/sizeof(int);
    int profit;
    int ii;

    profit = max_profit(prices,0,n);
  
    printf("Stock history:\n");
    for (ii=0;ii<n;ii++)
        printf("%d ",prices[ii]);
    printf("\n");
    printf("Best profit = %d\n",profit);

    return 0;
}
