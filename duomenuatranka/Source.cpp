#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const char cdfva[] = "1.txt";
const char cdfvr[] = "r.txt";
const char cdfvb[] = "2.txt";
const int CMax = 30;
const int CPav = 20;

struct Sportininkas {
	string pav;
	int laikas;
};

void Skaityti(const char fv[], Sportininkas A[], int & n);
void Spausdinti(Sportininkas A[], int n);
void Rikuoti(Sportininkas A[], int  n);
void Atrinkti(Sportininkas A[], Sportininkas B[], int n, int & m);

int main ()
{
	Sportininkas A[CMax]; int n;
	Sportininkas B[CMax]; int m = 0;
	Skaityti (cdfva, A, n);
	Rikuoti(A, n);
	Atrinkti(A, B, n, m);
	Skaityti(cdfvb, A, n);
	Rikuoti(A, n);
	Atrinkti(A, B, n, m);
	Rikuoti(B, m);
	Spausdinti(B, m);
}
void Skaityti(const char fv[], Sportininkas A[], int & n){
	ifstream in(fv);
	int min, sek;
	char eil[CPav+1];
	in >> n;
	in.ignore(80, '\n');
	for (int i = 0; i < n; i++){
		in.get(eil, CPav);
		A[i].pav = eil;
		in >> min >> sek;
		in.ignore(80, '\n');
		A[i].laikas = min * 60 + sek;
	}
	in.close();
}
void Spausdinti(Sportininkas A[], int n){
	ofstream out(cdfvr);
	out << "Begiku sarasas" << endl;
	out << "--------------------------------" << endl;
	out << "Vardas ir           Parodytas   " << endl;
	out << "pavarde              laikas     " << endl;
	for (int i = 0; i < n; i++){
		out << setw(20) << left << A[i].pav << "   "
								<< A[i].laikas / 60 << " : "
								<< A[i].laikas % 60 << "   "
								<< "  " << n-i << endl;
	}
	out << "--------------------------------" << endl;
	out.close();
}
void Rikuoti(Sportininkas A[], int  n){
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j<n; j++){
			if (A[j].laikas < A[i].laikas){
				Sportininkas sp = A[i];
				A[i] = A[j];
				A[j] = sp;
			}
		}
	}
}
void Atrinkti(Sportininkas A[], Sportininkas B[], int n, int & m){
	for(int i = 0; i < n/2; i++){
		B[m] = A[i];
		m++;
	}
}


















