#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <DS3231.h>
#include "FontGW.h"

DS3231 Clock;

const byte LDR_PIN = A1;
bool Century = false;
bool PM;
uint8_t dd, mm, yyy, dow;
uint8_t h, m, s;

#define MAX_DEVICES 4
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define CLK_PIN     13  
#define DATA_PIN 11
#define CS_PIN 10

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

#define SPEED_TIME 100
#define PAUSE_TIME_DATE 2000
#define PAUSE_TIME_TEMP 2000
#define MAX_MESG 20

char szTime[20];
const char* monthNames[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
bool button2Pressed = false;
bool button3Pressed = false;
bool button4Pressed = false;

uint8_t statusMode = 0;

uint16_t defaultYear;  // New variable for default display year

void updateDefaultYear() {
  defaultYear = Clock.getYear();
}
void getTime(char *psz)
{
  bool h12;
  s = Clock.getSecond();
  m = Clock.getMinute();
  h = Clock.getHour(h12, PM);
  
  if (statusMode == 0 || statusMode == 1 || statusMode == 4 || statusMode == 5 || statusMode == 6) {
    updateDefaultYear();  // Update default year if in relevant modes
  }

  int fullYear = Century ? (defaultYear) : defaultYear;

  if (statusMode == 0) {
    sprintf(psz, "%02d:%02d:%02d", h, m, s);
  } else if (statusMode == 1) {
    sprintf(psz, "%02d", dd);
  } else if (statusMode == 2) {
    sprintf(psz, "%s", monthNames[mm]);  // Adjust month index
  } else if (statusMode == 3) {
    sprintf(psz, "%04d", yyy + 2000);
  } else {
    // Add other cases as needed
    sprintf(psz, ""); // Handle other cases
  }
}

int daysInMonth(int month,int year){
  if(month == 4 || month == 6 || month == 8 ||month == 10 || month == 12 ){
    return 30; 
  }
  else if(month == 2){
    if(year % 4 == 0 ){
      return 29; 
    }else{
      return 28;} 
  }
  else {
    return 31;
  } 
}


void setup(void)
{

  DateTime now = Clock.getDate();
  dd = now.day();
  dd += 6;
  mm = now.month();
  yyy = now.year();
  yyy = yyy -35;
  int monthDifference = 12 - mm;  // Hitung selisih antara bulan saat ini dan Desember
  mm = mm + monthDifference;  // Kurangkan nilai bulan
  // Pastikan mm berada dalam rentang 1-12
  mm = (mm <= 0) ? (mm + 12) : ((mm > 12) ? (mm - 12) : mm);
  pinMode(3, INPUT_PULLUP); // Tombol 1
  pinMode(4, INPUT_PULLUP); // Tombol 2  
  pinMode(5, INPUT_PULLUP); // Tombol 31-+66
  pinMode(6, INPUT_PULLUP); // Tombol 4
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  P.begin(2);
  P.setInvert(false);
  P.setZoneEffect(0, true, PA_FLIP_UD);
  P.setZoneEffect(0, true, PA_FLIP_LR);

  Wire.begin();
  
  P.displayReset();

  P.setFont(newFont);

  P.setZone(0, 0, MAX_DEVICES - 1);
  P.setZone(1, 0, MAX_DEVICES - 1);

  P.displayZoneText(0, szTime, PA_CENTER, SPEED_TIME, 0, PA_PRINT, PA_NO_EFFECT);

  getTime(nullptr);
}
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500; 
byte alarm1Hour = 0;
byte alarm1Minute = 0;

byte alarm2Hour = 0;
byte alarm2Minute = 0;

byte alarm3Hour = 0;
byte alarm3Minute = 0;

bool setAlarm1Hour = true;
bool setAlarm2Hour = true;
bool setAlarm3Hour = true;

bool isAl1On = false;
bool isAl2On = false;

void loop(void)
{

  bool button1 = digitalRead(3); // Tombol 1
  bool button2 = digitalRead(4); // Tombol 2
  bool button3 = digitalRead(5); // Tombol 3
  bool button4 = digitalRead(6); // Tombol 4
  unsigned long currentMillis = millis();


  if(alarm1Hour == h && alarm1Minute == m && s < 5){
    if(statusMode == 0){
    digitalWrite(7,HIGH);
    if(P.displayAnimate()){
      P.displayText("5024211061", PA_CENTER, 25 , 500,PA_SCROLL_LEFT,PA_SCROLL_LEFT);
    }
    isAl1On = true;

    
    }
  } else {
    isAl1On = false;
  }

  if(alarm2Hour == h && alarm2Minute == m && s < 5){
    if(statusMode == 0){
    digitalWrite(7,HIGH);
    if(P.displayAnimate()){
      P.displayText("5024211061 Rianco Marcelino Andreas", PA_CENTER, 25 , 500,PA_SCROLL_LEFT,PA_SCROLL_LEFT);
    }
    isAl2On = true;
    }
  } else {
    isAl2On = false;
  }

  if(alarm3Hour == h && alarm3Minute == m && s < 5){
    if(statusMode == 0){
    digitalWrite(7,HIGH);
    Serial.print("apaan");
    }
  }


  if (button1 == LOW && (currentMillis - lastDebounceTime) > debounceDelay) {
    // Tombol 1 ditekan, lakukan tindakan yang sesuai
    statusMode = (statusMode + 1) % 7;    
    lastDebounceTime = currentMillis;
  }
  

  if (button2 == LOW && (currentMillis - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = currentMillis;

    // Tombol 3 ditekan, atur flag penanda
    button2Pressed = true;
      } 
  else {
    // Tombol 3 tidak ditekan, reset flag penanda
    button2Pressed = false;
  }




  if (button3 == LOW && (currentMillis - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = currentMillis;

    // Tombol 3 ditekan, atur flag penanda
    button3Pressed = true;
      } 
  else {
    // Tombol 3 tidak ditekan, reset flag penanda
    button3Pressed = false;
  }
 

  if (button4 == LOW && (currentMillis - lastDebounceTime)> debounceDelay) {
    lastDebounceTime = currentMillis; 
    button4Pressed = true; 
  }
  else{
    button4Pressed = false; 
  } 


  int lightValue = analogRead(LDR_PIN);
  byte ledIntensity = ledIntensitySelect(lightValue);
  P.setIntensity(ledIntensity);

  char szTime[12];
    getTime(szTime);
  

  if (isAl1On || isAl2On) return;
  if(statusMode == 0) {
    if (s == 10 || s == 40 )
    {
      sprintf(szTime, "%02d", dd);
      if(P.displayAnimate()){
        P.displayText(szTime, PA_CENTER, 25 , 500,PA_OPENING_CURSOR,PA_OPENING_CURSOR);
      }
    }
    else if(s == 11 || s == 41){
      sprintf(szTime,"%s",monthNames[mm-1] );
      P.print(szTime);
     }
    else if( s == 12 || s == 42){
      sprintf(szTime, "%04d", yyy+2000);
      if(P.displayAnimate()){
        P.displayText(szTime, PA_CENTER, 25 , 500,PA_OPENING_CURSOR,PA_OPENING_CURSOR);
      }
    }
    else if (s == 13 || s == 14 || s == 43 || s == 44)
    {
      float temperature = Clock.getTemperature();
      dtostrf(temperature, 4, 1, szTime);
      strcat(szTime, "$°C");
      if(P.displayAnimate()){
        P.displayText(szTime, PA_CENTER, 25 , 500,PA_SCROLL_LEFT,PA_SCROLL_LEFT);
      }
  
    }
    else
    {
      P.print(szTime);
    }
  }




  else if (statusMode == 1) {
    if (button3Pressed) {
        // Tombol 3 ditekan, tambahkan satu hari ke tanggal
        dd++;
        if (dd > daysInMonth(mm, yyy)) {
            dd = 1;
            if (mm == 12) {
                mm = 1;
                yyy++;
            } else {
                mm++;
            }
        }
    }
    if (button4Pressed){
      dd--; 
      if (dd < 1) {
        if (mm == 1) {
            mm = 12;
            yyy--;
        } else {
            mm--;
        }
        dd = daysInMonth(mm, yyy);
    }
      if(dd == 255){
        dd = daysInMonth(mm,yyy);
      }
    }
    sprintf(szTime, "%02d", dd);
    if ((millis() % 1000) / 500 == 0) {
      P.print(szTime);
    } else {
      P.print("");
    }
  } 
  


    else if (statusMode == 2) {
    if (button3Pressed) {
        // Tombol 3 ditekan, tambahkan satu bulan
        mm++;
        if (mm > 12) {
            mm = 1;
            yyy++;
        }
    }

    // Logika untuk tombol 4
    if (button4Pressed) {
        // Tombol 4 ditekan, kurangkan satu bulan
      mm--;
       if (mm < 1) {
            mm = 12;
            yyy--;
        }
       if (mm == 0){
        mm = 1;
       }
      
    }
    if(mm == 0){
      mm = 1; 
    }
    sprintf(szTime, "%s", monthNames[mm-1]);
    if ((millis() % 1000) / 500 == 0) {
        P.print(szTime);
    } else {
        P.print("");
    }
}
  



  else if (statusMode == 3) {
    if (button3Pressed) {
        // Tombol 3 ditekan, tambahkan satu tahun
        yyy++;
    }

    // Logika untuk tombol 4
    if (button4Pressed) {
        // Tombol 4 ditekan, kurangkan satu tahun
        yyy--;
    }
    sprintf(szTime, "%04d", yyy+2000);
    if ((millis() % 1000) / 500 == 0 ) {
      P.print(szTime);
    } else {
      P.print("");
    }
  } 
  
    else if (statusMode == 4) {
    if(button2Pressed) {
      setAlarm1Hour = !setAlarm1Hour;
    }

    if(button3Pressed){
      if (setAlarm1Hour) {
        alarm1Hour++;
        if (alarm1Hour == 23 || alarm1Hour == 24){
          alarm1Hour = 0 ; 
        }
      } else {
        alarm1Minute++;
        if (alarm1Minute == 60){
          alarm1Minute = 0 ; 
        }
      }
    }
    if(button4Pressed){
      if (setAlarm1Hour) {
        alarm1Hour--;
        if(alarm1Hour <0 || alarm1Hour ==255){
          alarm1Hour  = 23;
        }
      } else {
        alarm1Minute--;
        if (alarm1Minute < 0 || alarm1Minute == 255){
          alarm1Minute = 59 ; 
        }
      }
    }
    // Tampilkan informasi alarm 1
    sprintf(szTime, "AL1 %02d:%02d", alarm1Hour, alarm1Minute);
    if ((millis() % 1000) / 500 == 0 ) {
      P.print(szTime);
    } else {
      if (setAlarm1Hour) {
        szTime[4] = '@';
        szTime[5] = '@';
      } else {
        szTime[7] = '@';
        szTime[8] = '@';
      }
      P.print(szTime);
    }
  } 
  
  
  else if (statusMode == 5) {
    if(button2Pressed) {
      setAlarm2Hour = !setAlarm2Hour;
    }

    if(button3Pressed){
      if (setAlarm2Hour) {
        alarm2Hour++;
        if (alarm2Hour == 23 || alarm2Hour == 24){
          alarm2Hour = 0 ; 
        }
      } else {
        alarm2Minute++;
        if (alarm2Minute == 60){
          alarm2Minute = 0 ; 
        }
      }
    }
    if(button4Pressed){
      if (setAlarm2Hour) {
        alarm2Hour--;
        if(alarm2Hour <0 || alarm2Hour ==255){
          alarm2Hour  = 23;
        }
      } else {
        alarm2Minute--;
        if (alarm2Minute < 0 || alarm2Minute == 255){
          alarm2Minute = 59 ; 
        }
      }
    }
    // Tampilkan informasi alarm 1
    sprintf(szTime, "AL2 %02d:%02d", alarm2Hour, alarm2Minute);
    if ((millis() % 1000) / 500 == 0 ) {
      P.print(szTime);
    } else {
      if (setAlarm2Hour) {
        szTime[4] = '@';
        szTime[5] = '@';
      } else {
        szTime[7] = '@';
        szTime[8] = '@';
      }
      P.print(szTime);
    }
  } 
   

  else if (statusMode == 6) {
    if(button2Pressed) {
      setAlarm3Hour = !setAlarm3Hour;
    }

    if(button3Pressed){
      if (setAlarm3Hour) {
        alarm3Hour++;
        if (alarm3Hour == 23 || alarm3Hour == 24){
          alarm3Hour = 0 ; 
        }
      } else {
        alarm3Minute++;
        if (alarm3Minute == 60){
          alarm3Minute = 0 ; 
        }
      }
    }
    if(button4Pressed){
      if (setAlarm3Hour) {
        alarm3Hour--;
        if(alarm3Hour <0 || alarm3Hour ==255){
          alarm3Hour  = 23;
        }
      } else {
        alarm3Minute--;
        if (alarm3Minute < 0 || alarm3Minute == 255){
          alarm3Minute = 59 ; 
        }
      }
    }
    // Tampilkan informasi alarm 1
    sprintf(szTime, "AL3 %02d:%02d", alarm3Hour, alarm3Minute);
    if ((millis() % 1000) / 500 == 0 ) {
      P.print(szTime);
    } else {
      if (setAlarm3Hour) {
        szTime[4] = '@';
        szTime[5] = '@';
      } else {
        szTime[7] = '@';
        szTime[8] = '@';
      }
      P.print(szTime);
    }
    
} 
}

byte ledIntensitySelect(int light)
{
  byte _value = 0;
  if (light >= 0 && light <=  250)
  {
    _value = 20;
  }

  else if (light >=250 && light <= 512)
  {
    _value = 15;
  }
  return _value;
}