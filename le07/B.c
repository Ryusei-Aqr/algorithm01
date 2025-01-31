#include<stdio.h>
#define null -1
#define max 100000

//leftがchild、rightがsiblingとなる
typedef struct{
  int parent,left,right;
}node;

node tree[max];

int num,depth[max],high[max];

//深さ、再帰
void deep(int a,int d){
  if(a==null)return;
  depth[a]=d;
  deep(tree[a].right,d+1);
  deep(tree[a].left,d+1);
}

//兄弟
int sibling(int a){
  if(tree[a].parent==null){
    return null;
  }
  if(tree[tree[a].parent].right!=a && tree[tree[a].parent].right!=null){
    return tree[tree[a].parent].right;
  }
  if(tree[tree[a].parent].left!=a && tree[tree[a].parent].left!=null){
    return tree[tree[a].parent].left;
  }
  return null;
  
}

//高さ、再帰
int tall(int a){
   int h1=0,h2=0;

   if(tree[a].left!=null){
     h1=tall(tree[a].left)+1;
   }
   if(tree[a].right!=null){
     h2=tall(tree[a].right)+1;
   }
   return high[a]=(h1>h2 ? h1:h2);
}

//関数、出力、深さ、兄弟の数、高さ
void print(int a){
  int d=0;
  
  printf("node %d: ",a);
  printf("parent = %d, ",tree[a].parent);
  printf("sibling = %d, ",sibling(a));

  if(tree[a].right!=null)d++;
  if(tree[a].left!=null)d++;

  printf("degree = %d, ",d);
  printf("depth = %d, ",depth[a]);
  printf("height = %d, ",high[a]);

  if(tree[a].parent==null){
    printf("root\n");
  }else if(tree[a].left==null && tree[a].right==null){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}

int main(){
  int i,id,left,right,root=0;
  //節点の個数
  scanf("%d",&num);
  //親を全て初期化
  for(i=0;i<num;i++){
    tree[i].parent=null;
  }
  //節点番号、左側、右側
  for(i=0;i<num;i++){
    scanf("%d%d%d",&id,&left,&right);
    tree[id].left=left;
    tree[id].right=right;
    //親を決めてあげる（イメージができない）
    if(left!=null){
      tree[left].parent=id;
    }
    if(right!=null){
      tree[right].parent=id;
    }
  }
  //根を求める
  for(i=0;i<num;i++){
    if(tree[i].parent==null){
      root=i;
    }
  }

  deep(root,0);
  tall(root);
  
  for(i=0;i<num;i++){
    print(i);
  }
  
  return 0;
}
/*
二分木
入力
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
出力
node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
node 1: parent = 0, sibling = 4, degree = 2, depth = 1, height = 1, internal node
node 2: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
node 3: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
node 4: parent = 0, sibling = 1, degree = 2, depth = 1, height = 2, internal node
node 5: parent = 4, sibling = 8, degree = 2, depth = 2, height = 1, internal node
node 6: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
node 7: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
node 8: parent = 4, sibling = 5, degree = 0, depth = 2, height = 0, leaf*/
