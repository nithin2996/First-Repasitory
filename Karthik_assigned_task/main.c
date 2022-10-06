#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display_searched_data();
void display_file_word();

int line_position = 1,line_search=0;
int main()
{
//    char myname[10];
//    printf("Enter the name   ***************\n");
//    for(int i=0;i<10;i++)
//    {
//        scanf("%c",&myname[i]);
//    }
//    for(int i=0;i<10;i++)
//    {
//        printf("%d my name  %c\n",i,myname[i]);
//    }
   display_searched_data();
    display_file_word();
}
void display_searched_data()
{
    char store_The_Value[100];
    FILE *file;
    file = fopen("task.txt","r");
    if (file == NULL)
    {
        printf("file does not exist\n");
    }
    //printf("file %u\n",&file);
    printf("Enter line number to search :");
    scanf("%d",&line_search);
    //printf("line search %c\n",line_search);
    while(fgets(store_The_Value,100,file))
    {
        printf("Information : %s\n",store_The_Value);
        //printf("storeTheValue[0]---   %c\n",store_The_Value[0]);
        //printf("address storeTheValue[0]---   %u\n",&store_The_Value[0]);
        // printf("address storeTheValue[1]---   %u\n",&store_The_Value[1]);
        //printf("size of store the value [0] ---%zu byte \n",sizeof(store_The_Value[0]));
        if(line_search == line_position)
        {
            printf("line no. %d\nInformation : %s\n",line_search,store_The_Value);
            //printf("line search   inside the if condition    %d\n",line_search);
            //printf("line position inside the if condition    %d\n",line_position);
        }
        line_position++;
    }
    //printf("file address %zu\n",sizeof (file))
    display_file_word();
}

int countOccurrences(FILE *file,  char *word)
{
    char verifyThevalue[100];
    char *position;
    int index, count;
    count = 0;
    printf("Inside the Count the occourance function \n");
    //printf("word  %u\n",word);
    printf("*word %d\n",*word);
    while((fgets(verifyThevalue,100,file))!=NULL)
    {
        index = 0;
        while ((position=strstr(verifyThevalue+index,word)) != NULL)
        {
            index=(position-verifyThevalue)+1;
            //printf("verify the value size is  ******   %zu\n",sizeof (verifyThevalue[0]));
           // printf("verifyTheValue[0]*** ****              %s\n",verifyThevalue[0]);
            //printf("size of verifyTheValue[0]***       %zu\n",sizeof (verifyThevalue[0]));
           // printf("verifyThevalue address  ****[0]    %u\n",&verifyThevalue[0]);
//            printf("verifyTheValue[1]        %c\n",verifyThevalue[1]);
//            printf("verifyTheValue[2]        %c\n",verifyThevalue[2]);
            //printf("string  \nindex  %u=(position======(%s) - verifyTheValue=====(%s) )+1\n",index,position,verifyThevalue);
            //printf("position\nindex  %u=(position==(%u)-verifyTheValue==(%u))+1\n",index,*position,verifyThevalue);
            //printf("character\nindex %u=(position==(%c)-verifyTheValue ==(%c))+1\n",index,*position,*verifyThevalue);
            count++;
        }
        //printf("position*****pointer    %p\n",position);
        //printf("string data      %s\n",verifyThevalue);
        printf("position         %s\n",position);
    }
    return count;
}
void display_file_word()
{
    FILE *file;
    char *word;
    int i=0;
    word = malloc(10*sizeof(char));
    file = fopen("task.txt", "r");
    if (!file)
    {
        printf("File not found. \n");
    }
    else
    {
        printf("Enter the word to be searched : ");
        scanf("%s",word);
        i=countOccurrences(file,word);
    }
    if (i==0)
        printf("Word not found------------- %s\n",word);
    else
        printf("******** Word ******* found *************     %s\n",word);
    fclose(file);
}





