#include<stdio.h>
#define FRAMES 5
#define SIZE 10000
struct ptable
{
	int pid; //pid of process
	int psize; //no. of frames
	int pg[SIZE]; //page logical address
	int fr[SIZE]; //frames in the memory
	int fault; //faults in that process
	int flag; //if element is found or not
	int pgindex; 
	int n; //no. of logical adresses for process[i]
	int c;
}process[10];


void fifo();
void optimal();
void lru();
void main()
{
	int ch;
	/*printf("\nEnter total number of pages:");
	scanf("%d",&n);
	printf("\nEnter sequence:");
	for(i=0;i<n;i++)			//accepting sequence
		scanf("%d",&pg[i]);*/
//initialize struct members
		
FILE *fp;
int value,j,k,val1;

 for( j=0;j<10;j++)
{
	for(k=0;k<SIZE;k++)
	{
		process[j].pg[k] = -1;
		 
	}
	
	process[j].pid = j; //store pid's for respective processes
	process[j].psize = FRAMES;
	process[j].pgindex = 0; //pointer to each page of process i
	process[j].n = 0;
	
}

  int i = -1; /* EDIT have i start at -1 :) */

  if ((fp = fopen ("Integers.txt", "r")) == NULL)
    return 1;


  while (!feof (fp) && fscanf (fp, "%d", &val1) && i++ < SIZE )
 {
 	    	
    	 //val1 has the pid
    
    if(fscanf(fp,"%d",&value) > 0 && !feof(fp) )
    {
    	process[val1].pg[process[val1].pgindex] = value;
    	(process[val1].pgindex)++;
    	
 	}
}


  fclose (fp);

printf("Input is \n\n");
/*	for(i=0;pg[i] != -1 && pid[i] != -1;i++)
{
	printf("%d  ",pid[i]);
	printf("%d\n",pg[i]);
}*/
for( j=0;j<10;j++)
{
	printf("Entries for process = %d\n",process[j].pid) ; //store pid's for respective processes
	/*for(k=0;k<process[j].pgindex;k++)
	{
		printf("%d\n",process[j].pg[k] );
		 
	}*/
	printf("\nNumber of pages = %d\n-------------------------------\n\n",process[j].pgindex);
	
}



	do
	{
		printf("\n\tMENU\n");
		printf("\n1)FIFO");
		printf("\n2)OPTIMAL");
		printf("\n3)LRU");
		printf("\n4)Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				fifo();
				break;

			case 2: optimal();
				break;

			case 3: lru();
				break;

		}
	}while(ch!=4);
	getchar();
}

void fifo()
{
	int i,k,f,r,s,count,flag,num,psize;
	/*f=0;
	r=0;
	s=0;
	flag=0;
	count=0;*/
	
	
	/*printf("\nEnter number of  frame:");
	scanf("%d",&psize);*/
	
	for(k=0;k<10;k++)
	{
	
		for(i=0;i<process[k].psize;i++)	
		{
			process[k].fr[i]=-1;
		}
	}
	
	
	
	for(k=0;k<10;k++)
	{
	f=0;
	r=0;
	s=0;
	flag=0;
	count=0;
		while(s<process[k].pgindex)	
		{
			flag=0;
			num=process[k].pg[s];
			for(i=0;i<process[k].psize;i++)
			{
				if(num==process[k].fr[i])
			{
				s++;
				flag=1;
				break;
			}
			}
			if(flag==0)
			{
				if(r<process[k].psize)
				{	
				process[k].fr[r]=process[k].pg[s];
				r++;
				s++;
				process[k].fault++;
			}
			else
			{
				if(f<process[k].psize)
				{
					process[k].fr[f]=process[k].pg[s];
					s++;
					f++;
					process[k].fault++;
				}
				else 
					f=0;
			}
		}
	/*	printf("\n");			
		for(i=0;i<process[k].psize;i++)
		{
			printf("%d\t",process[k].fr[i]);
		}*/
	}
	
	printf("\nFor process = %d : Page Faults=%d\n----------------------\n\n",process[k].pid,process[k].fault);
	
	//end of FIFO for Process =  i
	}

getchar();


}
void optimal()
{
	int count[1000],i,j,k,fault,f,flag,temp,current,c,dist,max,m,cnt,p,x;
	fault=0;
	dist=0;
	k=0;
	/*printf("\nEnter number of frames :");
	scanf("%d",&f);
	//initilizing distance and frame array	
	for(i=0;i<f;i++)
	{
		count[i]=0;
		fr[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		temp=pg[i];
		for(j=0;j<f;j++)			
		{
			if(temp==fr[j])
			{
				flag=1;
				break;
			}
		}
		if((flag==0)&&(k<f))
		{
			fault++;
			fr[k]=temp;
			k++;
		}
		else if((flag==0)&&(k==f))
		{
			fault++;			
			for(cnt=0;cnt<f;cnt++)			
			{		
				current=fr[cnt];
				for(c=i;c<n;c++)
				{
					if(current!=pg[c])
						count[cnt]++;
					else
						break;
				}
			}
			max=0;
			for(m=0;m<f;m++)
			{
				if(count[m]>max)
				{
					max=count[m];
					p=m;
				}
			}
			fr[p]=temp;
		}
		printf("\n");			
		for(x=0;x<f;x++)
		{
			printf("%d\t",fr[x]);
		}
	}*/
	printf("\nTotal number of faults=%d",fault);
	getchar();
}

void lru()
{
	int count[10000],i,j,k,fault,f,flag,temp,current,c,dist,max,m,cnt,p,x;
	int y;
	for(y=0;y<10;y++)
{
	
	process[y].fault=0;
	dist=0;
	k=0;
	/*printf("\nEnter number of frames :");
	scanf("%d",&f);*/
	//initilizing distance and frame array	
	for(i=0;i<process[y].psize;i++)  //f = psize
	{
		count[i]=0;
		process[y].fr[i]=-1;
	}
	
	for(i=0;i<process[y].pgindex;i++)
	{
		flag=0;
		temp=process[y].pg[i];
		for(j=0;j<process[y].psize;j++)			
		{
			if(temp==process[y].fr[j])
			{
				flag=1;
				break;
			}
		}
		if((flag==0)&&(k<process[y].psize))
		{
			process[y].fault++;
			process[y].fr[k]=temp;
			k++;
		}
		else if((flag==0)&&(k==process[y].psize))
		{
			process[y].fault++;			
			for(cnt=0;cnt<process[y].psize;cnt++)			
			{		
				current=process[y].fr[cnt];
				for(process[y].c=i;process[y].c>0;(process[y].c)--)
				{
					if(current!=process[y].pg[process[y].c])
						count[cnt]++;
					else
						break;
				}
			}
			max=0;
			for(m=0;m<process[y].psize;m++)
			{
				if(count[m]>max)
				{
					max=count[m];
					p=m;
				}
			}
			process[y].fr[p]=temp;
		}
		/*printf("\n");			
		for(x=0;x<process[y].;x++)
		{
			printf("%d\t",process[y].fr[x]);
		}*/
	}
	printf("\nProcess = %d, Total number of faults=%d",process[y].pid,process[y].fault);
	
}
	getchar();
	
}
