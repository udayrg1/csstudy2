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
                 
	       
	        printf("I'm child[1] and my  pid is %d and my parent ppid = %d\n",
			getpid(), getppid());
		read(fda, buf, 1000);
		printf("child 1 read data is %s\n", buf);
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
			        sleep(5);
				printf("I'm child[2] and my  pid is %d and my parent ppid = %d\n",
				getpid(), getppid());
			       
				read(fda, buf, 1000);
                                printf("child 2 read data is %s\n", buf);
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
				sleep(10);
				printf("I'm child[3] and my  pid is %d and my parent ppid = %d\n",
					getpid(), getppid());
                               
                                read(fda, buf, 1000);
                                printf("child 3 read data is %s\n", buf);
			}
			else {
				sleep(12);
				printf("parent --> pid = %d\n", getpid()); // parent process
			}
		}
	}

	return ;
}
