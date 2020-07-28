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
int safetyAlgorithm(int customerCount);


int available[4]; //available array
int finish[5] = {1,1,1,1,1};
Customer* customermax = NULL;    // max number of resources needed
Customer* customeralloc = NULL;  // currently allocated resources
Customer* customerneed = NULL;   // remaining resources (maxneeded-currently allocated)
int i;

/*main is where we will pass the commandline arguments for the filename 
and we call readFile().
main will listen to the user and push the command "RL, RQ or *"
to runCommand function*/
int main(int argc, char *argv[])
{
	char *fileName ="sample4_in.txt";
	

	if(argc!=5) //check if we have enough
	{
		printf("INVALID: Enter 4 values only\n");
		printf("Goodbye!\n");
		return -1;
	}
	else
	{
		//int i=1;
		for (i=1; i<argc; i++) //put argv into available array
		{
			available[i]=atoi(argv[i]);
			//printf("%d\n ", available[i]);
		}
	}

	int customerCount = readFile(fileName,&customermax);

	customeralloc = (Customer*) malloc(sizeof(Customer)*customerCount);
	customerneed = (Customer*) malloc(sizeof(Customer)*customerCount);
	for(i =0; i <customerCount;i++)
	{
		// initial allocation is 0
		customeralloc[i].cusID = customermax[i].cusID;
		customeralloc[i].item1 = 0;
		customeralloc[i].item2 = 0;
		customeralloc[i].item3 = 0;
		customeralloc[i].item4 = 0;

		//initial allocation is 0 so, need = max (for now)
		customerneed[i].cusID = customermax[i].cusID;
		customerneed[i].item1 = customermax[i].item1;
		customerneed[i].item2 = customermax[i].item2;
		customerneed[i].item3 = customermax[i].item3;
		customerneed[i].item4 = customermax[i].item4;
	}

	printf("Number of Customers: %d\n",customerCount);

	printf("Currently available resources: %d %d %d %d\n", available[1],available[2],available[3],available[4]);

	printf("Maximum Resources from file:\n");

	//int i=0;
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d, %d, %d, %d\n", customermax[i].item1,customermax[i].item2,customermax[i].item3,customermax[i].item4);
	}

	printf("current alloc\n");
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d, %d, %d, %d\n", customeralloc[i].item1,customeralloc[i].item2,customeralloc[i].item3,customeralloc[i].item4);
	}

	printf("still needed\n");
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d, %d, %d, %d\n", customerneed[i].item1,customerneed[i].item2,customerneed[i].item3,customerneed[i].item4);
	}

	int k = safetyAlgorithm(customerCount);
	
	if (k!=0){
		printf("error with saftey algorithm\n");
	}

	
	char line[100];
	char cmd[2];
	// char *arguments[100];
	int threadID=-1;
	int item1=-1;
	int item2=-1;
	int item3=-1;
	int item4=-1;

	
	do {
        
		printf("Enter Command [999 to Exit]:");
		fgets(line,100,stdin);
		// scanf("%s %d %d %d %d %d",cmd,&threadID,&item1,&item2,&item3,&item4);
		// printf("%s\n",line);

		char *ptr = strtok(line, " ");

		strcpy(cmd,ptr);

		int j =0;
		while(ptr!=NULL)
		{
			switch(j){
				case 1:
					threadID = atoi(ptr);
					break;
				case 2:
					item1 = atoi(ptr);
					break;
				case 3:
					item2 = atoi(ptr);
					break;
				case 4:
					item3 = atoi(ptr);
					break;
				default:
					item4 = atoi(ptr);
			}
			
			j++;
			ptr = strtok(NULL," ");
		}
		
		if (strcasecmp(cmd,"RQ")==0)
		{
			printf("process request function\n");
			/*
			do something
			*/
			printf("You have typed: %s %d %d %d %d %d \n\n", cmd, threadID, item1,item2,item3,item4);
			

		}
		else if(strcasecmp(cmd,"RL")==0)
		{
			printf("process release function\n");
			/*
			do something
			*/

			printf("You have typed: %s %d %d %d %d %d \n\n", cmd, threadID, item1,item2,item3,item4);
		}
		else if(strcmp(cmd,"*")==0)
		{
			printf("process/display current state\n");
			/*
			do something
			*/
			printf("You have typed: %s\n\n", cmd);
		}
		else if(strcasecmp(cmd,"RUN")==0)
		{
			printf("run function\n");
			/*
			do something
			*/

			printf("You have typed: %s\n\n", cmd);
		}		
		else if(strcmp(cmd,"999")==0)
		{
			printf("Goodbye!\n");
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
int readFile(char* fileName, Customer** customermax)
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
	*customermax = (Customer*) malloc(sizeof(Customer)*customerCount);

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
				(*customermax)[k].cusID = cID;
				cID++;
				case 0:
					(*customermax)[k].item1 = atoi(token);
					break;
				case 1:
					(*customermax)[k].item2 = atoi(token);
					break;
				case 2:
					(*customermax)[k].item3 = atoi(token);
					break;
				default:
					(*customermax)[k].item4 = atoi(token);
					
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
int safetyAlgorithm(int customerCount)

{
	// make a copy of available allocation and needed
	int available_copy[4];
	Customer* alloc_copy = NULL;
	Customer* needed_copy = NULL;
	alloc_copy = (Customer*) malloc(sizeof(Customer)*customerCount);
	needed_copy = (Customer*) malloc(sizeof(Customer)*customerCount);
	for(i=0;i<4;i++)
		available_copy[i] = available[i];

	for(i =0; i <customerCount;i++)
	{
		
		alloc_copy[i].cusID = customermax[i].cusID;
		alloc_copy[i].item1 = customeralloc[i].item1;
		alloc_copy[i].item2 = customeralloc[i].item2;
		alloc_copy[i].item3 = customeralloc[i].item3;
		alloc_copy[i].item4 = customeralloc[i].item4;
		
		needed_copy[i].cusID = customermax[i].cusID;
		needed_copy[i].item1 = customerneed[i].item1;
		needed_copy[i].item2 = customerneed[i].item2;
		needed_copy[i].item3 = customerneed[i].item3;
		needed_copy[i].item4 = customerneed[i].item4;
	}
	printf("current alloc copy \n");
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d, %d, %d, %d\n", alloc_copy[i].item1,alloc_copy[i].item2,alloc_copy[i].item3,alloc_copy[i].item4);
	}
	printf("current need copy \n");
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d, %d, %d, %d\n", needed_copy[i].item1,needed_copy[i].item2,needed_copy[i].item3,needed_copy[i].item4);
	}

	printf("available copy \n");
	for (i=0; i<customerCount; i++) //print customer items
	{
		printf("%d\n", available_copy[i]);
	}

	return 0;
}