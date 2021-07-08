#include "../NDS_server_library/nds_server_library.c"
#include "winuser_alpha_headers.h"
#include <stdio.h>
#include <winuser.h>
/*TO CHANGE BINDINGS, USE YOUR EDITOR'S SEARCH FEATURE
TO FIND THE NDS/3DS BUTTON YOU WANT TO REBIND IN QUESTION*/

/* CHANGE "VK_X" where X is the key you want for each binding */
/* MAKE SURE TO CHANGE IT ON THE "Section PRESS" AS WELL AS THE "Section
 * RELEASE" */

/*AVAILABLE SELECTION:*/

/*"CIRCLE PAD {DOWN UP LEFT RIGHT}"  "TOUCH" "Y BUTTON" "X BUTTON" "L BUMPER"
"R BUMPER" "DPAD {DOWN UP LEFT RIGHT}" "START "SELECT" "B BUTTON" "A BUTTON"*/

int main() {

  create_socket();
  printf("Default Mappings: <[DPAD - ARROWS] [B A Y X L R SELECT START - Z X C "
         "V B N F G]\n [CIR_PAD] - [W A S D] [TOUCH] - [M]\n");

  int offset = 17;
  int k;

  INPUT inputs[34] = {};
  ZeroMemory(inputs, sizeof(inputs));

  // Section PRESS
  inputs[0].type = INPUT_KEYBOARD; // CIRCLE PAD DOWN
  inputs[0].ki.wVk = VK_S;

  inputs[1].type = INPUT_KEYBOARD; // CIRCLE PAD UP
  inputs[1].ki.wVk = VK_W;

  inputs[2].type = INPUT_KEYBOARD; // CIRCLE PAD LEFT
  inputs[2].ki.wVk = VK_A;

  inputs[3].type = INPUT_KEYBOARD; // CIRCLE PAD RIGHT
  inputs[3].ki.wVk = VK_D;

  inputs[4].type = INPUT_KEYBOARD; // TOUCH
  inputs[4].ki.wVk = VK_M;

  inputs[5].type = INPUT_KEYBOARD; // Y BUTTON
  inputs[5].ki.wVk = VK_C;

  inputs[6].type = INPUT_KEYBOARD; // X BUTTON
  inputs[6].ki.wVk = VK_V;

  inputs[7].type = INPUT_KEYBOARD; // L BUMPER
  inputs[7].ki.wVk = VK_B;

  inputs[8].type = INPUT_KEYBOARD; // R BUMPER
  inputs[8].ki.wVk = VK_N;

  inputs[9].type = INPUT_KEYBOARD; // DPAD DOWN
  inputs[9].ki.wVk = VK_DOWN;

  inputs[10].type = INPUT_KEYBOARD; // DPAD UP
  inputs[10].ki.wVk = VK_UP;

  inputs[11].type = INPUT_KEYBOARD; // DPAD LEFT
  inputs[11].ki.wVk = VK_LEFT;

  inputs[12].type = INPUT_KEYBOARD; // DPAD RIGHT
  inputs[12].ki.wVk = VK_RIGHT;

  inputs[13].type = INPUT_KEYBOARD; // START
  inputs[13].ki.wVk = VK_F;

  inputs[14].type = INPUT_KEYBOARD; // SELECT
  inputs[14].ki.wVk = VK_G;

  inputs[15].type = INPUT_KEYBOARD; // B BUTTON
  inputs[15].ki.wVk = VK_Z;

  inputs[16].type = INPUT_KEYBOARD; // A BUTTON
  inputs[16].ki.wVk = VK_X;

  // Section RELEASE
  inputs[17].type = INPUT_KEYBOARD; // CIRCLE PAD DOWN
  inputs[17].ki.wVk = VK_S;
  inputs[17].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[18].type = INPUT_KEYBOARD; // CIRCLE PAD UP
  inputs[18].ki.wVk = VK_W;
  inputs[18].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[19].type = INPUT_KEYBOARD; // CIRCLE PAD LEFT
  inputs[19].ki.wVk = VK_A;
  inputs[19].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[20].type = INPUT_KEYBOARD; // CIRCLE PAD RIGHT
  inputs[20].ki.wVk = VK_D;
  inputs[20].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[21].type = INPUT_KEYBOARD; // TOUCH
  inputs[21].ki.wVk = VK_M;
  inputs[21].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[22].type = INPUT_KEYBOARD; // Y BUTTON
  inputs[22].ki.wVk = VK_C;
  inputs[22].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[23].type = INPUT_KEYBOARD; // X BUTTON
  inputs[23].ki.wVk = VK_V;
  inputs[23].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[24].type = INPUT_KEYBOARD; // L BUMBER
  inputs[24].ki.wVk = VK_B;
  inputs[24].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[25].type = INPUT_KEYBOARD; // R BUMPER
  inputs[25].ki.wVk = VK_N;
  inputs[25].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[26].type = INPUT_KEYBOARD; // DPAD DOWN
  inputs[26].ki.wVk = VK_DOWN;
  inputs[26].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[27].type = INPUT_KEYBOARD; // DPAD UP
  inputs[27].ki.wVk = VK_UP;
  inputs[27].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[28].type = INPUT_KEYBOARD; // DPAD LEFT
  inputs[28].ki.wVk = VK_LEFT;
  inputs[28].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[29].type = INPUT_KEYBOARD; // DPAD RIGHT
  inputs[29].ki.wVk = VK_RIGHT;
  inputs[29].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[30].type = INPUT_KEYBOARD; // START
  inputs[30].ki.wVk = VK_F;
  inputs[30].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[31].type = INPUT_KEYBOARD; // SELECT
  inputs[31].ki.wVk = VK_G;
  inputs[31].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[32].type = INPUT_KEYBOARD; // B BUTTON
  inputs[32].ki.wVk = VK_Z;
  inputs[32].ki.dwFlags = KEYEVENTF_KEYUP;

  inputs[33].type = INPUT_KEYBOARD; // A BUTTON
  inputs[33].ki.wVk = VK_X;
  inputs[33].ki.dwFlags = KEYEVENTF_KEYUP;

  while (true) {
    get_controls(groupdef_bool);
    for (k = 0; k < 17; k++) {
      switch (k) {
      case 0:
        // CIRCLE PAD DOWN
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 1:
        // CIRCLE PAD UP
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 2:
        // CIRCLE LEFT
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 3:
        // CIRCLE PAD RIGHT
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 4:
        // TOUCH SCREEN TAP
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 5:
        // Y BUTTON
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 6:
        // X BUTTON
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 7:
        // L BUMPER/TRIGGER
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 8:
        // R BUMPER/TRIGGER
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 9:
        // DPAD DOWN
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 10:
        // DPAD UP
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 11:
        // DPAD LEFT
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 12:
        // DPAD RIGHT
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 13:
        // SELECT
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 14:
        // START
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 15:
        // B BUTTON
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      case 16:
        // A BUTTON
        if (groupdef_bool[k]) {
          SendInput(1, &inputs[k], sizeof(INPUT));
        }

        else {
          SendInput(1, &inputs[k + offset], sizeof(INPUT));
        }
        break;
      }
    }
  }
}
