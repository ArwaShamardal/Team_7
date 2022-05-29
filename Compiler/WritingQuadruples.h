// Wrapper.h
// #include "Utility.h"

#ifdef __cplusplus
extern "C" {
#endif
    void write_mov(char* instr, char* res, int arg1, char* arg2);
    void write_arithmetic(char* instr, char* res, int arg1, int arg2);
    void write_declaration(char* instr, char* res, char* arg1, char* arg2);

#ifdef __cplusplus
    }
#endif
