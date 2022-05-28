
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

int size = 200;

entry** CreateTable()
{

	entry** table = malloc( sizeof( struct entry* ) * size );    // Hashmap has 200 entries 
    for( int i = 0; i < size; i++ )
	{
		table[i] = NULL;
	}

	return table;
}

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

int InsertInHashMap(struct entry** table, struct entry* e)
{
	// int hash = 0;
   	// int i = 0;
	// char* givenString = e->name;
    // while(givenString[i] != '\0')
    // {
    //     hash = (hash + givenString[i]) % size;
    //     i++;
    // }

	int indx = 0;

	if(table[indx] == NULL)
    {
        table[indx] = e;
        printf("Entered the index");
    }
	else
	{
		struct entry* e2 = table[indx];
		while(e2->next != NULL)
		{
			e2 = e2->next;
		}
		e2->next = e;
	}
}

// int insert(char name, int value, int data_type, struct entry** table){
//     struct entry myEntry =  create_entry(  name,  value,  data_type);
//     return InsertInHashMap(table, myEntry);
// }

int main(){
	struct entry ** current_table = CreateTable();
	struct entry* currentEntry = create_entry("dad", 3, 2);
	struct entry* currentEntry2 = create_entry("mum", 3, 2);

    
    //printf("%s",currentEntry->name);

	InsertInHashMap(current_table, currentEntry);
	InsertInHashMap(current_table, currentEntry2);


    printf("%s",current_table[0]->name);
    printf("%s",current_table[0]->next->name);
}