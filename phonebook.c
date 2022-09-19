# include "phonebook.h"


void add_record(record* new_record)
{
    FILE* fptr = fopen("data.txt", "a");
	
	fprintf(fptr, "\n%d %s %s", new_record->id, new_record->name, new_record->phone_number);
	
	fclose(fptr);	
}

void write_record_list_to_file(node* records)
{
	FILE* fptr = fopen("data.txt", "w");
	
	while (records != NULL)
	{
		fprintf(fptr, "\n%d %s %s", records->record.id, records->record.name, records->record.phone_number);

		records = records->next;
	}

	
	fclose(fptr);
}


node* get_records()
{
	node* head = NULL;
	node* current = NULL;
	
	FILE *file = fopen("data.txt", "r");

	while(!feof(file)) 
	{	
		node* tmp = (node*)malloc(sizeof(node));

		fscanf(file, "%d %s %s", &tmp->record.id, tmp->record.name, tmp->record.phone_number);

		if (current != NULL)
		{
			current->next = tmp;
			current = current->next;
		}
		else
		{
			current = tmp;
			head = current;
		}
		
		current->next = NULL;		
	}

	fclose(file);

	return head;
}

int get_list_size()
{
	node* records = get_records();
	node* tmp;
	int size = 0;

	while (records != NULL)
	{
		size += 1;

		tmp = records;
		records = records->next;

		free(tmp);
	}

	return size;
}

record* get_record_by_name(char* name)
{
	node* records = get_records();

	while (records != NULL)
	{
		if (strcmp(records->record.name, name) == 0)
			return &(records->record);	

		records = records->next;
	}
		
	return NULL;
	
}

void delete_record(int id)
{
	node* records = get_records();
	node* tmp;

	while (records != NULL)
	{

		if (records->record.id ==  id)
			records->next = records->next->next;

		records = records->next;
	}

	write_record_list_to_file(records);

	while (records != NULL)
	{
		tmp = records;
		records = records->next;		
		
		free(tmp);
	}		
}

