#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address_book.h"

/*Function for reading the data from the addressbook*/
void read_delete_data (AddressBook *array, Readinputs *read, int *count)
{
	int bytes, index;
	char buff[32], temp[2];

	//for loop to run upto feof returns 0
	for (index = 0; feof(read->fptr) == 0; index++)
	{
		//incrementing the count
		(*count)++;

		// Store name
		fread(buff, 1, 32, read->fptr);
		array[index].name = malloc(strlen(buff));
		strcpy(array[index].name, buff);

		// Store email
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].email = malloc(strlen(buff));
		strcpy(array[index].email, buff);

		// Store phone
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].phone = malloc(strlen(buff));
		strcpy(array[index].phone, buff);

		// Store city
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].city = malloc(strlen(buff));
		strcpy(array[index].city, buff);
		fread(temp, 1, 1, read->fptr);
	}
	
	fclose(read->fptr);
}

/*Function for deleting the contents*/
int skip_array_index(AddressBook *array, Readinputs *read, int count)
{
	int index;
	char delimeter[5] = "//";
	char newline = '\n';
	
	//opening the file in the w mode
	read->fptr = fopen(read->fname, "w");

	//Handling the errors
	if (read->fptr == NULL)
	{
		//printing the error message
		perror("fopen");
		fprintf(stderr, "ERROR: unable to open the file %s\n", read->fname);
		return 1;
	}

	//for loop to run upto count -1
	for (index = 0; index < (count - 1); index++)
	{
		//checking if the entered data and address book are same or not
		if (strcmp(read->newdata, array[index].name) == 0)
			//if it is true, skipping the next info to read
			continue;

		//store the name
		fwrite(array[index].name, 1, 32, read->fptr);
		
		//store the email
		fwrite(delimeter, 1, 2, read->fptr);
		fwrite(array[index].email, 1, 32, read->fptr);
		
		//store the phone
		fwrite(delimeter, 1, 2, read->fptr);
		fwrite(array[index].phone, 1, 32, read->fptr);
		
		//store the city
		fwrite(delimeter, 1, 2, read->fptr);
		fwrite(array[index].city, 1, 32, read->fptr);
		fwrite(&newline, 1, 1, read->fptr);
	}

	//closing the file
	fclose(read->fptr);
}

/*Function for deliting the data from the addressbook*/
int delete_data(AddressBook *addressbook, Readinputs *read, int option)
{
	AddressBook array[25];
	int count = 0;

	//reading the info from the user
	if (inputs(addressbook, read, option) < 0)
		return -1;

	//opening the file in the r mode
	read->fptr = fopen(read->fname, "r");

	//Handling the errors
	if (read->fptr == NULL)
	{
		//printing the error message
		perror("fopen");
		fprintf(stderr, "ERROR: unable to open the file %s\n", read->fname);
		return 1;
	}

	//invoking the function call to read the addressbook
	read_delete_data(array, read, &count);

	//invoking the function call to delete the contact
	skip_array_index(array, read, count);
}
