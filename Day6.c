/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100]; // assuming max size 100
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Index to place next unique element
    int j = 0;

    for (int i = 0; i < n; i++) {
        // If current element is different from the previous one, keep it
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[j++] = arr[i];
        }
    }

    // Print unique elements
    for (int i = 0; i < j; i++) {
        printf("%d", arr[i]);
        if (i < j - 1) printf(" ");
    }

    return 0;
}
