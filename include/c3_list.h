#ifndef C3_LIST_H
#define C3_LIST_H

#include <stddef.h>

/* doubly linked list */
typedef struct c3_list_iter_t {
  void *data;
  struct c3_list_iter_t *n, *p;
}C3ListIter;

typedef struct c3_list {
  C3ListIter *head;
  C3ListIter *tail;
  size_t length;
}C3List;

typedef int (*C3ListComparator)(const void *a, const void *b);

#define c3_list_foreach(list, it, val) \
  if (list) \
    for (it = list->head; it && (val = it->data); it = it->n)
#define c3_list_foreach_prev(list, it, val) \
  if (list) \
    for (it = list->tail; it && (val = it->data); it = it->p)
#define c3_list_head(list) list->head
#define c3_list_tail(list) list->tail

void c3_list_init(C3List *list);
C3List *c3_list_new(void);
C3ListIter *c3_list_append(C3List *list, void *data);
void c3_list_clear(C3List *list);
void c3_list_free(C3List *list);
size_t c3_list_length(C3List *list);
C3ListIter *c3_list_find(C3List *list, const void *data, C3ListComparator cmp);
void *c3_list_head_data (C3List *list);
void *c3_list_get_data (C3ListIter *iter);
bool c3_list_delete_data(C3List *list, void *data, C3ListComparator cmp);
void c3_listiter_free(C3ListIter *iter);
void c3_listiter_delete(C3List *list, C3ListIter *iter);

#endif
