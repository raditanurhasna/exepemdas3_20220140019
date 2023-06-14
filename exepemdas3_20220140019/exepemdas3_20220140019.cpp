#include<iostream>
#include<vector>
using namespace std;

class penerbit;

class buku {
public:
	string namaBuku;
	buku(string pNamabuku) :namaBuku(pNamabuku) {}
};

class pengarang {
public:
	string namaPengarang;
	vector<penerbit*> daftar_penerbit;
	vector<buku*> daftar_buku;

	pengarang(string pNama) :namaPengarang(pNama) {}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();

	void tambahBuku(buku*);
	void cetakBuku();
};

class penerbit {
public:
	string namaPenerbit;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) : namaPenerbit(pNama) {}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

void pengarang::tambahPenerbit(penerbit* pPenerbit)
{
	daftar_penerbit.push_back(pPenerbit);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit yang dikuti\"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->namaPenerbit << "\n";
	}
	cout << endl;
}

void penerbit::tambahPengarang(pengarang* pPengarang)
{
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar Penerbit yang diikuti\"" << this->namaPenerbit << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->namaPengarang << "\n";
	}
	cout << endl;
}

void pengarang::tambahBuku(buku* pNamaBuku)
{
	daftar_buku.push_back(pNamaBuku);
}

void pengarang::cetakBuku() {
	cout << "Daftar buku yang dikarang\"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->namaBuku << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");

	buku* varBuku1 = new buku("Fsisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemprograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);

	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);

	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);

	varPengarang1->tambahBuku(varBuku1);
	varPengarang1->tambahBuku(varBuku2);
	varPengarang2->tambahBuku(varBuku3);
	varPengarang4->tambahBuku(varBuku4);
	varPengarang3->tambahBuku(varBuku5);

	return 0;
}


	

