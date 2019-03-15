#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int p[2];
    pid_t child_id;
    pid_t child_id2;
    pid_t child_id3;
    int stat;
    
    pipe(p);
    child_id = fork();
    if(child_id == 0){
    	char *unzip[] = {"unzip","/home/irkham/SISOP/modul2/campur2.zip", NULL};
 		execvp("unzip",unzip);
 	}
    else{
	    while ((wait(&stat)) > 0);
	    	child_id2 = fork();
    	if(child_id2 == 0){
  			dup2(p[1], 1);
            close(p[0]);
            char *ls[] = {"ls","/home/irkham/SISOP/modul2/campur2", NULL};
            execvp("ls", ls);
      }
      else{
        child_id3 = fork();
  		if(child_id3 > 0){
			while (wait(&stat) > 0);
       		int open_file;
       		open_file = open("daftar.txt",O_WRONLY); 
            dup2(p[0], 0);
            close(p[1]);
            
       		dup2(open_file, 1);
            char *grep[] = {"grep", "[.]txt$", NULL};
            execvp("grep", grep);
            close(p[0]);
            
         	
		}	
  		else{
       		char *touch[] = {"touch","daftar.txt",NULL};
     		execvp("touch",touch);
  		}
  
    	}	
    	
	}
}
