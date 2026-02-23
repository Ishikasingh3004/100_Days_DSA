/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements
*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100], freq[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;  // initialize frequency array
    }

    // Count frequencies
    for (int i = 0; i < n; i++) {
        if (freq[i] != -1) continue;  // already counted

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;  // mark as counted
            }
        }
        freq[i] = count;
    }

    // Print results
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("%d:%d\n", arr[i], freq[i]);
        }
    }

    return 0;
}
