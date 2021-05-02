#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>

int fp; 
char filepath[15];
char prc[100][15];
int sany; 

void print_prc()
{	char soz[15];
	int i=1; 
	fp = open(filepath,O_RDONLY);

	if (fp<0 ) 
	{
		printf("Unable to open %s block. \n",filepath);
		printf("Please check whether block exists and you have enough privilige.\n");
		exit(EXIT_FAILURE);
	}	
	printf("\nListing whitelisted PrC's : \n");
	off_t off = lseek(fp,0,SEEK_SET);
	ssize_t len = read(fp,prc,sizeof prc);
	sscanf(prc[0],"%d",&sany);
	printf("Number of Prc's = %d ",sany);
	for (i=0;i<=sany;i++) printf("%s, ",prc[i]);
	printf("\nEnd of block.\n\n");

	close(fp);
}

void insert_prc()
{	char value[10];
	printf("Enter the whitelisted PrC : ");
	scanf("%s",value);
	sany++;
	strcpy(prc[sany],value);

	fp = open(filepath,O_RDWR);
	if (fp < 0 ) 
	{	
		printf("Unable to open %s block. \n",filepath);
		printf("Please check whether block exists and you have write privilege. \n");
		exit(EXIT_FAILURE);
	}
	
	//strcat(value,"\n");
	//printf("New value of value=%s ...",value);
	if (lseek(fp,0,SEEK_SET)<0) {perror("write: ");}
	if (write(fp,&prc,sizeof(prc))<0) {perror("write2: ");}
	close(fp);

}

void delete_prc()
{
	int n,i,k = 0;
	char soz[15];
	system("clear");
	
	fp = open(filepath,O_RDWR);
	
	off_t off = lseek(fp,0,SEEK_SET);
        ssize_t len = read(fp,prc,sizeof prc);
	for (i=1;i<=sany;i++) printf("%d.%s \n",i,prc[i]);


	printf("Enter id of PrC to be deleted: ");
	scanf("%d",&n);
	printf("Deleting %d PrC.\n",n);

	fp = open(filepath,O_RDWR);
	if (lseek(fp,0,SEEK_SET)<0) {perror("write1:");}
	strcpy(prc[n],prc[sany]);
	strcpy(prc[sany]," ");
	sany--;
	if (write(fp,prc,sizeof prc)<0) {perror("write3");}
	close(fp);

}

void Home()
{
	int Option = 0;
	

	printf("Welcome to Whitelisting Application.\n");
while (Option!=4) { 
	printf("1. Print the Whitelisted PrC's : \n");
	printf("2. Insert new PrC. \n");
	printf("3. Delete PrC. \n");
	printf("4. Exit. \n");

	printf("Enter your choice: "); 
	scanf("%d",&Option);

	if (Option == 1) print_prc(); else 
	if (Option == 2) insert_prc(); else 
	if (Option == 3) delete_prc(); else 
	if (Option == 4) exit(0); else 
		{
			system("clear");
			printf("\n Input Error. \n");
		}
	}
	
}

int main()
{
	char username[15];
	char passwd[15];

	strcpy(filepath,"/dev/fbSSD"); 
	
	strcpy(username,"user");
	strcpy(passwd,"1234");
	
	char logus[15];
	char logpass[15];
	
	printf("Enter your username : "); 
	scanf("%s",logus);

	printf("Enter password : ");
	scanf("%s",logpass);
	printf("Thanks for entering authentication information. \n");
	sany = 0;
	if ((strcmp(username,logus)==0)  && (strcmp(logpass,passwd)==0)) Home(); else 
		{
			printf("Sorry, Authentication information is not correct. \n");
			exit(0); 

		}
}

