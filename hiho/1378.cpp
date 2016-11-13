#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 505;
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp
{
    int m, n;

    vector<Edge> edges;  // double edge number
    vector<int> G[maxn]; //adj list the G[i][j] store the j-th edge of node i's index in edges
    int p[maxn];         // p[i] indicates the parent arc edge index
    int a[maxn];         // a[i] indicates the flow that we could modify from start to a[i]

    void init(int _n)
    {
        n = _n;
        edges.clear();

        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
        }
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    void maxFlow(int s, int t)
    {
        int res = 0;

        while (true)
        {
            memset(a, 0, sizeof(a));
            a[s] = 0x7fffffff;
            queue<int> q;
            q.push(s);

            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int i = 0; i < G[x].size(); i++)
                {
                    //get edges adjacent to x
                    Edge e = edges[G[x][i]];

                    if (!a[e.to] && e.cap > e.flow)
                    {
                        a[e.to] = min(a[x], e.cap - e.flow);
                        p[e.to] = G[x][i];
                        q.push(e.to);
                    }
                }

                if (a[t])
                {
                    break;
                }
            }

            if (!a[t])
            {
                // no augement path exist just break
                break;
            }

            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }

            res += a[t];
        }

        vector<int> S;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                S.push_back(i);
            }
        }

        printf("%d %d\n", res, S.size());

        for (int i = 0; i < S.size(); i++)
        {
            printf("%d ", S[i]);
        }

        printf("\n");
    }
};

int main()
{
    int n, m;

    while (~scanf("%d%d", &n, &m))
    {
        EdmondsKarp ek;
        ek.init(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            ek.addEdge(u, v, c);
        }
        ek.maxFlow(1, n);
    }
}