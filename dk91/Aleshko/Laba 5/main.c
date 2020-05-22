int main()
{
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 12);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 4);
    iterInorder(root);
    printf("------------------\n");
    printf("max = %d\n", getMaxNode(root)->data);
    printf("min = %d\n", getMinNode(root)->data);
    deleteValue(root, 4);
    printf("parent of 7 is %d\n", getNodeByValue(root, 7)->parent->data);
    deleteValue(root, 8);
    printf("------------------\n");
    deleteValue(root, 10);
    iterInorder(root);

    getch();
}
