#include <iostream>
using namespace std;

class Menu{
  friend istream& operator>>(istream&in, Menu& mn);
  friend ostream& operator<<(ostream&, Menu& mn);

private:
  struct str{
	string nama;
  };

  char n='Y';
  int counter=0;
  int jarak,ongkir;
  float sum=0;
  int jumlahMenu[100],harga[100],nomorMenu[100];
  str namaMenu[30];

public:
  void ongkos();
  void potongan();
};


ostream& operator<<(ostream&, Menu& mn){
  cout<<"Total Harga\t\t\t: Rp."<<mn.sum<<endl;
  cout<<"Silahkan Ambil Struk Anda"<<endl;
}

istream& operator>>(istream& in, Menu& mn){
  cout << "============================================================="<<endl;
  cout << "1. Ayam Geprek  : Rp 21000"<<endl;
	cout << "2. Ayam Goreng  : Rp 17000"<<endl;
	cout << "3. Udang Goreng : Rp 19000"<<endl;
	cout << "4. Cumi Goreng  : Rp 20000"<<endl;
	cout << "5. Ayam Bakar   : Rp 25000"<<endl;
  cout << "============================================================="<<endl;
  cout<<"Masukkan Jarak(m)    : ";in>>mn.jarak;
  while((mn.n=='Y')||(mn.n=='y')){
  	cout << "============================================================="<<endl;
    cout<<"Masukkan Nomor Menu    : ";in>>mn.nomorMenu[mn.counter];
    cout<<"Masukkan Jumlah Pesanan  : ";in>>mn.jumlahMenu[mn.counter];
    switch(mn.nomorMenu[mn.counter]){
    	case 1 :
    	mn.namaMenu[mn.counter].nama="Ayam Geprek";
		mn.harga[mn.counter]=21000*mn.jumlahMenu[mn.counter]; break;
    	case 2 :
    	mn.namaMenu[mn.counter].nama="Ayam Goreng";
		mn.harga[mn.counter]=17000*mn.jumlahMenu[mn.counter]; break;
    	case 3 :
    	mn.namaMenu[mn.counter].nama="Udang Goreng";
		mn.harga[mn.counter]=19000*mn.jumlahMenu[mn.counter]; break;
    	case 4 :
    	mn.namaMenu[mn.counter].nama="Cumi Goreng";
		mn.harga[mn.counter]=20000*mn.jumlahMenu[mn.counter]; break;
    	case 5 :
    	mn.namaMenu[mn.counter].nama="Ayam Bakar";
		mn.harga[mn.counter]=25000*mn.jumlahMenu[mn.counter]; break;
		default:
			cout<<"Kode Tidak Ditemukan"<<endl;
	}
    cout<<"Memesan Lagi ?(Y=Ya/T=Tidak)";in>>mn.n;
    cout << "============================================================="<<endl;
    if((mn.n=='T')||(mn.n=='t')){
      cout<<"Pemesanan Selesai"<<endl;
      cout<<"Menu Yang Anda Pesan"<<endl;
    for(int i=0;i<=mn.counter;i++){
      	cout<<"Nama Makanan\t	: "<<mn.namaMenu[i].nama<<endl;
      	cout<<"Jumlah Makanan\t	: "<<mn.jumlahMenu[i]<<endl;
      	cout<<"Harga\t\t\t\t: Rp."<<mn.harga[i]<<endl;
      	mn.sum+=mn.harga[i];
	  }
    }
    mn.counter++;
  }
  return in;
}

void Menu::ongkos(){
  if(jarak == 0){
		ongkir=0;
	}
	else if(jarak <= 3000){
		ongkir=15000;
		cout << "Ongkir\t\t\t\t: 15000" << endl;
	}
	else if(jarak > 3000){
		ongkir=25000;
		cout << "Ongkir\t\t\t\t: 25000" << endl;
	}
}

void Menu::potongan(){
  if((sum>=25000)&&(sum<50000)){
		sum=sum+ongkir-3000;
		cout<<"Anda Mendapat Potongan Ongkir RP 3000"<<endl;
	}
	else if((sum>=50000)&&(sum<150000)){
		sum=sum-(sum*0.15)+(ongkir-5000);
		cout<<"Anda Mendapat Diskon 15% dan Potongan Ongkir RP 3000"<<endl;
	}
	else if((sum>=150000)){
		sum=sum-(sum*0.35)+(ongkir-8000);
		cout<<"Anda Mendapat Diskon 35% dan Potongan Ongkir RP 3000"<<endl;
	}
}

int main() {
  Menu X;
	cin>>X;
  X.ongkos();
  X.potongan();
	cout<<X;
	return 0;
}
