#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>


int main()
{
 pid_t pid, sid;
    pid = fork();
    if (pid < 0){
        exit(EXIT_FAILURE);
    }
    if (pid > 0){
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0){
        exit(EXIT_FAILURE);
    }
    if ((chdir("/")) < 0){
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    while(1){
        DIR *dir;
  chdir("/home/celiachintara/SISOP/prak2/gambar/");
  dir=opendir("/home/celiachintara/SISOP/prak2/");
  struct dirent *ent;
  int length;
  
  char new[2000], old[1000] , grey[20],fn[100];
  memset(new, '\0' , sizeof(new));
  memset(old, '\0' , sizeof(old));
  memset(grey, '\0' , sizeof(grey));
  memset(fn, '\0' , sizeof(fn));

  char *pointer;

  while((ent=readdir(dir)) != NULL){
    strcpy(fn,ent->d_name);
    pointer = strrchr(fn,'.');
    printf("1");
    if(pointer && (strcmp(pointer,".png")==0)){
printf("2");
    *pointer = '\0';
    length = strlen(ent->d_name);
    strcpy(old, "/home/celiachintara/SISOP/prak2/");
    strcpy(new,"/home/celiachintara/SISOP/prak2/gambar/");
    strcpy(grey, "_grey.png");
    
    strcat(old,ent->d_name);
    strncat(new, ent->d_name,length-4);
    strcat(new,grey);
    
    pid_t child_id;
          int status;
          
          child_id = fork();
  
          if (child_id == 0) {
            char *argv[4] = {"mv", old, new, NULL};
            execv("/bin/mv", argv);
          }
          else{
            while ((wait(&status)) > 0);
          }
   }
  }
  closedir(dir);
     sleep(1);
 }
 exit(EXIT_SUCCESS);
}
