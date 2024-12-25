#pragma once

#include <PR/os_libc.h>

#define TABLE_SIZE 1024

typedef struct batch_ht_entry {
    const void* startPtr;
    const void* endPtr;
    int idx;
    struct batch_ht_entry *next;
} batch_ht_entry_t;

typedef struct {
    batch_ht_entry_t *entries[TABLE_SIZE];
    int next;
    void* nextAlloc;
} batch_ht_t;

static inline unsigned int hash(const void* startPtr) {
    return (0x61C88647 * (unsigned int)startPtr) >> (32 - 10);
}

static inline void batch_ht_init(batch_ht_t *table) {
    bzero(table, sizeof(table));
    table->nextAlloc = table + 1;
}

static inline void* batch_ht_malloc(batch_ht_t *table, int sz) {
    void* ret = table->nextAlloc;
    table->nextAlloc += sz;
    return ret;
}

static inline batch_ht_entry_t* batch_ht_set(batch_ht_t *table, const char *startPtr, int idx) {
    unsigned int slot = hash(startPtr);

    batch_ht_entry_t* newEntry = (batch_ht_entry_t*) batch_ht_malloc(table, sizeof(batch_ht_entry_t));
    newEntry->startPtr = startPtr;
    newEntry->idx = idx;
    newEntry->next = table->entries[slot];
    table->entries[slot] = newEntry;

    return newEntry;
}

static inline batch_ht_entry_t* batch_ht_get(batch_ht_t *table, const char *startPtr) {
    unsigned int slot = hash(startPtr);
    batch_ht_entry_t *entry = table->entries[slot];
    while (entry != NULL) {
        if (startPtr == entry->startPtr) {
            return entry;
        }
        entry = entry->next;
    }

    return 0;
}

static __attribute__ ((noinline)) batch_ht_entry_t* batch_ht_indexize(batch_ht_t *table, const char *startPtr) {
    batch_ht_entry_t *entry = batch_ht_get(table, startPtr);
    if (entry != NULL) {
        return entry;
    }

    int idx = table->next++;
    entry = batch_ht_set(table, startPtr, idx + 1);
    return entry;
}
