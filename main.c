#include <stdio.h>

#include <stdlib.h>

#include<sched.h>

#include<stdbool.h>

#include<limits.h>

#include<unistd.h>

#include"FIFO.h"

#include"SJF.h"
#include"SRT.h"
#include"RR.h"
#include"priorite_preemptive.h"
#include <dirent.h>

#include <sys/types.h>

#include <string.h>

int main(int argc, char *argv[])

{

    int i=0, nbr,q ;

    char aa[20][20] ={0};
char comment[200];
    int bb[20]={0}, cc[20]={0} , dd[20]={0};



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







process* proc ;


printf("********BIENVENUE********\n");
printf("=========================\n ");







printf("\n \n");


char fichier[50];
printf("donner le fichier de configuration : \n ");
scanf("%s",&fichier);


FILE *f = fopen(fichier,"r");




int c;

int nbp = 1;

while((c=fgetc(f)) != EOF)

{

	if(c=='\n')

		nbp++;

}

fclose(f);





f=fopen(fichier,"r");



proc=( process *)malloc(sizeof( process )*nbp);

if(f!=NULL){

        do{   fscanf(f,"%s %d %d %d #%s",&aa[i],&bb[i],&cc[i],&dd[i],&comment);





        i++;



        }

   while(i<nbp) ;



   }











char all[20];

strcpy(all , aa[0]);











fclose(f);







int j,jj; for ( j=0,jj=1 ;j<(nbp-1),jj<nbp;j++,jj++){

strcpy(proc[j].nom , aa[jj]);

proc[j].DA=bb[jj];

proc[j].TE=cc[jj];
proc[j].prio=dd[jj];}





nbp--;



printf("\n Voici les algorithmes existants dans notre applications : \n \n");




   DIR *di;

    char *ptr1,*ptr2;

    int retn,retn1;

    struct dirent *dir;

    di = opendir("."); //specify the directory name

    if (di)

    {

        while ((dir = readdir(di)) != NULL)

        {

            ptr1=strtok(dir->d_name,".");

            ptr2=strtok(NULL,".");

            if(ptr2!=NULL)

            {

                retn=strcmp(ptr2,"c");

                retn1=strcmp(ptr1,"main");



                if((retn==0)&&(retn1!=0))

                {
                    printf(" * %s\n",ptr1);


                }

            }

        }

        closedir(di);

    }

    printf("\n");
    char choix[20];

  printf("Choisir un algorithme .. \n");

  scanf("%s",&choix);



int c1,c2,c3 ,c4 , c5 , c6;

c1=strcmp(choix,"fifo");

c2=strcmp(choix,"sjf");

c3=strcmp(choix,"rr");
c4=strcmp(choix,"srt");

c5=strcmp(choix,"prio");



if (c1==0){

   FIFO(proc,nbp);

}

else if(c2==0){

SJF(proc,nbp);

}



else if (c3==0){

        printf("donner le quatum : \n");

scanf("%d",&q);



        RR(proc,nbp,q);}




        else if(c4==0){

SRT(proc,nbp);

}

else if (c5==0) { prio(proc,nbp);}
else { FIFO(proc,nbp);}
printf("\n=============================================== \n \n \n");

}

