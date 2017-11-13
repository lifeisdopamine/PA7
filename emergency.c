#include "emergency.h"


int main(void)
{
        struct patient * details;
        struct patient *head_child = NULL;
        struct leaf_t *QChildHead = NULL;
        struct leaf_t *QSeniorHead = NULL;
        details = malloc(sizeof(struct patient));
        
        if (patient -> age <= 10) {
                child_data(head, details);
        } else if (patient -> age >= 60) {
                senior_data(details);
        } else {
                adult_data(details);
        }

        return 0;
}
void child_data(struct patient *head, struct patient *details, struct leaf_t *QchildHead)
{
        if (head == NULL) {
                head = create_node(details -> name, details -> age, details -> arrivalTime);
                return;
        }
        struct patient node = create_node(details);
        head = insert(head, node, QchildHead);
        head = minHeapify(head);


}
/*Min Heap */
struct patient * create_node(struct patient *details)
{
        
        struct patient node = calloc(1, sizeof(struct patient));
        strcpy(node -> name, details -> name);
        node -> age = details -> age;
        node -> arrivalTime = details -> arrivalTime;
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
        
        head -> left = minHeapify(head -> left);
        head -> right = minHeapify(head -> right);

        return head;
        
}/* Old Insert Function */
/*
struct patient *insert(struct patient *head, const struct patient *node)
{
        if (head == NULL)
                head = node;
        else if (head -> left == NULL)
                head -> left = node;
        else
                head -> right = node;
        
        head = insert(head -> left, node);
        head = insert(head -> right, node);
        return head;
        
}*/

struct patient *insert(struct patient *head, struct patient *node, struct leaf_t *QHead)
{
        QChildHead -> ptr -> left = node;
        dequeue_leaf(&QHead);
        enqueue_leaf(&Qhead, node);
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
        
        free(tmp);
        
        return d1;
}
void find_leaf(struct patient *head)
{
        if (head -> left == NULL && head -> right == NULL) {
                return enqueue_leaf(head);
        }       
        find_leaf(head -> left);
        find_lead(head -> right); 
}
void enqueue_leaf(struct leaf_t **head, struct patient *node)
{
        if (*head == NULL) {
                *head = calloc(1, sizeof(struct leaf_t));
                *head -> ptr = node;
        } else {
                struct leaf_t *tmp = *head;
                while (tmp -> next != NULL) {
                        tmp = tmp -> next;
                }
                tmp -> next = calloc(1, sizeof(struct leaf_t));
                tmp -> next -> ptr = node;
        }
        return;
}
void dequeue_leaf(struct leaf_t **head) 
{
        if (*head == NULL) {
                return;
        }
        struct leaf_t *tmp = *head -> next;
        free(*head);
        *head = tmp;
}
