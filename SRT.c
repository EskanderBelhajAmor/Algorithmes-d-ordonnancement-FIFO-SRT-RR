#include<stdio.h>
#include<stdlib.h>
# define MAX_VALUE 9999;
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
void sort(int* a, int *b,int *pro,int n){
	int k,j,key1,key2,key3;
	for(int i=1; i<n; i++){
		j=i-1;
		key1=a[i];
		key2=b[i];
		key3=pro[i];
		while(j>=0 && key1<a[j]){
			a[j+1]=a[j];
			b[j+1]=b[j];
			pro[j+1]=pro[j];
			j--;
		}
		a[j+1]=key1;
		b[j+1]=key2;
		pro[j+1]=key3;
	}
}
int findLeastBurstTime(int* bt, int* at, int ct,int n){
	int min_value=bt[0];
	int min_index=0;
	for(int i=0; i<n && at[i]<=ct; i++){
		if(bt[i]<min_value){
			min_value=bt[i];
			min_index=i;
		}
	}
	return min_index;
}
void SRT(process* proc , int nbp){
    int n;
    n=nbp;

	int at[n],bt[n],bt1[n],ct[n],tat[n],wt[n],pro[n];

	for(int i=0; i<n; i++){
		at[i]=proc[i].DA;
		bt[i]=proc[i].TE;
		pro[i]=i+1;
	}



	printf("\n");

/*Afficher l'ordonnancement appilqué*/
printf("Ordonnancement SRT\n");

/*Afficher la date d'arrivee et le temps d'execution de chaque processus*/
printf("Processus\t DA\t TE\n");
for (int i=0;i<nbp;i++)
{
printf("%s\t\t %dms \t %dms\n",proc[i].nom,proc[i].DA,proc[i].TE);
}
printf("\n");

	sort(at,bt,pro,n);
	for(int i=0; i<n; i++)
		bt1[i]=bt[i];
	// calculating complete time

	printf("\nDiagramme de GANTT\n");

	int prev_i,c,i,loop_count=n,max=MAX_VALUE;
	i=findLeastBurstTime(bt,at,at[0],n);
	//printf("i=%d\n",i);
	printf("%s ",proc[i].nom);
	c=at[i]+1;
	ct[i]=c;
	bt[i]--;

	if(bt[i]==0)
	{
		bt[i]=MAX_VALUE;
		loop_count--;
	}

	while(loop_count>0)
	{
		prev_i=i;
		i=findLeastBurstTime(bt,at,c,n);
		if(prev_i!=i)
			printf("%s ",proc[i].nom);
		c++;
		if(bt[i]!=max)
		{
			ct[i]=c;
			bt[i]--;
			if(bt[i]==0)
			{
				bt[i]=MAX_VALUE;
				loop_count--;
			}
		}
	}

	// calculating waiting and turn around time
	float sum_tat=0,sum_wt=0;
	for(int i=0; i<n; i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt1[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	printf("\n");

	printf("\n\proc     temps d arrivee      temps d'execution      Temps sejour     Temps d attente\n");
	for(int i=0; i<n; i++){
		printf("%s\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",proc[i].nom,at[i],bt1[i],tat[i],wt[i]);
	}

	printf("\ntemps de rotation moyenne: %.2f\ntemps d attente moyenne: %.2f\n",sum_tat/n,sum_wt/n);
}
