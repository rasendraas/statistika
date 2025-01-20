#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// -- FUNGSI RATA-RATA & STANDAR DEVIASI
float rata2(float x[], int n){
	
	float jml = 0;
	for(int i=0; i<n; i++){
		jml += x[i];
	}
	return (jml/n);
}

float standarDeviasi(float x[], float y, int n){
	
	float sd = 0;
	for(int i=0; i<n; i++){
		sd += pow(x[i]-y, 2);
	}
	sd = sqrt(sd/(n-1));
	return (sd);
	
}

int main(){
	
	float var_a[] = {29, 31, 11, 47, 37};
	float var_b[] = {27, 30, 21, 49, 36};
	
	int na = sizeof(var_a)/sizeof(var_a[0]);
	int nb = sizeof(var_b)/sizeof(var_b[0]);
	
	// a. Gabungkan variabel A dan B menjadi suatu matriks
	int matriks_gabungan[na][nb];
	
	for(int i=0; i<na; i++){
		matriks_gabungan[i][0] = var_a[i];
	}
	
	for(int i=0; i<nb; i++){
		matriks_gabungan[i][1] = var_b[i];
	}
	
	cout<<" Gabungan matriks variabel A dan B : "<<endl;
	for(int i=0; i<5; i++){
		for(int j=0; j<2; j++){
			cout<<setw(5)<<matriks_gabungan[i][j]<<"   "; // setw() AGAR KOLOM MATRIKNYA LEBIH RAPIH
		}
		cout<<endl;
	}
	cout<<endl;
	
	// Menghitung Rata2 dan Standar deviasi masing2 Array
	float rata2_a = rata2(var_a, na);
	float rata2_b = rata2(var_b, nb);
	
	float sd_a = standarDeviasi(var_a, rata2_a, na);
	float sd_b = standarDeviasi(var_b, rata2_b, nb);
	
	float Z[50][50];
	for(int i=0; i<5; i++){
		for(int j=0; j<2; j++){
			if(j==0){
				Z[i][j] = (var_a[i]-rata2_a)/sd_a;
			}
			else{
				Z[i][j] = (var_b[i]-rata2_b)/sd_b;
			}
		}
	}
	
	cout<<" Matrik Z : "<<endl;
	cout << fixed << setprecision(5); //NAMBAHIN ANGKA DESIMAL
	for(int i=0; i<5; i++){
		for(int j=0; j<2; j++){
			cout<<setw(10)<<Z[i][j]<<"   "; // setw() AGAR KOLOM MATRIKNYA LEBIH RAPIH
		}
		cout<<endl;
	}
	cout<<endl;
	
	// -- PERHITUNGAN KORELASI
	cout<<" Hasil matrik korelasi : "<<endl;
	
	//Transpose
	float Z_t[50][50];
	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			Z_t[i][j] = Z[j][i];
		}
	}
	
	//Perkalian Z dengan Z_t
	float ZZ_t[50][50];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			ZZ_t[i][j] = 0;
			for(int k=0; k<5; k++){
				ZZ_t[i][j] += Z_t[i][k]*Z[k][j];
			}
		}
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			ZZ_t[i][j] = ZZ_t[i][j]/(na-1);
			cout<<setw(9)<<ZZ_t[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//PERNYATAAN KONDISI
	if(ZZ_t[0][1]>0.5){
		cout<<" Variabel A dan B memiliki hubungan yang positif dan kuat sebesar "<<ZZ_t[0][1]<<endl;
	}
	else if(ZZ_t[0][1]<=0.5 && ZZ_t[0][1]>0){
		cout<<" Variabel A dan B memiliki hubungan yang positif namun lemah sebesar "<<ZZ_t[0][1]<<endl;
	}
	else{
		cout<<" Variabel A dan B memiliki hubungan yang negatif dan lemah sebesar "<<ZZ_t[0][1]<<endl;
	}
	
	
}
