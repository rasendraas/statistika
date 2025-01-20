#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	//Rasendra Akbar Satyatama_5003221120
	//Nomor 1
	
	int n;
	cout<<"n (Banyak Data) : ";cin>>n;
	
	//Input data
	int data[50];
	for(int i=1; i<=n; i++){
		cout<<"Data ke-"<<i<<" = ";
		cin>>data[i];
		
	}
	cout<<"-----------------------------"<<endl;

	// VEKTOR A
	
	/*Inisialisasi nilai variabel untuk rata-rata 
	dan banyaknya elemen vektor A*/
	int n_a = 0;
	float rata2 = 0;
	
	/*Menampilkan vektor A yaitu genap & menyimpan bilangan genap
	ke variabel "vektor1"*/
	cout<<"Vektor A (Genap) = ";
	int indeks_A = 1; //indeks untuk nyimpen nilai2 di vektor A
	float vektor1[50];
	for(int i = 1; i<=n; i++){
		if(data[i]%2==0){
			cout<<data[i]<<" ";
			n_a ++; //n_a untuk menyimpan berapa banyak elemen di vektor A
			rata2 += data[i]; //mengihitung rata-rata
			vektor1[indeks_A++] = data[i]; //menyimpan bil genap ke variabel vektor1
		}
	}		
	rata2 /= n_a;
	
	float s_dev = 0;
	for(int i = 1; i<=n_a; i++){
		s_dev += pow(vektor1[i]-rata2, 2);	
	}
	s_dev = sqrt(s_dev/n_a);
	
	cout<<endl;
	
	
	// VEKTOR B
	
	//Menyimpan bilangan ganjil pada variabel "vektor2"
	int n_b = 0, 
	indeks_b = 1;
	
	float vektor2[50];
	cout<<"Vektor B (Ganjil) = ";
	for (int i = 1; i<=n ; i++){
		if(data[i]%2!=0){
			cout<<data[i]<<" ";
			vektor2[indeks_b++]=data[i]; //Memasukkan nilai elemen vektor B dari data [i]
			n_b++; //Variabel banyaknya elemen di vektor B
		}
	}
	cout<<endl;
	
	cout<<"-----------------------------"<<endl;
	
	//urutkan data vektor B dengan algoritma BUBBLE SORT
	for(int i = 1; i<=n_b; i++){
		for(int j = i+1; j<=n_b; j++){
			if(vektor2[j]<vektor2[i]){
				float kosong = vektor2[i];
				vektor2[i] = vektor2[j];
				vektor2[j] = kosong;
			}
		}		
	}
	
	// median
	float median;
	if(n_b%2==0){
		median = (vektor2[n_b/2]+vektor2[(n_b/2)+1])/2;
	}
	else{
		median = vektor2[(n_b+1)/2];
	}
	
	//Ouput Perhitungan VEKTOR A & B
	cout<<"Mean (Vektor A) = "<<rata2<<endl;
	cout<<"Standar Deviasi (Vektor A) = "<<s_dev<<endl;
	cout<<"Urutan Data (Vektor B) : ";
	for(int i = 1; i<=n_b; i++){
		cout<<vektor2[i]<<" ";
	}
	
	cout<<"\nMedian (Vektor B) = "<<median<<endl;
	
}
