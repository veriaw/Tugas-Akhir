#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef struct{
	int kode;
	string nama;
	string ukuran;
	int harga;
	string kondisi;
	}item;
	item apparel[30], temp;

string replaceUnderscore(string m);
string replaceSpasi(string m);
void login(string *, int *, int *);
void registr();
void forgot(string *, int *);
void menucostumer();
void menuadmin();
void stock(int *);
void edit(int *);
void sell();
void buy(int *);//searching sequential belum urut non sentinel
void sort1(int *);//bubble sort
void sort2(int *);//bubble sort

int barang(){
	int jumlah=0;
	ifstream loop;
	string buffer, buffer1;
	loop.open("stock.txt");
	while(getline(loop,buffer)){
		jumlah=jumlah+1;
		}
	loop.close();
	return(jumlah);
	}

int customer(){
	int jumlah=0;
	ifstream loop;
	string buffer, buffer1;
	loop.open("database.txt");
	while(getline(loop,buffer)){
		jumlah=jumlah+1;
		}
	loop.close();
	return(jumlah);
	}

int admin(){
	int jumlah=0;
	ifstream loop;
	string buffer, buffer1;
	loop.open("admin.txt");
	while(getline(loop,buffer)){
		jumlah=jumlah+1;
		}
	loop.close();
	return(jumlah);
	}

int history(){
	int jumlah=0;
	ifstream loop;
	string buffer, buffer1;
	loop.open("histori.txt");
	while(getline(loop,buffer)){
		jumlah=jumlah+1;
		}
	loop.close();
	return(jumlah);
	}
	
int main(){
	int menu, As, jml_admin, jml_cus;
	char ulang;
	string file;
		do{
			system("cls");
			jml_admin=admin();
			jml_cus=customer();
			cout<<right<<setfill('=')<<setw(30)<<"\n";
			cout<<right<<setfill(' ')<<setw(21)<<"Apparel Avenue"<<setw(9)<<"\n";
			cout<<right<<setfill('=')<<setw(17)<<"Identify"<<setw(13)<<"\n";
			cout<<"1. Registrasi Akun"<<endl;
			cout<<"2. Login Akun"<<endl;
			cout<<"3. Lupa Akun"<<endl;
			cout<<"4. Exit"<<endl;
			cout<<"Pilih Menu\t:";
			cin>>menu;
			system("cls");
			switch(menu){
				case 1:
					cin.ignore();
					registr();
					cout<<"Ingin Kembali Ke Menu?[y/n} : ";
					cin>>ulang;
					system("cls");
					break;
				case 2:
					cout<<right<<setfill('=')<<setw(30)<<"\n";
					cout<<right<<setfill(' ')<<setw(21)<<"Apparel Avenue"<<setw(9)<<"\n";
					cout<<right<<setfill('=')<<setw(17)<<"Identify"<<setw(13)<<"\n";
					cout<<"Login Sebagai\t: "<<endl;
					cout<<"1. Customer"<<endl;
					cout<<"2. Admin"<<endl;
					cout<<"Pilih Opsi\t: ";
					cin>>As;
					cin.ignore();
					if(As==1){
						file="database.txt";
						login(&file, &As, &jml_cus);
						}else if(As==2){
							file="admin.txt";
							login(&file, &As, &jml_admin);
							}
					cout<<"Ingin Kembali Ke Menu?[y/n} : ";
					cin>>ulang;
					system("cls");
					break;
				case 3:
					cout<<right<<setfill('=')<<setw(30)<<"\n";
					cout<<right<<setfill(' ')<<setw(21)<<"Apparel Avenue"<<setw(9)<<"\n";
					cout<<right<<setfill('=')<<setw(17)<<"Identify"<<setw(13)<<"\n";
					cout<<"Pemulihan Akun\t: "<<endl;
					cout<<"1. Customer"<<endl;
					cout<<"2. Admin"<<endl;
					cout<<"Pilih Opsi\t: ";
					cin>>As;
					system("cls");
					cin.ignore();
					if(As==1){
						file="database.txt";
						forgot(&file, &jml_cus);
						menucostumer();
						}else if(As==2){
							file="admin.txt";
							forgot(&file, &jml_admin);
							menuadmin();
							}
					cout<<"Ingin Kembali Ke Menu?[y/n} : ";
					cin>>ulang;
					system("cls");
					break;
				case 4:
					exit(0);
					break;
				default :
					cout<<"Menu Yang anda pilih tidak ditemukan"<<endl;
					system("pause");
					cout<<"Ingin Kembali Ke Menu?[Y/N} : ";
					cin>>ulang;
					break;
				}
			}while(ulang=='Y'||ulang=='y');
	}

