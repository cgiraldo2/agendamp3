#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t; 

int pulsador=9;
int contador=1;
int horasPico[6]={6, 9, 11, 14, 17, 21};
int minutosPico[6]={00, 59, 30, 30, 00, 30};
int diaspico[7]={4, 1, 5, 2, 3, 'n', 'n'};

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  pinMode(pulsador,INPUT);
  mySoftwareSerial.begin(9600);
  
 
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30


}

void loop(){
 t=rtc.getTime();
 Serial.println(rtc.getDateStr());
 Serial.println(rtc.getTimeStr());
 fijarfecha();
 int pul = digitalRead(pulsador);
 if ( pul == 1){
  delay(200);
  HoraPico();
 }
 delay(1000);
     
}

void fijarfecha(){
   if (Serial.available()){
    String dato=Serial.readString();
    Serial.println(dato);
    String mes,dia,ano,hora,minuto,diaSemana;

    dia= dato.substring(0, 2);
    mes= dato.substring(2, 4);
    ano= dato.substring(4, 8);
    hora= dato.substring(8, 10);
    minuto= dato.substring(10, 12);
    diaSemana=dato.substring(12);
    
    Serial.print("mes: "); Serial.println(mes);
    Serial.print("dia: "); Serial.println(dia);
    Serial.print("ano: "); Serial.println(ano);
    Serial.print("hora: "); Serial.println(hora);
    Serial.print("minuto: "); Serial.println(minuto);
    Serial.print("dia semana: "); Serial.println(diaSemana);
    
    rtc.setTime(hora.toInt(),minuto.toInt(),0 );     // Set the time to 12:00:00 (24hr format)
    rtc.setDate(mes.toInt(),dia.toInt(),ano.toInt());   // Set the date to January 1st, 2014
    rtc.setDOW(diaSemana.toInt());

    Serial.print(rtc.getDOWStr());
    Serial.print(" ");
    // Send date
    Serial.print(rtc.getDateStr());
    Serial.print(" -- ");
  
    // Send time
    Serial.println(rtc.getTimeStr());
    // put your main code here, to run repeatedly:
  }

  
  
}  
void Reproducir(){

   for (int i = 0; i <= 2; i++) {
    myDFPlayer.play(1);  //Play the first mp3
    delay(8000);
   }    
  
}

void HoraPico(){
  
   if (t.dow == diaspico[0] || t.dow == diaspico[1] || t.dow == diaspico[2] ){
       
      if ((t.hour >= horasPico[0]) and (t.min >= minutosPico[0]) and (t.hour < horasPico[1]) and (t.min <= minutosPico[1])){ 
        Serial.println("Hora pico y placa 1"); // pico 6:00  a 9:00 
        Reproducir(); 
        }
      
      if ((t.hour >= horasPico[2]) and (t.min >= minutosPico[2]) and (t.hour < horasPico[3]) and (t.min <= minutosPico[3])){ 
        Serial.println("Hora pico y placa 2"); // pico 11:30am  a 14:30
        Reproducir();  
        }
      
      if ((t.hour >= horasPico[4]) and (t.min >= minutosPico[4]) and (t.hour < horasPico[5]) and (t.min <= minutosPico[5])){ 
        Serial.println("Hora pico y placa 3");  // pico 17:00  a 19:30
        Reproducir(); 
        }
 }
}
