#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address_book.h"

/*Function for searching the addressbook by name*/
int search_by_name(AddressBook *addressbook, Readinputs *readinputs, int count)
{
	int i_index, flag = 1;

	for (i_index = 0; i_index < count; i_index++)
	{
		//comparing the address book data and entered data
		if ((strcmp(addressbook[i_index].name, readinputs->newdata)) == 0)
		{
			//if it is true returning the index value and clearing the flag
			flag = 0;
			return i_index;
		}
	}

	//if flag is set, returning the -1
	if (flag)
		return -1;
}

/*Function for searching the addressbook by phone number*/
int search_by_phonenumber(AddressBook *addressbook, Readinputs *readinputs, int count)
{
	int i_index, flag = 1;

	for (i_index = 0; i_index < count; i_index++)
	{
		//comparing the address book data and entered data
		if ((strcmp(addressbook[i_index].phone, readinputs->newdata)) == 0)
		{
			//if it is true returning the index value and clearing the flag
			flag = 0;
			return i_index;
		}
	}
	
	//if flag is set, returning the -1
	if (flag)
		return -1;
}

/*Function for searching the addressbook by emailId*/
int search_by_emailId(AddressBook *addressbook, Readinputs *readinputs, int count)
{
	int i_index, flag = 1;

	for (i_index = 0; i_index < count; i_index++)
	{
		//comparing the address book data and entered data
		if ((strcmp(addressbook[i_index].email, readinputs->newdata)) == 0)
		{
			//if it is true returning the index value and clearing the flag
			flag = 0;
			return i_index;
		}
	}
	
	//if flag is set, returning the -1
	if (flag)
		return -1;
}

/*Function for searching the addressbook by city*/
int search_by_city(AddressBook *addressbook, Readinputs *readinputs, int count, char index_array[], int *j_index)
{
	int i_index, flag = 1;

	for (i_index = 0; i_index < count; i_index++)
	{
		//comparing the address book data and entered data
		if ((strcmp(addressbook[i_index].city, readinputs->newdata)) == 0)
		{
			//if it is true returning the index value and clearing the flag
			flag = 0;
			index_array[(*j_index)] = i_index;
			(*j_index)++;
		}
	}
	
	//if flag is set, returning the -1
	if (flag)
		return -1;
}


/*Function for to print the searched contents*/
void search_print_display(AddressBook *addressbook, int i_index)
{
	printf("\n***********************************************\n");
	
	printf("Name		: %s\n", addressbook[i_index].name);
	printf("EmailId		: %s\n", addressbook[i_index].email);
	printf("PhoneNumber	: %s\n", addressbook[i_index].phone);
	printf("City		: %s\n", addressbook[i_index].city);

	printf("\n***********************************************\n");
}


/*Function for searching the data by name email phone and city*/
int search_data_address_book(AddressBook *addressbook, Readinputs *readinputs, int count)
{
	int j_index = 0, i_index = 0, limit = 0;
	char array[25];

	switch (readinputs->option)
	{
		case 1:
			
			//calling the search by name function, and stroing the index value
			j_index = search_by_name(addressbook, readinputs, count);
	
			//if the returned value is -1
			if (j_index == -1)
			{
				//print the error message
				printf("The name is not found\n");
				return -1;
			}
	
			//printing the contents
			search_print_display(addressbook, j_index);

			break;

		case 2:

			//calling the search by phonenumber function, and storing the index value
			j_index = search_by_phonenumber(addressbook, readinputs, count);

			//if the returned value is -1
			if (j_index == -1)
			{
				//print the error message
				printf("The phone number is not found\n");
				return -1;
			}
			
			//printing the contents
			search_print_display(addressbook, j_index);
			
			break;

		case 3:

			//calling the search by emailId function, and storing the index value
			j_index = search_by_emailId(addressbook, readinputs, count);
			
			//if the returned value is -1
			if (j_index == -1)
			{
				//print the error message
				printf("The emailid is not found\n");
				return -1;
			}
			
			//printing the contents
			search_print_display(addressbook, j_index);

			break;

		case 4:
			
			//calling the search by city function, and storing the index value
			j_index = search_by_city(addressbook, readinputs, count, array, &limit);
			
			//if the returned value is -1
			if (j_index == -1)
			{
				//print the error message
				printf("The city is not found\n");
				return -1;
			}
			
			for (i_index = 0; i_index < limit; i_index++)
			{
				//printing the contents
				search_print_display(addressbook, array[i_index]);
			}

			break;
	}
	
}


/*Function for reading the information from the file and searching the contents*/
int search_add_book(Readinputs *readinputs, int option)
{
	int bytes, index;
	char buff[32], temp[2];
	AddressBook addressbook[25];
	int count = 0;

	//calling the inputs function for reading the information
	inputs(addressbook, readinputs, option);

	//opening the file in the r+ mode
	readinputs->fptr = fopen(readinputs->fname, "r");

	//Handling the errors
	if (readinputs->fptr == NULL)
	{
		//printing the error message
		perror("fopen");
		fprintf(stderr, "ERROR: unable to open the file %s\n", readinputs->fname);
		return 1;
	}

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

	//invoking the function call to search the data by name, email, phone num, city
	search_data_address_book(addressbook, readinputs, count - 1);

	//closing the file
	fclose(readinputs->fptr);
}









