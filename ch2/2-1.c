#include <stdio.h>
#include <limits.h>

int main() {
    printf("----------FROM LIMITS.H----------\n");
    printf("  signed char : [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char : [%d, %d]\n", 0, UCHAR_MAX);
    printf("  signed short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: [%d, %d]\n", 0, USHRT_MAX);
    printf("  signed int  : [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int  : [%d, %u]\n", 0, UINT_MAX);
    printf("  signed long : [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long : [%d, %lu]\n", 0, ULONG_MAX);
    printf("-----------MY FUNCTION-----------\n");
    printf("  signed char : [%d, %d]\n", -(unsigned char)~0/2-1, (unsigned char)~0/2);
    printf("unsigned char : [%d, %d]\n", 0, (unsigned char)~0);
    printf("  signed short: [%d, %d]\n", -(unsigned short)~0/2-1, (unsigned short)~0/2);
    printf("unsigned short: [%d, %d]\n", 0, (unsigned short)~0);
    printf("  signed int  : [%d, %d]\n", -(int)(~(unsigned int)0>>1)-1, (int)(~(unsigned int)0>>1));  
    printf("unsigned int  : [%d, %u]\n", 0, ~(unsigned int)0);
    printf("  signed long : [%ld, %ld]\n", -(long)(~(unsigned long)0>>1)-1, (long)(~(unsigned long)0>>1));
    printf("unsigned long : [%d, %lu]\n", 0, ~(unsigned long)0);
    
    return 0;
}
