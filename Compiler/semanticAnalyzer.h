#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H 
#define size  200
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>



typedef enum { false, true } bool;
/* struct to hold each entry */
typedef struct entry
{
	char *name;
	double value;
	int data_type;
	int is_constant;
	struct entry* next;
	bool is_null;

} entry ;

//int size = 200;
int tableID = 0;

entry** CreateTable()
{
	tableID++;
	entry** table = malloc( sizeof( struct entry* ) * size );    // Hashmap has 200 entries 
    for( int i = 0; i < size; i++ )
	{
		table[i] = NULL;
	}

	return table;
}

bool InsertInHashMap(struct entry** table, struct entry* e)
{
	bool inserted = false;
	int hash = 0;
   	int i = 0;
	char* givenString = e->name;
    while(givenString[i] != '\0')
    {
        hash = (hash + givenString[i]) % size;
        i++;
    }

	int indx = hash;

	if(table[indx] == NULL)
    {
        table[indx] = e;
        //printf("Entered the index");
		inserted = true;
    }
	else
	{
		struct entry* e2 = table[indx];
		while(e2->next != NULL)
		{
			e2 = e2->next;
		}
		e2->next = e;
		inserted = true;
	}

	return inserted;
}



// entry* e SearchingInIndex(struct entry** table, int indx)
// {
	
// }

entry * create_entry( char *name, int value, int data_type)
{
	entry *new_entry = NULL;

	/* Allocate space for new_entry */
	if( ( new_entry = malloc( sizeof( entry ) ) ) == NULL ) {
		return NULL;
	}
	/* Copy name to new_entry location using strdup (string-duplicate). Return NULL if it fails */
	if( ( new_entry->name = strdup( name ) ) == NULL ) {
		return NULL;
	}
    
	new_entry->value = value;
	new_entry->is_constant = 0;
	new_entry->data_type = data_type;
    new_entry->next = NULL;
	return new_entry;
}

struct entry* insert(char *name, int value, int data_type, struct entry** table)
{
    struct entry *myEntry =  create_entry(  name,  value,  data_type);
    bool insertedSuccessfully = InsertInHashMap(table, myEntry);
	if(insertedSuccessfully == true)
		return myEntry;
	else 
		return NULL;
}

void printEntry(struct entry *entry){
	printf("%s\n", entry->name);
	printf("%f\n", entry->value);
	printf("%d\n", entry->data_type);
}


#endif