/* Problem:
Find total weight of Minimum Spanning Tree using Prim's Algorithm.
*/

#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, min_index;

    for(int i = 0; i < n; i++) {
        if(!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n = 4;
    int graph[4][4] = {
        {0,3,0,5},
        {3,0,1,4},
        {0,1,0,2},
        {5,4,2,0}
    };

    int parent[n], key[n], mst[n];

    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n-1; i++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;

        for(int v = 0; v < n; v++) {
            if(graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    for(int i = 1; i < n; i++)
        total += key[i];

    printf("%d", total);
    return 0;
}