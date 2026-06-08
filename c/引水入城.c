#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MAXV 5005
#define MAXE 400000
struct Edge {
    int to, next;
    ll cap;
} edge[MAXE];
int head[MAXV], cur[MAXV], dep[MAXV];
int cnt = 0;
void addEdge(int u, int v, ll w) {
    edge[cnt].to = v;
    edge[cnt].cap = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int q[MAXV];
int bfs(int s, int t) {
    memset(dep, -1, sizeof(dep));
    int front = 0, rear = 0;
    q[rear++] = s;
    dep[s] = 0;
    while (front < rear) {
        int u = q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (dep[v] == -1 && edge[i].cap > 0) {
                dep[v] = dep[u] + 1;
                q[rear++] = v;
            }
        }
    }
    return dep[t] != -1;
}
ll dfs(int u, int t, ll flow) {
    if (u == t) return flow;
    for (int *i = &cur[u]; *i != -1; *i = edge[*i].next) {
        int e = *i;
        int v = edge[e].to;
        if (dep[v] == dep[u] + 1 && edge[e].cap > 0) {
            ll d = dfs(v, t,
                       flow < edge[e].cap ? flow : edge[e].cap);
            if (d > 0) {
                edge[e].cap -= d;
                edge[e ^ 1].cap += d;
                return d;
            }
        }
    }
    return 0;
}
ll dinic(int s, int t) {
    ll maxflow = 0;
    while (bfs(s, t)) {
        memcpy(cur, head, sizeof(head));
        ll flow;
        while ((flow = dfs(s, t, INF)) > 0) {
            maxflow += flow;
        }
    }
    return maxflow;
}
int id(int x, int y, int m) {
    return (x - 1) * m + y;
}
int main() {
    ll n, m, A, B, Q, X0;
    scanf("%lld%lld%lld%lld%lld%lld",
          &n, &m, &A, &B, &Q, &X0);
    memset(head, -1, sizeof(head));
    int S = 0;
    int T = n * m + 1;
    ll x = X0;
    ll *ver = (ll*)malloc(sizeof(ll) * (n - 1) * m);
    for (ll i = 0; i < (n - 1) * m; i++) {
        x = (A * x + B) % Q;
        ver[i] = x;
    }
    ll *hor = (ll*)malloc(sizeof(ll) * (n - 2) * (m - 1));
    for (ll i = 0; i < (n - 2) * (m - 1); i++) {
        x = (A * x + B) % Q;
        hor[i] = x;
    }
    for (int j = 1; j <= m; j++) {
        addEdge(S, id(1, j, m), INF);
    }
    for (int j = 1; j <= m; j++) {
        addEdge(id(n, j, m), T, INF);
    }
    int idx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int u = id(i, j, m);
            int v = id(i + 1, j, m);
            ll c = ver[idx++];
            addEdge(u, v, c);
            addEdge(v, u, INF);
        }
    }
    idx = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int u = id(i, j, m);
            int v = id(i, j + 1, m);
            ll c = hor[idx++];
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
    }
    printf("%lld\n", dinic(S, T));
    free(ver);
    free(hor);
    return 0;
}