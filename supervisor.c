#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp; 
char filepath[15];

void print_prc()
{	char soz[15];
	int i=1; 
	fp = fopen(filepath ,"rb");

	if (fp==NULL) 
	{
		printf("Unable to open %s file. \n",filepath);
		printf("Please check whether file exists and you have enough privilige.\n");
		exit(EXIT_FAILURE);
	}	
	printf("\nListing whitelisted PrC's : \n");
	while (fscanf(fp,"%s", &soz) != EOF) {printf("%d.%s\n",i++,soz);}
	printf("\nEnd of file.\n\n");
	fclose(fp);
}

void insert_prc()
{	char value[10];
	printf("Enter the whitelisted PrC : ");
	scanf("%s",value);
	fp = fopen(filepath, "a");
	if (fp== NULL) 
	{	
		printf("Unable to open %s file. \n",filepath);
		printf("Please check whether file exists and you have write privilege. \n");
		exit(EXIT_FAILURE);
	}
	
	strcat(value,"\n");
	//printf("New value of value=%s ...",value);
	fputs(value,fp);
	fclose(fp);

}

void delete_prc()
{	char prc[100][15];
	int n,i,k = 0;
	char soz[15];
	system("clear");
	
	fp = fopen(filepath,"rb");
	while (fscanf(fp,"%s",&soz) != EOF) 
		{
		 strcat(soz,"\n");
		 strcpy(prc[k++],soz);
		}
	for (i=0;i<k;i++) printf("%d.%s\n",i+1,prc[i]);

	printf("Enter id of PrC to be deleted: ");
	scanf("%d",&n);
	printf("Deleting %d PrC.\n",n);

	fp = fopen(filepath,"w");
	for (i=0;i<k;i++) if ((i+1)!=n) fprintf(fp,prc[i]);
	fclose(fp);

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

	strcpy(filepath,"prclist.txt"); 
	
	strcpy(username,"user");
	strcpy(passwd,"1234");
	
	char logus[15];
	char logpass[15];
	
	printf("Enter your username : "); 
	scanf("%s",logus);

	printf("Enter password : ");
	scanf("%s",logpass);
	printf("Thanks for entering authentication information. \n");
	if ((strcmp(username,logus)==0)  && (strcmp(logpass,passwd)==0)) Home(); else 
		{
			printf("Sorry, Authentication information is not correct. \n");
			exit(0); 

		}
}

