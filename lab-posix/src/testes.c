#include "mintest/macros.h"

int test1() {
    //test_printf("segmentation fault\n");
    int *p = NULL;
    *p = 1;
    // nem preciso de trst assert ??
    return 0;
}

int test2() {
    //printf("divisao por zero\n");
    int i = 10/0;
    printf("%d",i);
    return 0;
    // nem preciso de trst assert ??
}

int test3() {
   // test_printf("loop infinito");
    while(1){

    }
    return 0;
    // nem preciso de trst assert ??
}
int test4_6() {
    //tipo teste  4 e 6
    int t;
    for(int i=0; i<20000; i++){
        t+=i;
        printf("%d",i);
    }
    return 0;
    // isso seria muito trabalho?
}
int test5() {
 // por exemplo isso?     
    test_assert(1 == 1, "This always succeeds");
    test_assert(0 == 1, "This always fails");

    return 0;
}

int test7_1() {     
    sleep(1000);

    return 0;
}
int test7_2() {    
    return 0;
}



test_list = { TEST_TIME(test1,5), TEST_TIME(test2,5), TEST_TIME(test3,5), TEST_TIME(test4_6,5),TEST_TIME(test5,5),TEST_TIME(test7_1,5),TEST_TIME(test7_2,5)};

#include "mintest/runner.h"
