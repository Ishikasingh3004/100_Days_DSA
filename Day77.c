/* Problem:
Check if entire graph is connected using DFS.
*/

#include <stdio.h>

int visited[100];
int adj[100][100];

void dfs(int v, int n) {
    visited[v] = 1;

    for(int i = 1; i <= n; i++) {
        if(adj[v][i] && !visited[i])
            dfs(i, n);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v;

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(1, n);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}