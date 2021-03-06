#include "emergency.h"



int main(void)
{
        struct patient * details;
        struct patient *head_child = NULL;
        
        details = malloc(sizeof(struct patient));
        
        if (patient -> age <= 10) {
                child_data(head, details);
        } else if (patient -> age >= 60) {
                senior_data(details);
        } else 
                adult_data(details);

        return 0;
}
void child_data(struct patient *head, struct patient *details)
{
        if (head == NULL) {
                head = create_node(details -> name, details -> age, details -> arrivalTime);
                return;
        }
        struct patient node = create_node(details -> name, details -> age, details -> arrivalTime);
        head = insert(head, node);
        head = minHeapify(head);


}
/*Min Heap */
struct patient * create_node(char n[], int a, int time)
{
        
        struct patient node = calloc(1, sizeof(struct patient));
        strcpy(node -> name, n);
        node -> age = a;
        node -> arrivalTime = time;
        return node;
}
struct patient * minHeapify(struct patient *head)
{
        if (head == NULL) 
                return NULL;
        if ((head -> left -> age) <= head -> age)
                head = swap(head, head -> left);
        if ((head -> right -> age) <= head -> age)
                head = swap(head, head -> right);
        
        head = minHeapify(head -> left);
        head = minHeapify(head -> right);

        return head;
        
}
struct patient *insert(struct patient *head, const struct patient *node)
{
        if (head == NULL) {
                return node;
        }
        if ((head -> left) && (head -> right)) {
                head = insert(head -> left, node);
                head = insert(head -> right, node);
        }
        else if (!(head -> left)) {
                head -> left = node;
        } else {
                head -> right = node;
        }
        return head;
}
struct patient *max_age(struct patient *left, struct patient *right) 
{
        if ((left -> age) >= (right -> age))
                return left;
        return right;
}
struct patient *swap(struct patient *d1, struct patient *d2)
{
        struct patient *tmp = calloc(1, sizeof(struct patient));
        if (!tmp) {
                printf("Error: Calloc Failed \n\n");
                exit(1);
        }
        tmp -> age = d1 -> age;
        strcpy(tmp -> name, d1 -> name);
        tmp -> arrivalTime = d1 -> arrivalTime;
        
        d1 -> age = d2 -> age;
        d1 -> arrivalTime = tmp -> arrivalTime;
        strcpy(d1 -> name, d2 -> name);

        d2 -> age = tmp -> age;
        d2 -> arrivalTime = tmp -> arrivalTime;
        strcpy(d2 -> name, tmp -> name);
        return d1;
}
find_leaf(struct patient head)
{
        if (head -> left == NULL && head -> right == NULL) {
                return head -> left;
        } else if (head -> right == NULL) {
                return head -> right;
        } else {
                return head -> left;
        }
        return find_leaf(head -> left);
}
