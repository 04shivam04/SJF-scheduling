#include <stdio.h>

void avarageTime(int n, int ta[], char s[]){
    int totalTime = 0;
    float avarageTime = 0;
    for(int i=0; i<n; i++){
        totalTime = totalTime + ta[i]; 
    }
    
    avarageTime = (float)totalTime/n;
    printf("Total avarage %s time is: %.2f \n",s,avarageTime);
}

int sjfArraySort(int n, int bt[]){
    int i, j, temp;

    for(i=0; i<n; i++)
    {
        
        for(j=i+1; j<n; j++)
        {
            
            if(bt[i] > bt[j])
            {
                temp  = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

}
// int prioritySchedulingSorting(int n, int process[], int priority[], int bt[]){
//     int i,j,temp,pos;
//     for(i=0;i<n;i++)
//     {
//         pos=i;
//         for(j=i+1;j<n;j++)
//         {
//             if(priority[j]<priority[pos])
//                 pos=j;
//         }

//         temp=priority[i];
//         priority[i]=priority[pos];
//         priority[pos]=temp;

//         temp=bt[i];
//         bt[i]=bt[pos];
//         bt[pos]=temp;

//         temp=process[i];
//         process[i]=process[pos];
//         process[pos]=temp;
//     }

// }
void findWaiingTime(int n, int bt[], int process[], int priority[]){
    int wt[n];
    int tt[n];
    wt[0]=0;
    int i;
    sjfArraySort(n,bt);
    //prioritySchedulingSorting(n, process, priority, bt);
    
    for (i=1; i<n; i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    for (i=0; i<n; i++){
        tt[i] = bt[i]+wt[i];
    }
    printf("Process | \t BT | \tWT | \t TT\n");
    for(i=0; i<n; i++){
        printf(" %d",(i+1));
        printf("\t\t %d",bt[i]);
        printf("\t %d",wt[i]);
        printf("\t %d",tt[i]);
        printf("\n");
    }
    
    avarageTime(n, wt, "Waiting");
    avarageTime(n, tt, "Turn Around Time");
}

int main()
{
    int process[] = {1,2,3,4,5};
    int priority[] = {3,1,3,4,2};
    int burst_time[] = {10,1,2,1,5};
    
    int n = 5;
    
    findWaiingTime(n,burst_time,process,priority);

    return 0;
}
