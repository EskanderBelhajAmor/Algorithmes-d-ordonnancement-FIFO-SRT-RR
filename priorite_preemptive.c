#include<stdio.h>
#define MIN -9999;
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

void prio(process* proc , int nbp)
{

  struct proc
{
    int no,at,bt,rt,ct,wt,tat,pri,temp;
};
 struct proc p[20],temp;
for (int i=0 ;i<nbp;i++){
p[i].no=i;
p[i].at=proc[i].DA;
p[i].rt=p[i].bt=proc[i].TE;
p[i].temp=p[i].pri=proc[i].prio;

}






    int i,n,c,remaining,max_val,max_index;

    float avgtat=0,avgwt=0;
    printf("\n");
    /*Afficher l'ordonnancement appilqué*/
printf("Ordonnancement Priorite preemptive\n");

/*Afficher la date d'arrivee et le temps d'execution de chaque processus*/
printf("Processus\t DA\t TE\t PRIO \n");
for (int i=0;i<nbp;i++)
{
printf("%s\t\t %dms \t %dms  \t %dms\n",proc[i].nom,proc[i].DA,proc[i].TE,proc[i].prio);
}
printf("\n");
   n=nbp;
remaining=n;

	for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
    max_val=p[0].temp,max_index=0;
	for(int j=0;j<n&&p[j].at<=p[0].at;j++)
		if(p[j].temp>max_val)
			max_val=p[j].temp,max_index=j;
	i=max_index;
	c=p[i].ct=p[i].at+1;
	p[i].rt--;
	if(p[i].rt==0)
	{
		p[i].temp=MIN;
		remaining--;
	}
	while(remaining>0)
	{
		max_val=p[0].temp,max_index=0;
    	for(int j=0;j<n&&p[j].at<=c;j++)
    		if(p[j].temp>max_val)
    			max_val=p[j].temp,max_index=j;
    	i=max_index;
		p[i].ct=c=c+1;
		p[i].rt--;
		if(p[i].rt==0)
		{
		    p[i].temp=MIN;
		    remaining--;
		}
	}
	printf("\nProcess\t\tTA\tTE\tPrio\tTemps sejour\ttemps d attente\n");
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        avgtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avgwt+=p[i].wt;
        printf("%s\t\t%d\t%d\t%d\t\t%d\t\t%d\n",proc[i].nom,p[i].at,p[i].bt,p[i].pri,p[i].tat,p[i].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\ntemps de rotation moyenne=%f\ntemps d attente moyenne=%f",avgtat,avgwt);
}
