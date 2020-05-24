
#include "list.h"
#include "tools.h"

int main(int argc, char const *argv[])
{
    ListPtr list = NULL;
    while (1)
    {
        printf("________MENU_______\n");
        printf("1: create list;\n");
        printf("2: print list;\n");
        printf("3: set by index;\n");
        printf("4: sort list;\n");
        printf("5: delete by value;\n");
        printf("6: exit;\n");

        int mode;
        scanf("%d", &mode);

        if (!(mode != 1 || mode != 5) && list == NULL)
        {
            printf("list not initialized\n");
            continue;
        }
        switch (mode)
        {
        case 1:
        {
            printf("\n");
            int size = get_natural_int("Write down the size of new elements: \n");
            list = create_list();
            push_random_elements(list, size);
        }
        break;
        case 2:
        {
            print_list(list);
        }
        break;
        case 3:
        {
            int index = get_int("Write down index of element:\n");
            printf("index of element: %d\n", add_element_by_index(list, index, get_int("Write down value of element:\n")));
        }
        break;
        case 4:
        {
            quick_sort(list);
            print_list(list);
        }
        break;
        case 5:
        {
            int index = get_int("Write down value of element:\n");
            if (remove_element(list, index))
            {
                printf("Removed successfully. \n");
            }
            else
            {
                printf("Deleting failed.\n");
            }
        }
        break;
        case 6:
        {
            if (list != NULL)
                free_list(list);
            return 0;
        }
        break;
        default:
            printf("write number from 1 to 6");
        }
    }
    return 0;
}
