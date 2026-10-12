
#include <stdio.h>
#define N 100

int cap[N][N], parent[N], seen[N], n;

int dfs(int u, int t) {
    if (u == t) return 1;
    seen[u] = 1;

    for (int v = 0; v < n; v++)
        if (!seen[v] && cap[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, t)) return 1;
        }

    return 0;
}

int main() {
    int m, s, t, u, v, c, flow = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        cap[u][v] += c;
    }

    scanf("%d%d", &s, &t);

    while (1) {
        for (int i = 0; i < n; i++) seen[i] = 0;
        if (!dfs(s, t)) break;

        int add = 999999;
        for (v = t; v != s; v = parent[v])
            if (cap[parent[v]][v] < add)
                add = cap[parent[v]][v];

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            cap[u][v] -= add;
            cap[v][u] += add;
        }

        flow += add;
    }

    printf("Maximum flow = %d\n", flow);
    return 0;
}
