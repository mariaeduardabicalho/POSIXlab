void sig_handler(int num){
    printf("\033[0m");
    printf(" Confirmacao de saida\n");
    sleep(1);
    exit(0);
}

int main() {


  
    int size = sizeof(all_tests)/sizeof(test_data);
    printf("Running %d tests:\n", size);
    printf("=====================\n\n");
    int pass_count = 0;

    // Inicializações para forks e o waitpid()
    pid_t f[size];  
    pid_t w[size];
    int wstatus;

    // Inicializações para arquivo

    char bufs;
    int fds[size];

   


    // criacao dos forks e wait

    for (int i = 0; i < size; i++) {
        fds[i]= open("/tmp", O_TMPFILE | O_RDWR, 0600);
        
        f[i]= fork();
        printf("\033[0m");
        
        
        if(f[i] == 0){
            alarm(all_tests[i].time);
            dup2(fds[i],1);
            if (all_tests[i].function() >= 0) {
                printf("\033[0;32m %s:  [PASS]\n", all_tests[i].name);
                return 0;
            }; 
            return -1;
        }
        
    }

    for (int i = 0; i < size; i++) {
        
        
        w[i]=  waitpid(f[i],&wstatus,NULL);  
        
        if (WIFEXITED(wstatus)){
            printf("\033[0m %s exited, status= %d\n",all_tests[i].name, WEXITSTATUS(wstatus)); 
            if(WEXITSTATUS(wstatus) == 0){
                pass_count++;
            }
            
        } 
        if(WIFSIGNALED(wstatus)){
            printf("\033[0m %s : \033[0;31m [FAIL] com sinal: %s\n \n ",all_tests[i].name,strsignal(WTERMSIG(wstatus)));
        }
         
       
        lseek(fds[i],0,SEEK_SET);
        
        while(read(fds[i],&bufs,1)>0){
    
            printf("%c",bufs);

        }
        
           
        
        

    }

    printf("\033[0m \n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}