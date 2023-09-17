#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	
	int m = 100,
	n = 0;
	int data[m];
	char x;
	
	// -- MEMASUKKAN INPUT DAN MENGAKHIRI DENGAN HURUF
	cout<<"--------------------------------------------------------"<<endl;
	cout<<" Masukkan input data dan mengakhirinya dengan huruf"<<endl;
	cout<<"(Jangan menginput angka 0 plis karna programnya akan error)"<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	for(int i=0; i<m; i++){
		cout<<"Data ke-"<<i+1<<" = ";
		cin>>data[i];
		if(data[i]==x){
			break;
		}
		n++;
	}
	cout<<"---------------------------"<<endl;
	int jml_sisabagi;
	int array_a [n], array_b[n];
	int indeks_a = 0;
	int indeks_b = 0;
	
	// -- MEMISAHKAN BIL. PRIMA DAN BUKAN BIL. PRIMA --
	for(int i=0; i<n; i++){
		jml_sisabagi= 0;
		
		if(data[i]>1){
			for(int j=2; j*2 <= data[i]; j++){
				if(data[i]%j == 0){
				jml_sisabagi++;
				}
			}
			if(jml_sisabagi==0){
				array_a[indeks_a] = data[i];
				indeks_a++;
			}
			else{
				array_b[indeks_b] = data[i];
				indeks_b++;
			}
		}
		else if(data[i] == 0 || data[i] == 1){
			array_b[indeks_b] = data[i];
			indeks_b++;
		}
	}
	
	cout<<"---------------------------"<<endl;
	cout<<" Data Asli"<<endl;
	cout<<" Variabel A : ";
	for(int i=0; i<indeks_a; i++){
		cout<<" "<<array_a[i]<<" ";
	}
	cout<<endl;
	
	cout<<" Variabel B : ";
	for(int i=0; i<indeks_b; i++){
		cout<<" "<<array_b[i]<<" ";
	}
	
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<" Data setelah diurutkan"<<endl;
	for(int i=0; i<indeks_a; i++){
		for(int j=i+1; j<indeks_a; j++){
			if(array_a[j]<array_a[i]){
				float temp = array_a[i];
				array_a[i] = array_a[j];
				array_a[j] = temp;
			}
		}
	}
	for(int i=0; i<indeks_b; i++){
		for(int j=i+1; j<indeks_b; j++){
			if(array_b[j]<array_b[i]){
				float temp = array_b[i];
				array_b[i] = array_b[j];
				array_b[j] = temp;
			}
		}
	}
	cout<<" Variabel A : ";
	for(int i=0; i<indeks_a; i++){
		cout<<" "<<array_a[i]<<" ";
	}
	cout<<endl;
	cout<<" Variabel B : ";
	for(int i=0; i<indeks_b; i++){
		cout<<" "<<array_b[i]<<" ";
	}
	
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<" Statistika deskriptif dari Variabel A dan B"<<endl;
	cout<<"============================================="<<endl;
	cout<<" Variabel\tq1\tq2\tq3"<<endl;
	cout<<"============================================="<<endl;
	cout<<" A\t\t";
	
	// -- Posisi Kuartil A --
	float pq1;
	pq1 = (indeks_a+1)/4.0;
	float pq2;
	pq2 = (indeks_a+1)/2.0;
	float pq3;
	pq3 = 3*(indeks_a+1)/4.0;
	
	// -- Menentukan nilai kuartilnya Variabel A --
	float nilai_q1, nilai_q2, nilai_q3;
	
	int trunc_q1 = trunc(pq1);
	int trunc_q2 = trunc(pq2);
	int trunc_q3 = trunc(pq3);
	
	nilai_q1 = array_a[trunc_q1-1]+(array_a[trunc_q1]-array_a[trunc_q1-1])*(pq1-trunc_q1);
	nilai_q2 = array_a[trunc_q2-1]+(array_a[trunc_q2]-array_a[trunc_q2-1])*(pq2-trunc_q2);
	nilai_q3 = array_a[trunc_q3-1]+(array_a[trunc_q3]-array_a[trunc_q3-1])*(pq3-trunc_q3);
	
	cout<<nilai_q1<<"\t"<<nilai_q2<<"\t"<<nilai_q3<<"\t"<<endl;
	
	cout<<" B\t\t";
	
	// -- Posisi Kuartil B --
	float pq11;
	pq11 = (indeks_b+1)/4.0;
	float pq22;
	pq22 = (indeks_b+1)/2.0;
	float pq33;
	pq33 = 3*(indeks_b+1)/4.0;
	
	// -- Menentukan nilai kuartilnya Variabel B --
	float nilai_q11, nilai_q22, nilai_q33;
	
	int trunc_q11 = trunc(pq11);
	int trunc_q22 = trunc(pq22);
	int trunc_q33 = trunc(pq33);
	
	nilai_q11 = array_b[trunc_q11-1]+(array_b[trunc_q11]-array_b[trunc_q11-1])*((pq11-1)-(trunc_q11-1));
	nilai_q22 = array_b[trunc_q22-1]+(array_b[trunc_q22]-array_b[trunc_q22-1])*((pq22-1)-(trunc_q22-1));
	nilai_q33 = array_b[trunc_q33-1]+(array_b[trunc_q33]-array_b[trunc_q33-1])*((pq33-1)-(trunc_q33-1));
	
	cout<<nilai_q11<<"\t"<<nilai_q22<<"\t"<<nilai_q33<<"\t"<<endl;
	
	cout<<"============================================="<<endl;
	
}
