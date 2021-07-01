#include "nds_input_server.c"

int main(void) {
  // get_controls modifies a bool array it is passed
  // this is what each of the bools (left being index 0
  // and right index 16) map to:
  // [CDOWN CUP CLEFT CRIGHT  TOUCH Y X L R DOWN UP LEFT RIGHT START SELECT B A]
  // Print the output for debugging purposes
  create_socket();
  while (true) {
    get_controls(groupdef_bool);
    printf("ITERATION %i:\n Packet:\n[%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i]\n]",
           x, groupdef_bool[0], groupdef_bool[1], groupdef_bool[2],
           groupdef_bool[3], groupdef_bool[4], groupdef_bool[5],
           groupdef_bool[6], groupdef_bool[7], groupdef_bool[8],
           groupdef_bool[9], groupdef_bool[10], groupdef_bool[11],
           groupdef_bool[12], groupdef_bool[13], groupdef_bool[14],
           groupdef_bool[15], groupdef_bool[16]);
    x++;
  }
}
