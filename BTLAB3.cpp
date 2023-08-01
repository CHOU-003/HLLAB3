#include <iostream>
#include <string>
using namespace std;

int GT(int n){
	int GT = 1;
	for(int i=1; i<=n; i++){
		GT *= i;
	}
	
	return GT;	
}

int X(int x, int n){
	int Tich=1;
	while(n>0){
		Tich *=x;
		n--;
	}
	 
	return Tich;
}

int ToHop(int n, int k){
	double C;
	C = (double)GT(n)/GT(k)*GT(n-k);
	return C;
}

void HCN(int dai, int rong){
	int DT = dai*rong;
	int Chuvi = (dai+rong)*2;
	cout << "Dien tich HCN: " << DT <<" " << "Chu vi HCN: " << Chuvi << endl;
	for(int i=0; i<=rong; i++){
		cout << "*";	
	}
	cout << endl;
	
	for (int i = 0; i <= dai; i++) {
		cout << "*";
		cout << " ";
		for (int j = 0; j < rong - 2; j++) {
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}
	for(int i=0; i<=rong; i++){
		cout << "*";	
	}
	
}

bool KT(int n){
	int sum=0;
	for(int i=1; i<n; i++){
		if(n%i==0){
			sum += i;
		}
	}
	
	return  sum == n;	
}

void XuatSHT(int k){
	for(int i=0; i<k; i++){
		if(KT(i)){
			cout << i << endl;
		}
	}
}

void RutTien(int MenhGia[], int Dem[]){
	int k;
	cout << "Nhap so tien can rut: ";
	cin >> k;
	for(int i=0; i<6; i++){
		Dem[i] = k/MenhGia[i];
		k %= MenhGia[i];	
	}
	cout << "So luong tien it nhat can tra: " << endl;
	for(int i=0; i<6; i++){
		if(Dem[i] != 0){
			cout << Dem[i] << " to tien co manh gia la " << MenhGia[i] <<endl;		
		}
	}
}


void DaoNguoc(int n){
    int daoNguoc = 0;
    while(n > 0){
        int du = n % 10;
        daoNguoc = daoNguoc * 10 + du;
        n /= 10;
    }
    cout << "So dao nguac là: " << daoNguoc;
}


void DemChuDe(string CD[], int n){
	int dem =0, dem2 = 0;
	for(int i=0; i<n; i++){
		cout << "Nhap chu de: ";
		getline(cin, CD[i]);
		if(CD[i] == "Home/accomodation"){
			cout << "Nhap chu de: ";
			getline(cin, CD[i]);
			dem++;
			if(dem == 3)
				break;
		} else if(CD[i] == "Study"){
			cout << "Nhap bo chu de: ";
			getline(cin, CD[i]);
			dem2++;	
			if(dem == 3)
				break;
		}
	}
	cout << "Home/acommodation: " << " " << dem << endl;
	cout << "Study: " << "  " << dem2;
}


int main() { 
    int chon; 
    cout << "nhap cau hoi muon xem: "; 
    cin >> chon; 
  
    switch(chon) { 
        case 1: {
            int n; 
            cout << "nhap so dong: "; 
            cin >> n; 
            cin.ignore(); 
            string CD[n]; 
            DemChuDe(CD,n); 
            break; }
        case 2: {
            int MenhGia[6] = {50000,20000,10000,5000,2000,1000}; 
            int Dem[6] = {0}; 
            RutTien(MenhGia,Dem); 
            break; }
        case 3: {
        	int n;
        	cout <<" Nhap n: ";
        	cin >> n;
        	int KQ = GT(n);
        	cout << "Ket qua la: " << KQ;
        	break;}
       	case 4:{
       		int x,n;
       		cout << "Nhap x: "; cin >> x;
       		cout << "Nhap n: "; cin >> n;
       		int KQ = X(x,n);
       		cout << "Ket qua la: " << KQ << endl;
       		break;}
		case 5:{
			int n, k;
			cout << "Nhap n: "; cin >> n;
       		cout << "Nhap k: "; cin >> k;
       		int result = ToHop(n,k);
       		cout << "Ket qua to hop la: " << result <<endl;
       		break;}
 		case 6: {
 			int dai, rong;
 			cout << "Nhap chieu dai: "; cin >> dai;
 			cout << "Nhap chieu rong: "; cin >> rong;
 			HCN(dai, rong);
 			break;}
		case 7: {
			int N;
			cout << "Nhap vao so N: ";
			cin >> N;
			XuatSHT(N);
			break;}
		case 8: {
			int n;
			cout << "Nhap so nguyen : ";
			cin >> n;
			DaoNguoc(n);
			break;}
			
    } 
    return 0; 
}

