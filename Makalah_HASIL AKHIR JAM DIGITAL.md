**LAPORAN TUGAS PEMBUATAN RANGKAIAN JAM DENGAN ARDUINO**
![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.001.png)


Disusun oleh:             **Rianco Marcellino Andreas 5024211061** 



1. **GAMBARAN UMUM SISTEM** 

   Pada Sistem rangkaian terdiri dari Arduino sebagai otak utama, modul RTC (misalnya DS3231) untuk menyediakan waktu real-time yang akurat, sensor DHT22 untuk mengukur suhu dan kelembaban udara, serta modul tampilan dot matriks (seperti MAX7219) untuk menampilkan informasi waktu, suhu, dan kelembaban. RTC dan DHT22 dihubungkan ke mikrokontroler melalui pin SDA dan SCL untuk RTC, dan pin data untuk LM35. Tampilan dot matriks dihubungkan melalui data pin, jam, dan beban. Setelah inisialisasi, program mikrokontroler  membaca  waktu  dari  RTC,  mengambil  data  suhu  dan kelembaban dari LM35, dan menampilkan informasi tersebut secara terformat di  tampilan  dot  matriks.  Sumber  daya  diberikan  melalui  catu  daya  untuk mendukung operasi sistem secara keseluruhan. Dan ditambahkan 4 button yaitu button pertama untuk mengganti mode pada display, Button2 digunakan untuk adjust yang digunakan pada alarm untuk merubah dari jam ke menit, Button3 digunakan untuk Menambah nilai, Button4 Digunakan untuk mengurangi nilai. 

2. **SPESIFIKASI** 

a.  Spesifikasi Sistem 

1. **Tujuan Sistem** 

Alat ini dapat digunakan untuk menampilkan Sebuah hasil dari Jam Menit Detik di dotmatrix 8x32 ( progress sementara ) 

2. Komponen Sistem: 
- DotMatrix 8x32 1 Buah 



|Matrix Size |32x8 (256-Dots) |
| - | - |
|Display Size |128x33 mm |
|Display Color |Red |
|Interface |Serial SPI Protocol |
|Operating Voltage |4\.5V - 5V DC |
|Module size |128 x 33 x 15 mm (L x W x H) |
|Mounting Hole |M3 |

Tampilan yang digunakan adalah Led Dot Matrix 8x32 dengan modul MAX7219, dengan spesifikasi sebagai berikut 

- LDR 1 Buah 
- RTC DS3231 1 Buah RTC digunakan untuk 

|Operating Voltage |3\.3V - 5V DC |
| - | - |
|RTC Chip |DS1307 |
|Clock Information |Second, Minute, Hour, Date, Month, Year |
|Time Format |AM/PM or 24 Hour |
|Communication |I2C bus interface SDA, SCL |
|||
|Battery |CR2032 |

menyediakan pencatatan waktu yang akurat dalam format jam, menit, detik, juga hari, bulan, dan  tahun.  RTC  yang digunakan pada jam digital ini adalah  DS1307  dengan spesifikasi sebagai berikut: 

- Arduino Nano 1 Buah 

  Arduino Nano adalah papan berdesain ramah papan tempat memotong roti klasik Arduino dengan dimensi terkecil. Arduino Nano dilengkapi dengan header pin yang memungkinkan pemasangan yang mudah ke papan tempat memotong roti dan dilengkapi dengan konektor USB Mini-B. 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.002.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.003.png)

- LM35 1 Buah 

|Operating Voltage |3\.5V - 5.5V DC |
| - | - |
|Operating Current |0\.3mA (measuring) 60uA (standby) |
|Temperature Range |0°C to 50°C |
|Humidity Range |20% to 90% |
|Communication |Serial data |



|Resolution |16-bit (Temperature and Humidity) |
| - | - |
|Accuracy |±1°C and ±1% |

Sensor suhu digunakan untuk mengambil informasi suhu ruangan. Sensor yang digunakan adalah LM35 dengan spesifikasi sebagai berikut: 

