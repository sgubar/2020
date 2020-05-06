#include "tools.h"
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    List *list = load_from_file("input.txt");
    printf ("input.txt is open");
    list_reverse(&list);
    write_to_file(list, "output.txt");
    printf ("reversed text was written to open.txt");
    return 0;
}
