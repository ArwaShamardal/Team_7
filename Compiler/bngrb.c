
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

int size = 200;
int tableID = 0;
int parentID = 0;
bool tableCreated = 0;

table* TABLES;
int CreateTable()
{
    if(tableCreated == false)
        {
            tableCreated = true;
            TABLES = malloc(sizeof( struct table* ) * size );  // creating the list of tables
        }
    tableID++; // index of tables is starting from 1
    

	entry** table = malloc( sizeof( struct entry* ) * size );    // Hashmap has 200 entries 
    for( int i = 0; i < size; i++ )
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

int ExitingTable()
{
    int exitingTableID;
    exitingTableID = TABLES[tableID].parentId;
    return exitingTableID;
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

int FoundInCurrentAndParents(struct table symbolsTable, struct entry* e, int indx)
{
    //table currentTable = symbolsTable;
    while (TABLES[symbolsTable.id].created == true)
    {
        //printf("current table id is %d\n", symbolsTable.id);
        //printf("parent table id is %d\n", symbolsTable.parentId);
        //printf("searching for %s\n", e->name);
        
        //printf("index is %d\n", indx);
        char *findingChar = e->name;
       
        if (TABLES[symbolsTable.id].tableOfSymbols[indx] != NULL)
        {
            printf("%s\n",findingChar);
            printf("index is %d\n", indx);
            printf("goog %s \n", TABLES[symbolsTable.id].tableOfSymbols[indx]->name );
            if(strcmp(findingChar, TABLES[symbolsTable.id].tableOfSymbols[indx]->name) == 0)
            {
                printf("this variable %s is defined at the parent or the current table\n" , findingChar);
                return 1;
            }
        }
        //currentTable.parentId= TABLES[currentTable.parentId].parentId;
        symbolsTable.id = TABLES[symbolsTable.id].parentId;
        
    }
    return 0;
    
}

int InsertInHashMap(struct table tableOfSymbols, struct entry* e)
{
    // HASHING PART
    //printf("current table id is %d\n", tableOfSymbols.id);
    //    printf("parent table id is %d\n", tableOfSymbols.parentId);
	int hash = 0;
   	int i = 0;
	char* givenString = e->name;
    while(givenString[i] != '\0')
    {
        hash = (hash + givenString[i]) % size;
        i++;
    }

	int indx = hash;
    if (FoundInCurrentAndParents(tableOfSymbols, e, indx) == 0)
    {
        if(tableOfSymbols.tableOfSymbols[indx] == NULL)
        {
            //printf("insert index is %d\n", indx);
            tableOfSymbols.tableOfSymbols[indx] = e;
            //printf("didn't enter this index before\n");
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
    }    
	
}



// int insert(char name, int value, int data_type, struct entry** table){
//     struct entry myEntry =  create_entry(  name,  value,  data_type);
//     return InsertInHashMap(table, myEntry);
// }

int main(){
	int myTableID =  CreateTable();
	struct entry* currentEntry = create_entry("zdad", 3, 2);
	struct entry* currentEntry2 = create_entry("y", 3, 2);
    int myTableID2 = CreateTable();
     TABLES[myTableID2].parentId = 1;
    struct entry* currentEntry3 = create_entry("y", 3, 2);
	struct entry* currentEntry4 = create_entry("zdad", 3, 2);
    //struct table current_table = CreateTable();
     


    //printf("id is %d\n", TABLES[TABLES[2].parentId].parentId);
	InsertInHashMap(TABLES[myTableID], currentEntry);
    printf("moonn\n");
	InsertInHashMap(TABLES[myTableID], currentEntry2);
printf("knight\n");
    InsertInHashMap(TABLES[myTableID2], currentEntry3);
	InsertInHashMap(TABLES[myTableID2], currentEntry4);
    // printf("%s \n",TABLES[myTableID].tableOfSymbols[0]->name);
    // printf("%s \n",TABLES[myTableID].tableOfSymbols[0]->next->name);

    // printf("%s \n",TABLES[myTableID2].tableOfSymbols[0]->name);
    // printf("%s \n",TABLES[myTableID2].tableOfSymbols[0]->next->name);

    // printf("%d \n",TABLES[myTableID].id);
    // printf("%d \n",TABLES[myTableID].parentId);

    // printf("%d \n",TABLES[myTableID2].id);
    // printf("%d \n",TABLES[myTableID2].parentId);
}