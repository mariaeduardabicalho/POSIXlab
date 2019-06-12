# POSIX


#C
##Iniciei o lab separando os processos e os deixando rodar paralelamente. Fiz isso criando um um novo processo para cada teste, por meio de um for.

#B

##Utilizei outro for para fazer wait com todos os filhos. Utilizei waitpid para o resultado ser mostrado em ordem. Para redirecionar a saisa dos testes para outro arquivo, possibilitando que  fosse mostrado tudo de u teste por vez, utilizei o dup2  com um arquivo temporario para cada filhos. Criei um tempo maximo de execucao para cada processo filho. Depois, utilizei o WIFSIGNALED para o pai saber se o filho foi terminado com sinal, e qual o sinal. 

#B+
##Fiz uma API para que fosse possivel escolher o tempo maximo de cada teste, por meiO da funcao TEST_TIME presente no macros.h
 