void registr(){
	system("cls");
	cout<<setfill('=')<<setw(30)<<"\n";
	cout<<setfill(' ')<<setw(21)<<"Apparel Avenue"<<setw(9)<<"\n";
	cout<<setfill('=')<<setw(18)<<"Register"<<setw(12)<<"\n";
	string username, password;
	cout<<"Masukan UserName\t:";
	getline(cin,username);
	cout<<"Masukan Password\t:";
	getline(cin,password);
	ofstream reg;
	reg.open("database.txt", ios::app);
	reg<<username<<"\t"<<password<<endl;
	cout<<endl<<"Pendaftaran Berhasil!"<<endl;
	reg.close();
	system("pause");
	}
	
void login(string *file2, int *role, int *jumlah){
	bool loop=false;
	string buff;
	int a=0;
	system("cls");
	cout<<setfill('=')<<setw(60)<<"\n";
	cout<<setfill(' ')<<setw(37)<<"Apparel Avenue"<<setw(23)<<"\n";
	cout<<setfill('=')<<setw(33)<<"Login"<<setw(27)<<"\n";
	string user, pass, u, p;
	cout<<"Masukan UserName\t:";
	getline(cin,user);
	cout<<"Masukan Password\t:";
	getline(cin,pass);
	ifstream log;
	log.open(*file2);
	while(loop!=true && a<*jumlah){
	log>>u;
	log>>p;
	if(user==u && pass==p){
		loop=true;
		}
	a++;
	}
	log.close();
	if(loop==true){
		cout<<"Login Berhasil!"<<endl;
		system("pause");
		if(*role==1){
			menucostumer();
			}else if(*role==2){
				menuadmin();
				}
		}else{
			cout<<"Username atau Password anda salah!!"<<endl;
			system("pause");
			}
	}

void forgot(string *rec, int *jumlah){
	int a=0, b=0;
	ifstream sch;
	sch.open(*rec);
	string searchuser, searchpass,su, pu;
	bool search = false;
	int menu;
	cout<<setfill('=')<<setw(50)<<"\n";
	cout<<setfill(' ')<<setw(32)<<"Apparel Avenue"<<setw(18)<<"\n";
	cout<<setfill('=')<<setw(28)<<"Forgot"<<setw(22)<<"\n";
	cout<<"1. Mencari Berdasarkan UserName"<<endl;
	cout<<"2. Mencari Berdasarkan Password"<<endl;
	cout<<"3. Main Menu"<<endl;
	cout<<"Pilih Menu\t:";
	cin>>menu;
	cin.ignore();
	switch(menu){
		case 1: 
			cout<<"Username yang Anda Ingat\t: ";
			getline(cin,searchuser);
			while(search!= true && a<*jumlah){
				sch>>su;
				sch>>pu;
				if(searchuser==su){
					search=true;
				}
			a++;
			}
			if(search==true){
				cout<<"Akun Anda Ditemukan!!"<<endl;
				cout<<"Username\t: "<<su<<endl;
				cout<<"Password\t: "<<pu<<endl;
				}else{
					cout<<"Username Anda Tidak Ditemukan"<<endl;
					system("pause");
					system("cls");
					main();
					}
				system("pause");
				system("cls");
			break;
		case 2:
			cout<<"Password yang Anda Ingat\t: ";
			getline(cin,searchpass);
			while(search!= true && b<*jumlah){
				sch>>su;
				sch>>pu;
				if(searchpass==pu){
					search=true;
				}
			b++;
			}
			if(search==true){
				cout<<"Akun Anda Ditemukan!!"<<endl;
				cout<<"Username\t: "<<su<<endl;
				cout<<"Password\t: "<<pu<<endl;
				}else{
					cout<<"Username Anda Tidak Ditemukan"<<endl;
					system("pause");
					system("cls");
					main();
					}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			main();
			break;
		default :
			cout<<"Menu Yang Anda Pilih Tidak Tersedia!!"<<endl;
			system("pause");
			main();
		}
	sch.close();
	system("cls");
	}

