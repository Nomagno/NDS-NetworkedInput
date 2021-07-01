#include "nds_server_library.h"

void get_input_packet() {
// Gets any incoming packages
#if defined(_WIN32)
  recvtmp = recvfrom(sock, (int)buffer, MAXLINE, MWMO_WAITALL,
                     (struct sockaddr *)&cliaddr, &len);
#endif

#if defined(__unix__) || defined(__unix) ||                                    \
    (defined(__APPLE__) && defined(__MACH__))
  recvtmp = recvfrom(sock, (unsigned int *)buffer, MAXLINE, MSG_WAITALL,
                     (struct sockaddr *)&cliaddr, &len);
#endif
}

void create_socket() {
#if defined(_WIN32)

  static WSADATA wsa;
  WSAStartup(MAKEWORD(2, 2), &wsa);

#endif

  // Creates socket
  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Could not create socket\n");
  } else {
    printf("Socket created successfully\n");
  }
  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  // Fills standard info
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  // Binds the socket with the server address
  if (bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Could not bind socket\n");
  } else {
    printf("Socket binded successfully\nListening for client input, take note "
           "of this devices's IPv4 address.\n");
  }

  len = sizeof(cliaddr);
}

char *int_to_bin(int n) {
  /*Binary operations to transform a base
    10 integer into a string of bits*/
  int c, d, t;
  char *p;

  t = 0;
  p = (char *)malloc(32 + 1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31; c >= 0; c--) {
    d = n >> c;

    if (d & 1)
      *(p + t) = 1 + '0';
    else
      *(p + t) = 0 + '0';

    t++;
  }

  return p;
}

void get_controls(bool control_output[17]) {
  /*Requires it to be passed an 12 element bool array,
  and checks it against the controls being received.
  structure of the array (False = not pressed, true = pressed):
  CDOWN CUP CLEFT CRIGHT  TOUCH Y X L R DOWN UP LEFT RIGHT START SELECT B A*/
  get_input_packet();
  buffer_bin = int_to_bin(buffer[0]);
  strncpy(groupdef + 9, buffer_bin, sizeof(groupdef) - 10);
  strncpy(groupdef + 5, buffer_bin + 12, sizeof(groupdef) - 14);
  strncpy(groupdef + 4, buffer_bin + 19, sizeof(groupdef) - 17);
  strncpy(groupdef, buffer_bin + 24, sizeof(groupdef) - 14);
  groupdef[sizeof(groupdef) - 1] = '\0';

  for (i = 0; i < 17; i++) {
    switch (groupdef[i]) {
    case '0':
      control_output[i] = false;
      break;
    case '1':
      control_output[i] = true;
      break;
    }
  }
}

/*
int debug(void) {
    while (true) {

                get_controls(groupdef_bool);
                //Print the output for debugging purposes
                printf("ITERATION %i:\n Packet:\n[%i%i%i%i%i%i%i%i%i%i%i%i]\nG",
                x, groupdef_bool[0], groupdef_bool[1], groupdef_bool[2],
                 groupdef_bool[3], groupdef_bool[4], groupdef_bool[5],
groupdef_bool[6], groupdef_bool[7], groupdef_bool[8], groupdef_bool[9],
                groupdef_bool[10], groupdef_bool[11]);
                        }
}
*/
