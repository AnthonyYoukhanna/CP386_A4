/*
CP386 Assignment 4

URL:http://www.github.com/SakirJiva/CP386_A4

Basil Zuberi
Github Login: basilzuberi
Student ID: 170145220


Sakir Soyab Jiva
Github Login: SakirJiva 
Student ID: 180580140
*/
#include<stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>



typedef struct customer
{
	int cusID;
	int item1;
	int item2;
	int item3;
	int item4;
} Customer;
int readFile(char* fileName, Customer** customer);



/*main is where we will pass the commandline arguments for the filename 
and we call readFile().
main will listen to the user and push the command "RL, RQ or *"
to runCommand function*/
int main(int argc, char *argv[])
{
	char *fileName ="sample4_in.txt";
	Customer* customer = NULL;

	int customerCount = readFile(fileName,&customer);

	printf("Number of Customers: %d\n",customerCount);

	printf("Maximum Resources from file:\n");

	int i=0;
	for (i=0; i<customerCount; i++)
	{
		printf("%d, %d, %d, %d\n", customer[i].item1,customer[i].item2,customer[i].item3,customer[i].item4);
	}

	
	char cmd[100];
	do {
        
		printf("Enter Command [999 to Exit]:\n");
		scanf("%[^\n]%*c",cmd);
		
		if (strcasecmp(cmd,"RQ")==0)
		{
			printf("process request function\n");
			/*
			do something
			*/

		}
		else if(strcasecmp(cmd,"RL")==0)
		{
			printf("process release function\n");
			/*
			do something
			*/
		}
		else if(strcmp(cmd,"*")==0)
		{
			printf("process/display current state\n");
			/*
			do something
			*/
		}
		else if(strcmp(cmd,"999")==0)
		{
			printf("Good bye!\n");
			break;
		}
		else
		{
			printf("invalid command try again\n");
		}
		

    } while (1);

}

/*readFile function will take in a filename and read and return
its contents for the bankers algorithm
*/
int readFile(char* fileName, Customer** customer)
{
	
    FILE *file = fopen(fileName, "r");

	struct stat st;
	fstat(fileno(file), &st);
	char* fileContent = (char*)malloc(((int)st.st_size+1)* sizeof(char));
	fileContent[0]='\0';

	if (file != NULL)
	{
		char str[1000]; //string buffer
		while (fgets(str, sizeof(str), file) != NULL) //read lines
		{

            strncat(fileContent,str,strlen(str));
			
		}
		fclose(file);

		

	}
	else
	{
		perror(fileName); //error
        return -1;
	}
	char* command = NULL;
	int customerCount;

	char* fileCopy = (char*)malloc((strlen(fileContent)+1)*sizeof(char));
	strcpy(fileCopy,fileContent);
	command = strtok(fileCopy,"\r\n");
	while(command!=NULL)
	{
		customerCount++;
		command = strtok(NULL,"\r\n");
	}
	*customer = (Customer*) malloc(sizeof(Customer)*customerCount);

	char* lines[customerCount];
	command = NULL;
	int i=0;
	command = strtok(fileContent,"\r\n");
	while(command!=NULL)
	{
		lines[i] = malloc(sizeof(command)*sizeof(char));
		strcpy(lines[i],command);
		i++;
		command = strtok(NULL,"\r\n");
	}

	for(int k=0; k<customerCount; k++)
	{
		char* token = NULL;
		int j = 0;
		int cID=0;
		token =  strtok(lines[k],",");
		while(token!=NULL)
		{
			switch(j){
				(*customer)[k].cusID = cID;
				cID++;
				case 0:
					(*customer)[k].item1 = atoi(token);
					break;
				case 1:
					(*customer)[k].item2 = atoi(token);
					break;
				case 2:
					(*customer)[k].item3 = atoi(token);
					break;
				default:
					(*customer)[k].item4 = atoi(token);
					
			}
			
			j++;
			token = strtok(NULL,",");
		}
	}
	return customerCount;
	

}

/* runProgram will use bankers algorithm to implement the program.
we will use this function to call requestResource, releaseResource and outputValues
depending on what command the user types: "RL, RQ or *"
*/
void runProgram()
{
	return;

}

/* Will fill an allocation array, then we will use saftey algorithm and
output whether the request was satisfied or denied by using 0 for sucess and -1 
for denied.  Command will look like this:

RQ cus# th# th# th# th#
example: RQ 0 3 1 2 1 (from assignment)
*/
void requestResource()
{
	return;
}

/* we will release the resource when the command RL is used:
RQ cus# th# th# th# th#
example: RL 4 1 2 3 1 (from assignment)
*/
void releaseResource()
{
	return;
}

/*
when user uses "*" as a command we will output the current state of the struct
show user Available, Maximum, Allocation and Need arrays
*/
void outputValues()
{
	return;
}

/* Implmentation of the safety algorithm
*/
int safetyAlgorithm()
{
	return 0;
}