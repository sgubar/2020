#include <stdio.h>
#include <stdlib.h>
void fff(char *a, int n)
{

    for (int i=0; i<n; i++)
    {
      printf("%c", a[i]);
    }

}
int ggg(char* a)
{
    int i=0, n=0;
    while (a[i] != '\0')
    {
        n++;
        i++;
    }
    printf("n = %d\n", n);
    return n;
}
void Insertion__Sort(char* a, int n)
{
    int i, j;
    char buff;
    for (i=1; i<n; i++)
    {
         buff = a[i];
        for (j=i-1; j>-1; j--)
        {

            if(buff<a[j])
            {
                //buff = a[i];
                a[j+1] = a[j];
                a[j] = buff;
            }

        }
    }
    fff(a, n);
}
void Selection__Sort(char* a, int n)
{
    int i, j;
    int buff;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                buff = a[i];
                a[i] = a[j];
                a[j] = buff;
            }
        }
    }
    fff(a, n);
}
void Bubble__Sort(char* a, int n)
{
    int i, f;
    char buff;
    while (f==0)
    {
        f=1;
        for(i=0; i<n-1; i++)
        {
            if(a[i]>a[i+1])
            {
                buff = a[i];
                a[i] = a[i+1];
                a[i+1] = buff;
                f=0;
              }
        }
    }
    fff(a, n);
}
