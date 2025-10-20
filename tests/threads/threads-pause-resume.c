/*
  File for 'threads-pause-resume' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "devices/timer.h"

static void printer_A(void* t);
static void printer_B(void* t);

void test_threads_pause_resume(void) 
{
  struct thread* thread_A;
  struct thread* thread_B;
  msg("Starting test...");
  tid_t A = thread_create("thread_A", PRI_DEFAULT, printer_A, thread_A);
  tid_t B = thread_create("thread_B", PRI_DEFAULT, printer_B, thread_B);
;
  // printf("name: %s\n", get_thread(A)->status);
  timer_sleep(400); // 4 sec sleep
  msg("Pause A...");
  thread_pause(A);
  timer_sleep(400);
  msg("Resume A...");
  thread_resume(A);
  timer_sleep(400);
  thread_pause(A);
  thread_pause(B);
  pass();
}


static void printer_A(void* t)
{
  while (1)
  {
    timer_sleep(100);
    msg("Thread_A");
  }
}

static void printer_B(void* t)
{
  while (1)
  {
    timer_sleep(100);
    msg("Thread_B");
  }
}