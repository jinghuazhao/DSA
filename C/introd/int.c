#include <stdint.h>
#include <stdio.h>

int main()
{
signed char a=-1;
short int b=-2;
int c=-3;

unsigned char x=1;
unsigned short int y=2;
unsigned int z=3;

printf("a=%d b=%d c=%d, x=%d y=%d z=%d\n",a,b,c,x,y,z);

return 0;

}

void int8(int *a,signed char *b) {*b=*a;}
void int16(int *a,short int *b) {*b=*a;}
void int32(int *a,int *b) {*b=*a;}

void uint8(int *a,unsigned char *b) {*b=*a;}
void uint16(int *a,unsigned short int *b) {*b=*a;}
void uint32(int *a,unsigned int *b) {*b=*a;}

