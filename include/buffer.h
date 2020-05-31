#ifndef BUFFER_H
#define BUFFER_H

#define BS 256

char c_buff[BS];
int r_p; // read pointer
int w_p; // write pointer
int count; //contador de posicions

int read_buffer(char *c);
int write_buffer(char c);

#endif  /* BUFFER_H */
