/*
  File for 'max-rec-calls' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"

static void recursive(void* t);

int rec_func(int depth, int x)
{
  printf("depth: %d\n", depth);
  depth++;
  rec_func(depth, x);
}

void test_max_rec_calls(void) 
{
  struct thread *t;
  thread_create("new_th", PRI_DEFAULT, recursive, t);
}

/* Recursive thread */
static void
recursive (void* t)
{
  printf("thread start rec test\n");
  rec_func(1, 0);
}

// 102 depth for name[16]
// 99 depth for name[128]