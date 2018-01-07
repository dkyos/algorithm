//https://www.acmicpc.net/problem/2644

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int N, M;
int K1, K2;

vector< vector<int> > adj;
vector<bool> visited;
int relation = -1;

//#define DEBUG
#ifdef DEBUG
#define D printf
#else
#define D
#endif

void dfs(int node, int depth)
{
    int i; 

    visited[node] = true;
    ++depth;

    for( i=0; i<adj[node].size(); i++){

        int next = adj[node][i];

        D("depth: %d with (%d, %d) \n", depth, node, next);

        if (next == K2){
            D("depth found: %d \n", depth);
            relation = depth;
            return;
        }

        if( visited[next] == false)
            dfs(next, depth);
    }

    return;
}

int main()
{
    int i, j;
    int s, e;

#ifdef DEBUG
    freopen("2644.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d", &N);
    scanf("%d %d", &K1, &K2);
    scanf("%dd", &M);
    D("N:%d, M:%d, K1:%d, K2:%d \n", N, M, K1, K2);

    adj.resize(N+1);
    visited = vector<bool>(N+1, false);

    for( i=0; i<M; i++){
        scanf("%d %d", &s, &e);
        D("s:%d, e:%d \n", s, e);

        adj[s].push_back(e);
        adj[e].push_back(s);
    }

#ifdef DEBUG
    for( i=0; i<adj.size(); i++){
        D("[%d] ", i);
        for( j=0; j<adj[i].size(); j++){
            D("%d ", adj[i][j]);
        }
        D("\n");
    }
    D("===============\n");

    for( i=0; i<N; i++){
        sort(adj[i].begin(), adj[i].end());
    }
#endif

    dfs(K1, 0);

    printf("%d\n", relation);

}

