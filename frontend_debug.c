#include "networkedinput.h"

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
#include <stdio.h>
int main() {
  NI_Init();
  NI_Data bindata = {0};

  unsigned x = 0, checksum = 0, checksum_old = 0;
  while (1) {
	for(unsigned i = 0; i < 17; i++) {
		checksum_old += bindata.dat[i];	
	}
	bindata = NI_FetchInput();

	for(unsigned i = 0; i < 17; i++) {
		checksum += bindata.dat[i];	
	}
	if (checksum_old != checksum) {
      printf("ITERATION %i:\n Packet:\n[%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i]\n\n]",
             x, bindata.dat[0], bindata.dat[1], bindata.dat[2],
             bindata.dat[3], bindata.dat[4], bindata.dat[5],
             bindata.dat[6], bindata.dat[7], bindata.dat[8],
             bindata.dat[9], bindata.dat[10], bindata.dat[11],
             bindata.dat[12], bindata.dat[13], bindata.dat[14],
             bindata.dat[15], bindata.dat[16]);
             x++;
	}
	checksum = 0;
	checksum_old = 0;
  }
}
