/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array
*/
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    // Normalize k in case it's larger than n
    k = k % n;

    // Print rotated array
    for (int i = 0; i < n; i++) {
        int newIndex = (i + k) % n;
        printf("%d ", arr[(n - k + i) % n]);
    }

    return 0;
}
