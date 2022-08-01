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

void FIFO(process* proc , int nbp){
    struct sched_param P;
int i,j,nb,sfin,ss,ssej,q,ttime,c;process permut;float temsej;int pidd,* pri;
  P.sched_priority=5;
for(i=0;i<nbp;i++)
for(j=i+1;j<nbp-1;j++)
{
if (proc[i].DA>proc[j].DA)

{
permut=proc[i];
proc[i]=proc[j];
proc[j]=permut;
}

}
printf("\n");

/*Afficher l'ordonnancement appilqué*/
printf("Ordonnancement FIFO\n");

/*Afficher la date d'arrivee et le temps d'execution de chaque processus*/
printf("Processus\t DA\t TE\n");
for (i=0;i<nbp;i++)
{
printf("%s\t\t %dms \t %dms\n",proc[i].nom,proc[i].DA,proc[i].TE);
}
printf("\n");
/*afficher lA DATE DE FIN D'EXECUTION DE CHAQUE  processuss*/
printf("****date de fin d'execution des %d processus****\n",nbp);
for(i=0;i<nbp;i++)
{printf("%s\t",proc[i].nom);
}
printf("\n");
/*Calcul*/
sfin=0;
ssej=0;
for(i=0;i<nbp;i++)
{
 sfin=sfin+proc[i].TE;
 proc[i].temfin=sfin;
 ssej=sfin-proc[i].DA;
 proc[i].tempsej=ssej;
printf("%dms\t",proc[i].temfin);

}
printf("\n");
/*afficher le temps de sejour de chaque processuss*/

printf("*******TEMPS DE SEJOUR*******\n");
for(i=0;i<nbp;i++)
{printf("%s\t",proc[i].nom);
}
printf("\n");
ss=0;
for(i=0;i<nbp;i++)
{ss=ss+proc[i].tempsej;
 printf("%dms\t",proc[i].tempsej);
}
printf("\n");
/*afficher le temps moyen de sejour */
printf("*******TEMPS MOYEN DE SEJOUR*******");
printf("\n");
temsej=(float)ss/nbp+1;
printf("le temps moyen de sejour est (temps moyen sejour= %fms\n",temsej);


}
