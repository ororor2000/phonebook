
#include "main.h"
/*
void add_record()
{
	system("cls");
	printf("####### Add New Record #######\n");

	record* new_record = malloc(sizeof(record));

	printf("Enter Name: ");
	scanf("%s", new_record->name);	
	
	printf("\nEnter Phone Numeber: ");
	scanf("%s", new_record->phone_number);

	FILE* fptr = fopen("data.txt", "w");
	
	fscanf("%s %s\n", new_record->name, new_record->phone_number);
	fclose(fptr);
	
	free(new_record);

	printf("\nPress any key to return");
	getch();
}
*/


void get_records(node* head)
{

	FILE *file = fopen("data.txt", "r");

	while(!feof(file)) 
	{	
		node* tmp = (node*) malloc(sizeof(node));		
		tmp->next = NULL;

		fscanf(file, "%s %s", &(tmp->record->name), &(tmp->record->phone_number));

		
		if (head == NULL)
		{
			head = tmp;			
			printf("name: %s, phone: %s\n", head->record->name, head->record->phone_number);
		}
		else
		{
			tmp->next = head;
			head = tmp;
			printf("name: %s, phone: %s\n", head->record->name, head->record->phone_number);

		}
	}

	fclose(file);
}

/*
int get_records(record* records, int* size)
{           
    int count = 0;
    
    FILE *file = fopen("data.txt", "r");

    
    while(!feof(file)) 
    {
        if (count == *size)
        {
            records = (record*) realloc(records, (*size + 3) * sizeof(record));
            *size += 3;
        }

        fscanf(file, "%s %s", &(records+count)->name, &(records+count)->phone_number);

        printf("name: %s\n", (records+count)->name);
        printf("phone: %s\n", (records+count)->phone_number);                
        printf("count: %d\n", count);
        
        count += 1;
    }           

    fclose(file);

    return count;
} 

*/
int main(int argc, char* argv[])
{
	node* records = NULL;

	get_records(records);

	node* head = records;

	while (head->next != NULL)
	{
		printf("name: %s, phone: %s", head->record->name, head->record->phone_number);
		head = head->next;
	}
	/*while (choice != 5)
	{
		input:
		system("cls");
		printf("####### PhoneBook #######\n");
		printf("1. Add New Record\n");
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
				add_record(&fptr);
				break;
		}
	}*/	
}