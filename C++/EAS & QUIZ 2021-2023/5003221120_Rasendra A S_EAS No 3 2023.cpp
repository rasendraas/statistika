/*******************************
Nama : Rasendra Akbar Satyatama
NRP : 5003221120
@brief : EAS Nomor 3, Buat function untuk menghitung rata - rata
standar deviasi dan korelasi dari 2 variabel yang diberikan
********************************/

#include <iostream>
#include <cmath>


float Mean(float x[], int n){
	float rata2 = 0;
	for(int i=0; i<n; i++){
		rata2 += x[i];
	}
	rata2 /= n;
	return rata2;
}

float StandarDeviasi (float x[], float rata, int n){
	float sd = 0;
	for(int i=0; i<n; i++){
		sd += pow(x[i] - rata, 2);
	}
	sd = sqrt (sd/(n-1));
	return sd;
}

float Korelasi (float x[], float y[], float ratax, float ratay, int n){
	float sxy = 0;
	for (int i=0; i<n; i++){
		sxy += (x[i]-ratax)*(y[i]-ratay);
	}
	
	float sx = 0;
	for (int i=0; i<n; i++){
		sx += pow(x[i]-ratax, 2);
	}
	float sy = 0;
	for (int i=0; i<n; i++){
		sy += pow(y[i]-ratay, 2);
	}
	float sxsy = sqrt (sx*sy);
	float r = sxy/sxsy;
	return r;
}

using namespace std;

int main(){
	float milk[] = {8.9, 19.9, 17.5, 8.3, 12.5, 25.0, 11.1, 33.7, 19.5, 17.6, 9.7, 25.8, 13.7, 23.4, 23.3};
	float cereals[] = {42.3, 28.0, 26.6, 56.7, 34.3, 21.9, 24.6, 26.3, 28.1, 41.7, 40.1, 24.0, 36.8, 22.4, 23.0};
	int m = sizeof(milk)/sizeof(milk[0]);
	int c = sizeof(cereals)/sizeof(cereals[0]);
	
	cout<<"Data :"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Milk 	= ";
	for(int i=0; i<m; i++){
		cout<<milk[i]<<"  ";
	}
	cout<<endl;
	cout<<"Cereals = ";
	for(int i=0; i<c; i++){
		cout<<cereals[i]<<"  ";
	}
	cout<<endl<<endl;
	
	cout<<"3a. Nilai mean untuk data Milk & Cereals"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Milk 		= ";
	float rata_m = Mean(milk, m);
	cout<<rata_m<<endl;
	cout<<"Cereals 	= ";
	float rata_c = Mean(cereals, c);
	cout<<rata_c<<endl;
	
	cout<<endl;
	cout<<"3c. Nilai standar deviasi untuk data Milk & Cereals"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Milk 		= ";
	float sd_m = StandarDeviasi(milk, rata_m, m);
	cout<<sd_m<<endl;
	cout<<"Cereals 	= ";
	float sd_c = StandarDeviasi(cereals, rata_c, c);
	cout<<sd_c<<endl;
	
	cout<<endl;
	cout<<"3d. Korelasi antara data Milk & Cereals"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Korelasi 	= ";
	float korelasi = Korelasi(milk, cereals, rata_m, rata_c, m);
	cout<<korelasi<<endl;
	
}
