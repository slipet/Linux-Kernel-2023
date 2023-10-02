#include "list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct item {
  uint16_t i;
  struct list_head list;
};

struct list_head *item_new();
void item_free(struct list_head *head);
void item_show(struct list_head *head);

bool item_insert_head(struct list_head *head, uint16_t value);

static inline void item_release_element(struct item *e) {
  e->i = 0;
  free(e);
}
