#include <stdio.h>

int main(){
  int N=0,A[101],i,j=0,v=0,k;

  //入力
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
   for(i=0;i<N-1;i++){
     printf("%d ",A[i]);
  }
   printf("%d",A[N-1]);
  
      printf("\n");
  //挿入ソート
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    //printf("%d",j);
    
    while(j>=0 && A[j]>v){//０番目ではないかつ取り出した数字より一つ前の数字が大きいとき
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
      for(k=0;k<N-1;k++){
	printf("%d ",A[k]);
      }
      printf("%d",A[N-1]);
      printf("\n");
  }
  /*
    for(i=0;i<N;i++){
    for(j=0;j<N;j++){
    printf("%d ",A[j]);
    }
    printf("\n");
    }*/
  return 0;
}
/*この問題は挿入ソート
出力は途中の計算結果全て
 入力
 6
 5 2 4 6 1 3
 出力
 5 2 4 6 1 3
 2 5 4 6 1 3
 2 4 5 6 1 3
 2 4 5 6 1 3
 1 2 4 5 6 3
 1 2 3 4 5 6
 */
