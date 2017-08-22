#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address_book.h"

/*Function for reading the contents form the file*/
int read_file_contents(AddressBook *addressbook, Readinputs *readinputs)
{
	int bytes, index;
	char buff[32], temp[2];
	int count = 0;

	//running the loop upto feof returns 0
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

	//seeking to the first byte
	fseek(readinputs->fptr, 0L, SEEK_SET);
}

/*Function for finding the array position by name*/
void find_array_pos(AddressBook *addressbook, Readinputs *readinputs)
{
	int i_index;

	/*runnng the loop upto 25*/
	for (i_index = 0; i_index < 25; i_index++)
	{
		//comparing the newdata and name in the address book
		if ((strcmp(readinputs->newdata, addressbook[i_index].name)) == 0)
		{
			break;
		}
	}		

	//storing the position
	readinputs->array_pos = i_index;

	printf("%d\n", readinputs->array_pos);
}


/*Function for writing the contents to the address book*/
void write_to_address_book(AddressBook *addressbook, Readinputs *readinputs)
{
	long fptr_pos;
	char delimeter = '/';
	char newline = '\n';

	//invoking the function call to find the array position
	find_array_pos(addressbook, readinputs);

	switch (readinputs->option)
	{
		case 1:
			
			//computing the array position
			fptr_pos = (readinputs->array_pos * 134) + readinputs->array_pos;

			//seeking to the fptr pos
			fseek(readinputs->fptr, fptr_pos, SEEK_SET);

			//writing the contents
			fwrite(readinputs->ename, 1, 32, readinputs->fptr);

			break;

		case 2:
			
			//computing the array position
			fptr_pos = (readinputs->array_pos * 134) + readinputs->array_pos;
			
			//seeking to the fptr pos
			fseek(readinputs->fptr, fptr_pos, SEEK_SET);
			
			//writing the contents
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(readinputs->ename, 1, 32, readinputs->fptr);
			
			break;

		case 3:
			
			//computing the array position
			fptr_pos = (readinputs->array_pos * 134) + readinputs->array_pos;
			
			//seeking to the fptr pos
			fseek(readinputs->fptr, fptr_pos, SEEK_SET);
			
			//writing the contents
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(readinputs->ename, 1, 32, readinputs->fptr);
			
			break;

		case 4:
			
			//computing the array position
			fptr_pos = (readinputs->array_pos * 134) + readinputs->array_pos;
			
			//seeking to the fptr pos
			fseek(readinputs->fptr, fptr_pos, SEEK_SET);
			
			//writing the contents
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(&delimeter, 1, 1, readinputs->fptr);
			fwrite(readinputs->ename, 1, 32, readinputs->fptr);
			fwrite(&newline, 1, 1, readinputs->fptr);
			
			break;
	}
}


/*Function for editing the address book*/
int edit_address_book(AddressBook *addressbook, Readinputs *readinputs, int option)
{
	AddressBook array[25];

	//invoking the inputs function,to read the inforamation
	if (inputs(addressbook, readinputs, option) < 0)
		return -1;

	//opening the file in the r+ mode
	readinputs->fptr = fopen(readinputs->fname, "r+");

	//Handling the errors
	if (readinputs->fptr == NULL)
	{
		//print the error message
		perror("fopen");
		fprintf(stderr, "ERROR : unable to open the file %s\n", readinputs->fname);
		return 1;
	}

	//invoking the function call to read the addressbook
	read_file_contents(array, readinputs);

	//writing  the contents to the addressbook
	write_to_address_book(array, readinputs);

	//closing the file
	fclose(readinputs->fptr);
}
