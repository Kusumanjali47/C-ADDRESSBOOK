#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address_book.h"

/* Function for adding spaces */
void add_space(char *string)
{
	int i_index;

	//adding the spaces after the string upto 32 chars
	for (i_index = strlen(string); i_index < 32; i_index++)
		string[i_index] = ' ';

	//stoing null
	string[i_index] = '\0';
}

/* Function for reading information */
int information(Readinputs *readinputs)
{
	int size, index;

	char buff[50];

	switch (readinputs->option)
	{
		case 1:

			/*reading the name*/
			printf("Enter the name: ");
			scanf("%s", buff);

			//adding spaces
			add_space(buff);

			size = strlen(buff + 1);

			//allocating memory dynamically
			readinputs->newdata = malloc(sizeof(char *) * size);

			//copying the content of buff to newdata
			strcpy(readinputs->newdata, buff);

			break;

		case 2:

			//reading the emailID
			printf("Enter the email id: ");
			scanf("%s", buff);

			//adding spaces
			add_space(buff);

			size = strlen(buff + 1);

			//allocating memory dynamically
			readinputs->newdata = malloc(sizeof(char *) * size);

			//copying the content of buff to newdata
			strcpy(readinputs->newdata, buff);

			break;

		case 3:

			//reading the mobile number
			printf("Enter the mobile number: ");
			scanf("%s", buff);

			//checking if the length of the mobile number is 10 or not
			if ((strlen(buff)) != 10)
			{
				//printing error message
				printf("Invalid mobile number\n");
				return 1;
			}
			else
			{
				index = 0;
				//The number should be between 0 and 9
				while (buff[index] >= '0' && buff[index] <= '9')
					index++;
			}
			//adding spaces
			add_space(buff);

			size = strlen(buff + 1);

			//allocating memory dynamically
			readinputs->newdata = malloc(sizeof(char *) * size);

			//copying the content of buff to newdata
			strcpy(readinputs->newdata, buff);
			break;

		case 4:

			//read the city name
			printf("Enter the city: ");
			scanf("%s", buff);

			//adding spaces
			add_space(buff);
			size = strlen(buff + 1);

			//allocating memory dynamically
			readinputs->newdata = malloc(sizeof(char *) * size);

			//copying the content of buff to newdata
			strcpy(readinputs->newdata, buff);
			break;
	}
}

/* Function for reading information for insert, search, edit, delete*/
int inputs(AddressBook *addressbook, Readinputs *readinputs, int option)
{
	int size, index;

	char buff[50];

	switch (option)
	{
		//case for inserting the data into the addressbook
		case 1:
			
			//reading the name
			printf("Enter the name: ");
			scanf("%s", buff);

			//adding the spaces
			add_space(buff);

			size = strlen(buff);

			//allocating the memory dynamically
			addressbook->name = malloc(sizeof(char *) * size);

			//copying the buff contents to the name
			strcpy(addressbook->name, buff);


			//reading the email id
			printf("Enter the email id: ");
			scanf("%s", buff);

			//adding the spaces
			add_space(buff);

			size = strlen(buff);

			//allocating the memory dynamically
			addressbook->email = malloc(sizeof(char *) * size);

			//copying the contents of buff to the email
			strcpy(addressbook->email, buff);



			//reading the mobile number
			printf("Enter the mobile number: ");
			scanf("%s", buff);

			//checking the length of the mobile number, if it is not 10, printing the error message
			if ((strlen(buff)) != 10)
			{
				printf("Invalid mobile number\n");
				return 1;
			}
			else
			{
				index = 0;

				//the number should in between 0 and 9
				while (buff[index] >= '0' && buff[index] <= '9')
					index++;
			}

			//adding the spaces
			add_space(buff);

			size = strlen(buff);

			//allocating the memory dynamically
			addressbook->phone = malloc(sizeof(char *) * size);

			//copying the contents of buff to the phone
			strcpy(addressbook->phone, buff);



			//reading the city name
			printf("Enter the city: ");
			scanf("%s", buff);

			//adding the spaces
			add_space(buff);

			size = strlen(buff);

			//allocating the memory dynamically
			addressbook->city = malloc(sizeof(char *) * size);

			//copying the contents of buff to the city
			strcpy(addressbook->city, buff);

			break;

		//switch case for searching the data
		case 2:

			//reading the option
			printf("Edit by:\n1. Name\n");
			printf("Enter the option : \n");
			scanf("%d", &readinputs->option);

			//reading the information by user
			information(readinputs);
			

			//reading the new data
			printf("Enter the new data: ");
			scanf("%s", buff);

			//adding the spaces
			add_space(buff);

			size = strlen(buff + 1);

			//allocating the memory dynamically
			readinputs->ename = malloc(sizeof(char *) * size);

			//copying the contents of buff to the ename
			strcpy(readinputs->ename, buff);

			break;

		case 3:

			//reading the option
			printf("Search by:\n1. Name\n2. Email\n3. Phone\n4. City\n");
			printf("Enter the option : \n");
			scanf("%d", &readinputs->option);

			//reading the information by user
			information(readinputs);

			break;

		case 4:

			//reading the option
			printf("Delete by:\n1. Name\n");
			printf("Enter the option : \n");
			scanf("%d", &readinputs->option);

			//reading the information by user
			information(readinputs);

			break;	
	}
}