- Jumper 30 Buah 
- PCB HIJAU 1 Buah 
- Pin Header 
3. **Integrasi dengan Sistem Lain** 

Alat  ini  dapat  diintegrasikan  dengan  banyak  hal.  Salah  satu  contohnya adalah ketika digunakan sebagai Penampil Jam Dan Tanggal serta fitur Alarm dan sensor Cahaya dan suhu dan button untuk mengganti mode modenya . 

4. **Fitur Utama** 

Spesifikasi Menampilkan jam dan tanggal dengan karakter pada dot matrix LED 8 x 32. 

Tombol input / keyboard (non keypad). 

1 mode : run, adjust (set jam, set tanggal), alarm 1/2/3 (diplay seting alarm, 

dan adjust alarm) 

2 select adjust : jam, menit, detik / tgl, bln, thn, alarm 1 (NRP), Alarm 2 (NRP 

\+ Nama), Alarm 3 (customizable) 

3 adjust up 

4 adjust down 

Perhatikan untuk mengatur waktu tanggapan tombol input agar tidak terjadi 

input berganda yang tidak diinginkan. 

Dalam mode run, ditampilkan jam:menit:detik. Namun pada setiap detik ke 10 

dan 40 ditampilkan tanggal-bulan-tahun, 

detik ke 13 dan 43 ditampilkan suhu dalam derajad Celcius. 

Untuk mengamankan pengaturan waktu pada saat terjadi keadaan mati daya, 

maka diperlukan unit RTC sebagai pendukung. 

Kecerahan tampilan disesuaikan secara otomatis menurut keadaan cahaya 

dihadapannya menggunakan sensor cahaya. 

Dalam mode adjust, tombol up dan down bisa menerima perulangan jika 

ditekan dalam waktu lebih dari 1 detik. 

Alarm juga didukung dengan tampilan yang bersesuaian dan buzer yang akan 

berbunyi pada saat yang diprogramkan. 

Output : 

8x32 dot matrix LED warna bebas 

5. **Spesifikasi Fungsional**

iInformasi Waktu: 

Menampilkan jam, menit, dan detik. 

Format 24 jam: "Hour Minutes Second". 

Contoh: "22:45:32". 

2. Informasi Hari: 

Menampilkan tanggal, bulan (dalam bahasa Inggris 3 huruf), dan tahun. Format: "DD MM YYY". 

Contoh: "13 December 2023". 

3. Informasi Suhu: 

Menampilkan suhu dalam Celcius. 

Format: "DERAJAT °C", dengan 1 angka di belakang koma. 

Contoh: "23.3 °C". 

4. Alarm: 

3 alarm dengan display nama yang bergerak dari kanan ke kiri saat aktif. Label alarm dapat disesuaikan. 

Buzzer berbunyi saat alarm aktif. 

6. **Spesifikasi Operasional** 

   **Mode:** Pengaturan Mode: 

- Run/Aktif 
- Pengaturan Waktu 
- Pengaturan Hari 
- Pengaturan Waktu Alarm 1 
- Pengaturan Waktu Alarm 2 
- Pengaturan Waktu Alarm 3 
- Pengaturan Label Alarm 3 

Pengguna dapat mengubah mode dengan menekan tahan Tombol Mode selama 1 detik. Mode berubah sesuai urutan di atas. Untuk beralih paksa ke mode Run/Aktif, pengguna dapat menekan Tombol Mode dua kali dalam interval 500 milidetik. 

Mode Run/Aktif: 

- Menampilkan waktu, hari, dan suhu secara bergantian setiap 30 detik. 
- Detik 0-10: Informasi Waktu 
- Detik 10-13: Informasi Hari 
- Detik 13-15: Informasi Suhu 
- Detik 15-40: Kembali ke Informasi Waktu 

Pengaturan Hari: 

- Pengguna dapat mengatur TANGGAL, BULAN, dan TAHUN. 

Pengaturan Waktu Alarm 1, 2, dan 3: 

