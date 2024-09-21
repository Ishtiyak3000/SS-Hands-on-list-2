/*
 ============================================================================================
  Name: 18.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to find out total number of directories on the pwd.
  execute ls -l | grep ^d | wc ? Use only dup2.
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int pipefd1[2];
  int pipefd2[2];
  pipe(pipefd1);
  pipe(pipefd2);
  int id1 = fork();
  if (id1 == 0)
  {
    close(pipefd1[0]);
    dup2(pipefd1[1], STDOUT_FILENO);
    close(pipefd1[1]);
    execlp("ls", "ls", "-l", (char *)NULL);
  }
  int id2 = fork();
  if (id2 == 0)
  {
    close(pipefd1[1]);
    dup2(pipefd1[0], STDIN_FILENO);
    close(pipefd1[0]);
    close(pipefd2[0]);
    dup2(pipefd2[1], STDOUT_FILENO);
    close(pipefd2[1]);
    execlp("grep", "grep", "^d", (char *)NULL);
  }
  int id3 = fork();
  if (id3 == 0)
  {
    close(pipefd1[0]);
    close(pipefd1[1]);
    close(pipefd2[1]);
    dup2(pipefd2[0], STDIN_FILENO);
    close(pipefd2[0]);
    execlp("wc", "wc", (char *)NULL);
  }

  close(pipefd1[0]);
  close(pipefd1[1]);
  close(pipefd2[0]);
  close(pipefd2[1]);
  waitpid(id1, NULL, 0);
  waitpid(id2, NULL, 0);
  waitpid(id3, NULL, 0);

  return 0;
}
