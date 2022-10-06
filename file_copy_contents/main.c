#include <stdio.h>                                                               //Pre-processor directives
#include <stdlib.h>
int main()
{
    FILE *fp1,*fp2;                                                             //File pointers
    char file1[100],c;
    printf("Enter the file to open for reading\n");
    scanf("%s",file1);
    fp1=fopen(file1,"r");                                                     //File opened in reading mode
    if(fp1==NULL)
    {
        printf("Cannot open file %s",file1);
        exit(1);
    }
    printf("Enter the file name open for writing \n");
    scanf("%s",file1);
    fp2=fopen(file1,"w");                                                     //File opened in writing mode
    if(fp2==NULL)
    {
       printf("Cannot open file %s",file1);
       exit(1);
    }
    c=fgetc(fp1);
    while (c!=EOF)                                                           // chracter not equal to End of File
    {
        fputc(c,fp2);
        c=fgetc(fp1);
    }
    printf("Contents copied %s",file1);
    fclose(fp1);                                                           // file closed
    fclose(fp2);                                                          //file closed
    return 0;
}
