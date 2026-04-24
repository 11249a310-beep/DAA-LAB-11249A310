#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, src;
    int cost[10][10], dist[10], visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Fix 1: Initialize all distances to INT_MAX, then set reachable neighbors
    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (i = 0; i < n; i++) {
        if (i != src && cost[src][i] != 0)   // Fix 2: 0 means no edge
            dist[i] = cost[src][i];
    }

    visited[src] = 1;

    for (i = 1; i < n; i++) {
        int min = INT_MAX, u = -1;            // Fix 3: initialize u to -1

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;                   // Fix 4: handle disconnected graph

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            // Fix 5: guard against INT_MAX overflow and skip absent edges
            if (!visited[j] && cost[u][j] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> %d = unreachable\n", src, i);   // Fix 6: handle unreachable
        else
            printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}