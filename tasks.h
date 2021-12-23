#ifndef TASKS_H
#define TASKS_H

const int WORD_LEN = 50;

/***
 * Master process. 
 * Reads the text file and sends words to other processes,
 * receives the results, and outputs them.
***/
void Master(int num_proc);

/***
 * Worker process. 
 * Receives a word from the master process, encrypts
 * it, then sends it back to the master.
***/
void Worker(int my_id, int num_proc);

#endif
