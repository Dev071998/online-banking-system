#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct details
{
	char name[100];
	char phone[20];
	char ac_num[50];
	char password[50];
	float balance;
};
void main()
{
	int op,choice;
	float amount;
	struct details user;
	FILE *fp;
	char count ='y';
	char filename[100],pword[50];
	printf("\t\t\t\twelcome\n\n");
	printf("\n\t\t1)Register account\t\t2)Login account\n");
	scanf("%d",&op);
	if(op==1)
	{
		system("clear");
		printf("Enter your name:\t\t");
		scanf("%s",user.name);
		printf("Enter your mobile number:\t");
		scanf("%s",user.phone);
		printf("Enter your account number:\t");
		scanf("%s",user.ac_num);
		printf("Enter the password:\t\t");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(struct details),1,fp);
		if(fwrite != 0)
			printf("\n\nAccount sucessfully register\n");
		else
			printf("\n\nSomthing wrong try again\n");
		fclose(fp);
	}
	else
	{
		printf("\t\t\t\tLogin account\n\n");
		printf("Enter the ID:\t");
		scanf("%s",user.phone);
		printf("\nEnter the password:\t\t");
		scanf("%s",pword);
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"r");
		if(fp==NULL)
			printf("Account not registered\n");
		else
		{
			fread(&user,sizeof(struct details),1,fp);
			fclose(fp);
			if(!strcmp(pword,user.password))
			{
				while(count == 'y')
				{
					system("clear");
					printf("1)Check the balance\n2)deposit\n3)withdraw\n4)Transfer balance\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1:
						printf("\n\nyour account balance is %.2f\n",user.balance);
						break;
						case 2:
						printf("\nEnter Deposit amount\n");
						scanf("%f",&amount);
						user.balance += amount;
						fp=fopen(filename,"w");
						fwrite(&user,sizeof(struct details),1,fp);
						if(fwrite != NULL)
							printf("sucessfully deposited\n");
						fclose(fp);
						break;
						case 3:
						printf("\nEnter withdraw amount\n");
						scanf("%f",&amount);
						if(amount<user.balance)
						{
							user.balance -= amount;
							fp=fopen(filename,"w");
							fwrite(&user,sizeof(struct details),1,fp);
							if(fwrite != NULL)
							printf("sucessfully withdraw\n");
							fclose(fp);
							break;
						}
						else
							printf("\nInsufficient balance\n");
					}
					printf("Do you want to continue the transaction[y/n]\n");
					scanf("%s",&count);
				}
			}
			else
			printf("\nInvalid password\n");
		}
	}


}
