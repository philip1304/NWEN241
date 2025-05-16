#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	int pid, ret_exec, status;
	pid = fork();

	switch (pid) {
	case -1:
		// Error Forking
		perror("Error");
		exit(1);

	case 0:
		// Child Process: run `ps -A`
		ret_exec = execl("/bin/ps", "/bin/ps", "-A", (char *) NULL);

        if (ret_exec == -1) {
            perror("Error executing exec");
            exit(1);
        }

        break;

	default:
		// Parent Process: wait for child
		pid = wait(&status);


		if (WIFEXITED(status)) {
			printf("Parent Process ID: %d\n", getpid());
			printf("Child Process ID: %d\n", pid);
			printf("Child Termination Status: %d\n", WEXITSTATUS(status));
		}
	}

	return 0;
}
