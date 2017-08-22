#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address_book.h"

/*Function for reading the file name*/
void read_file_name(Readinputs *readinputs)
{
	int size;
	char buff[32], *ptr;

	/*Reading the file name*/
	printf("Enter the file name: ");
	scanf("%s", buff);
	size = strlen(buff);

	/*Allocating the memory dynamically*/
	ptr = (char *)malloc(sizeof(char) * size);
	strcpy(ptr, buff);

	readinputs->fname = ptr;
}

/*Main program*/
int main()
{
	int size;
	char buff[32], *ptr;
	int option, option_1;
	char ch;

	/*Declaring the variables*/
	Readinputs readinputs;
	AddressBook addressbook;
				
	/*Reading the file name*/
	read_file_name(&readinputs);
	
	do
	{
		/*Reading the option*/
		printf("1. Insert\n2. Edit\n3. Search\n4. Delete\n5. Display\n6. Exit\nEnter the option: ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:

				/*Invoking the function call to insert the data into the addressbook*/
				if ((insert_data_to_addressbook(&addressbook, &readinputs, option)))
					return 0;

				printf("Inserted Successfully!!!!\n");
				
				break;

			case 2:
				
				/*Invoking the function call to edit the addressbook*/
				edit_address_book(&addressbook, &readinputs, option);
				
				printf("Edited Successfully!!!!\n");
				
				break;

			case 3:

				/*Invoking the function call to search the addressbook*/
				search_add_book(&readinputs, option);
				
				printf("Searched the contact Successfully!!!!\n");

				break;

			case 4:
				
				/*Invoking the function call to delete the data*/
				delete_data(&addressbook, &readinputs, option);
				
				printf("Deleted Successfully!!!!\n");
				
			case 5:
				
				/*Invoking the function call to display the contents in the addressbook*/
				display_add_book(&readinputs);
				
				break;

			case 6:

				/*exit the loop*/
				return 0;

			default:

				printf("Check the option\n");
		}

		/*read the continue option*/
		printf("Do you want to continue: (y/n)");
		scanf("\n%c", &ch);

	} while(ch == 'y');
}
