#include "list.h"

NodePtr create_node(int val)
{
    NodePtr new_node = malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->val = val;
}

ListPtr create_list()
{
    ListPtr list = malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
}

int push_element(ListPtr list, int val)
{
    NodePtr new_node = create_node(val);
    if (list->head)
    {
        NodePtr head = list->head;
        for (; head->next != NULL; head = head->next)
            ;
        head->next = new_node;
    }
    else
    {
        list->head = new_node;
    }

    return list->size++;
}

int add_element_by_index(ListPtr list, int index, int val)
{
    NodePtr parent = list->head;
    NodePtr current = list->head;
    if (index > list->size && list == NULL)
    {
        return -1;
    }

    NodePtr new_node = create_node(val);

    if (index == 0)
    {
        if (current = NULL)
        {
            list->head = new_node;
        }
        else
        {
            new_node->next = current;
            list->head = new_node;
        }
        list->size++;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (i == index)
        {
            if (parent == NULL)
            {
                parent = new_node;
            }
            else
            {
                new_node->next = current;
                parent->next = new_node;
            }
            list->size++;
            break;
        }
        parent = current;
        current = current->next;
    }
}

int remove_element(ListPtr list, int value)
{
    NodePtr parent = list->head;
    NodePtr current = list->head;

    for (int i = 0; i < list->size; i++)
    {
        if (current->val == value)
        {
            parent->next = current->next;
            free(current);
            return 1;
        }
        parent = current;
        current = current->next;
    }
    return 0;
}

void free_list(ListPtr list)
{

    NodePtr current = list->head;
    NodePtr prev = NULL;

    for (; current != NULL; current = current->next)
    {
        if (prev)
            free(prev);
        prev = current;
    }

    free(list);
}

void print_list(ListPtr list)
{
    printf("Size of list: %d\n", list->size);
    NodePtr current = list->head;
    int index = 0;

    for (; current != NULL; current = current->next)
    {
        printf("element #%d: %d\n", index++, current->val);
    }
}

NodePtr get_tail(NodePtr current)
{
    for (; current != NULL && current->next != NULL; current = current->next)
        ;
    return current;
}

NodePtr partition(NodePtr head, NodePtr end,
                  NodePtr *newHead, NodePtr *newEnd)
{
    NodePtr pivot = end;
    NodePtr prev = NULL, cur = head, tail = pivot;
    while (cur != pivot)
    {
        if (cur->val < pivot->val)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            NodePtr tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

NodePtr quick_sort_recur(NodePtr head, NodePtr end)
{
    if (!head || head == end)
        return head;
    NodePtr newHead = NULL, newEnd = NULL;
    NodePtr pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        NodePtr tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quick_sort_recur(newHead, tmp);
        tmp = get_tail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quick_sort_recur(pivot->next, newEnd);

    return newHead;
}

void quick_sort(ListPtr list)
{
    list->head = quick_sort_recur(list->head, get_tail(list->head));
    return;
}

void push_random_elements(ListPtr list, int size)
{
    for (int i = 0; i < size; i++)
    {
        push_element(list, rand() % 10000);
    }
}