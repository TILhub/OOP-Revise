#include <stdio.h>
#include <string.h>
//typedef unsigned int size_t
//char * strncat ( char * destination, const char * source, size_t num );
char * my_strncat ( char*, const char* , size_t  );
int main(){
    char src[500] = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"; 
    char dest[50]= "|defg|"; 
    char src1[500] = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"; 
    char dest1[50]= "|defg|"; 
    strncat(dest1, src1, 50);
    printf("Lib Function: \nSource: %s\nDestination: %s\n",src1,dest1); 
    my_strncat(dest, src, 50); 
    printf("Self Implementation\nSource : %s\n", src); 
    printf("Destination : %s", dest); 
    return 0;
}
char * my_strncat ( char* dest, const char* src, size_t n ){
    size_t dlen=strlen(dest);
    size_t i=0;
    for(;i<n && src[i]!='\0';i++)
        dest[dlen+i]=src[i];
    dest[dlen+i]='\0';
    return dest;
}