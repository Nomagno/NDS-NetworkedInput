#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 3210
#define MAXLINE 5

extern int x;
extern bool groupdef_bool[];


void get_input_packet(void);

void create_socket(void);

void int_to_bin(int, char[]);

extern void get_controls(bool[]);
