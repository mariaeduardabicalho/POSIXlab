
int main() {
    int size = sizeof(all_tests)/sizeof(test_data);
    printf("Running %d tests:\n", size);
    printf("=====================\n\n");
    int pass_count = 0;

    pid_t f1= fork();
    pid_t f2 = -1;
    pid_t f3 = -1;
    if (f1!= 0){
        f2 = fork();
        if(f2!=0){
            f3= fork();
        }
    }
    
    pid_t w1;
    pid_t w2;
    pid_t w3;
    int wstatus1, wstatus2,wstatus3;
    
    
    // for (int i = 0; i < size; i++) {
    // }   
        
    if (f1==0){
        if (test1() >= 0) { 
            printf("Teste 1 : [PASS]\n");
            return 0;
        };
        return -1;
    }
    if (f2==0){
        if (test2() >= 0) { 
            printf("Teste 2 : [PASS]\n");
            return 0;
        };
        return -1;
    }
    
    
    
    if (f3==0){
       if (test3() >= 0) { 
            printf("Teste 3 : [PASS]\n");
            return 0;
        };
        return -1;
    }
    w1 = waitpid(f1,&wstatus1,NULL);
    w2 = waitpid(f2,&wstatus2,NULL);
    w3 = waitpid(f3,&wstatus3,NULL);
    //printf("w1 /%d\n",w1);
     printf("wstatus2 /%d\n",wstatus3);
    /////////////////////////////////////////////// twste 1
    
    if(WIFEXITED(wstatus1)){
        printf("Teste 1 exited, status= %d\n",WEXITSTATUS(wstatus1));
    }
      
    else{
        printf("sucesso exit funcao 1 : %d \n",w1);
    } 
    if(wstatus1 == 0){
        pass_count++;
    }
    ///////////////////////////////////////////////   teste 2

    if(WIFEXITED(wstatus2)){
        printf("Teste 2 exited, status= %d\n",WEXITSTATUS(wstatus2));
    } 
    else{
        printf("sucesso exit funcao 2 : %d \n",w1);
    }  
    if(wstatus2 == 0){
        pass_count++;
    }
    ///////////////////////////////////////////////  teste 3
    if(WIFEXITED(wstatus3)){
            printf("Teste 3 exited, status= %d\n",WEXITSTATUS(wstatus3));
    }  
    else{    
        printf("sucesso exit funcao 3 : %d \n",w1);
    }  
    if(wstatus3 == 0){
        pass_count++;
    }
    

    printf("\n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}
