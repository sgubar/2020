#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void bubble_sort(char *array, int size)
{
  int k, i;
  for(k = 0; k < size - 1; k++)
  {
      int swaps = 0;
      for(i = 0; i < size - 1 - k; i++)
    {
          if(array[i] < array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = swaps;
        swaps++;
          }
    }
      if(!swaps)
    break;
  }
}



void insert_sort(char *array, int size)
{
    char newElement;
    int  location, i;

    for (i = 1; i < size; i++)
    {
        newElement = array[i];
        location = i - 1;
        while (location >= 0 && array[location] < newElement)
        {
            array[location] = array[location + 1];
            location = location - 1;
        }
        array[location] = newElement;
    }
}



void selection_sort(char *array, int size)
{
    char temp;
    int location, i, j;
    for(i = 0; i < size; ++i)
    {
        location = i;
        temp = array[i];
        for(j = i + 1; j < size; ++j)
        {
            if (array[j] > temp)
            {
               location = j;
               temp = array[j];
            }
        }
        array[location] = array[i];
        array[i] = temp;
    }
}



int GetCharsAmountInFile (FILE* file)
{
  int size = 0;
  if (file != NULL)
  {
    fseek (file, 0, SEEK_END);
      size = ftell (file);
      fseek (file, 0, SEEK_SET);
      return size-1;
  }
  else return -1;
}



int GetLetterAmountInFile (FILE* file)
{
  int size = 0, i = 0;
  char value;
  int _size = GetCharsAmountInFile (file);
  fseek(file, 0, SEEK_SET);
  if (file != NULL)
    {
      for(i = 0; i < _size; i++)
      {
      fscanf (file, "%c", &value);
      if(value >= 'A' && value <= 'Z')
      {
        size++;
      }
      if(value >= 'a' && value <= 'z')
      {
        size++;
      }
    }
    return size-1;
    }
    else return -1;
}



char* loadFile (char * path , int  *size)
{
  FILE *infile = fopen(path, "r");
  if (infile != NULL)
    {
    int _size = GetCharsAmountInFile (infile);
      fseek(infile, 0, SEEK_SET);

      int size_ = GetLetterAmountInFile (infile);
      fseek(infile, 0, SEEK_SET);

      int i = 0, k = 0;
      char value;
      char *c = malloc(sizeof (char) * size_);

      for (i = 0; i < _size; i++)
    {
      fscanf (infile, "%c", &value);
      if(value >= 'A' && value <= 'Z')
      {
        c[k] = value;
        k++;
      }
      if(value >= 'a' && value <= 'z')
      {
        c[k] = value;
        k++;
      }
    }
      fclose(infile);
      *size = size_;
      return c;
  }
  return NULL;
}



void record_to_file(char *array, int size, char *name)
{
  FILE *file;
  file = fopen(name, "w+");
  int i;

  for(i = 0; i < size; i++)
  {
      fprintf(file,"%c\n", array[i]);
  }

  fclose(file);
}



void output_of_the_array(char* x, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%c", x[i]);
  }
  printf("\n");
}
