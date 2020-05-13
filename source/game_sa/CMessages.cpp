#include "StdInc.h"

// Returns length of a string
unsigned int CMessages::GetStringLength(char* string)
{
    return ((unsigned int(__cdecl*)(char*))0x69DB50)(string);
}

// Inserts key events into string
void CMessages::InsertPlayerControlKeysInString(char* string)
{
    ((void(__cdecl*)(char*))0x69E160)(string);
}
