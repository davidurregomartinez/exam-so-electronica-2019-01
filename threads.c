#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <time.h>

    //clock_t start, end;
    //double t_time;
    

volatile int counter = 0; 
int loops;
puerta m;

void *worker(void *arg) {
    //start = clock();
    int i;
    //cerrar_puerta(m);
    for (i = 0; i < loops; i++) {
    cerrar_puerta(m);
	counter++;
    abrir_puerta(m);
    }
    //abrir_puerta(m);
    //end = clock();
    return NULL;
}

int main(int argc, char *argv[]) {
    clock_t start, end;
    double t_time;
    start = clock();
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    crear_puerta(m);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    //destruir_puerta(m);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    //crear_puerta(m);
    destruir_puerta(m);
    //end = clock();
    t_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("el tiempo total fue: %f \n", t_time);
    return 0;
}

