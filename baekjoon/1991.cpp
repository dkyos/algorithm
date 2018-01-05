//https://www.acmicpc.net/problem/1991

#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include <string.h>

//#define DEBUG
#ifdef DEBUG
#define D printf
#else
#define D
#endif

// 1 <= N <= 26, # of Node
#define N_MAX 26

struct tree {
    char me;
    char left;
    char right;
    char tmp;
};

tree data[N_MAX];

// order 0 : preorder, order 1 : inorder, order 2 : postorder
int porder(int node, int order)
{
    if (order == 0){
        printf("%c", data[node].me);
    }

    if (data[node].left != '.'){
        porder(data[node].left - 'A', order);
    }

    if (order == 1){
        printf("%c", data[node].me);
    }

    if (data[node].right != '.'){
        porder(data[node].right - 'A', order);
    }

    if (order == 2){
        printf("%c", data[node].me);
    }

    return 0;
}

int main() {
    int N;
    int i, j;
    int node, order;
    char a, b, c;

#ifdef DEBUG
    freopen("1991.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d ", &N);
    D("N:%d \n", N);

    memset(data, 0, sizeof(data));

    for(i=0; i<N; i++){
        scanf("%c %c %c ", &a, &b, &c);
        node = a - 'A';
        data[node].me    = a;
        data[node].left  = b;
        data[node].right = c;
    }

#ifdef DEBUG
    for(i=0; i<N; i++){
        D("(%c, %c, %c) \n", data[i].me, data[i].left, data[i].right);
    }
    D("==========\n");
#endif

    // order 0 : preorder, order 1 : inorder, order 2 : postorder
    for(order=0; order<3; order++){
        porder(0, order);
        printf("\n");
    }

#ifdef DEBUG
    D("0: ABDCEFG \n");
    D("1: DBAECFG \n");
    D("2: DBEGFCA \n");
#endif

}