void menucostumer(){
	int total;
	system("cls");
	int mn;
	char kembali;
	do{
		total=barang();
		system("cls");
		cout<<right<<setfill('=')<<setw(86)<<"\n";
		cout<<right<<setfill(' ')<<setw(50)<<"Apparel Avenue"<<setw(36)<<"\n";
		cout<<right<<setfill('=')<<setw(48)<<"Menu Utama"<<setw(38)<<"\n";	
		cout<<"1. Melihat Apparel Yang Tersedia"<<endl;
		cout<<"2. Mengurutkan Aparel Dari Mahal Ke Murah"<<endl;
		cout<<"3. Mengurutkan Aparel Dari Murah Ke Mahal"<<endl;
		cout<<"4. Membeli Apparel"<<endl;
		cout<<"5. Menjual Apparel"<<endl;
		cout<<"6. Logout"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Pilih Menu\t: ";
		cin>>mn;
		switch(mn){
			case 1:
				stock(&total);
				cout<<"Kembali Ke Menu Utama\t[y/n]: ";
				cin>>kembali;
				break;
			case 2:
				sort1(&total);
				break;
			case 3:
				sort2(&total);
				break;
			case 4:
				buy(&total);
				cout<<"Kembali Ke Menu Utama\t[y/n]: ";
				cin>>kembali;
				break;
			case 5:
				sell();
				cout<<"Kembali Ke Menu Utama\t[y/n]: ";
				cin>>kembali;
				break;
			case 6:
				system("cls");
				main();
				break;
			case 7:
				exit(0);
				break;
			}
		}while(kembali=='Y'||kembali=='y');
	}
	
void menuadmin(){
	int income=0, hasil, menu;
	int jumlah=barang();
	int total=history();
	char ulang;
	string buffer;
	do{
		system("cls");
		cout<<right<<setfill('=')<<setw(86)<<"\n";
		cout<<right<<setfill(' ')<<setw(50)<<"Apparel Avenue"<<setw(36)<<"\n";
		cout<<right<<setfill('=')<<setw(48)<<"Menu Admin"<<setw(38)<<"\n";
		cout<<"1. Lihat Laba Penjualan"<<endl;
		cout<<"2. Edit Data Barang"<<endl;
		cout<<"3. Kembali Ke Menu Login"<<endl;
		cout<<right<<setfill('=')<<setw(86)<<"\n";
		cout<<"Pilih Menu\t: ";
		cin>>menu;
		if(menu==1){
			ifstream history;
			history.open("histori.txt");
			cout<<setfill('=')<<setw(86)<<"\n";
			cout<<"| "<<left<<setfill(' ')<<setw(6)<<"Kode"<<" | "<<setw(30)<<"Nama"<<" | "<<setw(8)<<"Ukuran"<<" | "<<setw(10)<<"Harga"<<" | "<<setw(15)<<"Kondisi"<<" |";
			cout<<setfill('=')<<setw(86)<<"\n"<<endl;
			for(int a=1;a<=total;a++){
				history>>apparel[a].kode;
				history>>apparel[a].nama;
				history>>apparel[a].ukuran;
				history>>apparel[a].harga;
				history>>apparel[a].kondisi;
				apparel[a].nama=replaceUnderscore(apparel[a].nama);
				}
			history.close();
			for(int b=1;b<=total;b++){
				cout<<"| "<<left<<setfill(' ')<<setw(6)<<apparel[b].kode<<" | "<<setw(30)<<apparel[b].nama<<" | "<<setw(8)<<apparel[b].ukuran<<" | "<<setw(10)<<apparel[b].harga<<" | "<<setw(15)<<apparel[b].kondisi<<" |"<<endl;
				income = income + apparel[b].harga;
				}
			hasil=income*5/100;
			cout<<setfill('=')<<setw(86)<<"\n"<<endl;;
			cout<<"Laba Penjualan\t: "<<hasil<<endl;
			cout<<"Kembali Ke Menu Utama\t[y/n]: ";
			cin>>ulang;
		}else if(menu==2){
			edit(&jumlah);
			cout<<"Kembali Ke Menu Utama\t[y/n]: ";
			cin>>ulang;
			}else if(menu==3){
				main();
				}else{
				cout<<"Menu Tidak Tersedia!!"<<endl;
				cout<<"Kembali Ke Menu Utama\t[y/n]: ";
				cin>>ulang;
				}
		}while(ulang=='Y'||ulang=='y');
	}

