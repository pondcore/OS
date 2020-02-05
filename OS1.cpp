
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void findWaitingTime(int processes[], int n,
					 int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	cout << "Processes "
		 << " Burst time "
		 << " Waiting time "
		 << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
			 << wt[i] << "\t\t " << tat[i] << endl;
	}

	cout << "Average waiting time = "
		 << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		 << (float)total_tat / (float)n;
}

int main()
{
	srand(time(0));

	int processes[60];
	int n = sizeof processes / sizeof processes[0];

	int burst_time[60];

	int i=0;
	int type;

	while (i < 60)
	{
		type = rand()%10;
		if (type >= 0 and type <= 7)
		{
			burst_time[i] = rand()%7+2;
		}
		if (type > 7 and type <= 9)
		{
			burst_time[i] = rand()%11+20;
		}if (type > 9 and type <= 1)
		{
			burst_time[i] = rand()%6+35;
		}
		i++;
	}
	
	findavgTime(processes, n, burst_time);
	return 0;
}
