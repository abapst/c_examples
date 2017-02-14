#include <stdio.h>
#include <string.h>

/* Function Declarations */
void permute(char *str,int start, int end);
void swap(char *str,int start, int end);
/*************************/

/* Prints permutations of string with duplicates allowed */
void permute(char *str,int start, int end)
{
    int ii;

    if (start == end)
        printf("%s\n",str);
    else {
      for (ii = start; ii < end; ii++) {
        swap(str,start,ii);
        permute(str,start+1,end);
        swap(str,start,ii); // reverse the swap
      }
    }
}

void swap(char *str, int start, int end)
{
    char tmp;
  
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
}

int main(int argc, char* argv[])
{
    char *str;
    int n;
    if (argc > 1)
        str = argv[1];
    else
        printf("Usage: ./permute_string <string>\n"); 
    n = strlen(str);
    permute(str,0,n);

    return 0;
}
