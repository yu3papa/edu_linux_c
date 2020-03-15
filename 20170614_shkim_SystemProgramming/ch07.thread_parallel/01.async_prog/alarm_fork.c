#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int seconds;
	char line[128];
	char message[64];
	pid_t pid;
	int status;
	
	while(1) {
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if(strlen(line) <= 1) continue;
		if(!strncmp(line, "exit", 4)) exit(0);
		
		if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
			fprintf(stderr, "Bad command\n");
		} else {
			..........
			switch(pid) {
			case -1 :
				perror("fork() error");
				break;
			case 0 :
				.......
				
			default :
				do {
					pid = waitpid((pid_t)-1, NULL, WNOHANG);
					if(pid == (pid_t)-1) {
						perror("waitpid() error");
						exit(1);
					}
				} while(pid != (pid_t)0);
			} // end of switch
		} // end of if-else
	} //end of while
}
