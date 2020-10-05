/*
    Classic C code to understand MIDI files
    MIDI Study Guide : https://ccrma.stanford.edu/~craig/14q/midifile/MidiFileFormat.html
*/


#include <stdio.h>
#include <stdlib.h>

struct headerChunk {
    char fileID[4];     // indicates an actual MiDi file
    int length;         // header length
    short format;       // format [2 bytes]   0 : single track | 1 : multiple track | 2 : multiple song file format
    short n;            // number of tracks that follow
    short division;     // unit of time for delta timing
};

struct trackChunk {

};

int main() {
    FILE *fp;
    char data;
    fp = fopen("sample.mid", "rb");
    int i=0, j=0;
    
    if(fp == NULL) {
        printf("\nError: failed to open mid file\nTerminating...\n");
        return -1;
    }
    fread(&data, 1, sizeof(unsigned char), fp);

    printf("\nPrinting data (i = %d)...\n\n", i);
    
    printf("%c ", data);
    return 0;
}