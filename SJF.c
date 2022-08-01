#include <stdio.h>
#include <stdlib.h>
#include<sched.h>
#include<unistd.h>
#include<stdbool.h>
#include<limits.h>
typedef struct process
{
char nom[20];
int pid;
int DA;
int TE;
int tempsej;
int temfin;
int pol;
int pr;
int reste;
int ct,wt,tat,rt,start_time;
int prio;
}process;
int findmax(int a, int b)
{
    return a>b?a:b;
}

int findmin(int a, int b)
{
    return a<b?a:b;
}

void SJF(process* proc , int nbp){






    int n;
    bool is_completed[100]={false},is_first_process=true;
    int current_time = 0;
    int completed = 0;;

    int sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0,prev=0,length_cycle;
    float cpu_utilization;
    int max_completion_time,min_arrival_time;

    for(int i=0;i<nbp;i++)
    {

        proc[i].pid = i ;
    }

/*Afficher l'ordonnancement appilqué*/
printf("Ordonnancement SJF\n");
/*Afficher la date d'arrivee et le temps d'execution de chaque processus*/
printf("Processus\t DA\t TE\n");
for (int i=0;i<nbp;i++)
{
printf("%s\t\t %dms \t %dms\n",proc[i].nom,proc[i].DA,proc[i].TE);
}
printf("\n");
/*afficher lA DATE DE FIN D'EXECUTION DE CHAQUE  processuss*/
printf("****date de fin d'execution des %d processus****\n",nbp);
for(int i=0;i<nbp;i++)
{printf("%s\t",proc[i].nom);
}
printf("\n");

    while(completed!=nbp)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < nbp; i++) {
            if(proc[i].DA <= current_time && is_completed[i] == false) {
                if(proc[i].TE < minimum) {
                    minimum = proc[i].TE;
                    min_index = i;
                }
                if(proc[i].TE== minimum) {
                    if(proc[i].DA < proc[min_index].DA) {
                        minimum= proc[i].TE;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index==-1)
        {
            current_time++;
        }
        else
        {
      proc[min_index].start_time = current_time;
      proc[min_index].ct = proc[min_index].start_time + proc[min_index].TE;
      proc[min_index].tat = proc[min_index].ct - proc[min_index].DA;
      proc[min_index].wt = proc[min_index].tat - proc[min_index].TE;
       proc[min_index].rt = proc[min_index].wt;
        // ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;

        sum_tat +=proc[min_index].tat;
        sum_wt += proc[min_index].wt;
        sum_rt += proc[min_index].rt;
        total_idle_time += (is_first_process==true) ? 0 : (proc[min_index].start_time -  prev);

        completed++;
        is_completed[min_index]=true;
        current_time = proc[min_index].ct;
        prev= current_time;
        is_first_process = false;
        }
    }

    //Calculate Length of Process completion cycle
    max_completion_time = INT_MIN;
    min_arrival_time = INT_MAX;
    for(int i=0;i<nbp;i++)
    {
        max_completion_time = findmax(max_completion_time,proc[i].ct);
        min_arrival_time = findmin(min_arrival_time,proc[i].DA);
    }
    length_cycle = max_completion_time - min_arrival_time;

   for(int i=0;i<nbp;i++)
{

printf("%dms\t",proc[i].ct);

}
printf("\n");
/*afficher le temps de sejour de chaque processuss*/

printf("*******TEMPS D ATTENTE*******\n");
for(int i=0;i<nbp;i++)
{printf("%s\t",proc[i].nom);
}
printf("\n");
for(int i=0;i<nbp;i++)
{
 printf("%dms\t",proc[i].wt);
}
printf("\n");
/*afficher le temps moyen de sejour */
printf("*******TEMPS MOYEN *******");
printf("\n");



    cpu_utilization = (float)(length_cycle - total_idle_time)/ length_cycle;

    printf("\ntemps moyenne de rotation= %f ",(float)sum_tat/nbp);
    printf("\ntemps moyenne d'attente= %f ",(float)sum_wt/nbp);


    return 0;


}
