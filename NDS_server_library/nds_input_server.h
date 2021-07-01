#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 3210
#define MAXLINE 32

#if defined(__unix__) || defined(__unix) ||                                    \
    (defined(__APPLE__) && defined(__MACH__))

// Unix-like
#include <arpa/inet.h>
#include <sys/socket.h>
socklen_t len;
int buffer[1];
int sock;

#endif

#if defined(_WIN32)

// Windows
#include <winsock.h>
#include <windows.h>
int len;
int buffer[1];
SOCKET sock;

#endif

char *buffer_bin;
char groupdef[18];

int x = 0, i, f;
int recvtmp;

bool groupdef_bool[17];

struct sockaddr_in servaddr, cliaddr;
void get_input_packet(void);
// Gets any incoming packages

void create_socket(void);

char *int_to_bin();

void get_controls();
