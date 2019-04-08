#include<stdio.h>
int main()
{
	int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;//variable declaration 
	float wtavg, tatavg;
	printf("Enter the number of PROCESS  in the queue : ");//no of process
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time for process  %d : ", i+1);//burst time
		scanf("%d",&bt[i]);
		printf("teacher/student process (0/1) ? ");//priority is given to teacher
		scanf("%d", &su[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(su[i] > su[k])//when teacher is having more priority
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];//calculation of waitinng time
		tat[i] = tat[i-1] + bt[i];//calculating turn around time
		wtavg = wtavg + wt[i];//waituing time 
		tatavg = tatavg + tat[i];//average tat
	}
	printf("\nPROCESS\t\t TEACHER/STUDENT-PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t\t %d \t\t\t %d \t\t %d \t\t %d ",p[i]+1,su[i],bt[i],wt[i],tat[i]);//value to be displayed at console
	}

	printf("\nAverage Waiting Time is %f",wtavg/n);
	printf("\nAverage Turnaround Time is  %f",tatavg/n);

	return 0;
}
