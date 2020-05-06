#ifndef BUFFER_HH
#define BUFFER_HH

#define BS 256

int r_p = 0; // read pointer
int w_p = 0; // write pointer

char read_buffer(char *c);
void write_buffer(char c);

#endif