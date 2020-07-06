#include <stdio.h>
#include <string.h>
#include <iostream> 
#include <unordered_set>  
using namespace std;
//char * strtok ( char * str, const char * delimiters );
//complexity is O(N*d)  where N is length of string and d are number of delimiters
// nunber of delim are always very small and would be <=255 character so max complexity would be O(N*255) = O(N)
// Approx
char* my_strtok(char *str, const char *delim){
    static bool flag=false;
    static char* ptr=NULL;
    
    if(ptr==NULL){
        ptr=new char[1+strlen(str)];
        strcpy(ptr,str);                    //define memory to static integer 
        ptr[strlen(str)]='\0';   
    }
    if(ptr[0]=='\0')    return NULL;
    char* init=ptr;    
    unordered_set<char> m;
    if(ptr==NULL)   return NULL;    
    for(int i;i<strlen(delim);i++)  m.insert(delim[i]);
    int n=strlen(ptr);    
    for(int i=0;i<=n;i++){        
        if(m.find(*(ptr+i))!=m.end()){
            *(ptr+i)='\0';
            int x=1;
            while(m.find(*(ptr+i+x))!=m.end())x++;
            ptr=init+i+x;
            return init;
        }
        else if(*(ptr+i)=='\0'){ 
            ptr=NULL;
            return init;}
    }
    return NULL;
}
int main(){
    char str1[]="This is a sample, string with numerous: delimitors. As seen we can tokenize ";
    char* ptr1;
    cout<<"Original Array Before strtok(): "<<str1;
    printf("\n\nUsing Self Implemented Code\n\n");
    ptr1=my_strtok(str1," :,.");    
    while(ptr1!=NULL){
        printf("\t");
        printf("%s\n",ptr1);
        ptr1=my_strtok(NULL," :,.");
    }
    cout<<"Original Array After strtok(): "<<str1<<"\n\n";
    return 0;
}
