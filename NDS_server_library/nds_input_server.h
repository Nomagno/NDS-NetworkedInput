#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h> 
#include <stdlib.h>

#define PORT 3210
#define MAXLINE 5

char *buffer_bin;
char group1[8];
char group2[4];
unsigned int x; 
int buffer[1];
int recvtmp;
int sock;
socklen_t len;
struct sockaddr_in servaddr, cliaddr;



void get_input_packet() {
	// Gets any incoming packages
		recvtmp = recvfrom(sock, (unsigned int * ) buffer, MAXLINE,
        MSG_WAITALL, (struct sockaddr * ) & cliaddr, &
        len);
}


void create_socket() {

    // Creates socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Could not create socket");
    } else {
        printf("Socket created successfully\n");
    }
    memset( & servaddr, 0, sizeof(servaddr));
    memset( & cliaddr, 0, sizeof(cliaddr));

    // Fills standard info
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Binds the socket with the server address
    if (bind(sock, (const struct sockaddr * ) & servaddr, sizeof(servaddr)) < 0) {
        perror("Could not bind socket");
    } else {
        printf("Socket binded successfully\nListening for client input, enter IP: "
            "[TO BE IMPLEMENTED]\n");
    }

    len = sizeof(cliaddr);
}

char *int_to_bin(int n)
{
  /*Binary operations to transform a base 
    10 integer into a string of bits*/
  int c, d, t;
  char *p;

  t = 0;
  p = (char*)malloc(32+1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(p+t) = 1 + '0';
    else
      *(p+t) = 0 + '0';

    t++;
  }
  *(p+t) = '\0';

  return  p;
}

int debug(void) {
    create_socket();
    while (true) {
        get_input_packet();
		buffer_bin  = int_to_bin(buffer[0]);
		strncpy(group1, buffer_bin, 8);
		group1[8] = '\0';
		strncpy(group2, buffer_bin + 12, 4);
		group2[4] = '\0';		
		//Print the output for debugging purposes
		printf("ITERATION %i:\n GROUP1 [%s]\n GROUP2 [%s]\n", x, group1, group2);

		x++;
			}
}
