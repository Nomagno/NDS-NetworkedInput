#include <stdint.h>
#include <limits.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "networkedinput.h"

struct sockaddr_in servaddr, cliaddr;
uint8_t buffer[4];
unsigned sock;

void get_input_packet(void) {
  recvfrom(sock, buffer, MAXLINE, MSG_WAITALL,
                     (struct sockaddr *)&cliaddr, &(socklen_t){ sizeof(cliaddr) });
}

unsigned NI_Init(void) {
  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    return 1; /*Could not create socket*/
  }
  servaddr = (struct sockaddr_in){0};
  cliaddr = (struct sockaddr_in){0};
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  if (bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    return 2; /*Could not bind socket*/
  }
  return 0;
}

_Bool bitindex(uint8_t *arr, unsigned index){
	_Bool retval;
	retval = (arr[index / 8] << (index % 8)) & 128;
	return retval;
}

/*
  Structure of the returned _Bool array:
  CDOWN CUP CLEFT CRIGHT TOUCH Y X L R DOWN UP LEFT RIGHT START SELECT B A
*/
NI_Data NI_FetchInput(void) {
  NI_Data retval = {0};
  get_input_packet();
  for(unsigned i = 0, j = 0; i < 32 || j < 17; i++){
    if(i <= 3 || i == 11 || i >= 20)
      retval.dat[j] = bitindex(buffer, i), j++;
  }
  return retval;
}
