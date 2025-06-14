#include <8051.h>
void main() {
	unsigned i,j,k,a,n;
	unsigned char massiv[11] = {
		0xC0,
		0xF9,
		0xA4,
		0xB0,
		0x99,
		0x92,
		0x82,
		0xF8,
		0x80,
		0x90,
		0xFF
	};
	P2 = massiv[10];
	P3 = 0;
	i = 0;
	k = 2;
	a = 0;
	while (1) {
		n = 0;
		P2 = massiv[i];
		i += 1;
		if (i > 9) i = 0;
		
		while (n<75) {
			if (P30 == 1) {
				a = 1;
				P2 = massiv[9];
				break;
			}
			n += 1;
		}
		
		while(a) {
			while (P30 == 1) {
				if (k < 10) P2 = massiv[9-k];
				k += 2;
				if (k > 10) {
					k = 0;
					a = 0;
				}
			}
		}
	}
}
