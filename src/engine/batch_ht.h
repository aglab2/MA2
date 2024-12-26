#pragma once

#include <PR/os_libc.h>

#define TABLE_SIZE 1024

typedef struct batch_ht_entry {
    const void* startPtr;
    const void* endPtr;
    s16 layer;
    s16 idx;
    struct batch_ht_entry *next;
} batch_ht_entry_t;

typedef struct {
    batch_ht_entry_t *entries[TABLE_SIZE];
    int next;
    int totals[LAYER_COUNT];
    batch_ht_entry_t* firstEntry;
    batch_ht_entry_t* nextEntry;
} batch_ht_t;

static inline unsigned int hash(const void* startPtr) {
    return (0x61C88647 * (unsigned int)startPtr) >> (32 - 10);
}

static inline void batch_ht_init(batch_ht_t *table) {
    bzero(table, sizeof(table));
    table->firstEntry = table->nextEntry = (batch_ht_entry_t*) (((uint8_t*) table) + sizeof(batch_ht_t));
}

static inline batch_ht_entry_t* batch_ht_set(batch_ht_t *table, const char *startPtr, int idx, int layer) {
    unsigned int slot = hash(startPtr);

    batch_ht_entry_t* newEntry = table->nextEntry++;
    newEntry->startPtr = startPtr;
    newEntry->layer = layer;
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

static inline batch_ht_entry_t* batch_ht_indexize(batch_ht_t *table, const char *startPtr, int layer) {
    batch_ht_entry_t *entry = batch_ht_get(table, startPtr);
    if (entry != NULL) {
        return entry;
    }

    table->next++;
    int idx = table->totals[layer]++;
    entry = batch_ht_set(table, startPtr, idx, layer);
    return entry;
}
