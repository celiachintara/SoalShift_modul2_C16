# SoalShift_modul2_C16

1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar. 

Catatan : Tidak boleh menggunakan crontab.

#### Jawaban :

Membuat script soal1.c pada terminal
```
nano soal1.c
```

Kemudian, berikut penjelasan dari script soal1.c yang telah kami buat
```
DIR *dir;
chdir("/home/irkham/SISOP/modul2/gambar/");
dir=opendir("/home/irkham/SISOP/modul2/");
struct dirent *ent;
int length;
```

- DIR *dir; : membuat sebuah variable yang bernama dir dengan tipe DIR.
- chdir("/home/irkham/SISOP/modul2/gambar/") : menentukan spesifikasi path tujuan.
- dir=opendir("/home/irkham/SISOP/modul2/") : variable dir membuka folder dengan direktori seperti yang tertulis.
- struct dirent *ent : variable ent yang bertipe struct dirent yaitu sebuauh tipe struktur yang mengembalikan informasi mengenai direktori suatu entri.
- int length : variable length dengan tipe integer yang nantinya berfungsi untuk menyimpan panjang karakter dari nama filenya.

```
char new[2000], old[1000] , grey[20];
memset(new, '\0' , sizeof(new));
...
...
```

- char new[2000], old[1000] , grey[20] : membuat array bertipe char yang akan digunakan untuk menyimpan direktori asal, yang baru, dan menyimpan tambahan kata "_grey.png".
- memset(new, '\0' , sizeof(new)) : meng-set seluruh array berisi null.
  
```
while((ent=readdir(dir)) != NULL){
 if(strstr(ent->d_name,".png") != NULL){
   length = strlen(ent->d_name);
```
- while((ent=readdir(dir)) != NULL): variable ent membaca isi dir, jika ada isinya (tidak NULL), maka perintah dalam while tersebut akan dijalankan.
- if(strstr(ent->d_name,".png") != NULL): perintah **strstr** berfungsi untuk memotong string. String yang dipotong adalah string d_name yang diambil dari variable ent, stringnya dipotong dari mulai tulisan ".png". jadi yang didapat yaitu hanya nama filenya saja tanpa ekstensinya.
- length = strlen(ent->d_name) : menghitung panjang karakter dari string d_name dari variable ent.

```
strcpy(old, "/home/irkham/SISOP/modul2/");
strcpy(new,"/home/irkham/SISOP/modul2/gambar/");
strcpy(grey, "_grey.png");
```

- strcpy(old, "/home/irkham/SISOP/modul2/") : meng-copy tulisan dikanan tanda koma(,) , ke dalam variable old.
- strcpy(new,"/home/irkham/SISOP/modul2/gambar/") : meng-copy tulisan dikanan tanda koma(,) , ke dalam variable new;
- strcpy(grey, "_grey.png") : meng-copy tulisan dikanan tanda koma(,) , ke dalam variable grey.

```
strcat(old,ent->d_name);
strncat(new, ent->d_name,length-4);
strcat(new,grey);
```

- strcat(old,ent->d_name) : menggabungkan isi variable old dengan string d_name dari variable ent, maka akan didapatkan direktori lengkap dari file asli serta nama filenya dan hasilnya akan meng-replace isi variable old sebelumnya.
- strncat(new, ent->d_name,length-4) : menggabungkan isi variable new dengan string d_name dari variable ent sebanyak *length - 4* karakter, dikurangi 4 karakter yaitu (.) (p) (n) (g) , maka akan didapatkan direktori tujuan serta nama filenya dan hasilnya akan meng-replace isi variable new sebelumnya.
- strcat(new,grey) : menggabungkan isi variable new dengan variable grey, maka akan didapatkan direktori tujuan serta nama filenya yang sudah dilengkapi dengan tambahan kata "_grey.png" dan hasilnya akan mengreplace isi variable new sebelumnya.

``` 
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
```

- char *argv[4] = {"mv", old, new, NULL} : memindahkan file dari direktori old ke direktori new.

Kemudian, compile soal1.c dengan cara mengetikkan ini di terminal
```
gcc -o soal1 soal1.c
```

Kemudian, run soal1 yang telah dibuat dengan mengetikkan ini di terminal
```
./soal1
```



2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.

Catatan: Tidak boleh menggunakan crontab.

#### Jawaban :

Buatlah folder /hatiku
```
mkdir hatiku
```

