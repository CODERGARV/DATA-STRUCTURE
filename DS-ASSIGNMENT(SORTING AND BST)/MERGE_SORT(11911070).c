//PROGRAMME MADE BY GARV SINGHAL

//ROLL NO-11911070 BRANCH - CSE

//PROGRAMME FOR MERGE SORT AND IS WRITTEN IN C LANGUAGE

#include<stdlib.h>
#include<stdio.h>
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(char a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    char L1[n1], L2[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L1[i] = a[l + i];
    for (j = 0; j < n2; j++)
        L2[j] = a[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L1[i] <= L2[j])
        {
            a[k] = L1[i];
            i++;
        }
        else
        {
            a[k] =L2[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a[k] = L1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a[k] = L2[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergesort(int a,int b,char ptr[])
{
        if(a<b)
        {
        int c=(a+b)/2;
        mergesort(a,c,ptr);
        mergesort(c+1,b,ptr);
        merge(ptr,a,c,b);
        }
}

/* main functions */
int main()
{
    int n;
    printf("Enter size of array=");
    scanf("%d",&n);
    char *arr;
    arr=(char *)malloc(n*sizeof(char));
    printf("Enter list-");
            scanf("%s",arr);
    mergesort(0,n-1,arr);

    printf("\nSorted array is\n");
    for(int x=0;x<n;x++)
    {
         printf(" %c",arr[x]);
    }
 }
