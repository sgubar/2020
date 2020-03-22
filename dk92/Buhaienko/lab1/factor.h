#ifndef Factor
#define Factor
double factor(float x)
{
double fact = 0;
if(x<1){
    return -1;
}
else{
fact = 1;

        for(int i=1; i<=x; i++)
        {
            fact *= i;

        }
}
 return fact;
}


#endif // Factor