Buat file bernama *elen.ku* didalam folder /hatiku
```
cd hatiku
touch elen.ku
```

Membuat script soal2.c pada terminal
```
nano soal2.c
```

Berikut penjelasan script soal2.c yang telah kami buat
```
struct stat file;
  char loc[100] = "/home/celiachintara/SISOP/prak2/hatiku/elen.ku";
```

- struct stat file : membuat variable bernama file yang bertipe struct stat, yaitu variable yang dapat menyimpan informasi tentang file itu sendiri.
- char loc[100] = "/home/celiachintara/SISOP/prak2/hatiku/elen.ku" : membuat variable array of char bernama loc yang berisikan direktori dari file elen.ku.

```
if( stat(loc,&file) == 0){
   chmod(loc, S_IRWXU|S_IRWXG|S_IRWXO);
```

- if( stat(loc,&file) == 0) : mengarahkan isi variable loc yang berupa direktori menuju alamat variable file.
- chmod(loc, S_IRWXU|S_IRWXG|S_IRWXO) : digunakan untuk mengganti permission file.

```
 struct passwd *pw;
   pw = getpwuid(file.st_uid);
 struct group *gr;
   gr  = getgrgid(file.st_gid);
   
   char *ow , *grp;
   ow = pw->pw_name;
   grp = gr->gr_name;
```

- script diatas digunakan untuk mengecek owner dan group

```
if(strcmp(ow,"www-data")==0 && strcmp(grp,"www-data")==0){
    remove(loc);
   }
```

- membandingkan data yang didapat dari script sebelumnya dengan "www-data" , jika benar maka file yang terdapat dalam variable loc akan terhapus.

```
sleep(3)
```

- karena permintaan soal untuk menghapus file setiap 3 detik, maka digunakan sleep(3). Setelah 3 detik dilalui, maka program akan dijalankan lagi.


Ubah permission file dengan mengetikkan ini di terminal
```
chmod 777 elen.ku
```

Ketikkan pada terminal perintah berikut, untuk mengecek owner dan group 
```
sudo chown www-data:www-data elen.ku
```

Kemudian, compile script soal2.c
```
gcc -o soal2 soal2.c
```

Kemudian, run file soal2
```
./soal2
```




3. Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :

i)  mengekstrak file zip tersebut.

ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 

Catatan:
- Gunakan fork dan exec.
- Gunakan minimal 3 proses yang diakhiri dengan exec.
- Gunakan pipe
- Pastikan file daftar.txt dapat diakses dari text editor

#### Jawaban : 

Membuat script soal3.c
```
nano soal3.c
```

Berikut penjelasan dari script soal3.c yang telah kami buat
```
char *unzip[] = {"unzip","/home/irkham/SISOP/modul2/campur2.zip", NULL};
 		execvp("unzip",unzip);
```

- Perintah untuk meng-unzip folder campur2.zip.

```
dup2(p[1], 1);
            close(p[0]);
            char *ls[] = {"ls","/home/irkham/SISOP/modul2/campur2", NULL};
            execvp("ls", ls);
```

- Perintah untuk meng-list isi dari folder campur2.

```
dup2(open_file, 1);
            char *grep[] = {"grep", "[.]txt$", NULL};
            execvp("grep", grep);
```

- Perintah untuk memfilter file didalam folder campur2 yang memiliki ekstensi .txt.

```
char *touch[] = {"touch","daftar.txt",NULL};
     		execvp("touch",touch);
```

- Perintah untuk membuat file daftar.txt.


Kemudian, compile script soal3.c dengan mengetikkan ini pada terminal
```
gcc -o soal3 soal3.c
```

Kemudian, run file soal3
```
./soal3
```





4. Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
- dilarang menggunakan crontab
- Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

#### Jawaban :

Membuat folder /makanan dalam folder /Documents dan pastikan file makanan_enak.txt terletak didalam folder makanan tadi.
```
mkdir makanan
```

Membuat script soal4.c
```
nano soal4.c
```

Berikut penjelasan script soal4.c yang telah kami buat
```
char loc[200] = {"/home/celiachintara/Documents/makanan/makan_enak.txt"};
char rem[200] = {"/home/celiachintara/Documents/makanan/makan_sehat"};
```

- Membuat variable array of char yang menyimpan direktori asal dan tujuan.

```
char c[10000];
  	memset(c,'\0',sizeof(c));
  	int count = 1;
```

- Membuat array yang akan digunakan untuk menyimpan bilangan bulat untuk penamaan file barunya.

