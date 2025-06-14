#include <8051.h>
void tput(unsigned char c1)
{
	SBUF=c1;
	while(!TI); 
	TI=0; 
}
void init_serial()
{
	PCON_BITS.B7 = 1; 
  	TMOD_BITS.B6 = 0; 
  	TMOD_BITS.B4 = 0; 
  	TMOD_BITS.B5 = 1;
  	TH1 = 0x0FD;  
  	TR1 = 1; 
	SCON = 0;
	SCON_BITS.B3 = 0;
  	SCON_BITS.B4 = 0;  
  	SCON_BITS.B5 = 0; 
  	SCON_BITS.B6 = 1; 
  	SCON_BITS.B7 = 0; 
}
void main()
{
	int i;
	char xdata *ptr;
	ptr = (char xdata *) 0x50;
    ptr[0] = 'h';
    ptr[1] = 'o';
    ptr[2] = 's';
    ptr[3] = 'p';
    ptr[4] = 'i';
    ptr[5] = 't';
    ptr[6] = 'a';
    ptr[7] = 'l';
    ptr[8] = 'i';
    ptr[9] = 's';
	ptr[10] = 'a';
	ptr[11] = 't';
	ptr[12] = 'i';
	ptr[13] = 'o';
	ptr[14] = 'n';
	init_serial();
	while(1){
		for(i=0; i<15; i++)
		{
			tput(ptr[i]);
		}
	}
}
