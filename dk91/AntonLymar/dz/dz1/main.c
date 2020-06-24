#include <stdio.h>
#include <string.h>
void probel(char str[]);

int main()
{
    char str[250];
    printf ("Vvedite vashe predlozhenie: ");
    fgets(str, sizeof(str), stdin);
    probel(str);
    return 0;
}
void probel(char str[])
{
int counter = 0;
for (int i = 0; i <= strlen(str); i++) {
    if (str[i] == ' ' && str[i+1] != ' '){
        counter++;
    }
}
printf("Kolichestvo slov v predlozhenii sostavilo: %d\n", counter+1);
}
