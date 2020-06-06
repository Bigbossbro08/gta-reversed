#pragma once

#include <cstddef>
#include <cstdint>

class CMemoryMgr 
{
public:
    static void *Malloc(size_t size);
    static void Free(void *memory);
    static void *Realloc(void *memory, size_t size);
    static void *Calloc(size_t elemsize, size_t nelems);
    static void *InitScratchPad();
    static void LockScratchPad();
    static void ReleaseScratchPad();
    static std::uint8_t *MallocAlign(size_t size, uintptr_t align);
    static void FreeAlign(void *memory);
};
