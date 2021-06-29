#include "../NDS_server_library/nds_input_server.h"
#include <fcntl.h>
#include <linux/uinput.h>
#include <string.h>
#include <unistd.h>

/*TO CHANGE BINDINGS, USE YOUR EDITOR'S SEARCH FEATURE
TO FIND THE NDS/3DS BUTTON YOU WANT TO REBIND IN QUESTION*/

/* CHANGE "KEY_X" where X is the key you want for each binding */
/* MAKE SURE TO ALSO CHANGE IT ON THE CORRESPONDING ioctl() AT THE START OF THE main() FUNCTION */

/*AVAILABLE SELECTION:*/

/*"CIRCLE PAD {DOWN UP LEFT RIGHT}"  "TOUCH" "Y BUTTON" "X BUTTON" "L BUMPER" "R
 * BUMPER" "DPAD {DOWN UP LEFT RIGHT}" "START "SELECT" "B BUTTON" "A BUTTON"*/

int k;
void emit(int fd, int type, int code, int val) {
  struct input_event ie;

  ie.type = type;
  ie.code = code;
  ie.value = val;

  write(fd, &ie, sizeof(ie));
}

int main(void) {
  struct uinput_setup usetup;
  int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);

  ioctl(fd, UI_SET_EVBIT, EV_KEY);

  ioctl(fd, UI_SET_KEYBIT, KEY_DOWN);
  ioctl(fd, UI_SET_KEYBIT, KEY_UP);
  ioctl(fd, UI_SET_KEYBIT, KEY_LEFT);
  ioctl(fd, UI_SET_KEYBIT, KEY_RIGHT);

  ioctl(fd, UI_SET_KEYBIT, KEY_F);
  ioctl(fd, UI_SET_KEYBIT, KEY_G);

  ioctl(fd, UI_SET_KEYBIT, KEY_Z);
  ioctl(fd, UI_SET_KEYBIT, KEY_X);
  ioctl(fd, UI_SET_KEYBIT, KEY_C);
  ioctl(fd, UI_SET_KEYBIT, KEY_V);

  ioctl(fd, UI_SET_KEYBIT, KEY_B);
  ioctl(fd, UI_SET_KEYBIT, KEY_N);

  ioctl(fd, UI_SET_KEYBIT, KEY_M);

  ioctl(fd, UI_SET_KEYBIT, KEY_W);
  ioctl(fd, UI_SET_KEYBIT, KEY_A);
  ioctl(fd, UI_SET_KEYBIT, KEY_S);
  ioctl(fd, UI_SET_KEYBIT, KEY_D);

  memset(&usetup, 0, sizeof(usetup));
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x1234;  /* sample vendor */
  usetup.id.product = 0x5678; /* sample product */
  strcpy(usetup.name, "Example device");

  ioctl(fd, UI_DEV_SETUP, &usetup);
  ioctl(fd, UI_DEV_CREATE);
  create_socket();
  printf("Default Mappings: <[DPAD - ARROWS] [B A Y X L R SELECT START - Z X C "
         "V B N F G]\n [CIR_PAD] - [W A S D] [TOUCH] - [M]\n");

  while (true) {
    get_controls(groupdef_bool);
    for (k = 0; k < 17; k++) {
      switch (k) {
      case 0:
          //CIRCLE PAD DOWN
          emit(fd, EV_KEY, KEY_W, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 1:
          // CIRCLE PAD UP
          emit(fd, EV_KEY, KEY_S, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 2:
          // CIRCLE LEFT
          emit(fd, EV_KEY, KEY_A, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 3:
          // CIRCLE PAD RIGHT
          emit(fd, EV_KEY, KEY_D, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 4:
          // TOUCH SCREEN TAP
          emit(fd, EV_KEY, KEY_M, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 5:
          // Y BUTTON
          emit(fd, EV_KEY, KEY_C, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 6:
          // X BUTTON
          emit(fd, EV_KEY, KEY_V, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 7:
          // L BUMPER/TRIGGER
          emit(fd, EV_KEY, KEY_B, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 8:
          // R BUMPER/TRIGGER
          emit(fd, EV_KEY, KEY_N, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 9:
          // DPAD DOWN
          emit(fd, EV_KEY, KEY_DOWN, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 10:
          // DPAD UP
          emit(fd, EV_KEY, KEY_UP, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;


      case 11:
          // DPAD LEFT
          emit(fd, EV_KEY, KEY_LEFT, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 12:
          // DPAD RIGHT
          emit(fd, EV_KEY, KEY_RIGHT, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 13:
          // SELECT
          emit(fd, EV_KEY, KEY_F, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 14:
      	  // START
          emit(fd, EV_KEY, KEY_G, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 15:
           // B BUTTON
          emit(fd, EV_KEY, KEY_Z, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 16:
          // A BUTTON
          emit(fd, EV_KEY, KEY_X, groupdef_bool[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      }
    }
  }

  ioctl(fd, UI_DEV_DESTROY);
  close(fd);

  return 0;
}
