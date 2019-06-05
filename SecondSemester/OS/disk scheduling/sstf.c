#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,n,k,req[50],mov=0,cp,index[50],min,a[50],j=0,mini,cp1;
    printf("\nEnter the current position : ");
    scanf("%d",&cp);
    printf("\nEnter the number of requests : ");
    scanf("%d",&n);
    cp1=cp;
    printf("\nEnter the request order : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(k=0;k<n;k++){
    for(i=0;i<n;i++)
    {
        index[i]=abs(cp-req[i]); // calculate distance of each request from current position
                
    }
    // to find the nearest request
    min=index[0];
    mini=0;
    for(i=1;i<n;i++)
    {
        if(min>index[i])
        {
            min=index[i];
            mini=i;
        }
    }
    a[j]=req[mini];
    j++;
    cp=req[mini]; // change the current position value to next request
    req[mini]=199;
    } // the request that is processed its value is changed so that it is not processed again
    printf("Sequence is : ");
    printf("%d",cp1);    
    mov=mov+abs(cp1-a[0]);    // head movement
    printf("-->%d",a[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(a[i]-a[i-1]); ///head movement
        printf(" -> %d",a[i]);
    }
   
	printf("\nTotal head movement = %d\n",mov);
    printf("\nAverage seek time is %1.3f",mov/(float)n);
}