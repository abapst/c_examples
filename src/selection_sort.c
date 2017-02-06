#include <stdio.h>

/* Function declarations */
void selection_sort(int *data,int n);
void swap(int *data,int i1, int i2);
void print_array(int *data, int n);
/*************************/

void selection_sort(int *data,int n) {
  int ii,jj;
  int iMin;
  
  for(jj=0 ; jj<n ; jj++) {
    iMin = jj;
    for(ii=jj+1 ; ii<n ; ii++) {
      if (data[ii] < data[iMin])
        iMin = ii;
    }

    if (iMin != jj)
      swap(data,iMin,jj);

  }
}

void swap(int *data,int i1,int i2) {
  int tmp = data[i1];
  data[i1] = data[i2];
  data[i2] = tmp;
}

void print_array(int *data,int n) {
  int ii;

  for (ii = 0; ii < n; ii++)
    printf("%d ",data[ii]);
  printf("\n");
}

int main(int argc, char* argv[]) {

  int n = 10;
  int data[] = {143,12,98,2,3,3,41,27,23,100};

  print_array(data,n);
  selection_sort(data,n);
  print_array(data,n);

  return 0;
}
