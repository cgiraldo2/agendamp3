String setFecha = "###2307201920102##*";
String horasPico = "!!#080911141720!!*";
String minutospico = "***000030300030///";
int TablaHorasPico[6];
int Tablaminutospico[6];
void setup() {
  Serial.begin(9600);
  
  //extraerFecha(setFecha);
  //extraerhorapico(horasPico);
  
}
//concat() Unir
//startsWith() inicia con una letra " "
//endsWith() Termina con una letra " "
//indexOf() Devuelve un numero
//length() Devuelve el tamaño de la cadena
//toInt()Para Convertir
//toLowerCase()
//toUpperCase()
//substring(inicio,final)
String dato = "";
void loop() {
  while(Serial.available()>0){
    dato = Serial.readString();
    Serial.println(dato);
    delay(100);
    extraerhorapico(dato);
    extraerminutospico(dato);
    extraerFecha(dato);

    Serial.println("HORAS: ");
    for(int i=0;i< 6; i++){
      Serial.println(TablaHorasPico[i]);
    }

    Serial.println("Minutos: ");
    for(int i=0;i< 6; i++){
      Serial.println(Tablaminutospico[i]);
    }

    dato = "";
    Serial.flush();
  }
  

}

void extraerhorapico(String horas){
  int finalCadena = horas.length();
  finalCadena -= 3;

  //Serial.println(finalCadena);
  if(horas.startsWith("!!#") && horas.endsWith("!!*")){
    
     String horas1 = horas.substring(3,finalCadena);
     String horas2 = horas1.substring(0,2);
     String horas3 = horas1.substring(2,4);
     String horas4 = horas1.substring(4,6);
     String horas5 = horas1.substring(6,8);
     String horas6 = horas1.substring(8,10);
     String horas7 = horas1.substring(10,12);

     TablaHorasPico[0]=horas2.toInt();
     TablaHorasPico[1]=horas3.toInt();
     TablaHorasPico[2]=horas4.toInt();
     TablaHorasPico[3]=horas5.toInt();
     TablaHorasPico[4]=horas6.toInt();
     TablaHorasPico[5]=horas7.toInt();

  }
}

void extraerminutospico(String minutos){
  int finalCadena = minutos.length();
  finalCadena -= 3;

  //Serial.println(finalCadena);
  if(minutos.startsWith("***") && minutos.endsWith("///")){
    
     String minutos1 = minutos.substring(3,finalCadena);
     String minutos2 = minutos1.substring(0,2);
     String minutos3 = minutos1.substring(2,4);
     String minutos4 = minutos1.substring(4,6);
     String minutos5 = minutos1.substring(6,8);
     String minutos6 = minutos1.substring(8,10);
     String minutos7 = minutos1.substring(10,12);

     Tablaminutospico[0]=minutos2.toInt();
     Tablaminutospico[1]=minutos3.toInt();
     Tablaminutospico[2]=minutos4.toInt();
     Tablaminutospico[3]=minutos5.toInt();
     Tablaminutospico[4]=minutos6.toInt();
     Tablaminutospico[5]=minutos7.toInt();

  }
}
String extraerFecha(String fecha){
  int finalCadena = fecha.length();
  finalCadena -= 3;

  //Serial.println(finalCadena);
  if(fecha.startsWith("###") && fecha.endsWith("##*")){

    Serial.print("Hora establecida en: ");
    Serial.println(setFecha.substring(3,finalCadena));
    return setFecha.substring(3,finalCadena);
  }
}