- Pengguna dapat mengatur JAM dan MENIT untuk setiap alarm. 
- Mode "JAM / ON / OFF" menampilkan status dan JAM alarm. 
- Mode "MENIT" hanya dapat diakses saat alarm aktif. 
7. **Spesifikasi Perangkat Lunak** 

   Berikut adalah spesifikasi perangkat lunak yang digunakan pada alat ini: Firmware 

Arduino Nano menggunakan Arduino IDE sebagai environment pengembangan untuk memprogram mikrokontroler. 

Bahasa Pemrograman 

Arduino Nano diprogram dengan menggunakan bahasa pemrograman C++ dengan environment Arduino IDE. 

Libraries 

MD\_MAX72XX 

Digunakan untuk mengontrol dan berkomunikasi dengan modul LED dot matrix MAX7219 atau MAX7221. Modul ini sering digunakan untuk menampilkan teks bergerak atau informasi lainnya pada display dot matrix LED. 

MD\_Parola 

Merupakan library tambahan yang sering digunakan bersama dengan MD\_MAX72XX. MD\_Parola memungkinkan pembuatan efek teks dan animasi yang lebih kompleks pada display dot matrix LED. Ini memperluas kemampuan MD\_MAX72XX untuk membuat tampilan yang lebih menarik. 

SPI 

Library ini menyediakan fungsi-fungsi untuk komunikasi serial antar- perangkat, khususnya digunakan untuk berkomunikasi dengan perangkat keras seperti sensor, display, dan modul lainnya. Pada jam digital ini, digunakan untuk berkomunikasi dengan LED Dot Matrix, RTC, serta DHT. 

RTClib 

Digunakan untuk berkomunikasi dengan modul RTC (Real-Time Clock). Modul RTC menyediakan waktu realtime yang dapat diakses oleh mikrokontroler. RTClib mempermudah penggunaan dan pembacaan informasi waktu dari modul RTC, membantu dalam aplikasi yang memerlukan pengaturan waktu yang akurat. 

8. **Spesifikasi Perangkat Keras Mikrokontroler (Arduino Nano):** 
- Vendor: Arduino 
- Cores: Atmega328P 
- RAM: 2 KB 
- Flash: 32 KB 
- Frequency: 16 MHz 
- GPIOs: 22 
- I2Cs: 1 

**Sensor:** 

Real Time Clock (DS3231): 

- Operating Voltage: 3.3V - 5V DC 
- Clock Information: Second, Minute, Hour, Date, Month, Year 
- Time Format: AM/PM or 24 Hour 
- Communication: I2C bus interface SDA, SCL 
- Backup Battery: CR2032 

**Suhu (LM35):** 

- Operating Voltage: 4V - 30V DC 
- Output Voltage: 10 mV/°C 
- Temperature Range: -55°C to 150°C 
- Accuracy: ±0.5°C 

**Cahaya (LDR):** 

- Maximum Voltage: 150V 
- Operating Temperature: -20°C to 60°C 
- Power Dissipation at 25°C: 30mW 
- Light Resistance: 10k - 20k Ω 
- Dark Resistance: 2M Ω 
3. **RANCANGAN SISTEM** 
1. Gambar Rangkaian 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.004.png)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.005.png)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.006.jpeg)

2. Rancangan Perangkat Lunak 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.007.png) ![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.008.png)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.009.jpeg)![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.010.png)

C. Rancangan Suara 

Terdapat 1 macam suara yang digunakan pada alat digital ini, yakni sebagai berikut: 

Alarm Sound 

Suara alarm yang digunakan adalah suara alarm pada umumnya yakni hanya satu nada yang diulang sebanyak 5 kali karena 5 detik.Nada yang digunakan adalah frekuensi resonansi buzzer yakni 2048 Hz sehingga menghasilkan suara yang keras. 

4. Daftar Komponen 



|**Nama Komponen** |**Jumlah** |
| - | - |
|Arduino Nano |1 buah |
|RTC DS3231 |1 buah |
|LM35 |1 buah |
|Light Dependent Resistor |1 buah |
|Resistor 100k Ω |5 buah |