```
time_t lastvisited = hm.st_mtime
```

- Digunakan untuk menyimpan waktu terakhir file makan_enak.txt dibuka.

```
if(difftime(time(NULL),lastvisited) <= 30){
		sprintf(c,"%d",count);
		count++;
		strcat(c,".txt");
		strcat(rem,c);
		
		file=fopen(rem,"w+")
 ```
 
 - Difftime : digunakan untuk mencari selisih waktu saat ini dengan waktu terakhir file makan_enak.txt dibuka.
 - sprintf : digunakan untuk mengkonvert nilai count yang berupa integer menjadi nilai c yang berupa karakter. Setelah diconvert nilai count akan diincrement.
 - strcat(c,".txt") : menggabungkan bilangan bulat tadi dengan string ".txt".
 - strcat(rem,c) : menggabungkan direktori file yang baru dengan bilangan bulat yang telah dilengkapi denggan ekstensi ".txt".

Kemudian, compile script soal4.c dengan mengetikkan ini pada terminal
``` 
gcc -o soal4 soal4.c

```

Kemudian, run file soal4
```
./soal4
```




5. Kerjakan poin a dan b di bawah:

a. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log

Ket:
- Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
- Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1

b. Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

#### Jawaban :

Membuat script soal5a.c
```
nano soal5a.c
```

Berikut penjelasan script soal5a.c yang telah kami buat
``` 
char locsys[100] = "/var/log/syslog";
```

- Membuat array of char untuk menyimpan direktori syslog.

```
time_t waktuasli;
time(&waktuasli); //jagajaga
struct tm *timez;
timez = localtime(&waktuasli);
char timestamp[100];
sprintf(timestamp , "%02d:%02d:%d-%02d:%02d" , timez->tm_mday , timez->tm_mon+1 , timez->tm_year+1900 , timez->tm_hour , timez->tm_min);
```

- Menyimpan tanggal,bulan,tahun dan waktu berupa jam dan menit secara real time.

```
if(mkdir("/home/celiachintara/log",0777));
char loc[200] = "/home/celiachintara/log/";
char nama[200]; 
strcpy(nama,loc);
strcat(nama,timestamp);
mkdir(nama,0777);
```

- if(mkdir("/home/celiachintara/log",0777)) : membuat folder dengan direktori seperti yang tertulis.
- char loc[200] = "/home/celiachintara/log/" : akan digunakan untuk membuat folder log setiap 30 menit.
- char nama[200] : digunakan untuk menyimpan direktori folder log yang akan dibuat dalam folder log setiap 30 menit.
- Setelah dicopy dan digabungkan, kemudian dibuatlah folder sesuai dengan direktori yang sudah diatur dalam variable nama.

```
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
```

- Melakukan for sebanyak 30x dengan sleep(60) , artinya yaitu setiap menit akan dibuat file log selama 30 menit. Jadi dalam 30 menit akan terbentuk 1 folder log dengan isi 30 file log.
- Membuat direktori yang disimpan ke dalam variable file_dalam untuk membuat file log dengan format penamaan "log#.log", # merupakan bilangat bulat yang dimulai dari angka 1 sampai paling besar yaitu 30.
- Isi file yang telah jadi akan dicopy ke sebuah variable temp yang kemudian akan dicopy lagi ke file yang akan tersimpan di dalam folder.


Kemudian, compile script soal5a.c 
```
gcc -o soal5a soal5a.c
```

Kemudian, run file soal5a
```
./soal5a
```

Membuat script soal5b.c
```
nano soal5b.c
```

Berikut penjelasan script soal5b.c yang telah kami buat
```
FILE *openfile = popen("pidof /home/celiachintara/SISOP/prak2/soal5a", "r");
```

- Membuat variable openfile yang bertipe file gunanya untuk membuat file dengan direktori yang tertera di atas. 

```
fgets(t, 10, openfile);
```

- Menyimpan isi openfile ke dalam variable t.

```
pid = strtoul(t, NULL, 12)
```

- Mengkonversi variable t yang berupa string menjadi integer.

```
if(!kill(pid, SIGKILL)) //kill proses
        printf("Proses yang memiliki pid %d telah berhasil dihentikan\n", pid)
```

- Jika proses KILL berhasil, maka akan tercetak tulisan seperti diatas.


Kemudian, compile script soal5b.c
```
gcc -o soal5b soal5b.c
```

Kemudian, run script soal5b
```
./soal5b
```



