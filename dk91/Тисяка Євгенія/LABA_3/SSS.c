void ShellSort(int n, char mass[])
{

    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
       {

        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j = j - step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
       }
}
void fff(char *a, int n)
{
 printf("\n");
    for (int h=0; h<n; h++)
    {
      printf("%c", a[h]);
    }
 printf("\n");
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
int revice(char *mass, int n)
{
    int i;
    for(i=0; i<n-2; i++)
    {
        if((mass[i]>96 & mass[i]<123) || (mass[i]>47 & mass[i]<58) )
        {
         printf("%c", mass[i]);
        }
        else
        {

            printf("\nError %c", mass[i]);
            return 0;
        }
    }
    return 1;
}
int poisk(char *m, int n, char key)
{


  for (int f = 0; f < n; f++)
  {
    if (m[f] == key)
      return f-2;
  }
  return -1;
}
