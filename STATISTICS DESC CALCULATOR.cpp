#include <iostream>
#include <math.h>
using namespace std;

int main (){
 
 //deklarasi variabel
 int i, jml_data;
 float nilai[999];
 
 cout<<"\n     KALKULATOR STATISTIKA DESKRIPTIF"<<endl;
 cout<<"==========================================="<<endl;
 cout<<" Masukkan banyaknya data yang ingin diinput: ";cin>>jml_data;
 cout<<"-----------------------------------------------"<<endl;
 
 for(i=1;i<=jml_data;i++){
  cout<<" Data ke-"<<i<<": ";cin>>nilai[i];
 }
 cout<<"______________________________________________"<<endl;
 
 //Urutan data
 cout<<" Urutan Data: "<<endl;
 cout<<"----------------------------------------------"<<endl;
 
 for(i=1;i<=jml_data;i++){
  for(int j=i+1;j<=jml_data;j++){
   if(nilai[j]<nilai[i]){
    float temp = nilai[i];
    nilai[i]=nilai[j];
    nilai[j]=temp;
   }
  }
 }
 
 for(i=1;i<=jml_data;i++){
  cout<<" "<<nilai[i];
 }
 
 //rata-rata
 float rata_rata = 0;
 for(i=1;i<=jml_data;i++){
  rata_rata += nilai[i];
 }
 rata_rata = rata_rata/jml_data;
 
 //median
 float median;
 if(jml_data%2==0){
  median = (nilai[jml_data/2]+nilai[(jml_data/2)+1])/2;
 }
 else{
  median = nilai[(jml_data/2)+1];
 }
 
 
 //modus
 int frekuensi[999] = {0}; // inisialisasi semua elemen array menjadi 0

 for(i=1;i<=jml_data;i++){
     for(int j=1;j<=jml_data;j++){
         if(nilai[i] == nilai[j]){
             frekuensi[i]++;
         }
     }
 }

 int max_frekuensi = 0;
 for(i=1;i<=jml_data;i++){
     if(frekuensi[i] > max_frekuensi){
         max_frekuensi = frekuensi[i];
     }
 }
 
 //maksimum dan minimum
 float maks, min;
 maks = nilai[1];
 min = nilai[1];
 
 for(i=1;i<=jml_data;i++){
  if(i==1){
   maks = nilai[i];
   min = nilai[i];
  }
  else if(nilai[i]>maks){
   maks = nilai[i];
  }
  else if(nilai[i]<min){
   min = nilai[i];
  }
  else {
  }
 }
 
 //range
 float range = maks - min;
 
 //rata-rata ukur
 float angka_satu = 1;
 float rata2_ukur;
 for(i=1;i<=jml_data;i++){
  angka_satu *= nilai[i];
 }
 rata2_ukur = pow(angka_satu, (1.0/jml_data));
 
 
 
 //standar deviasi sampel
 float sd_sampel = 0;
 for(i=1;i<=jml_data;i++){
  sd_sampel += pow(nilai[i]-rata_rata, 2)/(jml_data-1);
 }
 sd_sampel = sqrt(sd_sampel);
 
 //standar deviasi populasi
 float sd_populasi = 0;
 for(i=1;i<=jml_data;i++){
  sd_populasi += pow(nilai[i]-rata_rata, 2)/jml_data;
 }
 sd_populasi = sqrt(sd_populasi);
 
 //varian sampel
 float varian_sampel;
 varian_sampel = pow(sd_sampel, 2);
 
 //varian populasi
 float varian_populasi;
 varian_populasi = pow(sd_populasi, 2);
 
 
 
 //simpangan rata-rata
 float simp_rata2 = 0;
 for(i=1;i<=jml_data;i++){
  simp_rata2 += abs(nilai[i]-rata_rata); 
 }
 simp_rata2 = simp_rata2/jml_data;

    //koefisien variasi
    float kv;
    kv = sd_populasi/rata_rata;
 
 
 //output
 cout<<"\n=============================================="<<endl;
 cout<<"\n Rata-rata   = "<<rata_rata<<endl;
 cout<<" Median    = "<<median<<endl;
 cout<<" Modus    = ";
 float modus[999] = {0};
    int n_modus = 0;
    for (i = 1; i <= jml_data; i++) {
        if (frekuensi[i] == max_frekuensi) {
            bool sudah_ada = false;
            for (int j = 0; j < n_modus; j++) {
                if (nilai[i] == modus[j]) {
                    sudah_ada = true;
                    break;
                }
            }
            if (!sudah_ada) {
                modus[n_modus++] = nilai[i];
                cout << nilai[i] << " ";
            }
        }
    }
 cout<<"\n Maks    = "<<maks<<endl;
 cout<<" Min    = "<<min<<endl;
 cout<<" Range    = "<<range<<endl;
 cout<<" Rata-rata ukur   = "<<rata2_ukur<<endl;
 cout<<" Standar deviasi sampel  = "<<sd_sampel<<endl;
 cout<<" Standar deviasi populasi = "<<sd_populasi<<endl;
 cout<<" Varian sampel   = "<<varian_sampel<<endl;
 cout<<" Varian populasi  = "<<varian_populasi<<endl;
 cout<<" Simpangan rata-rata  = "<<simp_rata2<<endl;
 cout<<" Koefisien variasi  = "<<kv<<endl;
 cout<<endl;
 
 return 0;
}
