
#include "main.h"

void add_record_cli(record* new_record)
{
	system("cls");
	printf("####### Add New Record #######\n");

	record* new_record = malloc(sizeof(record));

	printf("Enter Name: ");
	scanf("%s", &(new_record->name));	
	
	printf("\nEnter Phone Numeber: ");
	scanf("%s", &(new_record->phone_number));
	
	int size = get_list_size();
	new_record->id = size + 1;

	add_record(new_record);
    
	free(new_record);

	printf("\nPress any key to return");
	getch();
}

void print_records_cli()
{
	system("cls");
	printf("####### Add New Record #######\n");
	
	node* records = get_records();
	node* tmp;

	while (records != NULL)
	{
		tmp = records;
		records = records->next;

		printf("id: %d, name: %s, phone: %s\n", tmp->record.id, tmp->record.name, tmp->record.phone_number);

		free(tmp);
	}

	printf("\nPress any key to return");
	getch();
}


void print_record_by_name_cli()
{
	system("cls");
	printf("####### Search Record #######\n");

	char name[11];
	printf("Enter Name: ");
	scanf("%s", &name);

	record* rec;
	rec = get_record_by_name(name);

	printf("id: %d, name: %s, phone: %s\n", rec->id, rec->name, rec->phone_number);


	printf("\nPress any key to return");
	getch();
}


void delete_record_cli()
{
	system("cls");
	printf("####### Delete Record #######\n");

	char name[11];
	printf("Enter name: ");
	scanf("%s", &name);

	record *rec;
	rec = get_record_by_name(name);

	delete_record(rec->id);

	printf("\nPress any key to return");
	getch();
}

int main(int argc, char* argv[])
{
	int choice = 0;
	while (choice != 5)
	{
		input:
		system("cls");
		printf("####### PhoneBook #######\n");
		printf("1. Add New Record\n");
		printf("2. List Records\n");
		printf("3. Search Record\n");
		printf("4. Delete Record\n");
		printf("5. Exit\n");
		printf("_________________\n");

		printf("\nEnter Choice: ");
		scanf("%d", &choice);

		if (choice < 1 && choice > 5)
		{
			goto input;
		}

		switch (choice)
		{
			case 1:
				add_record_cli();
				break;
			case 2:
				print_records_cli();
				break;
			case 3:
				print_record_by_name_cli();
				break;
			case 4:
				delete_record_cli();
				break;
		}
	}
}