/* strncpy example */
#include <stdio.h>
#include <string.h>
//char * strncpy ( char * destination, const char * source, size_t num );
char* my_strncpy(char* dest,char* src,size_t n){        //never checkes for array overflow can be better implemented, 
    memset( dest, '\0', sizeof(char)*n );
    for(int i=0;i<n && src[i]!='\0';i++)
        dest[i]=src[i];
    return dest;
}
int main ()
{
    char src0[]="using my implementation function";
    char dest0[500];

    char src1[]="using string library function";
    char dest1[500];
    
    printf("Self Implementation Function\n");
    my_strncpy(dest0,src0,300);
    printf("Source: %s\nDestination: %s",src0,dest0);

    
    printf("\n\nLibrary Function\n");
    strncpy(dest1,src1,30);
    printf("Source: %s\nDestination: %s",src1,dest1);

  return 0;
}