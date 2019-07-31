String setFecha = "###2307201920102##*";
String horasPico = "!!#080911141720!!*";
String minutospico = "***000030300030///";
String DiasPico = "--*1234567//*";
int TablaHorasPico[6];
int Tablaminutospico[6];
int TablaDiasPico[7];
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
    delay(200);
    //extraerhorapico(dato);
    //extraerminutospico(dato);
    //extraerFecha(dato);
    extraerDiaspico(dato);
    
    Serial.println("HORAS: ");
    for(int i=0;i< 6; i++){
      Serial.println(TablaHorasPico[i]);
    }

    Serial.println("Minutos: ");
    for(int i=0;i< 6; i++){
      Serial.println(Tablaminutospico[i]);
    }

    Serial.println("dias semana: ");
    for(int i=0;i< 7; i++){
      Serial.println(TablaDiasPico[i]);
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
void extraerDiaspico(String dias){
  int finalCadena = dias.length();
  finalCadena -= 3;

  //Serial.println(finalCadena);
  if(dias.startsWith("--*") && dias.endsWith("//*")){
    
     String dias1 = dias.substring(3,finalCadena);
     String dias2 = dias1.substring(0,1);
     String dias3 = dias1.substring(1,2);
     String dias4 = dias1.substring(2,3);
     String dias5 = dias1.substring(3,4);
     String dias6 = dias1.substring(4,5);
     String dias7 = dias1.substring(5,6);
     String dias8 = dias1.substring(6,7);


     TablaDiasPico[0]=dias2.toInt();
     TablaDiasPico[1]=dias3.toInt();
     TablaDiasPico[2]=dias4.toInt();
     TablaDiasPico[3]=dias5.toInt();
     TablaDiasPico[4]=dias6.toInt();
     TablaDiasPico[5]=dias7.toInt();
     TablaDiasPico[6]=dias8.toInt();
  }
}
