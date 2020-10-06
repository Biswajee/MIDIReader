/*
    Classic C code to understand MIDI files
    MIDI Study Guide : https://ccrma.stanford.edu/~craig/14q/midifile/MidiFileFormat.html
*/


#include <stdio.h>
#include <stdlib.h>

struct headerChunk {
    char fileID[4];     // indicates an actual MiDi file
    short length;       // header length
    short format;       // format [2 bytes]   0 : single track | 1 : multiple track | 2 : multiple song file format
    short n;            // number of tracks that follow
    short division;     // unit of time for delta timing
};

struct trackEvent {
    short vTime;        // a variable length value specifying the elapsed time (delta time) from the previous event to this event
    short midiEvent;    // any MIDI channel message such as note-on or note-off
};

struct trackChunk {
    char trackID[4];    // marks the beginning of a track
    int length;         // track length
    struct trackEvent event;   // track event structure
};

int main() {
    FILE *fp;
    struct headerChunk head;
    struct trackChunk track;
    struct trackEvent evt;

    fp = fopen("sample.mid", "rb");
    
    if(fp == NULL) {
        printf("\nError: failed to open mid file\nTerminating...\n");
        return -1;
    }
    fread(&head.fileID[0], 1, sizeof(unsigned char), fp);
    fread(&head.fileID[1], 1, sizeof(unsigned char), fp);
    fread(&head.fileID[2], 1, sizeof(unsigned char), fp);
    fread(&head.fileID[3], 1, sizeof(unsigned char), fp);
    fread(&head.length, 1, sizeof(head.length), fp);
    fread(&head.format, 1, sizeof(head.format), fp);
    fread(&head.n, 1, sizeof(head.n), fp);
    fread(&head.division, 1, sizeof(head.division), fp);
    
    printf("File pointer position: %ld", ftell(fp));
    
    printf("\nMIDI Headers:\nFile Descriptor : %s\nLength : %d\nFormat : %d\nN : %d\nDivision : %d", head.fileID, head.length, head.format, head.n, head.division);
    return 0;
}