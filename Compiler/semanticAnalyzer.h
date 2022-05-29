
#define sizeTable  200
#define numTables 20 
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>



typedef enum { false, true } bool;


int tableID = 0;
int parentID = 0;

bool tableCreated = 0;



typedef struct entry
{
	char *name;
	double value;
    char char_value;
    short bool_value;
	int data_type;
	int is_constant;
	struct entry* next;
	bool is_null;

} entry ;

typedef struct table
{
    int parentID,ID;
    entry** symbolTable;
}   table;
table* tableList;

void printTableEntries(struct entry** symbolTable);


//Function to create the tables list and populate it with the initial main table
struct entry** Initialize(){
    if(tableCreated == false)
    {
        tableCreated = true;
        tableList = malloc(sizeof( struct table ) * numTables );  // creating the list of tables
        for( int i = 0; i < numTables; i++ )
	    {
		    tableList[i].symbolTable = NULL;
	    }
    }
    entry** mainTable = malloc( sizeof( struct entry* ) * sizeTable );
    for( int i = 0; i < sizeTable; i++ )
	{
		mainTable[i] = NULL;
	}
    tableList[tableID].symbolTable = mainTable;
    tableList[tableID].ID = tableID;
    tableList[tableID].parentID = -1;
    //printf("number: %d\n", tableList[tableID].ID);
    return mainTable;
}

//Function to create a new table, will be the current table
int CreateTable()
{

    tableID++; // index of tables is starting from 1

	entry** table = malloc( sizeof( struct entry* ) * sizeTable );    // Hashmap has 200 entries 
    for( int i = 0; i < sizeTable; i++ )
	{
		table[i] = NULL;
	}

    tableList[tableID].ID = tableID;
    tableList[tableID].parentID = parentID;
    tableList[tableID].symbolTable= table;

    parentID = tableID;
	return tableID;
}

//Function to exit a table, will teturn the index of the parent table
int ExitingTable()  // not sure of that function 
{
    int exitingTableID;
    exitingTableID = tableList[tableID].parentID;
    parentID = exitingTableID;
    tableID--;
    // if(tableList->symbolTable != NULL)
    // {
    //     free(tableList->symbolTable);
    // }
    return exitingTableID;
}

//Hash function of the symbol table
int HashFunction(char *givenString){
    int hash = 0;
    int i = 0;
    while(givenString[i] != '\0')
    {
        hash = (hash + givenString[i]) % sizeTable;
        i++;
    }
    return hash;
}

//Function that searches for a variable in symbol table, returns true if found, false if not
bool SearchInCurrentTable(char *name, struct entry** currentTable){
    bool found = false;
    int indx = HashFunction(name);
    if(currentTable[indx] != NULL){
        struct entry* e = currentTable[indx];
        while(e != NULL){
            if(strcmp(e->name,name) == 0)
            {
                found = true;
                break;
            }
            e = e->next;
        }
    }
    return found;
}

bool searchInCurrentAndParent(char* lexeme)
{
	int idx = tableID;
	bool finder = false;

	while(idx != -1)
	{
		finder = SearchInCurrentTable(lexeme, tableList[idx].symbolTable);

		if(finder != false)
			return finder;

		idx = tableList[idx].parentID;
	}

	return finder;
}


struct entry * ReturnEntryInTable(char *name, struct entry** currentTable){
    entry * found = NULL;
    int indx = HashFunction(name);
    if(currentTable[indx] != NULL){
        struct entry* e = currentTable[indx];
        while(e != NULL){
            if(strcmp(e->name,name) == 0)
            {
                found = e;
                break;
            }
            e = e->next;
        }
    }
    return found;
}


struct entry * searchReturnEntry(char* lexeme)
{
	int idx = tableID;
	entry * finder = NULL;

	while(idx != -1)
	{
		finder = ReturnEntryInTable(lexeme, tableList[idx].symbolTable);

		if(finder != NULL)
			return finder;

		idx = tableList[idx].parentID;
	}

	return finder;
}



//Function that inserts a variable in the current symbol table, returns true if insrted, false if not
bool InsertInHashMap(struct entry** symbolTable, struct entry* e)
{
	bool inserted = false;

	int indx = HashFunction(e->name);

    if(SearchInCurrentTable(e->name, symbolTable) == false){        // variable isn't entered in the current symbol table
        if(symbolTable[indx] == NULL)
        {
            symbolTable[indx] = e;
        }
        else
        {
            struct entry* e2 = symbolTable[indx] ;
            while(e2->next != NULL)
            {
                e2 = e2->next;
            }
            e2->next = e;
        
        }
        inserted = true;   
    }
    else
    {
        //printf("Variable %s already exists in the current symbol table\n", e->name);
    }
	return inserted;
}

entry * create_entry( char *name, int value, char character, short boolean, int data_type)
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
    new_entry->char_value = character;
    new_entry->bool_value = boolean;

	new_entry->is_constant = 0;
	new_entry->data_type = data_type;
    new_entry->next = NULL;
	return new_entry;
}

void printEntry(struct entry *entry){
	printf("        %s\n", entry->name);
	printf("        %f\n", entry->value);
	printf("        char: %c\n", entry->char_value);
	printf("        bool: %hd\n", entry->bool_value);
	printf("        %d\n", entry->data_type);
}

void printTableEntries(struct entry** symbolTable){
    for(int i = 0; i < sizeTable; i++){
        if(symbolTable[i] != NULL){
            struct entry* e = symbolTable[i];
            printf("    i: %d\n",i);
            while(e != NULL){
                printEntry(e);
                e = e->next;
            }
        }
    }
}

void printTableData(struct table* tableList){
    for(int i = 0; i < numTables; i++){
        if(tableList[i].symbolTable!=NULL){
            //printf("i: %d\n",i);
            printf("parentID: %d\n",tableList[i].parentID);
            printf("ID: %d\n",tableList[i].ID);
            printTableEntries(tableList[i].symbolTable);
            printf("\n");
        }
    }
}

//Function to Insert an entry to the currentTable, given its info
struct entry* insert(char *name, int value, char character, short boolean, int data_type, struct entry** currentTable)
{
    struct entry *myEntry =  create_entry(  name,  value, character, boolean, data_type);
    bool insertedSuccessfully = InsertInHashMap(currentTable, myEntry);
	if(insertedSuccessfully == true){
		return myEntry;
    }
	else 
		return NULL;
}



// int main(){
//     int currentID = 0;
//     entry **mainTable = Initialize();
//     struct entry* e4 = insert("main Table", 1, 1, tableList[currentID].symbolTable);
//     currentID = CreateTable();
//     struct entry* e3 = insert("deleted", 1, 1, tableList[currentID].symbolTable);;
//     currentID = ExitingTable();
//     currentID = CreateTable();
//     currentID = CreateTable();
//     struct entry* e = insert("aaaaa", 1, 1, tableList[currentID].symbolTable);
//     struct entry* e1 = insert("U", 1, 1, tableList[currentID].symbolTable);
//     struct entry* e2 = insert("b", 1, 1, tableList[currentID].symbolTable);
//     printTableData(tableList);
//     printf("found? %d", searchInCurrentAndParent("deleted"));
//     //printf("wahbshjbasdhvdah %d\n", currentID);
//     //printTableEntries(tableList[0].symbolTable);
// }




















