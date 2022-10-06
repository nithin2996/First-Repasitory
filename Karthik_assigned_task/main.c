#include <stdio.h>
#include <stdlib.h>                                                             //Pre-processor directive
#include <string.h>
void display_searched_data();                                                 //function declare
void display_file_word();

int line_position = 1,line_search=0;                                        // global integer variables
int main()
{
   display_searched_data();                                                //function call
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
    printf("Enter line number to search :");
    scanf("%d",&line_search);
    while(fgets(store_The_Value,100,file))
    {
        printf("Information : %s\n",store_The_Value);
        if(line_search == line_position)
        {
            printf("line no. %d\nInformation : %s\n",line_search,store_The_Value);
        }
        line_position++;
    }
    display_file_word();
}

int countOccurrences(FILE *file,  char *word)
{
    char verifyThevalue[100];
    char *position;
    int index, count;
    count = 0;
    printf("Inside the Count the occourance function \n");
    printf("*word %d\n",*word);
    while((fgets(verifyThevalue,100,file))!=NULL)
    {
        index = 0;
        while ((position=strstr(verifyThevalue+index,word)) != NULL)
        {
            index=(position-verifyThevalue)+1;
            count++;
        }
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





