#include <linux/uinput.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../NDS_server_library/nds_input_server.h"

/*TO CHANGE BINDINGS, USE YOUR EDITOR'S SEARCH FEATURE 
TO FIND THE NDS/3DS BUTTON YOU WANT TO REBIND IN QUESTION*/

/*TO CHANGE BINDINGS, USE YOUR EDITOR'S SEARCH FEATURE 
TO FIND THE NDS/3DS BUTTON YOU WANT TO REBIND IN QUESTION*/

/* CHANGE BOTH (THERE ARE TWO) "KEY_X" where X is the key you want for each binding" */

/* CHANGE BOTH (THERE ARE TWO) "KEY_X" where X is the key you want for each binding" */

/*AVAILABLE SELECTION:*/
 
/*"CIRCLE PAD {DOWN UP LEFT RIGHT}"  "TOUCH" "Y BUTTON" "X BUTTON" "L BUMPER" "R BUMPER" "DPAD {DOWN UP LEFT RIGHT}" "START "SELECT" "B BUTTON" "A BUTTON"*/

  
int k;
void emit(int fd, int type, int code, int val)
{
   struct input_event ie;

   ie.type = type;
   ie.code = code;
   ie.value = val;

   write(fd, &ie, sizeof(ie));
}

int main(void)
{
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
	usetup.id.vendor = 0x1234; /* sample vendor */
	usetup.id.product = 0x5678; /* sample product */
	strcpy(usetup.name, "Example device");

	ioctl(fd, UI_DEV_SETUP, &usetup);
	ioctl(fd, UI_DEV_CREATE);
	create_socket();
	printf("Default Mappings: <[DPAD - ARROWS] [B A Y X L R SELECT START - Z X C V B N F G]\n [CIR_PAD] - [W A S D] [TOUCH] - [M]");

	while (true) {
	get_controls(groupdef_bool);
	for (k = 0; k<17; k++){
		switch(k){
			case 0: if ((groupdef_bool[k]) && (k==0)) { //CIRCLE PAD DOWN
					emit(fd, EV_KEY, KEY_S, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0); 
		} else {
					emit(fd, EV_KEY, KEY_S, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			case 1: if ((groupdef_bool[k]) && (k==1))  { //CIRCLE PAD UP
					emit(fd, EV_KEY, KEY_W, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_W, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			case 2: if ((groupdef_bool[k]) && (k==2)) { //CIRCLE LEFT
					emit(fd, EV_KEY, KEY_A, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_A, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			case 3: if ((groupdef_bool[k]) & (k==3)) { //CIRCLE PAD RIGHT
					emit(fd, EV_KEY, KEY_D, 1); 
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_D, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}

			case 4: if ((groupdef_bool[k]) & (k==4)) { //TOUCH SCREEN TAP
					emit(fd, EV_KEY, KEY_M, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_M, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}

			case 5: if ((groupdef_bool[k]) & (k==5)) { //Y BUTTON
					emit(fd, EV_KEY, KEY_C, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_C, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}

			case 6: if ((groupdef_bool[k]) & (k==6)) { //X BUTTON
					emit(fd, EV_KEY, KEY_V, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_V, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0); 
					}

			case 7: if ((groupdef_bool[k]) & (k==7)) { //L BUMPER/TRIGGER 
					emit(fd, EV_KEY, KEY_B, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_B, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
					
			case 8: if ((groupdef_bool[k]) & (k==8)) { //R BUMPER/TRIGGER
					emit(fd, EV_KEY, KEY_N, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_N, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
					
			case 9: if ((groupdef_bool[k]) & (k==9)) { //DPAD DOWN
					emit(fd, EV_KEY, KEY_DOWN, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_DOWN, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			
			case 10: if ((groupdef_bool[k]) & (k==10)) { //DPAD UP
					emit(fd, EV_KEY, KEY_UP, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_UP, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			
			case 11: if ((groupdef_bool[k]) & (k==11)) { //DPAD LEFT
					emit(fd, EV_KEY, KEY_LEFT, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_LEFT, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			
			case 12: if ((groupdef_bool[k]) & (k==12)) { //DPAD RIGHT
					emit(fd, EV_KEY, KEY_RIGHT, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_RIGHT, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
					
			case 13: if ((groupdef_bool[k]) & (k==13)) { //SELECT
					emit(fd, EV_KEY, KEY_F, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_F, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
			case 14: if ((groupdef_bool[k]) & (k==14)) { //START
					emit(fd, EV_KEY, KEY_G, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_G, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}
					
			case 15: if ((groupdef_bool[k]) & (k==15)) { //B BUTTON
					emit(fd, EV_KEY, KEY_Z, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_Z, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}

			case 16: if ((groupdef_bool[k]) & (k==16)) { //A BUTTON
					emit(fd, EV_KEY, KEY_X, 1);
   					emit(fd, EV_SYN, SYN_REPORT, 0);
		} else {
					emit(fd, EV_KEY, KEY_X, 0);
					emit(fd, EV_SYN, SYN_REPORT, 0);
					}


			}
	}

}

   ioctl(fd, UI_DEV_DESTROY);
   close(fd);

   return 0;
}