void stock(int *jumlah){
	ifstream stck;
	stck.open("stock.txt");
	cout<<setfill('=')<<setw(86)<<"\n";
	cout<<"| "<<left<<setfill(' ')<<setw(6)<<"Kode"<<" | "<<setw(30)<<"Nama"<<" | "<<setw(8)<<"Ukuran"<<" | "<<setw(10)<<"Harga"<<" | "<<setw(15)<<"Kondisi"<<" |";
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	for(int a=1;a<=*jumlah;a++){
		stck>>apparel[a].kode;
		stck>>apparel[a].nama;
		stck>>apparel[a].ukuran;
		stck>>apparel[a].harga;
		stck>>apparel[a].kondisi;
		apparel[a].nama=replaceUnderscore(apparel[a].nama);
		cout<<"| "<<left<<setfill(' ')<<setw(6)<<apparel[a].kode<<" | "<<setw(30)<<apparel[a].nama<<" | "<<setw(8)<<apparel[a].ukuran<<" | "<<setw(10)<<apparel[a].harga<<" | "<<setw(15)<<apparel[a].kondisi<<" |"<<endl;
		}
	stck.close();
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	}

void edit(int *jumlah){
	int b=1, jml=*jumlah, editmenu;
	string buffer;
	bool cari=false;
	int code;
	cout<<setw(49)<<"STOCK BARANG"<<setw(37)<<"\n";
	ifstream beli;
	beli.open("stock.txt");
	cout<<setfill('=')<<setw(86)<<"\n";
	cout<<"| "<<left<<setfill(' ')<<setw(6)<<"Kode"<<" | "<<setw(30)<<"Nama"<<" | "<<setw(8)<<"Ukuran"<<" | "<<setw(10)<<"Harga"<<" | "<<setw(15)<<"Kondisi"<<" |";
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	for(int a=1;a<=*jumlah;a++){
		beli>>apparel[a].kode;
		beli>>apparel[a].nama;
		beli>>apparel[a].ukuran;
		beli>>apparel[a].harga;
		beli>>apparel[a].kondisi;
		apparel[a].nama=replaceUnderscore(apparel[a].nama);
		cout<<"| "<<left<<setfill(' ')<<setw(6)<<apparel[a].kode<<" | "<<setw(30)<<apparel[a].nama<<" | "<<setw(8)<<apparel[a].ukuran<<" | "<<setw(10)<<apparel[a].harga<<" | "<<setw(15)<<apparel[a].kondisi<<" |"<<endl;
		}
	beli.close();
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	cout<<"Kode Barang Yang Dicari\t: ";
	cin>>code;
		while(cari!=true && b<=*jumlah){
			if(code == apparel[b].kode){
				cari=true;
				}
				b++;
			}
			b--;
		if(cari==true){
				cout<<right<<setfill('=')<<setw(20)<<"EDIT DATA"<<setw(11)<<"\n";
				cout<<setfill(' ')<<"1. Nama Barang"<<endl;
				cout<<"2. Ukuran Barang"<<endl;
				cout<<"3. Harga Barang"<<endl;
				cout<<"4. Kondisi Barang"<<endl;
				cout<<"Pilih Menu\t: ";
				cin>>editmenu;
				cin.ignore();
				switch(editmenu){
					case 1:
						cout<<"Nama Lama\t: "<<apparel[b].nama<<endl;
						cout<<"Nama Baru\t: "; getline(cin,apparel[b].nama);
						cout<<"Data Berhasil Di Edit!"<<endl;
						break;
					case 2:
						cout<<"Ukuran Lama\t: "<<apparel[b].ukuran<<endl;
						cout<<"Ukuran Baru\t: "; getline(cin,apparel[b].ukuran);
						cout<<"Data Berhasil Di Edit!"<<endl;
						break;
					case 3:
						cout<<"Harga Lama\t: "<<apparel[b].harga<<endl;
						cout<<"Harga Baru\t: "; cin>>apparel[b].harga;
						cout<<"Data Berhasil Di Edit!"<<endl;
						cin.ignore();
						break;
					case 4:
						cout<<"Kondisi Lama\t: "<<apparel[b].kondisi<<endl;
						cout<<"Kondisi Baru\t: "; getline(cin,apparel[b].kondisi);
						cout<<"Data Berhasil Di Edit!"<<endl;
						break;
					default:
						cout<<"Menu Tidak Tersedia!!"<<endl;
						break;
					}
				ofstream simpan;
				simpan.open("stock.txt",ios::trunc);
				for(int c=1; c<=jml;c++){
					apparel[c].nama = replaceSpasi(apparel[c].nama);
					simpan<<apparel[c].kode<<"\t"<<apparel[c].nama<<"\t"<<apparel[c].ukuran<<"\t"<<apparel[c].harga<<"\t"<<apparel[c].kondisi<<endl;
					}
				simpan.close();
			}else{
				cout<<"Apparel tidak ditemukan!!"<<endl;
				system("pause");
				}
	}

