#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
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

int main(){
 pid_t pid, sid;
 pid = fork();
 if(pid<0){
  exit(EXIT_FAILURE);
 }
 
 if(pid>0){
  exit(EXIT_SUCCESS);
 }

 umask(0);

 sid = setsid(); 
 if(sid<0){
  exit(EXIT_FAILURE);
 }

 if((chdir("/")) < 0){
  exit(EXIT_FAILURE);
 }

 close(STDIN_FILENO);
 close(STDOUT_FILENO);
 close(STDERR_FILENO);

 while(1){
  struct stat file;
  char loc[100] = "/home/celiachintara/SISOP/prak2/hatiku/elen.ku";
  
  if( stat(loc,&file) == 0){
   chmod(loc, S_IRWXU|S_IRWXG|S_IRWXO);
  
   struct passwd *pw;
   pw = getpwuid(file.st_uid);
   struct group *gr;
   gr  = getgrgid(file.st_gid);

   char *ow , *grp;
   ow = pw->pw_name;
   grp = gr->gr_name;

   if(strcmp(ow,"www-data")==0 && strcmp(grp,"www-data")==0){
    remove(loc);
   }

  }
  sleep(3);
 }
 exit(EXIT_SUCCESS);
}
