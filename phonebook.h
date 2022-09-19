#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Record {
    int id;
    char name[11];	
	char phone_number[11];
} record;

typedef struct Node {
	record record;
    struct Node* next;
} node;


void add_record(record* new_record);
void write_record_list_to_file(node* records);
node* get_records();
int get_list_size();
record* get_record_by_name(char* name);
void delete_record(int id);