void sell(){
	int jumlah, kode, harga;
	string nama, kondisi, ukuran;
	ofstream jual;
	jual.open("stock.txt", ios::app);
	cout<<"Jumlah Barang Yang Ingin Dijual\t: ";
	cin>>jumlah;
	cout<<endl;
	for(int a=1; a<=jumlah; a++){
		cout<<"Barang ke- "<<a<<endl;
		cout<<"Kode Barang\t: ";
		cin>>kode;
		cin.ignore();
		cout<<"Nama Barang\t: ";
		getline(cin,nama);
		nama=replaceSpasi(nama);
		cout<<"Ukuran Barang\t: ";
		getline(cin,ukuran);
		cout<<"Harga Barang\t: ";
		cin>>harga;
		cin.ignore();
		cout<<"Kondisi Barang\t: ";
		getline(cin,kondisi);
		cout<<endl;
		jual<<kode<<"\t"<<nama<<"\t"<<ukuran<<"\t"<<harga<<"\t"<<kondisi<<endl;
		}
	jual.close();
	}

void buy(int *jumlah){
	int b=1, jml=*jumlah, uang, kembalian;
	string buffer;
	char co;
	bool cari=false;
	int code;
	ifstream beli;
	beli.open("stock.txt");
	cout<<setfill('=')<<setw(86)<<"\n";
	cout<<"| "<<left<<setfill(' ')<<setw(6)<<"Kode"<<" | "<<setw(30)<<"Nama"<<" | "<<setw(8)<<"Ukuran"<<" | "<<setw(10)<<"Harga"<<" | "<<setw(15)<<"Kondisi"<<" |";
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	for(int a=1;a<=*jumlah;a++){
		beli>>apparel[a].kode;
		beli>>apparel[a].nama;
		beli>>apparel[a].ukuran;
		beli>>apparel[a].harga;
		beli>>apparel[a].kondisi;
		apparel[a].nama=replaceUnderscore(apparel[a].nama);
		cout<<"| "<<left<<setfill(' ')<<setw(6)<<apparel[a].kode<<" | "<<setw(30)<<apparel[a].nama<<" | "<<setw(8)<<apparel[a].ukuran<<" | "<<setw(10)<<apparel[a].harga<<" | "<<setw(15)<<apparel[a].kondisi<<" |"<<endl;
		}
	beli.close();
	cout<<setfill('=')<<setw(86)<<"\n"<<endl;
	cout<<"Kode Barang Yang Dicari\t: ";
	cin>>code;
		while(cari!=true && b<=*jumlah){
			if(code == apparel[b].kode){
				cari=true;
				}
				b++;
			}
			b--;
		if(cari==true){
			cout<<right<<setfill('=')<<setw(86)<<"\n";
			cout<<"| "<<left<<setfill(' ')<<setw(6)<<"Kode"<<" | "<<setw(30)<<"Nama"<<" | "<<setw(8)<<"Ukuran"<<" | "<<setw(10)<<"Harga"<<" | "<<setw(15)<<"Kondisi"<<" |"<<endl;
			cout<<right<<setfill('=')<<setw(86)<<"\n";
			cout<<"| "<<left<<setfill(' ')<<setw(6)<<apparel[b].kode<<" | "<<setw(30)<<apparel[b].nama<<" | "<<setw(8)<<apparel[b].ukuran<<" | "<<setw(10)<<apparel[b].harga<<" | "<<setw(15)<<apparel[b].kondisi<<" |"<<endl;
			cout<<setfill('=')<<setw(86)<<"\n"<<endl;;
			cout<<"Checkout Apparel\t:[y/n]?";
			cin>>co;
			if(co=='Y' || co=='y'){
				cout<<"Masukan Kredit\t: ";
				cin>>uang;
				if(uang>=apparel[b].harga){
					if(uang>apparel[b].harga){
						kembalian=uang-apparel[b].harga;
						cout<<"Kembalian\t: "<<kembalian<<endl;
						}
					cout<<"Apparel Sukses DIbeli!!"<<endl;
					cout<<"Thanks For Your Purchase ;)"<<endl;
					ofstream history;
					history.open("histori.txt",ios::app);
					apparel[b].nama=replaceSpasi(apparel[b].nama);
					history<<apparel[b].kode<<"\t"<<apparel[b].nama<<"\t"<<apparel[b].ukuran<<"\t"<<apparel[b].harga<<"\t"<<apparel[b].kondisi<<endl;
					history.close();
					for(int i=b; i<=*jumlah; i++){
						apparel[i]=apparel[i+1];
						}
					jml--;
					ofstream simpan;
					simpan.open("stock.txt",ios::trunc);
					for(int c=1; c<=jml;c++){
						apparel[c].nama = replaceSpasi(apparel[c].nama);
						simpan<<apparel[c].kode<<"\t"<<apparel[c].nama<<"\t"<<apparel[c].ukuran<<"\t"<<apparel[c].harga<<"\t"<<apparel[c].kondisi<<endl;
						}
					simpan.close();
				}else{
					cout<<"Barang gagal untuk dibeli!"<<endl;
					}
			}else{
				cout<<"Barang gagal untuk dibeli!"<<endl;
				}
			}else{
				cout<<"Apparel tidak ditemukan!!"<<endl;
				system("pause");
				}
		}

