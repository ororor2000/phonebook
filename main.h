#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Record
{
	char name[10];	
	char phone_number[11];
} record;

typedef struct Node {
    record* record;
    struct Node* next;
} node;


void add_record();
void get_records(node* head);
