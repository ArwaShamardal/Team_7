#include <iostream>
#include "WritingQuadruples.h"
#include <fstream>
#include <string>
using namespace std;


ofstream file;
void write_mov(char* instr, char* res, int arg1, char* arg2)
{
    file.open("WriteQuadruple.txt", std::ios::app);
    file << instr << ' ' << res << ' ' << arg1 << ' ' << arg2 << ' ' << endl;
    file.close();
}

void write_declaration(char* instr, char* res, char* arg1, char* arg2) {
    file.open("WriteQuadruple.txt", std::ios::app);
    file << instr << ' ' << res << ' ' << arg1 << ' ' << arg2 << ' ' << endl;
    file.close();
}

void write_arithmetic(char* instr, char* res, int arg1, int arg2)
{
    file.open("WriteQuadruple.txt", std::ios::app);
    file << instr << ' ' << res << ' ' << arg1 << ' ' << arg2 << ' ' << endl;
    file.close();
}


// void quad_assign(string name, float value) {
//     write_quadruple("MOV ");																		
// 	char * text;
// 	sprintf(text, "%f", currentEntry->value);
// 	WriteQuadruple(currentName);
// 	WriteQuadruple(text);
// 	WriteQuadruple("\n");
// 	printEntry($1);

// }