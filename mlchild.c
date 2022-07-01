#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()

{
	int pid; // child 1
         int pid1; // child 2
      int pid2; // child 3
      int fda = 0;
      static char buf[3000];
		fda = open("data.txt", O_RDONLY);
	pid = fork();
if (pid == 0) { // child process return to zero
                 
	       
	        printf("child[1] --> pid = %d and ppid = %d\n",
			getpid(), getppid());
		read(fda, buf, 1000);
		printf("read data is %s\n", buf);
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
				printf("child[2] --> pid = %d and ppid = %d\n",
				getpid(), getppid());
			
				read(fda, buf, 1000);
                                printf("read data is %s\n", buf);
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
				printf("child[3] --> pid = %d and ppid = %d\n",
					getpid(), getppid());
				
                                read(fda, buf, 1000);
                                printf("read data is %s\n", buf);
			}
			else {
				sleep(10);
				printf("parent --> pid = %d\n", getpid()); // parent process
			}
		}
	}

	return ;
}
