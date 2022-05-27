#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H
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
	bool is_null;

} entry ;




entry * create_entry( char *name, int value, int data_type)
{
	entry *new_entry;

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
	return new_entry;
}


void printEntry(struct entry *entry){
	printf("%s\n", entry->name);
	printf("%f\n", entry->value);
	printf("%d\n", entry->data_type);
}


#endif