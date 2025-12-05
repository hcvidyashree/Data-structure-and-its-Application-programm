#include<stdio.h>
#include<stdlib.h>
void heapify(int a[10],int n){
    int i,k,v,j,flag=0;
    for(i=n/2;i>=1;i--){
        k=i;
        v=a[k];
        while(!flag && 2*k<=n){
            j=2*k;
            if(j<n){
                if(a[j]<a[j+1]){
                    j=j+1;
                }
            }
            if(v>=a[j]){
                flag=1;
            }
            else{
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
        flag=0;
    }
}
int main(){
    int n,a[10],i,ch;
    for(;;){
        printf("\n1.Create heap\n2.Extract max\n3.Exit\n");
        printf("\nRead choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nRead the no.of elements:");
                   scanf("%d",&n);
                   printf("\nRead elements:\n");
                   for(i=1;i<=n;i++){
                    scanf("%d",&a[i]);
                   }
                   heapify(a,n);
                   printf("\nElements after constructing heap\n");
                   for(i=1;i<=n;i++){
                        printf("%d\t",a[i]);
                   }
                   break;
            case 2:if(n>=1){
                        printf("\nElement deleted is %d",a[1]);
                        a[1]=a[n];
                        n=n-1;
                        heapify(a,n);
                        printf("\nHeap after reconstruction:\n");
                        for(i=1;i<=n;i++){
                            printf("%d\t",a[i]);
                   }
                   }
                   else{
                    printf("\nNo element to delete");
                    break;
                   }
            default:exit(0);
        }
    }
    return 0;
}
