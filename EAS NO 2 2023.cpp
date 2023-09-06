/************************************
Nama : Rasendra Akbar Satyatama
NRP : 5003221120
@file : 
@brief : Revisi
@date : 13/06/2023
************************************/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


float Euclidian(float x[], float y[], int n){
	
	float hasil = 0;
	for(int i=0; i<n; i++){
		hasil += pow(x[i]-y[i], 2);
	}
	hasil = sqrt (hasil);
	return hasil;
}


int main(){
	
	int data[100];
	
	int angka;
	vector<int> data_f;
	
	ifstream Miles_morales;
	Miles_morales.open("SeqData.txt");
	
	while(Miles_morales >> angka){
		data_f.push_back(angka);
	}
	Miles_morales.close();
	
	int panjang_data_f = data_f.size();
	int n = 0;
	
	for(int i=0; i<panjang_data_f; i++){
		data[i] = data_f[i];
		n++;
	}
	
	cout<<"2a. Import Data"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0; i<n; i++){
		cout<<data[i]<<"  ";
	}
	
	float data_genap[n], data_ganjil[n], data_prima[n];
	int jml_gen = 0, jml_gan = 0, jml_p = 0;
	
	for(int i=0; i<n; i++){
		if(data[i]%2 == 0){
			data_genap[jml_gen] = data[i];
			jml_gen++;
		}
		else if(data[i]%2 != 0){
			
			if(data[i]==2 || data[i]==3 || data[i]==5 || data[i]==7){
				data_prima[jml_p] = data[i];
				jml_p++;
			}
			else if(data[i]%2 == 0 || data[i]%3 == 0 || data[i]%5 == 0 || data[i]%7 == 0){
				data_ganjil[jml_gan] = data[i];
				jml_gan++;
			}
			else{ // Bil. prima selain 2 3 5 7
				data_prima[jml_p] = data[i];
				jml_p++;
			}	
		}
	}	
	
	cout<<endl<<endl;
	cout<<"2b. Hasil Filter Data"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<" Data genap 	: ";
	for(int i=0; i<jml_gen; i++){
		cout<<data_genap[i]<<"  ";
	}
	cout<<endl;
	cout<<" Data ganjil 	: ";
	for(int i=0; i<jml_gan; i++){
		cout<<data_ganjil[i]<<"  ";
	}
	cout<<endl;
	cout<<" Data prima 	: ";
	for(int i=0; i<jml_p; i++){
		cout<<data_prima[i]<<"  ";
	}
	cout<<endl;
	
	// 2c.
	ofstream UploadTXT;
	UploadTXT.open("DistMatrix.txt");
	
	
	float matriks_euclidian [3][3];
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==j){
				matriks_euclidian[i][j] = 0; //KARENA SAMA VARIABELNYA MAKA JARAKNYA PASTI 0	
			}
			else{
				if(i==0 && j==1){
					matriks_euclidian[i][j] = Euclidian(data_genap, data_ganjil, jml_gen);
				}
				else if(i==0 && j==2){
					matriks_euclidian[i][j] = Euclidian(data_genap, data_prima, jml_gen);
				}
				else if(i==1 && j==2){
					matriks_euclidian[i][j] = Euclidian(data_ganjil, data_prima, jml_gan);
				}
				matriks_euclidian [j][i] = matriks_euclidian [i][j];
			}
		}
	}
	
	cout<<endl;
	cout<<"2c. Matriks Jarak Euclidean"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	UploadTXT<<"2c. Matriks Jarak Euclidean"<<endl;
	UploadTXT<<"------------------------------------------------------"<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<matriks_euclidian[i][j]<<"\t\t";
			UploadTXT<<matriks_euclidian[i][j]<<"\t\t";
		}
		cout<<endl;
		UploadTXT<<endl;
	}
	
	cout<<endl;
	cout<<"2d. Pasangan Data Terjauh & Terdekat"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	
	float maksimal = 0, minimal = matriks_euclidian[0][1];
	
	int baris_maks, kolom_maks, baris_min, kolom_min;
	string k_maks, k_min;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(matriks_euclidian[i][j]>maksimal){
				maksimal = matriks_euclidian[i][j];
				baris_maks = i;
				kolom_maks = j;
			}
			else if(matriks_euclidian[i][j]<minimal && i!=j){
				minimal = matriks_euclidian[i][j];
				baris_min = i;
				kolom_min = j;
			}
		}
	}
	
	if(baris_maks==0&&kolom_maks==1){
		k_maks="Bilangan genap & ganjil";
	}
	else if(baris_maks==0&&kolom_maks==2){
		k_maks="Bilangan genap & prima";
	}
	else if(baris_maks==1&&kolom_maks==0){
		k_maks="Bilangan ganjil & genap";
	}
	else if(baris_maks==1&&kolom_maks==2){
		k_maks="Bilangan ganjil & prima";
	}
	else if(baris_maks==2&&kolom_maks==0){
		k_maks="Bilangan prima & genap";
	}
	else if(baris_maks==2&&kolom_maks==1){
		k_maks="Bilangan prima & ganjil";
	}
	
	if(baris_min==0&&kolom_min==1){
		k_min="Bilangan genap & ganjil";
	}
	else if(baris_min==0&&kolom_min==2){
		k_min="Bilangan genap & prima";
	}
	else if(baris_min==1&&kolom_min==0){
		k_min="Bilangan ganjil & genap";
	}
	else if(baris_min==1&&kolom_min==2){
		k_min="Bilangan ganjil & prima";
	}
	else if(baris_min==2&&kolom_min==0){
		k_min="Bilangan prima & genap";
	}
	else if(baris_min==2&&kolom_min==1){
		k_min="Bilangan prima & ganjil";
	}
	cout<<"Terdekat --> "<<k_min<< " dengan jarak "<<minimal<<endl;
	cout<<"Terjauh --> "<<k_maks<< " dengan jarak "<<maksimal<<endl;
	
}
