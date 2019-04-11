#include<stdio.h>
#include<stdlib.h>
int num,bt[20],at[20],ct=0,wt=0,tat=0,rt[10];;
int i;
float awt,atat;
float sumWT,sumTAT;

void takeInput(){
    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&bt[i]);
        printf("\nEnter arival time for process %d : ",i+1);
        scanf("%d",&at[i]);
        rt[i]=bt[i]; 
    }
}
int rrMethod(){
    int count,j,time,remain,flag=0,time_quantum; 
    remain=num;  

    printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      wt+=time-at[i]-bt[i]; 
      tat+=time-at[i]; 
      flag=0; 
    }
    if(i==num-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wt*1.0/num); 
  printf("Avg Turnaround Time = %f",tat*1.0/num); 
  
  return 0; 
}
int fcfsMethod(){
      printf("\nPid \t\t AT \t\t BT \t\t CT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        ct += bt[i];
        tat=ct-at[i];
        wt=tat-bt[i];
        sumWT += wt;
        sumTAT += tat;
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],bt[i],ct,wt,tat);
    }
    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");
}
void main(){
    printf("Round Robin & FCFS scheduling algorithm \n");
    int ch;
    while(1){
        printf("1-RR\n2-FCFS\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                 takeInput();
                 rrMethod();
                  break;
            case 2:
                 takeInput();
                fcfsMethod();
                break;                
    }
}
}