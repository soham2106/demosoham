#include<stdio.h>
int visit[10]={0}, visit2[10]={0};
int n, m[10][10], q[10], f=-1, r=-1, stk[10], top=-1;

void insert(int x){
    q[++r]=x;
}

int delete(){
    return q[++f];
}

void bfs(int s){
    int u,i;
    visit[s]=1;
    insert(s);
    while(f!=r){
        u=delete();
        printf("%c", (u+65));
        for(i=0; i<n;i++){
            if(m[i][u]==1 && visit[i]==0){
                insert(i);
                visit[i]=1;
            }
        }
    }
    printf("\n");
}

void push(int e){
    stk[++top]=e;
}

int pop(){
    return(stk[top--]);
}

void dfs(int s){
    int u,i;
    visit2[s]=1;
    push(s);
    while(top!=-1){
        u=pop();
        printf("%c", (u+65));
        for(i=0; i<n; i++){
            if(m[i][u]==1 && visit2[i]==0){
                push(i);
                visit2[i]=1;
            }
        }
    }
    printf("\n");
}

int main(void){
    FILE *p;
    int i,j,s;
    p=fopen("adj.txt", "r");
    if(p==NULL)
        printf("FILE NOT FOUND!");
    else{
        fscanf(p, "%d", &n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                fscanf(p, "%d", &m[i][j]);
            }
        }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
        printf("Enter the starting vertex: ");
        scanf("%d", &s);
        printf("BFS: ");
        bfs(s);
        printf("DFS: ");
        dfs(s);
    }
}