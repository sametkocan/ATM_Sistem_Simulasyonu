#include<iostream>
#include<vector>
using namespace std;


class Hesap
{
	int sifre;
public:
	int HesapNo;
	string KullaniciAdi;
	float Bakiye;

	Hesap(int sfr, int hspNo, string nm, float account) :sifre(sfr), HesapNo(hspNo), KullaniciAdi(nm), Bakiye(account) {}
	friend void sifreKontrol(int password, int& Hak, Hesap& kullanici);
};

const float IslemUcreti = 8.20;

void sifreKontrol(int password, int& Hak, Hesap& kullanici)
{
	for (Hak; Hak != 0;)
	{
		if (kullanici.sifre != password)
		{
			cout << "Hatali Sifre Girdiniz Tekrar Deneyin!\n";
			Hak--;
			cin >> password;
		}
		else
		{
			break;
		}
	}

	if (Hak == 0)
	{
		throw "3 Defa Yanlis Sifre Girdiginiz Icin Kartiniz Bloke Edilmistir Subeden Actirabilirsiniz Iyi Gunler...\n";
	}
}

void ParaYatir(Hesap& kullanici)
{
	int tutar;
	cout << "Yatirmak Istediginiz Tutari Giriniz\n";
	cin >> tutar;
	while (tutar < 20)
	{
		cout << "Lutfen 20 TL den Yuksek Bir Tutar Giriniz\n";
		cin >> tutar;
	}

	cout << "Paranizi Hazneye Sekilde ki Gibi Yerlestirin\nParaniz Sayiliyor...\n";
	kullanici.Bakiye = kullanici.Bakiye + tutar - IslemUcreti;
	cout << "Paraniz Hesabiniza Basarili Bir Sekilde Yatirildi\n";
}

void ParaCek(Hesap& kullanici)
{
	int tutar, denemeHakki = 4;
	cout << "Cekmek Istediginiz Tutari Giriniz\n";
	cin >> tutar;
	while (tutar < 20)
	{
		cout << "Lutfen 20TL Den Daha Buyuk Bir Tutar Giriniz\n";
		cin >> tutar;
		denemeHakki--;
		if (denemeHakki == 0)
		{
			throw"Deneme Hakkiniz Bitmistir 1 Saat Sonra Islem Yapmayi Tekrar Deneyebilirsiniz...\n";
		}
	}

	while (kullanici.Bakiye < tutar + IslemUcreti)
	{
		cout << "Hesabinizda ki Bakiye Yetersizdir Islem Ucretimiz 8.20 TL dir\nLutfen Baska Bir Tutar Giriniz\n";
		cin >> tutar;
		denemeHakki--;
		if (denemeHakki == 0)
		{
			throw"Deneme Hakkiniz Bitmistir 1 Saat Sonra Islem Yapmayi Tekrar Deneyebilirsiniz...\n";
		}
	}

	kullanici.Bakiye = kullanici.Bakiye - (tutar + IslemUcreti);
	cout << "Paranizi Sekilde ki Gibi Aliniz\n";
}

void bakiyeSorgula(Hesap& Kullanici)
{
	char secim;
	cout << "Islem Ucreti 8.20TL Onayliyor Musunuz?(E-H)\n";
	cin >> secim;
	if (secim == 'E' || secim == 'e')
	{
		Kullanici.Bakiye -= IslemUcreti;
		cout << "Guncel Bakiyeniz: " << Kullanici.Bakiye;
	}
}


int main()
{
	vector<Hesap> kullanicilar;
	kullanicilar.push_back(Hesap(1453, 198247, "Samet Kocan", 23557.25));
	kullanicilar.push_back(Hesap(1071, 283562, "Fatih Erol", 2571.48));
	kullanicilar.push_back(Hesap(5252, 574983, "Eren Sagdic", 55327.65));
	kullanicilar.push_back(Hesap(4380, 981634, "Mustafa Enes Saridag", 3842.36));
	kullanicilar.push_back(Hesap(3434, 765497, "Rafet Yucel", 9835.58));

	try
	{
		int password, islem, GirilenHesapNo, BulunanIndeks = -1, denemeHakki = 3;
		char secim;
		cout << "Lutfen Kartinizi Giriniz.(Simulasyon Oldugu Icin Kart Okuma Yapamiyoruz Bu Nedenle Hesap Numarasini Manuel Alacagiz)\n";
		cin >> GirilenHesapNo;
		for (int i = 0; i < kullanicilar.size(); i++)
		{
			if (kullanicilar.at(i).HesapNo == GirilenHesapNo)
			{
				BulunanIndeks = i;
				break;
			}
		}

		if (BulunanIndeks == -1)
		{
			throw"Boyle Bir Hesap Numarasi VeriTabanimizda Bulunmamaktadir\n";
		}

		Hesap& kullanici = kullanicilar.at(BulunanIndeks);
		cout << "Kart Okunuyor...\nLutfen Sifrenizi Giriniz\n";
		cin >> password;
		sifreKontrol(password, denemeHakki, kullanici);

		while (true)
		{

		cout << "Hosgeldiniz " << kullanici.KullaniciAdi << "\nHesapNo:" << kullanici.HesapNo << "\nYapmak Istediginiz Islemi Seciniz\n";
		cout << "1. PARA YATIRMA\n2. PARA CEKME\n3. BAKIYE SORGULAMA\n";
		cin >> islem;
		while (islem < 1 || islem>3)
		{
			cout << "Hatali Islem Secimi Lutfen 1 Ile 3 Arasinda Bir Secim Yapin\n";
			cin >> islem;
		}

			switch (islem)
			{
			case 1:
			{
				ParaYatir(kullanici);
				break;
			}

			case 2:
			{
				ParaCek(kullanici);
				break;
			}

			case 3:
			{
				bakiyeSorgula(kullanici);
				break;
			}
			default:
				throw"Beklenmedik Bir Hata Olustu!\n";
			}

			cout << "Baska Bir Islem Yapmak Ister Misiniz?(E-H)\n";
			cin >> secim;

			if (secim != 'E' && secim != 'e')
			{
				break;
			}
		}
	}
	catch (const char* msg)
	{
		cout << msg;
		return 1;
	}

	cout << "Iyi Gunler Dileriz...\n";
	return 0;
}
