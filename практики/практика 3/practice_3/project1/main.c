#include <8051.h>
void main() {
	unsigned int i,j,k;
	unsigned int pos = 0xCF;
	unsigned char str1[] = {0xB1, 0xA0, 0xB2, 0xB3, 0xA9, 0xB9, 0xAB, 0xA0, 0x00};
	//unsigned char str1[] = {0xA1, 0xAF, 0xAE, 0xA7, 0xB4, 0xB1, 0x00}; //bonjour
	unsigned char str2[] = {0xAB, 0xAF, 0xB9, 0xAB, 0xA0, 0x00};
	unsigned char len1 = 0, len2 = 0;
	while (str1[len1] != '\0') len1++;
	while (str2[len2] != '\0') len2++;
	P0 = 0xC;
	P2 = 0x1;
	P2 = 0x0;
	P0 = 0x38;
	P2 = 0x1;
	P2 = 0x0;
	P0 = 0x88;
	P2 = 0x1;
	P2 = 0x0;
	for (i = 0; i<len1; i++) {
		P0 = str1[i];
		P2 = 0x3;
		P2 = 0x2;
	}
	while(1) {
		j = 0;
		while (j != 15) {
			if (j < len2) {
				P0 = pos;
				P2 = 0x1;
				P2 = 0x0;
				for (i = 0; i < j+1; i++) {
					P0 = str2[i];
					P2 = 0x3;
					P2 = 0x2;
				}
			}
			else {
				P0 = pos;
				P2 = 0x1;
				P2 = 0x0;
				for (i = 0; i < len2; i++) {
					P0 = str2[i];
					P2 = 0x3;
					P2 = 0x2;
				}
				P0 = " ";
				P2 = 0x3;
				P2 = 0x2;
			}
			pos -= 1;
			j += 1;
		}
		k = len2;
		while (k != -1) {
			P0 = 0xC0;
			P2 = 0x1;
			P2 = 0x0;
			for (i = len2-k; i < len2; i++) {
				P0 = str2[i];
				P2 = 0x3;
				P2 = 0x2;	
			}
			P0 = " ";
			P2 = 0x3;
			P2 = 0x2;
			k -= 1;
		}
		pos = 0xCF;
	}
}
