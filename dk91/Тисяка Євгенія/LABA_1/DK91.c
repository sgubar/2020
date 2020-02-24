float power2(float a)
{
   int x=1;
   int i;
   int j;

    if(a>=0);
    {


      for(j=0; j<a; j++)
      {
        x=x*2;
      }
     return x;
    }
    if(a<0)
    {
       a=-1*a;
      for(j=0; j<a; j++)
      {
        x=x*2;
      }
      x=1/x;
      return x;
    }
}
float  d(float A, float B, float C)
{

  if(100-B-C!=0)
  {
    float x=(A+B+C)/(100-B-C);
    return x;
  }
    else
    {

     printf("error:you cannot divide by zero");
     return 0;
  }


}
float s(float A,float B, float C, float D)
{
float s=0;
int i;
int j;
float step=D+i;
float x;
  for(i=0; i<=A; i++)
  {

    x=1;
    x = power2(step);
    s=s+x;
  }
  return s;
}
float q(float d, float s)
{
  return d+s;
}
float inputVariables(float B)
{
  float x;
  scanf("%f", &x);

  B=x;

  return B;

}







