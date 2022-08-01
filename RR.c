#include <stdio.h>
#include <stdlib.h>
#include<sched.h>
#include<unistd.h>
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
int ct;
int wt;
int tat;
int rt;
int start_time;
int prio;
}process;
 int queue[100];
int front=-1;
int rear=-1;
// function for insert the element
// into queue
void insert(int nbp)
{
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=nbp;
}

// function for delete the
// element from queue
int delete()
{
    int n;
    n=queue[front];
    front=front+1;
    return n;
}
void RR(process* proc , int nbp , int TQ){
 int n,p,TIME=0;


    int temp[20],exist[20]={0};
    float total_wt=0,total_tat=0,Avg_WT,Avg_TAT;
/*Afficher l'ordonnancement appilqué*/

printf("Ordonnancement RR\n");
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
    for(int i=0;i<nbp;i++)
    {

        proc[i].pid=i;
        temp[i]=proc[i].TE;
    }

    // logic for round robin scheduling

    // insert first process
    // into ready queue
    insert(0);
    exist[0]=1;
    // until ready queue is empty
    while(front<=rear)
    {
        p=delete();
        if(proc[p].TE>=TQ)
        {
            proc[p].TE=proc[p].TE-TQ;
            TIME=TIME+TQ;
        }
        else
        {
            TIME=TIME+proc[p].TE;
            proc[p].TE=0;
        }


        //if process is not exist
        // in the ready queue even a single
        // time then insert it if it arrive
        // at time 'TIME'
        for(int i=0;i<nbp;i++)
        {
            if(exist[i]==0 && proc[i].DA<=TIME)
            {
                insert(i);
                exist[i]=1;
            }
        }
        // if process is completed
        if(proc[p].TE==0)
        {
            proc[p].tat=TIME-proc[p].DA;
            proc[p].wt=proc[p].tat-temp[p];
            total_tat=total_tat+proc[p].tat;
            total_wt=total_wt+proc[p].wt;
        }
        else
        {
            insert(p);
        }
    }

    Avg_TAT=total_tat/nbp-1;
    Avg_WT=total_wt/nbp-1;

    // printing of the answer
      for(int i=0;i<nbp;i++)
{

printf("%dms\t",proc[i].tat+proc[i].DA);

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
printf("*******TEMPS MOYENNE*******\n");
    printf("Temps d'attente moyenne  : %f\n",Avg_WT);
    printf("Temps de rotation moyenne  : %f\n",Avg_TAT);




  return 0;



}
