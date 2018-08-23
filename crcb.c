#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bits
{
	char sbit[100],rbit[100];
	char key[100];
}b;

char rem[100];

void crc(char tempd[],char tempk[],int len)
{	
	int rlen=0,temp,flag,trav;
	char *e;
	e=tempd;
	while(*e!='\0')
	{
		flag=1;
		int i=rlen;
		while(*e!='\0' && i<len)
		{
			rem[i]=*e;
			e++;
			i++;
		}
		rem[i]='\0';
		if(strlen(rem)<len)
			break;
		for(int i=0;i<len;i++)
		{
			if(strncmp(rem+i,tempk+i,1)==0)
				rem[i]='0';
			else
				rem[i]='1';
		}
		temp=atoi(rem);
		if(temp==0)
			flag=0;
		sprintf(rem,"%d",temp);
		rlen=strlen(rem); 
		if(flag==0)
			rlen=0;		
	}

}

int main()
{

	int len,trav;
	char *e;
	

	printf("Enter the Key: ");
	scanf("%s",b.key);
	printf("Enter the Data: ");
	scanf("%s",b.sbit);

	len=strlen(b.key);
	char a[100]="0";
	while((len-1)!=0)
	{
		strcat(b.sbit,a);
		len--;
	}
	//printf("%s\n",b.sbit);
	len=strlen(b.key);

	crc(b.sbit,b.key,len);
	
	printf("Remainder is : %s\n\n",rem);
	
	e=rem;
	trav=strlen(b.sbit)-strlen(rem);
	while(*e!='\0')
	{	
		b.sbit[trav]=*e;
		trav++;
		e++;
	}
	printf("Data bits Modified for CRC : %s\n",b.sbit);

	printf("Enter the Received Data bits : ");
	scanf("%s",b.rbit);

	crc(b.rbit,b.key,len);

	if(atoi(rem)!=0)
		printf("\nData has been corrupted\n");
	else
		printf("\nData safely sent\n");
}