|LED Dot Matrix 4 MAX7219 |4 buah |
| - | - |
|Button 2 Pin |4 buah |
|Active Buzzer |1 buah |
|Kabel Micro USB |1 buah |
|Casing ABS |2 buah (front & back) |
|PCB Dot Matrix 9X15 cm |1 buah |

5. Rancangan Huruf 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.011.png)

6. Rancangan Casing 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.012.jpeg)

4. **UJI KETAHANAN** Uji Ketahanan UpTime: 

   Jam digital dinyalakan selama 2 hari berturut-turut untuk mengevaluasi ketahanannya terhadap operasi nonstop. 

Uji Ketahanan Suhu: 

Jam digital diuji di tempat dingin (25°C) dan panas (ruang terbuka siang hari) untuk mengevaluasi kinerjanya pada kondisi suhu ekstrem. Uji ini juga memverifikasi fungsi sensor suhu. 

Uji Ketahanan Tombol: 

Tombol jam digital ditekan dengan tekanan besar dan berulang kali untuk mengevaluasi ketahanan tombol terhadap tekanan tidak wajar. 

Uji Sensor Cahaya: 

Jam digital ditempatkan pada tiga tempat dengan pencahayaan yang berbeda (minim, terang) untuk mengevaluasi kemampuan jam mengatur kecerahan layar sesuai dengan intensitas cahaya. 

Uji Ketahanan Jatuh/Banting: 

Jam digital dijatuhkan dari ketinggian 1 meter untuk mengevaluasi ketahanan fisik dan hardware terhadap benturan. 

5. **HASIL KETAHANAN** 

Hasil Uji Ketahanan UpTime 

Setelah jam digital dinyalakan selama 1 hari berturut-turut / nonstop, jam digital tetap aktif dan tidak sedikitpun mengalami kerusakan atau kegagalan sistem. 

Hasil Uji Ketahanan Tombol 

Setelah tombol jam digital ditekan dengan tekanan yang cukup besar dan ditekan berulang kali sekitar 500 kali, tombol jam digital tetap dapat bekerja dengan 

normal. 

Uji Sensor Cahaya 

Pada tempat pertama, tingkat kecerahan unit tampilan jam digital dapat secara otomatis diatur pada tingkat terendah. Pada tempat kedua, tingkat kecerahan unit tampilan jam digital dapat secara otomatis diatur pada tingkat menengah. Dan pada tempat ketiga, tingkat kecerahan unit tampilan jam digital dapat secara otomatis diatur pada tingkat tertinggi. 

Hasil Uji Ketahanan Jatuh/Banting 

Setelah jam digital dijatuhkan dari ketinggian 1 meter dari permukaan tanah sebanyak 3 kali, jam digital dapat tetap bekerja dengan baik. 

6. **Daftar Pustaka** 

