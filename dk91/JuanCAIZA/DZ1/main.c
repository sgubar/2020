#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    /*int n, k;
    scanf("%d %d", &n, &k);
    char arr[n], arr2[k];
    for(int i = 0; i <= n; i++){
        scanf("%c", &arr[i]);
    }
    for(int i = 0; i <= k; i++){
        scanf("%c", &arr2[i]);
    }
    printf("%d", check(arr, arr2, n, k));*/
    const char *s1 = "helloohello11s``10";
    const char *s2 = "hello";
    printf("result = %d",string_compare(s1, s2));
    return 0;
}
