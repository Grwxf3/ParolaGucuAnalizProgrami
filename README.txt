Parola Gücü ve Kırılabilirlik Analiz Aracı

Bu proje, C++ ve Qt 6 kütüphanesi kullanılarak geliştirilmiş basit bir masaüstü uygulamasıdır. Kullanıcının girdiği parolanın gücünü analiz eder ve bu parolanın ne kadar sürede kırılabileceğine dair bir tahminde bulunur.

Özellikler

- Anlık Analiz: Parola yazılırken anında güç seviyesi güncellenir.
- Güç Kriterleri: Analiz yapılırken aşağıdaki kriterler göz önünde bulundurulur:
    - Parola uzunluğu
    - Küçük harf kullanımı
    - Büyük harf kullanımı
    - Rakam kullanımı
    - Özel karakter kullanımı
- Kırılma Süresi Tahmini: Parolanın sahip olduğu karakter havuzu ve uzunluğuna göre, saniyede 10 milyar deneme yapan bir sistemin parolayı ne kadar sürede kırabileceğini tahmin eder.
- Görsel Arayüz: Qt ile oluşturulmuş basit ve kullanıcı dostu bir arayüze sahiptir.

Kurulum ve Derleme Şekli

Bu projeyi derlemek ve çalıştırmak için sisteminizde CMake ve Qt 6 kütüphanelerinin kurulu olması gerekmektedir.

1. Proje dosyalarını bir klasöre indirin.
2. Terminal veya komut istemcisini açın ve proje klasörüne gidin.
3. Aşağıdaki komutları sırasıyla çalıştırın:

   # Bir build (derleme) klasörü oluşturun ve içine girin
   mkdir build
   cd build

   # CMake ile proje yapılandırmasını oluşturun
   cmake ..

   # Projeyi derleyin
   cmake --build .

4. Derleme tamamlandıktan sonra `build` klasörü içinde platformunuza göre `PasswordStrengthAnalyzer.exe` (Windows) veya `PasswordStrengthAnalyzer` (Linux/macOS) isminde çalıştırılabilir bir dosya oluşacaktır. Bu dosyayı çalıştırarak uygulamayı başlatabilirsiniz.