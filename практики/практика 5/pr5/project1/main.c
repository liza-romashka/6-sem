#include <8051.h>

void main() {
	unsigned int i,j,k;
	unsigned char* out;
	unsigned char* alph[] = {"01","02","03","04","05",
							 "06","07","08","09","10",
							 "11","12","13","14","15",
							 "16","17","18","19","20",
							 "21","22","23","24","25"};
	unsigned char row[5] = {0xFE,0xFD,0xFB,0xF7,0xEF};
	unsigned char col[5] = {0x1E,0x1D,0x1B,0x17,0x0F};
	
	while(1) {
		for (i = 0; i<5; i++) {
			P3 = col[i];
			for (j = 0;	j<5; j++) {
				if (P1 == row[j]) {
					P0 = 0xC;
					P2 = 0x1;
					P2 = 0x0;
					P0 = 0x38;
					P2 = 0x1;
					P2 = 0x0;
					P0 = 0x80;
					P2 = 0x1;
					P2 = 0x0;
					out = alph[i+j*5];
					for (k = 0; k<2; k++) {
						P0 = out[k];
						P2 = 0x3;
						P2 = 0x2;
					}
				}
			}
		}
	}
}
