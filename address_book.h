#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

/*structure for contact info*/
typedef struct _Addressbook
{
	char *name;
	char *email;
	char *phone;
	char *city;

}AddressBook;

/*structure for read info*/
typedef struct _ReadInfo
{
	FILE *fptr;

	char *fname;

	int option;

	char *ename;

	char *newdata;

	int array_pos;

}Readinputs;

void add_space(char *string);
int inputs(AddressBook *addressbook, Readinputs *readinputs, int option);
int insert_data_to_addressbook(AddressBook *addressbook, Readinputs *readinputs, int opton);
void print_display(AddressBook *addressbook, int count);
int display_add_book(Readinputs *readinputs);
int search_by_name(AddressBook *addressbook, Readinputs *readinputs, int count);
int search_by_phonenumber(AddressBook *addressbook, Readinputs *readinputs, int count);
int search_by_emailId(AddressBook *addressbook, Readinputs *readinputs, int count);
void search_print_display(AddressBook *addressbook, int i_index);
int search_data_address_book(AddressBook *addressbook, Readinputs *readinputs, int count);
int search_add_book(Readinputs *readinputs, int option);

#endif


