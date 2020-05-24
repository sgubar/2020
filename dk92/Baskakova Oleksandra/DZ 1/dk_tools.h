
typedef struct Matrix
{
    int nLen;
    int mLen;
    int **elements;
} Matrix;
unsigned int getUnsignedInt(char* label);
int getInt(char *label);
Matrix readMatrix(int nLen, int mLen);
Matrix MulMatrixToNumber(Matrix matrix, int num);
void printMatrix(Matrix matrix);
