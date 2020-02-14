// Para compilar use o seguinte comando (no linux):
//gcc -lrt fork_sm.c
// ou
//g++ -lrt fork_sm.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int *glob_var;

int main(){

	glob_var = mmap(NULL, sizeof(*glob_var), PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*glob_var = 5;

	pid_t pid;

	pid = fork();
	
	if (pid == 0) { 
		*glob_var += 15;
		return 0;
	}
	else if (pid > 0) { 
		wait(NULL);
		printf ("PARENT: value = %d\n", *glob_var); 
		munmap(glob_var, sizeof *glob_var);
		return 0;
	}
}
