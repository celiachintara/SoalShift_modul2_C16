#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  while(1){
  	char loc[200] = {"/home/celiachintara/Documents/makanan/makan_enak.txt"};
  	char rem[200] = {"/home/celiachintara/Documents/makanan/makan_sehat"};
  	
  	char c[10000];
  	memset(c,'\0',sizeof(c));
  	int count = 1;
  	
	struct stat hm;
	FILE *file;
	
	time_t lastvisited = hm.st_mtime;
	stat(loc,&hm);
	
	if(difftime(time(NULL),lastvisited) <= 30){
		sprintf(c,"%d",count);
		count++;
		strcat(c,".txt");
		strcat(rem,c);
		
		file=fopen(rem,"w+");
		fclose(file);
	}
	
	sleep(5);
  }
  
  exit(EXIT_SUCCESS);
}
