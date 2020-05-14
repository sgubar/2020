typedef struct list
{
    char field;
    struct list *next;
    struct list *prev;
} List;

List *init(char val);   // Створення першого елемента списку

List* scanElem();			// Створення списку

List* addElement(List *list, char val);      // Додавання елементів до списку

void listPrint(List* p_begin);				// Вивід списку на єкран

void check(List* p, char element);     //певірка на "Дурня"

void swapElements(List* right, List* left);       //Свап елементів

void error(); 		// помалка "данний елемент не повторюється!"
