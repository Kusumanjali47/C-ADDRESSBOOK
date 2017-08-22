#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address_book.h"

/*Function for inserting the data to the addressbook*/
int insert_data_to_addressbook(AddressBook *addressbook, Readinputs *readinputs, int option)
{
	int limit, i_index;
	char delimeter = '/'; 
	char newline = '\n';

	//opening the file in the a+ mode
	readinputs->fptr = fopen(readinputs->fname, "a+");

	//Handling the errors
	if (readinputs->fptr == NULL)
	{
		//printing the error message
		perror("fopen");
		fprintf(stderr, "ERROR: unable to open the file %s\n", readinputs->fname);
		return 1;
	}

	//reading the number of contacts to insert
	printf("Enter the number of contacts to enter :");
	scanf("%d", &limit);

	//for loop to run upto the number of contacts
	for (i_index = 0; i_index < limit; i_index++)
	{
		//reading the information
		inputs(addressbook, readinputs, option);

		/*name info*/

		//writing the name to the file
		fwrite(addressbook->name, 1, 32, readinputs->fptr);
		

		/*email info*/

		//writing the delimeter to the file
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		//writing the email to the file
		fwrite(addressbook->email, 1, 32, readinputs->fptr);


		/*phone number info*/

		//writing the delimeter to the file
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		//writing the phone number to the file
		fwrite(addressbook->phone, 1, 32, readinputs->fptr);


		/*city info*/


		//writing the delimeter to the file
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		fwrite(&delimeter, 1, 1, readinputs->fptr);
		//writing the city name to the file
		fwrite(addressbook->city, 1, 32, readinputs->fptr);
		//writing the newline to the file
		fwrite(&newline, 1, 1, readinputs->fptr);
	}

	//closing the file
	fclose(readinputs->fptr);

	return 0;
}
