// Program Kalkulator
// Program untuk menghitung penjumlahan pengurangan, perkalian, pembagian, perpangkatan, dan integral metode trapesium

#include <iostream>
using namespace std;

//Deklarasi Fungsi
float jumlah(float x,float y);  //Menghasilkan x+y
float kurang(float x,float y);  //Menghasilkan x-y
float kali(float x,float y);    //Menghasilkan x*y
float bagi(float x,float y);    //Menghasilkan x/y
float pangkat(float x,int y);   //Menghasilkan a^b


//PROGRAM UTAMA
int main(){
    //KAMUS
    int opr, derajat, i, j, part;
    float a, b, konstanta, hasil, hasil_a, hasil_b, sum, width, area;

    //ALGORITMA
    cout << "1.Penjumlahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Perpangkatan\n6.Integral\nPilih operasi: ";
    cin >> opr;
    //Membagi kasus-kasus berdasarkan operasi
    switch (opr){
        case 1:{    //Penjumlahan
            cout << "Bilangan pertama: "; cin >> a;
            cout << "Bilangan kedua: "; cin >> b;
            cout << a << "+" << b << "=" << jumlah(a,b); break;
        }
        case 2:{    //Pengurangan
            cout << "Bilangan pertama: "; cin >> a;
            cout << "Bilangan kedua: "; cin >> b;
            cout << a << "-" << b << "=" << kurang(a,b); break;
        }
        case 3:{    //Perkalian
            cout << "Bilangan pertama: "; cin >> a;
            cout << "Bilangan kedua: "; cin >> b;
            cout << a << "*" << b << "=" << kali(a,b); break;
        }
        case 4:{    //Pembagian
            cout << "Pembilang: "; cin >> a;
            cout << "Penyebut: "; cin >> b;
            cout << a << "/" << b << "=" << bagi(a,b); break;
        }
        case 5:{    //Perpangkatan
            cout << "Basis: "; cin >> a;
            cout << "Eksponen: "; cin >> b;
            cout << a << "^" << b << "=" << pangkat(a,b); break;
        }
        case 6:{    //Integral
            cout << "Derajat fungsi polinomial: "; cin >> derajat;
            float koef[derajat];
            cout << "Konstanta: "; cin >> konstanta;
            for (i=0; i<derajat; i++){
                cout << "Koefisien derajat " << i+1 << ": "; cin >> koef[i];
            }
            cout << "Batas bawah: "; cin >> a;
            cout << "Batas atas: "; cin >> b;
            hasil_a=konstanta; hasil_b=konstanta;
            for (i=0; i<derajat; i++){
                hasil_a = hasil_a + (koef[i]*pangkat(a,i+1));
            }
            for (i=0; i<derajat; i++){
                hasil_b = hasil_b + (koef[i]*pangkat(b,i+1));
            }
            cout << "Jumlah partisi: "; cin >> part;
            hasil = konstanta;
            sum = 0; width = (b-a)/part;
            for (i=1; i<part; i++){
                hasil = konstanta;
                for (j=0; j<derajat; j++){
                    hasil += koef[j]*pangkat(a+width*i, j+1);
                }
                sum += hasil;
            }
            area = width/2*(hasil_a+hasil_b+2*sum);
            cout << "Hasil integral: "; cout << area; break;
        }
        default:{   //Input operasi bukan angka 1 sampai 6
            cout << "Nomor operasi tidak tepat."; break;
        }
    }
    return 0;
}

//Realisasi fungsi
float jumlah(float x,float y){
    return(x+y);
}
float kurang(float x,float y){
    return(x-y);
}
float kali(float x,float y){
    return(x*y);
}
float bagi(float x,float y){
    return(x/y);
}
float pangkat(float x,int y){
    //KAMUS LOKAL
    int i;
    float hasil;
    //ALGORITMA
    hasil = x;
    for (i=1; i<y; i++){
        hasil = hasil*x;
    }
    return hasil;
}
