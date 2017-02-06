#include <stdio.h>

/* Function declarations */
void print_array(int *data, int n);
void copy_array(int *src, int iStart, int iEnd, int *dst);
void TopDownSplitMerge(int *src, int iStart, int iEnd, int *dst);
void TopDownMerge(int *src,int iStart, int iMiddle, int iEnd, int *dst);
/*************************/

void print_array(int *data,int n) {
  int ii;

  for (ii = 0; ii < n; ii++)
    printf("%d ",data[ii]);
  printf("\n");
}

void copy_array(int *src,int iStart, int iEnd, int *dst) {
  int ii;

  for(ii=iStart;ii<iEnd;ii++)
    dst[ii] = src[ii];
}

void TopDownSplitMerge(int *src, int iStart, int iEnd, int *dst) {

  int iMiddle;
  if (iEnd - iStart < 2)
    return;

  iMiddle = (iEnd + iStart) / 2;
  /* Alternating the merge direction with each level of recursion is
     a trick to avoid the copy-back step */
  TopDownSplitMerge(dst,iStart,iMiddle,src);
  TopDownSplitMerge(dst,iMiddle,iEnd,src);

  TopDownMerge(src,iStart,iMiddle,iEnd,dst);
}

void TopDownMerge(int *src,int iStart, int iMiddle, int iEnd, int *dst) {
  int ii = iStart;
  int jj = iMiddle;
  int kk;

  for (kk = iStart; kk < iEnd; kk++) {
    if (ii < iMiddle && (jj >= iEnd || src[ii] <= src[jj])) {
      dst[kk] = src[ii];
      ii = ii+1;
    } else {
      dst[kk] = src[jj];
      jj = jj+1;
    }
  } 
}

int main(int argc, char* argv[]) {

  int data[] = {143,12,98,2,3,3,41,27,23,100};
  int n = sizeof(data)/sizeof(int); // number of array elements
  int output[n];

  copy_array(data,0,n,output);
  print_array(data,n);

  // sort data from data into output
  TopDownSplitMerge(data,0,n,output);
  print_array(output,n);

  return 0;
}
