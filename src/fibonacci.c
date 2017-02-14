#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[])
{
    int ii,n;

    if (argc == 2)
        n = atoi(argv[1]);
  
    for (ii = 1; ii <= n; ii++) {
        printf("%d ",fibonacci(ii));
    }
    printf("\n");

    return 0;
}
