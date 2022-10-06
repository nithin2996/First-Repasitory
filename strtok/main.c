#include<stdio.h>
#include<string.h>
int main ()
{
    char str[]="....why ? but; not ? oh ! ,Depth where when\n";
    char seps[]="?!;.,\t";
    char *t;
    t=strtok(str,seps);
    while(t!=NULL)
    {
        printf("%s",t);
        t=strtok(NULL,seps);
    }
    return 0;
}
