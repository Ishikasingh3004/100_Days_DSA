///Problem: For each element, count how many smaller elements appear on right side.
///Use merge sort technique or Fenwick Tree (BIT).
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000  // adjust for input size

int BIT[MAX+1];

void update(int idx, int val, int n) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sorted[n];
    for(int i=0;i<n;i++) sorted[i]=arr[i];
    qsort(sorted, n, sizeof(int), cmp);

    // coordinate compression
    int rank[n];
    for(int i=0;i<n;i++) {
        int *pos = bsearch(&arr[i], sorted, n, sizeof(int), cmp);
        rank[i] = (int)(pos - sorted) + 1;
    }

    int result[n];
    for(int i=n-1;i>=0;i--) {
        result[i] = query(rank[i]-1);
        update(rank[i], 1, n);
    }

    printf("Result: ");
    for(int i=0;i<n;i++) printf("%d ", result[i]);
    return 0;
}
