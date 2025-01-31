#include<stdio.h>
#define max 1000
#include<stdlib.h>
#include<string.h>
int save_number[max];

int maximum(int a,int b){
    return (a>b)?a:b;
}
int lcs(char *x,char *y,int xlen,int ylen){
  int i,j;
//printf("%dと%d\n",xlen,ylen);
   int length[xlen+1][ylen+1];
   for(i=0;i<xlen+1;i++){
       for(j=0;j<ylen+1;j++){
           if(i==0 || j==0){
               //いくつ同じものがあるのかカウントするもの
              length[i][j]=0;
            }
           //同じものならば
            else if(x[i-1]==y[j-1]){
                length[i][j]=length[i-1][j-1]+1;
                //printf("same\n");
            }else{//違ければ
                 length[i][j]=maximum(length[i-1][j],length[i][j-1]);
                 //printf("different\n");
            }
        }
   }
   //printf("%d\n",length[xlen][ylen]);
   return length[xlen][ylen];
}

int main(){
    char x[max],y[max];
    int num,i;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%s",x);
        scanf("%s",y);
        /*
        int xlen=strlen(x);
        int ylen=strlen(y);
        printf("%d\n",lcs(x,y,xlen,ylen));
        */
        save_number[i]=lcs(x,y,strlen(x),strlen(y));
    }
    for(i=0;i<num;i++){
        printf("%d\n",save_number[i]);
    }
    return 0;
}

/*
最長共通部分列
与えられたそれぞれセットに置いて幾つ共通があるか求める
入力
3
abcbdab
bdcaba
abc
abc
abc
bc
出力
4
3
2
*/
