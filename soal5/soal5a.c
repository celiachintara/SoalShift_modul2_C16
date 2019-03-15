#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include <string.h>

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

  while(1) {
  	char locsys[100] = "/var/log/syslog";
       
	time_t waktuasli;
	time(&waktuasli); //jagajaga
    struct tm *timez;
	timez = localtime(&waktuasli);
	
	char timestamp[100];
    sprintf(timestamp , "%02d:%02d:%d-%02d:%02d" , timez->tm_mday , timez->tm_mon+1 , timez->tm_year+1900 , timez->tm_hour , timez->tm_min); //pake 02d biar jd 2 digit
	
	if(mkdir("/home/celiachintara/log",0777));
	char loc[200] = "/home/celiachintara/log/";
	
	char nama[200]; //
	strcpy(nama,loc);
	strcat(nama,timestamp);
	mkdir(nama,0777);

	char temp[300];

	int menit;
	for(menit=0 ; menit<30 ; menit++){
		
		FILE *now , *next ;
		now = fopen(locsys , "r");
		
		char file_dalam[300];
		strcpy(file_dalam , nama);
		char nomerlog[50];
		sprintf(nomerlog, "/log%d.log", menit+1);
		strcat(file_dalam , nomerlog);

		next = fopen(file_dalam,"w+");
		
		while((fgets(temp,sizeof(temp),now)) != NULL){
			fputs(temp,next);
		}
		fclose(now);
		fclose(next);
		sleep(60);
	}
  }
  exit(EXIT_SUCCESS);
}
