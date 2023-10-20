#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
   char *ptr;
   uint8_t leng;
} words;

bool sosanh(const char arr1[], const char arr2[], uint8_t leng) 
{
    for (uint8_t i = 0; i < leng; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void dem_ten(words array[], uint8_t size)
 {
    for (int i = 0; i < size; i++) {
        if (array[i].ptr == NULL) continue;
        int dem = 1;
        for (int j = i + 1; j < size; j++) {
            if (array[j].ptr != NULL && sosanh(array[i].ptr, array[j].ptr, array[i].leng)) {
                dem++;
                array[j].ptr = NULL;
            }
        }
        if (dem > 0) {
            printf("%.*s xuat hien %d lan\n", array[i].leng, array[i].ptr, dem);
        }
    }
}

bool compare(const char arr1[], const char arr2[])
{
    uint8_t i=0;
    while (arr1[i] != '\0')
    {
        if (arr1[i] > arr2[i]) return true;
        else if (arr1[i] < arr2[i]) return false;
        i++;
    }
    return false;
}

void sortalpha(words array[], uint8_t size)
{
    for (int i = 0; i < size; i++)
    {   
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (compare(array[temp].ptr, array[j].ptr))
            { 
                temp = j;
            }
            words w = array[i];
            array[i] = array[temp];  
            array[temp] = w;
        }
    }
}

words *splitstring(char string[], uint8_t size)
{
    words *array = (words*)malloc(sizeof(words) * size);
    uint8_t index = 0;
    uint8_t count = 0;
    array[index].ptr = string;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            array[index].leng = count;
            count = 0;
            string++;
            index++;
            array[index].ptr = string;
        }
        else
        {
            count++;
            string++;
        }
    }
    array[index].leng = count;
    return array;
}

uint8_t numberwords(char string[]) 
{
    uint8_t count = 0;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            count++;
        }
        string++;
    }
    return count + 1;
}

int sizestring(char string[]) 
{
    int count = 0;
    while (*string != '\0')
    {
        count++;
        string++;
    }
    return count;
}

void prinwords(words array[], uint8_t size)
{   
    for (uint8_t i = 0; i < size; i++)
    {   
        uint8_t j = 0; 
        while (j != array[i].leng)
        {
            printf("%c", array[i].ptr[j]);
            j++;
        }
        printf(" ");
    }
}

int main()
{
    char string[] = "anh bao bao anh nam bao";
    uint8_t number = numberwords(string);  
    words* array = splitstring(string, number);
    dem_ten(array, number);
    free(array);
    return 0;
}