MD\_MAX72XX font editor. Available at: [https://pjrp.github.io/MDParolaFontEditor ](https://pjrp.github.io/MDParolaFontEditor)

FP embed - WOKWI ESP32, STM32, Arduino Simulator. Available at: [https://wokwi.com/projects/382175464868009985 ](https://wokwi.com/projects/382175464868009985)

Anonim (2020) Arduino part-1. hardware Arduino, ELEKTRONIKA HENDRY. Available at: 

[https://www.elektronikahendry.com/2020/07/part-1-hardware- arduino.html#google_vignette ](https://www.elektronikahendry.com/2020/07/part-1-hardware-arduino.html#google_vignette)

An easier and PowerfulOnline PCB design tool (no date) EasyEDA. Available at: [https://easyeda.com/ ](https://easyeda.com/)

Arduino pinout: How use GPIO pins ? (no date) uPesy. Available at: [https://www.upesy.com/blogs/tutorials/arduino-pinout-reference-gpio-pins- ultimate-guide ](https://www.upesy.com/blogs/tutorials/arduino-pinout-reference-gpio-pins-ultimate-guide)

Arduino Nano based boards (no date) Generic Arduino Nano boards. Available at: [https://www.arduino.cc/en/Main/Products ](https://www.arduino.cc/en/Main/Products)

7. **LAMPIRAN** 
1. **Dokumentasi** 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.013.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.014.png)

2. **Program** 

**FontGW.h :**  

**MD\_MAX72XX::fontType\_t newFont[] PROGMEM = {3, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 64, 96, 2, 16, 16, 2, 96, 96, 0, 3, 127, 65, 127, 3, 66, 127, 64, 4, 113, 73, 73, 70, 3, 73, 73, 127, 3, 12, 10, 127, 3, 79, 73, 121, 3, 127, 73, 121, 3, 113, 9, 7, 3, 127, 73, 127, 3, 79, 73, 127, 1, 36, 2, 64, 36, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 126, 18, 126, 3, 126, 82, 60, 3, 60, 66, 66, 3, 126, 66, 60, 3, 126, 82, 82, 3, 126, 18, 18, 3, 126, 82, 118, 3, 126, 16, 126, 3, 66, 126, 66, 3, 66, 66, 62, 3, 126, 16, 110, 3, 126, 64, 64, 3, 126, 4, 126, 3, 126, 2, 126, 3, 126, 66, 126, 3, 126, 10, 14, 4, 62, 34, 62, 64, 3, 126, 26, 110, 3, 78, 82, 114, 3, 2, 126, 2, 3, 126, 64, 126, 3, 62, 64, 62, 5, 62, 64, 62, 64, 62, 3, 102, 24, 102, 8, 14, 120, 14, 0, 0, 0, 0, 0, 8, 114, 74, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 116, 84, 124, 3, 124, 80, 112, 3, 124, 68, 68, 3, 112, 80, 126, 3, 124, 84, 92, 3, 124, 20, 20, 3, 88, 84, 124, 3, 126, 16, 112, 1, 116, 2, 64, 52, 3, 124, 32, 80, 1, 124, 3, 124, 8, 124, 3, 124, 4, 124, 3, 124, 68, 124, 3, 124, 20, 28, 3, 28, 20, 124, 3, 120, 4, 4, 3, 92, 84, 116, 3, 8, 124, 72, 3, 124, 64, 124, 3, 56, 64, 56, 5, 60, 64, 32, 64, 60, 4, 108, 16, 16, 108, 3, 92, 80, 60, 3, 100, 84, 76, 0};![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.015.png)** ;

`     `**LISTING PROGRAM  DAN PENJELASANNYA** 

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.016.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.017.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.018.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.019.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.020.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.021.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.022.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.023.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.024.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.025.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.026.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.027.jpeg)

Kode Program ini dapat diakses di github [https://github.com/marcelaritonang/Jam_Digital_Project ](https://github.com/marcelaritonang/Jam_Digital_Project)

3. **Datasheet** 

Pinout Arduino Nano : [https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf ](https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.028.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.029.png)

DS3231: [https://components101.com/modules/ds3231-rtc-module-pinout-circuit-datasheet ](https://components101.com/modules/ds3231-rtc-module-pinout-circuit-datasheet)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.030.png)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.031.jpeg)

LDR:[ https://www.researchgate.net/figure/The-Specification-of-MKYY54C46- series-LDR_tbl1_257910407 ](https://www.researchgate.net/figure/The-Specification-of-MKYY54C46-series-LDR_tbl1_257910407)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.032.png)

MAX7219: [https://www.handsontec.com/dataspecs/module/MAX7219-4-In-1.pdf ](https://www.handsontec.com/dataspecs/module/MAX7219-4-In-1.pdf)

Active Buzzer: [https://grobotronics.com/buzzer-5v-Active.html?sl=en ](https://grobotronics.com/buzzer-5v-Active.html?sl=en)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.033.jpeg)

![](Aspose.Words.20da5dd7-5352-4a93-a825-49d44777c88d.034.png)
33 
