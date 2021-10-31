#define PORT 3210
#define MAXLINE 5

extern _Bool groupdef_bool[];


void get_input_packet(void);

void create_socket(void);

void int_to_bin(int, char[]);

extern void get_controls(_Bool[]);
