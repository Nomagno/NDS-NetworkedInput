#include "networkedinput.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
The MIT License (MIT)

Copyright (c) 2021, 2022 Nomagno

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifdef __linux__
#include <uinput.h>
#else
#include <dev/evdev/uinput.h>
#endif


/*TO CHANGE BINDINGS, CHANGE THE VALUE *AFTER* "NI_FOO"
  WHERE FOO IS THE BUTTON YOU WANT TO MAP TO*/

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

#define NI_UP KEY_UP
#define NI_DOWN KEY_DOWN
#define NI_LEFT KEY_LEFT
#define NI_RIGHT KEY_RIGHT
#define NI_SELECT KEY_F
#define NI_START KEY_G
#define NI_B KEY_Z
#define NI_A KEY_X
#define NI_Y KEY_C
#define NI_X KEY_V
#define NI_L KEY_B
#define NI_R KEY_N
#define NI_CIR_UP KEY_W
#define NI_CIR_DOWN KEY_S
#define NI_CIR_LEFT KEY_A
#define NI_CIR_RIGHT KEY_D
#define NI_TOUCH KEY_M

int main() {
  struct uinput_setup usetup;
  int fd = open("/dev/uinput", O_RDWR);

  ioctl(fd, UI_SET_EVBIT, EV_KEY);

  ioctl(fd, UI_SET_KEYBIT, NI_DOWN);
  ioctl(fd, UI_SET_KEYBIT, NI_UP);
  ioctl(fd, UI_SET_KEYBIT, NI_LEFT);
  ioctl(fd, UI_SET_KEYBIT, NI_RIGHT);

  ioctl(fd, UI_SET_KEYBIT, NI_SELECT);
  ioctl(fd, UI_SET_KEYBIT, NI_START);

  ioctl(fd, UI_SET_KEYBIT, NI_B);
  ioctl(fd, UI_SET_KEYBIT, NI_A);
  ioctl(fd, UI_SET_KEYBIT, NI_Y);
  ioctl(fd, UI_SET_KEYBIT, NI_X);

  ioctl(fd, UI_SET_KEYBIT, NI_L);
  ioctl(fd, UI_SET_KEYBIT, NI_R);

  ioctl(fd, UI_SET_KEYBIT, NI_TOUCH);

  ioctl(fd, UI_SET_KEYBIT, NI_CIR_UP);
  ioctl(fd, UI_SET_KEYBIT, NI_CIR_DOWN);
  ioctl(fd, UI_SET_KEYBIT, NI_CIR_LEFT);
  ioctl(fd, UI_SET_KEYBIT, NI_CIR_RIGHT);

  memset(&usetup, 0, sizeof(usetup));
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x1234;  /* sample vendor */
  usetup.id.product = 0x5678; /* sample product */
  strcpy(usetup.name, "Example device");

  ioctl(fd, UI_DEV_SETUP, &usetup);
  ioctl(fd, UI_DEV_CREATE);

  
  printf("Default Mappings: <[DPAD - ARROWS] [B A Y X L R SELECT START - Z X C "
         "V B N F G]\n [CIR_PAD] - [W A S D] [TOUCH] - [M]\n");

  NI_Init();
  NI_Data data = {0};
  
  while (1) {
    data = NI_FetchInput();
    for (k = 0; k < 17; k++) {
      switch (k) {
      case 0:
          //CIRCLE PAD UP
          emit(fd, EV_KEY, NI_CIR_UP, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 1:
          // CIRCLE PAD DOWN
          emit(fd, EV_KEY, NI_CIR_DOWN, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 2:
          // CIRCLE LEFT
          emit(fd, EV_KEY, NI_CIR_LEFT, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 3:
          // CIRCLE PAD RIGHT
          emit(fd, EV_KEY, NI_CIR_RIGHT, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 4:
          // TOUCH SCREEN TAP
          emit(fd, EV_KEY, NI_TOUCH, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 5:
          // Y BUTTON
          emit(fd, EV_KEY, NI_Y, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 6:
          // X BUTTON
          emit(fd, EV_KEY, NI_X, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 7:
          // L BUMPER/TRIGGER
          emit(fd, EV_KEY, NI_L, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 8:
          // R BUMPER/TRIGGER
          emit(fd, EV_KEY, NI_R, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 9:
          // DPAD UP
          emit(fd, EV_KEY, NI_UP, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 10:
          // DPAD DOWN
          emit(fd, EV_KEY, NI_DOWN, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;


      case 11:
          // DPAD LEFT
          emit(fd, EV_KEY, NI_LEFT, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 12:
          // DPAD RIGHT
          emit(fd, EV_KEY, NI_RIGHT, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 13:
          // SELECT
          emit(fd, EV_KEY, NI_SELECT, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 14:
      	  // START
          emit(fd, EV_KEY, NI_START, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      case 15:
           // B BUTTON
          emit(fd, EV_KEY, NI_B, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;

      case 16:
          // A BUTTON
          emit(fd, EV_KEY, NI_A, data.dat[k]);
          emit(fd, EV_SYN, SYN_REPORT, 0); break;
      }
    }
  }

  ioctl(fd, UI_DEV_DESTROY);
  close(fd);

  return 0;
}
