#include <stdio.h>
int n,m;
int arr[100];//n
int temp[10];//m
int line=0;

//temp madhe aahe ka nahi
int find(int key){
    for(int i=0;i<m;i++){
        if(temp[i]==key){
            //value is present
            // no need to perform any action  
            line ++;
            return 100;
        }
    }
   
    //element is not present then add that element
    return 1;
}


int main()
{
   
    printf("enter the string length :");
    scanf("%d",&n);
   
   
    printf("enter the value's :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
    printf("enter the number of PageFrame :");
    scanf("%d",&m);
   
    for(int i=0;i<m;i++){
        temp[i]=-1;
    }
   
    int old=0,k;
   
    for(int i=0;i<n;i++){
       
        for(int j=0;j<m;j++){
            printf("\t%d",temp[j]);
        }
       
        if(find(arr[i])==1){
            // element add kar
            if(old>=m){
            old=old%m;
            }
           
            temp[old]=arr[i];
            old++;
        }
        printf("\n");
    }
    for(int j=0;j<m;j++){
            printf("\t%d",temp[j]);
        }
   
   
    printf("\n");
   
    printf("total number of hit cases : %d",line);printf("\n");
    printf("total number of page fault : %d",n-line);printf("\n");
    printf("total number of hit cases : %f",(float)(n-line)*100/n);printf("\n");

    return 0;
}












