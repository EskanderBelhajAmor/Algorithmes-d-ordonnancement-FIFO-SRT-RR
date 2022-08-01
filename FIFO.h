#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED
  typedef struct process
{
char nom[20];
int DA;
int TE;
int tempsej;
int temfin;
int pol;
int pr;
int reste;
 int ct,wt,tat,rt,start_time;

}process;
void FIFO(process* proc , int nbp);

#endif
