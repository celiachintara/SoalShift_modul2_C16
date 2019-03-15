#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(){
    char t[10];
    FILE *openfile = popen("pidof /home/celiachintara/SISOP/prak2/soal5a", "r"); //mencari pid dari direktori

    fgets(t, 10, openfile); //menyimpan dalam bentuk variabel
    
	pid_t pid;
	pid = strtoul(t, NULL, 12); //konversi menuju unsigned long integer

    pclose(openfile);

    if(!kill(pid, SIGKILL)) //kill proses
        printf("Proses yang memiliki pid %d telah berhasil dihentikan\n", pid);

}
