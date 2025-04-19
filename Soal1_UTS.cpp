#include <iostream>
using namespace std;

int main() {
    unsigned long long nomor_kartu, temp, banyak_digit, digit_depan, i, digit, kali_digit, total;
    string tipe_kartu, status_kartu;

    cout << "Program Verifikasi Kartu Digital" << endl << endl;
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor_kartu;
    cout << endl;
    
    banyak_digit = 0;
    temp = nomor_kartu;
    while (temp > 0) {
        banyak_digit++;
        temp /= 10;
    }

    temp = nomor_kartu;
    for (i = 1; i <= banyak_digit - 2; i++) {
        temp /= 10;
    }
    digit_depan = temp;

    if (banyak_digit == 14 && digit_depan == 65) 
    tipe_kartu = "NUSANTARA";
    else if (banyak_digit == 15 && digit_depan == 91)
    tipe_kartu = "MERDEKA";
    else if (banyak_digit == 16 && (digit_depan == 77 || digit_depan == 78))
    tipe_kartu = "GARUDA";
    else {
        cout << "Nomor kartu tidak valid. Nomor tidak sesuai untuk tipe kartu mana pun.";
        return 1;
    }
    
    total = 0;
    temp = nomor_kartu;
    for (i = 1; i <= banyak_digit; i++) {
        digit = temp % 10;
        temp /= 10;
        if (i % 2 == 0) {
            kali_digit = digit * 2;
            if (kali_digit > 9) {
            kali_digit = (kali_digit / 10) + (kali_digit % 10);
            }
            total += kali_digit;
        }
        else {
            total += digit;
        }
    }

    if (total % 10 == 0)
    status_kartu = "VALID";
    else 
    status_kartu = "TIDAK VALID";

    cout << "Tipe kartu: " << tipe_kartu << endl;
    cout << "Nomor kartu " << status_kartu << "." << endl;
    return 0;
}


/*Penjelasan Algoritma serta Logika Penyelesaian Masalah

Program ini memiliki alur penyelesaian (Algoritma) sebagai berikut.
1. Program akan terlebih dahulu meminta input pengguna yang berupa nomor kartu dan menyimpannya pada variabel "nomor_kartu".

2. Proses penghitungan banyak digit dari nomor kartu yang dimasukkan akan dilakukan dengan langkah, yaitu:
   - Inisialisasi variabel "banyak_digit" dengan nilai 0.
   - Penyimpanan nomor_kartu pada variabel "temp" untuk mencegah perubahan angka pada variabel nomor_kartu yang akan digunakan utuk proses selanjutnya.
   - Struktur perulangan while akan dilakukan selama temp bernilai lebih dari 0, lalu variabel "banyak_digit" akan ditambah 1 pada setiap perulangan, kemudian nilai temp akan dibagi 10.
     Pembagian dengan 10 dilakukan karena notasi angka yang digunakan adalah desimal (0 -9) sehingga jika temp masih dapat dibagi 10, ini menunjukkan terdapat digit yang tersisa
     dan akan ditambahkan pada variabel banyak digit sehingga banyak digit diperoleh.

3. Proses perhitungan untuk mendapatkan 2 digit paling depan akan dilakukan dengan langkah, yaitu:
   - Penyimpanan nomor_kartu pada variabel "temp" untuk mencegah perubahan angka pada variabel nomor_kartu yang akan digunakan utuk proses selanjutnya.
   - Penggunaan struktur perulangan for dengan batasan perulangan dari 1 sampai banyaknya digit dikurangi 2 lalu temp akan terus dibagi 10 selama perulangan ini.
     Pembagian 10 pada temp dengan batasan dari 1 banyaknya digit ditujukan untuk menyisakan dua digit paling depan setelah proses pembagian.
   - Hasil yang diperoleh akan disimpan pada variabel "digit_depan".

4. Proses seleksi tipe kartu akan dilakukan dengan pemeriksaan kriteria melalui percabangan dengan syarat:
   - Jika banyaknya digit adalah 14 dengan 2 digit depan bernilai 65, tipe kartu akan didefinisikan sebagai "NUSANTARA"
   - Jika banyaknya digit adalah 15 dengan 2 digit awal bernilai 91, tipe kartu akan didefinisikan sebagai "MERDEKA"
   - Jika banyaknya digit adalah 16 dengan 2 digit awal bernilai 77 atau 78, tipe kartu akan didefinisikan sebagai "GARUDA"
   - Jika satu pun syarat tidak terpenuhi, program akan menampilkan "Nomor kartu tidak valid. Nomor tidak sesuai untuk tipe kartu mana pun." lalu menghentikan program.

5. Proses penjumlahan digit akan dilakukan dengan langkah, yaitu:
   - Inisialisasi variabel "total" dengan nilai 0.
   - Penyimpanan nomor_kartu pada variabel "temp".
   - Penggunaan struktur perulangan for dengan batasan dari 1 sampai banyaknya jumlah digit.
   - Digit dari yang paling kanan akan diperoleh dengan operasi mod antara temp dengan 10 lalu menyimpannya pada variabel "digit".
   - Pembagian temp dengan 10 melalui pembulatan akan dilakukan untuk bergeser ke digit yang lebih kiri pada perulangan berikutnya.
   - Struktur percabangan untuk mengecek digit yang paling belakang dilakukan di mana jika i yang merujuk pada digit di kanan yang sedang dieksekusi habis dibagi 2, 
     ini menandakan bahwa digit tersebut terletak di posisi kelipatan 2 dari belakang, sehingga sesuai dengan peraturan digit tersebut akan dikalli 2 dan disimpan pada variabel "kali_digit".
      * Jika hasil perkalian > 9, hasil tersebut akan dibagi 10 secara bulat dan diopeasikan dengan mod 10 yang masing-masing akan mendapatkan digit depan dan belakang pada bilangan puluhan.
        2 digit tersebut kemudian dijumlahkan dan disimpan pada variabel "kali_digit"
      * Jika hasil perkalian <= 9, persamaan sebelumnya tidak akan diproses.
        Program kemudian akan menjumlahkan  setiap hasil yang diperoleh melalui perulangan dan menyimpannya pada variabel total.
     Jika pengecekan syarat habis dibagi 2 sebelumnya tidak terpenuhi, ini menandakan digit tidak termasuk pada susunan kedua dari belakang sehingga
     digit tersebut akan dijumlahkan pada setiap perulangan dan disimpan pada variabel total.

6. Proses seleksi status kartu dilakukan dengan pemeriksaan kriteria melalui percabangan dengan syarat:
   - Jika total habis dibagi 10, status kartu adalah "VALID".
   - Jika tidak habis dibagi 10, status kartu adalah "TIDAK VALID".

7. Program menampilkan output berupa tipe kartu serta status kartu tersebut. Kemudian, program akan berhenti.*/