void sort2(int *jumlah){
	string buffer;
	ifstream barang;
	barang.open("stock.txt");
	for(int a=1;a<=*jumlah;a++){
		barang>>apparel[a].kode;
		barang>>apparel[a].nama;
		barang>>apparel[a].ukuran;
		barang>>apparel[a].harga;
		barang>>apparel[a].kondisi;
		apparel[a].nama=replaceUnderscore(apparel[a].nama);
		}
	barang.close();
	for(int i=1;i<=*jumlah;i++){
		for(int j=1;j<=*jumlah-i;j++){
			if(apparel[j].harga>apparel[j+1].harga){
				temp=apparel[j];
				apparel[j] = apparel[j+1];
				apparel[j+1]=temp;
				}
			}
		}
	ofstream simpan;
	simpan.open("stock.txt",ios::trunc);
	for(int k=1; k<=*jumlah;k++){
		apparel[k].nama=replaceSpasi(apparel[k].nama);
		simpan<<apparel[k].kode<<"\t"<<apparel[k].nama<<"\t"<<apparel[k].ukuran<<"\t"<<apparel[k].harga<<"\t"<<apparel[k].kondisi<<endl;
		}
	simpan.close();
	}

void sort1(int *jumlah){
	string buffer;
	ifstream barang;
	barang.open("stock.txt");
	for(int a=1;a<=*jumlah;a++){
		barang>>apparel[a].kode;
		barang>>apparel[a].nama;
		barang>>apparel[a].ukuran;
		barang>>apparel[a].harga;
		barang>>apparel[a].kondisi;
		apparel[a].nama=replaceUnderscore(apparel[a].nama);
		}
	barang.close();
	for(int i=1;i<=*jumlah;i++){
		for(int j=1;j<=*jumlah-i;j++){
			if(apparel[j].harga<apparel[j+1].harga){
				temp = apparel[j];
				apparel[j] = apparel[j+1];
				apparel[j+1] = temp;
				}
			}
		}
	ofstream simpan;
	simpan.open("stock.txt",ios::trunc);
	for(int k=1; k<=*jumlah;k++){
		apparel[k].nama=replaceSpasi(apparel[k].nama);
		simpan<<apparel[k].kode<<"\t"<<apparel[k].nama<<"\t"<<apparel[k].ukuran<<"\t"<<apparel[k].harga<<"\t"<<apparel[k].kondisi<<endl;
		}
	simpan.close();
	}
	
string replaceSpasi(string m)
{
    for (int i=0; i<m[i]; i++)
    {
        if (m[i] == ' ')
        {
            m[i] = '_';
        }
    }
    return m;
}

string replaceUnderscore(string m)
{
    for (int i= 0; i<m[i]; i++)
    {
        if (m[i] == '_')
        {
            m[i] = ' ';
        }
    }
    return m;
}

