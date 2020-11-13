#include <stdio.h>
#define MAX_SIZE 25

int N;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int village_num = 0;
int village[MAX_SIZE * MAX_SIZE];

void dfs(int i, int j){
    int x[] = {0, -1, 1, 0};
    int y[] = {-1, 0, 0, 1};
    int k;
    visit[i][j] = 1;
    village[village_num]++;

    for (k = 0; k < 4; k++){
        int new_x = i + x[k];
        int new_y = j + y[k];

        if (0<= new_x && new_x< N && 0<=new_y && new_y < N){
            if(map[new_x][new_y] == 1 && visit[new_x][new_y] == 0){
                dfs(new_x, new_y);
            }
        }
    }

}

int main(){
    int i, j;
    int p, q, temp;
    scanf("%d", &N);

    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(i = 0; i < N; i++){
        for(j = 0; j<N; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                village_num++;

                dfs(i, j);
            }
        }
    }

    //오름차순 정렬
    for(p = 1; p <= village_num; p++){
        for (q = 1; q< village_num; q++){
            if(village[q] > village[q+1]){
                temp = village[q];
                village[q] = village[q+1];
                village[q+1] = temp;
            }
        }
    }

    printf("%d\n", village_num);

    for(i = 1; i <= village_num; i++){
        printf("%d\n", village[i]);
    }

    return 0;
}
