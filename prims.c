#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, min, u, v;
    int from, next;                              // Fix 1: dedicated variables to track edge endpoints
    int cost[10][10], visited[10] = {0};
    int total = 0;                               // Bonus: track total MST cost

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;
    printf("Edges in MST:\n");

    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        from = -1;
        next = -1;                               // Fix 2: reset each iteration

        for (u = 0; u < n; u++) {
            if (visited[u]) {
                for (v = 0; v < n; v++) {
                    if (!visited[v] && cost[u][v] != 0 && cost[u][v] < min) {
                        min = cost[u][v];
                        from = u;               // Fix 3: save source vertex
                        next = v;               // Fix 4: save destination vertex
                    }
                }
            }
        }

        if (next == -1) {                        // Fix 5: handle disconnected graph
            printf("Graph is disconnected!\n");
            return 1;
        }

        printf("Edge %d -> %d  cost: %d\n", from, next, min);  // Fix 6: now prints full edge
        total += min;
        visited[next] = 1;                       // Fix 7: was visited[j], now visited[next]
    }

    printf("Total MST cost: %d\n", total);       // Bonus: print total cost
    return 0;
}