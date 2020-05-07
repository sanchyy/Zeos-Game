#ifndef BUFFER_H
#define BUFFER_H

#define BS 256

char c_buff[BS];
int r_p = 0; // read pointer
int w_p = 0; // write pointer

int read_buffer(char *c);
int write_buffer(char c);

#endif  /* BUFFER_H */
