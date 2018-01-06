#include<iostream>
#include<algorithm> 
#include<vector>
#include<queue>

#include <stdio.h>
using namespace std;

#define DEBUG

#ifdef DEBUG
#define D printf
#else
#define D
#endif

int N, M, V;

vector< vector<int> > adj;    
vector<bool> visited;       

void dfs(int node) 
{
    int i;

    visited[node] = true;   
    printf("%d ", node); 

    for (i=0; i<adj[node].size(); i++) {
        int next = adj[node][i]; 

        if (visited[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int node) {
    int i;
    queue<int> q;

    visited[node] = true;
    q.push(node);

    while (!q.empty()) {

        int here = q.front();

        printf("%d ", here);
        q.pop();

        for (i=0; i<adj[here].size(); i++) {

            int next = adj[here][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() 
{
    int i;
    int s, e;

#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d %d %d", &N, &M, &V);
    adj.resize(N + 1);

    for (i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    visited = vector<bool>(N + 1, false);
    for (i = 0; i < adj.size(); i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(V);
    printf("\n");

    visited = vector<bool>(N + 1, false);
    bfs(V);
    printf("\n");

    return 0;
}
