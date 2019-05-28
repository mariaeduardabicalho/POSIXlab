#define  _GNU_SOURCE
#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h> 
#include <sys/times.h>
#include <time.h>


typedef int (*test_func)();

typedef struct {
    char name[50];
    test_func function;
    int time;
} test_data;

#define test_printf (printf("%s: ", __func__));printf

#define test_assert(expr, str) { if(!(expr)) { printf("\033[0;31m %s: [FAIL] %s in %s:%d\n", __func__, str, __FILE__, __LINE__); return -1; } }

#define TEST(f,t) {.name=#f, .function=f,.time=t}

#define test_list test_data all_tests[]

//#define checklist int check[]
int check[7];

void api_tempo(int id,int te){
    
    if(check[id]==id){
        return;
    } 
    alarm(te);
    check[id]=id;
}

