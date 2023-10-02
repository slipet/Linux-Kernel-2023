
#include "item.h"

struct list_head *item_new()
{
    struct list_head *i_head = malloc(sizeof(struct list_head));
    if (!i_head)
        return NULL;
    INIT_LIST_HEAD(i_head);
    return i_head;
}
void item_free(struct list_head *head)
{
    if (!head)
        return;
    struct item *iter, *safe;
    list_for_each_entry_safe (iter, safe, head, list)
        item_release_element(iter);
    free(head);
}
void item_show(struct list_head *head)
{
    if (!head)
        return;
    struct item *iter, *safe;
    printf("[ ");
    list_for_each_entry_safe (iter, safe, head, list) {
        printf("%u ",iter->i);
    }
    printf("]\n");
}

static inline bool item_insert(struct list_head *head, uint16_t value)
{
    /*Consider the coditions of head
     *1. head is NULL -> return false
     *2. head had been initialized
     */
    if (!head)
        return false;
    struct item *new_element = malloc(sizeof(struct item));
    if (!new_element)
        return false;
    new_element->i = value;
    list_add(&new_element->list, head);
    return true;
}

bool item_insert_head(struct list_head *head, uint16_t value)
{
    return item_insert(head, value);
}