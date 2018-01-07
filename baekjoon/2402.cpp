//https://www.acmicpc.net/problem/2042


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

vector<long long> seg;
int seg_size;

typedef long long ll;
int N, M, K;

//#define DEBUG

#ifdef DEBUG
#define D printf
#else
#define D
#endif

void print_seg()
{
    int i;

    for(i=1; i<seg_size; i++){
        D("seg[%d] = %lld \n", i,  seg[i]);
    }
}

ll update(int pos, int val, int node, int x, int y) 
{
    if (pos < x || pos > y) 
        return seg[node];

    if (x == y) 
        return seg[node] = val;

    ll mid = (x + y)/2;

    return seg[node] 
        = update(pos, val, node*2, x, mid) 
        + update(pos, val, node*2+1, mid+1, y);
}

ll query(int lo, int hi, int node, int x, int y) 
{
    if (x > hi || y < lo)   
        return 0;

    if (lo <= x && y <= hi) 
        return seg[node];

    ll mid = (x + y)/2;
    return query(lo, hi, node*2, x, mid) 
        + query(lo, hi, node*2+1, mid+1, y);
}

int main() 
{
    int d;
    int i, j;

#ifdef DEBUG
    freopen("2402.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d %d %d", &N, &M, &K);
    D("N:%d, M:%d, K:%d \n", N, M, K);

    seg_size = pow(2, log2(N)+1) + 1;
    seg.resize(seg_size+1);

    for (i=0; i<N; i++) {
        scanf("%d", &d);
        update(i, d, 1, 0, N-1);
    }

#ifdef DEBUG
    print_seg();
#endif

    int a, b, c;
    for (i=0; i<M+K; i++) {
        scanf("%d %d %d ", &a, &b, &c);
        D("a:%d, b:%d, c:%d \n", a, b, c);

        if( a == 1){
            update(b-1, c, 1, 0, N-1);
        }else if( a == 2 ){
            printf("%lld\n", query(b-1, c-1, 1, 0, N-1));
        }
    }

    return 0;
}
