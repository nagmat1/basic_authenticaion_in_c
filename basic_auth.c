#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_program()
{
        printf("Welcome to Whitelisting Application.\n");
}

int main()
{
        char username[15];
        char passwd[15];

        strcpy(username,"user");
        strcpy(passwd,"1234");

        char logus[15];
        char logpass[15];

        printf("Enter your username : ");
        scanf("%s",logus);

        printf("Enter password : ");
        scanf("%s",logpass);
        printf("Thanks for entering authentication information. \n");
        if ((strcmp(username,logus)==0)  && (strcmp(logpass,passwd)==0)) main_program(); else
                {
                        printf("Sorry, Authentication information is not correct. \n");
                        exit(0);

                }
}
