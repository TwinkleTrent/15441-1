#ifndef CHUNKLIST_H
#define CHUNKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define SHA1_HASH_SIZE 20

enum chunkType{
    MASTER,
    GET,
    HAS,
};

typedef struct chunkLine{
    int seq;
    int fetchState;//0:N/A,1:fetched,2:fetching
    uint8_t hash[SHA1_HASH_SIZE];
}chunkLine;

typedef struct chunkList{
	enum chunkType type;
	int numChunk;
	chunkLine list[MAX_NUM_CHUNK];
    FILE *filePtr;//Master input or GET output
}chunkList;

/* Chunk */
chunkList masterChunk;
chunkList hasChunk;
chunkList getChunk;


#endif
