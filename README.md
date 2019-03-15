# SoalShift_modul2_C16

1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar. 

Catatan : Tidak boleh menggunakan crontab.

#### Jawaban :
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
memset(old, '\0' , sizeof(old));
memset(grey, '\0' , sizeof(grey));
```

- char new[2000], old[1000] , grey[20] : membuat array bertipe char yang akan digunakan untuk menyimpan direktori asal, yang baru, dan menyimpan tambahan kata "_grey.png".
- memset(new, '\0' , sizeof(new)) : meng-set seluruh array berisi null.
  memset(old, '\0' , sizeof(old))
  memset(grey, '\0' , sizeof(grey))
  
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



2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.

Catatan: Tidak boleh menggunakan crontab.

#### Jawaban :




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



4. Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
- dilarang menggunakan crontab
- Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

#### Jawaban :




5. Kerjakan poin a dan b di bawah:

a. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log

Ket:
- Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
- Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1

b. Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

#### Jawaban :

