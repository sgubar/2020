#include "functions.h"

int main()
{

    SquareArray *theArray = createArray(4);

 int A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;            //змінні для точок
 int K=1,number;
 float searchArea;

do
 {
    printf("Enter the coordinates of point A:\n");             //ввід кординат
    EnteringCoordinates (&A_x,&A_y);
    printf("Enter the coordinates of point B:\n");
    EnteringCoordinates (&B_x,&B_y);
	printf("Enter the coordinates of point C:\n");             //Вводимо координати точки С та перевіряємо їх правильність
	do
    {
        printf("x=");
        scanf("%d",&C_x);
        printf("y=");
        scanf("%d",&C_y);
        if(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2)||          //формули довжин
           pow(A_x-B_x,2)+pow(A_y-B_y,2)!=pow(C_x-B_x,2)+pow(C_y-B_y,2))
        {
            printf("Error! Enter the coordinates of point C again!");
        }
        printf("\n");

    }while( pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2) ||
            pow(A_x-B_x,2)+pow(A_y-B_y,2)!=pow(C_x-B_x,2)+pow(C_y-B_y,2));


    D_x=(A_x+C_x)-B_x;                                           //знаходимо кординати точки D
    D_y=(A_y+C_y)-B_y;

	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {D_x,D_y};

	Square ABCD={&A, &B, &C, &D};

	printf("Ploscha ABCD = %f\n\n", ploschaSquare(&ABCD));


	addElement(theArray, &ABCD, ploschaSquare(&ABCD));

	K++;
 }while(K<=4);

	FILE *theFile = fopen("test.json", "a+");                       //запис даних

	writeArrayToJSON(theFile, theArray);
	fclose(theFile);

	sort_vstavka(theArray);
	//quickSort( theArray, 0, theArray->count-1);

	FILE *theFile2 = fopen("test_vidsortovanyj.json", "a+");        //запис відсортованих даних

	writeArrayToJSON(theFile2, theArray);
	fclose(theFile2);

	printf("\nEnter area to search: ");
	scanf("%f",&searchArea);

	number = linijnyj_poshuk(theArray, searchArea);               //пошук

	if(number==-1)
{
    printf("\nNot found!\n");
}
else
{
    printf("\nThe number of the area in the array: %d \n", number);
}

	freeArray(theArray);                                                   //звільняємо пам'ять


	printf("\nFile created!\n");

	return 0;
}

