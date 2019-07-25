#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char*argv[]) {

    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
    fprintf(stderr, "fork fallido \n");
    exit(1);
    } else if (rc == 0) {
      int rc_wait = wait(NULL);
      printf("hola soy el hijo (pid: %d (rc_wait: %d)) \n", rc, rc_wait,(int) getpid());
    } else {
        printf("hola, soy el padre de %d (pid: %d) \n", (int) getpid());
}
return 0;
}
