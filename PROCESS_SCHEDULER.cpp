#include <stdio.h>
#include<stdlib.h>

struct node
{
  int id;
  int bt;
  struct node *next,*pre;
};

//*****************************************************************************************************************************************************************************
int k;
struct node *insertion(struct node *process)
{
  int ch=0;
  struct node *ptr,*n;
  n=(struct node *)malloc(sizeof(struct node));
  k++;
  n->id=k;
  n->bt=rand()%50;
  n->next=n;
  n->pre=n;
//printf("enter choice");

do
  {
if(process==NULL)
{
	
  process=n;
  
  }
  else
  {
  k++;
     n=(struct node *)malloc(sizeof(struct node));
     n->bt=rand()%50;
  n->id=k;
  n->next=process;
  process->pre=n;
  
    ptr=process;
    while(ptr->next!=process)
    ptr=ptr->next;
    ptr->next=n;
    n->pre=ptr;
  }
        ch++;
  
  }while(ch<=2);
return process;
}

//*****************************************************************************************************************************************************************************

void print(struct node *process)
{
struct node *ptr;
ptr=process->next;
printf("process %d || burst time=%d\n",process->id,process->bt);
while(ptr!=process)
{
printf("process %d || burst time=%d\n",ptr->id,ptr->bt);
ptr=ptr->next;
}
}

//*********************************************************************************************************************************************************************

struct node *generate_process(struct node *process,int remain)
{
			struct node *new_process;

			new_process=(struct node *)malloc(sizeof(struct node));
			
             new_process->bt=rand()%50;
             if(new_process->bt>=remain)
             return process;
             k++;
             new_process->id=k;
	if(process->next==process)
	{
		
		
	new_process->next=process;
	new_process->pre=process;
	process->next=new_process;
	process->pre=new_process;
		
	}
	else
	{

		struct node *ptr;
		ptr=process->next;
		while(ptr->next!=process)
		ptr=ptr->next;
		new_process->next=process;
	new_process->pre=ptr;
	ptr->next=new_process;
	process->pre=new_process;
		
		
	}
	return process;
}
//**************************************************************************************************************************************************************************
int process_scheduler(struct node *process)
{
  

  int time;
  printf("enter cpu time\n");
  scanf("%d",&time);
  printf("P_ID\tCPU_BURST\n");
  int count=0;
  int i,j;i=0;j=0;
  struct node *ptr,*temp;
  ptr=process;
  
  while(count<=time)
  {
    if(ptr->bt<=10)
    {	
      count+=ptr->bt;
printf("%d\t\t%d\n",ptr->id,count);
      i++;
      temp=ptr->next;
      ptr->next->pre=ptr->pre;
      ptr->pre->next=ptr->next;
    free(ptr);
    ptr=temp;
      
    }
    else
  {
  	if(count+10>time)
  	break;
    count+=10;
    printf("%d\t\t%d\n",ptr->id,count);
    ptr->bt-=10;
     ptr=ptr->next;
    process= generate_process(process,time-count);

  }

  }
  

}

//***********************************************************************************************************************************************************************
int main(void) 
{
int k,i,j;
  
struct node *process;
process=NULL;
process=insertion(process);
print(process);
process_scheduler(process);

  return 0;
}
