#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H 
#define sizeTable  200
#define numTables 20 
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

typedef struct table
{
    entry** tableOfSymbols;
    int id, parentId;
    bool created;
}   table;

int tableID = 0;
int parentID = 0;
bool tableCreated = 0;

table* TABLES;

int CreateTable()
{
    if(tableCreated == false)
        {
            tableCreated = true;
            TABLES = malloc(sizeof( struct table* ) * numTables );  // creating the list of tables
        }
    tableID++; // index of tables is starting from 1
    

	entry** table = malloc( sizeof( struct entry* ) * sizeTable );    // Hashmap has 200 entries 
    for( int i = 0; i < sizeTable; i++ )
	{
		table[i] = NULL;
	}
    // struct table createdTable;
    // createdTable.tableOfSymbols = table;
    // createdTable.id = tableID;
    // createdTable.parentId = parentID;
    TABLES[tableID].id = tableID;
    TABLES[tableID].parentId = parentID;
    TABLES[tableID].tableOfSymbols= table;
    TABLES[tableID].created = true;


	return TABLES[tableID].id;
}

int ExitingTable()  // not sure of that function 
{
    int exitingTableID;
    exitingTableID = TABLES[tableID].parentId;
    return exitingTableID;
}

int FoundInCurrentAndParents(struct table symbolsTable, struct entry* e, int indx)
{
    while (TABLES[symbolsTable.id].created == true)
    {

        char *findingChar = e->name;
       
        if (TABLES[symbolsTable.id].tableOfSymbols[indx] != NULL)
        {
            if(strcmp(findingChar, TABLES[symbolsTable.id].tableOfSymbols[indx]->name) == 0)
            {
                printf("this variable %s is defined at the parent or the current table\n" , findingChar);
                return 1;
            }
        }
        symbolsTable.id = TABLES[symbolsTable.id].parentId;
        
    }
    return 0;
    
}

bool InsertInHashMap(struct table tableOfSymbols, struct entry* e)
{
	bool inserted = false;
	int hash = 0;
   	int i = 0;
	char* givenString = e->name;
    while(givenString[i] != '\0')
    {
        hash = (hash + givenString[i]) % sizeTable;
        i++;
    }

	int indx = hash;

	if (FoundInCurrentAndParents(tableOfSymbols, e, indx) == 0)
    {
        if(tableOfSymbols.tableOfSymbols[indx] == NULL)
        {
            tableOfSymbols.tableOfSymbols[indx] = e;
        }
	    else
	    {
            struct entry* e2 = tableOfSymbols.tableOfSymbols[indx] ;
	        while(e2->next != NULL)
	    	{
	    	    e2 = e2->next;
	    	}
	        e2->next = e;
		
	    }
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

struct entry* insert(char *name, int value, int data_type, struct table currentTable)
{
    struct entry *myEntry =  create_entry(  name,  value,  data_type);
    bool insertedSuccessfully = InsertInHashMap(currentTable, myEntry);
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