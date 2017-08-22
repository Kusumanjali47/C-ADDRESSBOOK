#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address_book.h"

/*Function prototype for to display the contents*/
void print_display(AddressBook *addressbook, int count);


/*Function for reading the addressbook*/
int display_add_book(Readinputs *readinputs)
{
	int bytes, index;
	char buff[32], temp[2];
	AddressBook addressbook[25];
	int count = 0;

	//opening the file in the r mode
	readinputs->fptr = fopen(readinputs->fname, "r");

	//Handling the errors
	if (readinputs->fptr == NULL)
	{
		//printing the error message
		perror("fopen");
		fprintf(stderr, "ERROR: unable to open the file %s\n", readinputs->fname);
		return 1;
	}

	//running the loop upto feof retuns 0, means there is a contents to read from the file
	for (index = 0; feof(readinputs->fptr) == 0; index++)
	{
		//incrementing the count
		count++;

		// Store name
		fread(buff, 1, 32, readinputs->fptr);
		addressbook[index].name = malloc(strlen(buff));
		strcpy(addressbook[index].name, buff);

		// Store email
		fread(temp, 1, 2, readinputs->fptr);
		fread(buff, 1, 32, readinputs->fptr);
		addressbook[index].email = malloc(strlen(buff));
		strcpy(addressbook[index].email, buff);

		// Store phone
		fread(temp, 1, 2, readinputs->fptr);
		fread(buff, 1, 32, readinputs->fptr);
		addressbook[index].phone = malloc(strlen(buff));
		strcpy(addressbook[index].phone, buff);

		// Store city
		fread(temp, 1, 2, readinputs->fptr);
		fread(buff, 1, 32, readinputs->fptr);
		addressbook[index].city = malloc(strlen(buff));
		strcpy(addressbook[index].city, buff);
		fread(temp, 1, 1, readinputs->fptr);
	}

	//dispalying the contents of the file
	print_display(addressbook, count);

	//closing the file
	fclose(readinputs->fptr);
}


/*Function for to print the contents in the addressbook*/
void print_display(AddressBook *addressbook, int count)
{
	int i_index;

	printf("\n******************************************\n");

	//running the loop up to count - 1
	for (i_index = 0; i_index < (count - 1); i_index++)
	{
		printf("Name		: %s\n", addressbook[i_index].name);
		printf("EmailId		: %s\n", addressbook[i_index].email);
		printf("PhoneNumber	: %s\n", addressbook[i_index].phone);
		printf("City		: %s\n", addressbook[i_index].city);
	
		printf("\n******************************************\n");
	}
}

