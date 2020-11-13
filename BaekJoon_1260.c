#include <stdio.h>

void dfs(int v, int num);
void bfs(int start, int num);

//define queue
int q[10001];
int front = -1, rear = 0;

//define matrix and visit arrays
int matrix[1001][1001];
int dfsvisit[1001];
int bfsvisit[1001];

int main(void) {

    int num, edge, start;  //user's input
    int i, row, col;       //for matrix

    scanf("%d %d %d", &num, &edge, &start);
    for (i = 0; i < edge; i++) {
        scanf("%d %d", &row, &col);
        matrix[row][col] = matrix[col][row] = 1;
    }
    dfs(start, num);
    printf("\n");
    bfs(start, num);

    return 0;


}

/*
 * dfs function
 * v for vertices, num for edges
 * if the vertex has a edge and it hasn't been visited,
 * recursively put the vertex as parameter.
 */
void dfs(int v, int num) {
    dfsvisit[v] = 1;
    printf("%d ", v);
    for (int j = 1; j <= num; j++) {
        int next = j;
        if (matrix[v][next] == 1 && dfsvisit[next] == 0){
            dfs(next, num);
        }

    }
}

/*
 * bfs function
 * start for starting point, num for edges
 * if the vertex has a edge and it hasn't been visited,
 * mark vertex visited and put in queue.
 */
void bfs(int start, int num) {
    q[rear++] = start;
    bfsvisit[start] = 1;
    while (rear - front != 1) {
        int now = q[++front];
        printf("%d ", now);
        for (int j = 1; j <= num; j++) {
            int next = j;
            if (matrix[now][next] == 1 && bfsvisit[next] ==0) {
                bfsvisit[next] = 1;
                q[rear++] = next;
            }
        }
    }
}

