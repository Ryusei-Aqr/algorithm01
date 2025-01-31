#include<stdio.h>
#define max 1000
#define inf 100000
#define w 0
#define g 1
#define b 2
int vertex_num,admat[max][max];
/*
int Prims(){
  int i,j,u,v,cost[max][max],min_distance;
  int visit[max],no_edges,min_cost,distance[max],from[max];
  
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
      if(admat[i][j]==0){
          cost[i][j]=inf;
      }else{
	cost[i][j]=admat[i][j];
	}
    }
  }
  
  distance[0]=0;
  visit[0]=1;

  for(i=1;i<vertex_num;i++){
      distance[i]=cost[0][i];
      from[i]=0;
      visit[i]=0;
  }
  min_cost=0;
  no_edges=vertex_num-1;

  while(no_edges>0){
     min_distance=inf;
     for(i=1;i<vertex_num;i++){
         if(visit[i]==0 && distance[i]<min_distance){
             v=i;
             min_distance=distance[i];
         }
     }
     u=from[v];
     no_edges--;
     visit[v]=1;
     for(i=1;i<vertex_num;i++){
         if(visit[i]==0 && cost[i][v]<distance[i]){
             distance[i]=cost[i][v];
             from[i]=v;
         }
     }
     min_cost+=cost[u][v];
  }
  
  return min_cost;
}
*/

int Prim(){
  int vertex,min_vertex;
  int distance[max],parent[max],color[max],cost;
  int i,j;
  for(i=0;i<vertex_num;i++){
    distance[i]=inf;
    parent[i]=-1;
    color[i]=w;
  }
  distance[0]=0;
  while(1){
    min_vertex=inf;
    vertex=-1;
    for(i=0;i<vertex_num;i++){
      if(min_vertex>distance[i] && color[i]!=b){
	vertex=i;
	min_vertex=distance[i];
      }
    }
    if(vertex==-1)break;
    color[vertex]=b;
    for(i=0;i<vertex_num;i++){
      if(color[i]!=b && admat[vertex][i]!=inf){
	if(distance[i]>admat[vertex][i]){
	  distance[i]=admat[vertex][i];
          parent[i]=vertex;
	  color[i]=g;
	}
      }
    }
  }
  cost=0;
  for(i=0;i<vertex_num;i++){
    if(parent[i]!=-1){
      cost+=admat[i][parent[i]];
    }
  }
  return cost;
}




int main(){
  //admatは隣接行列
  int i,j,num;

  scanf("%d",&vertex_num);
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
      scanf("%d",&num);
      if(num==-1){
	admat[i][j]=inf;
      }else{
	admat[i][j]=num;
      }
  }
  }
  /*
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
       if(admat[i][j]==-1){
           admat[i][j]=0;
       }
       //printf("%d ",admat[i][j]);
    }
*/
  
  printf("%d\n",Prim());
  return 0;
}

/*この問題はプリム法、最小全域木に関する問題
入力
5
 -1 2 3 1 -1
 2 -1 -1 4 -1
 3 -1 -1 1 1
 1 4 1 -1 3
 -1 -1 1 3 -1
出力
5
*/
