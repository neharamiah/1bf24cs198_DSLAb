#include<stdio.h>
#define MAX 10
int visited[MAX];
int adj[MAX][MAX];
int n;
void DFS(int v){
    visited[v]=1;
    printf("%d",v);
    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && !visited[i]){
            DFS(i);
        }
    }
}
int main(){
    printf("enter the number of vertices: ");
    scanf("%d",&n);
    printf("adjacency matrix is:");
    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&adj[i][j]);
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("DFS traversal: ");
    DFS(0);
    return 0;
}
