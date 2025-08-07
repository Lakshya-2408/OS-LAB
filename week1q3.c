/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int x=fork();
    if(x>0){
        wait(NULL);
        printf("parent\n");
        int y=fork();
        if(y>0){
            wait(NULL);
            printf("parent1\n");
        }
        else if(y==0){

            printf("child1\n");
            exit(0);
        }
        else{
            printf("rare1");
        }
    }
    else if(x==0){
        
        execlp("ls","ls","-l",(char*)NULL);
        printf("child\n");
        exit(0);
    }
    else{
        printf("rare");
    }

    return 0;
}