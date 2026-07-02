# 🏧 C++ ile ATM Sistem Simülasyonu

Bu proje; **Nesne Yönelimli Programlama (OOP)** prensipleri, dinamik bellek yönetimi ve gelişmiş **Hata Yönetimi (Exception Handling)** mekanizmaları kullanılarak geliştirilmiş dönemsel bir ATM simülasyonudur.

---

## 🚀 Öne Çıkan Özellikler

* **Dinamik Kullanıcı Yönetimi:** Banka müşterileri veri tabanı yerine `std::vector` yapısı kullanılarak RAM üzerinde dinamik olarak modellenmiştir.
* **Güvenli Kart Giriş Simülasyonu:** Fiziksel bir kart okuyucuyu taklit etmek adına kullanıcıdan hesap numarası alınır ve `std::vector::at()` fonksiyonu kullanılarak güvenli sınır kontrolü (bound checking) ile eşleştirme yapılır.
* **Gelişmiş Hata Yönetimi (`try-catch`):** * Hatalı hesap numarası girişleri,
    * Üst üste 3 defa yanlış şifre girilmesi (Kart bloke simülasyonu),
    * Para çekme limitleri ve işlem ücreti dahilinde yetersiz bakiye durumları,
    * Hatalı menü seçimleri...
    gibi tüm riskli senaryolar `throw` mekanizmasıyla fırlatılarak ana `try-catch` bloğunda yakalanır ve programın çökmesi engellenir.
* **İşlem Döngüsü:** Kullanıcı her işlem sonunda "Başka bir işlem yapmak ister misiniz?" sorusuyla karşılaşır ve güvenli döngü yapısı sayesinde kurşun geçirmez bir menü deneyimi yaşar.

---

## 🛠️ Teknik Detaylar & Yapı

* **Dil:** C++ (Modern C++ Standartları)
* **OOP Konseptleri:** Sınıf (Class) yapısı, Kurucu Fonksiyonlar (Constructor), `friend` fonksiyon kullanımı, Kapsülleme (Encapsulation) ve Referans (`&`) ile nesne manipülasyonu.
* **Biçimlendirme:** Temiz ve okunabilir kod standartlarına (Clean Code) uygun girintileme ve mantıksal boşluklar.

---

## 💻 Projeyi Çalıştırma

Proje tek bir kaynak dosyasından oluşmaktadır. Herhangi bir C++ derleyicisinde (Visual Studio, GCC, Clang vb.) direkt olarak derleyip çalıştırabilirsiniz:

```bash
g++ atm_projesi.cpp -o atm_simulasyonu
./atm_simulasyonu
