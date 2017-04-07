                       
#include <DHT.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 2
#define RELAY1 6       

DHT dht(DHTPIN, DHTTYPE);
 int temp;
 int rled = 8;
 int gled = 10;
 int bled = 12;
 
 void setup(){    


  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);  

  //LED RGB
  pinMode(rled,OUTPUT);
  pinMode(bled,OUTPUT);
  pinMode(gled,OUTPUT);
  digitalWrite(RELAY1,1);
  

}



  void loop(){
     temp = dht.readTemperature();
     Serial.println(temp);
     delay(500);
   
    if(temp>=5){
      digitalWrite(RELAY1,0); //Compresor Encendido
      analogWrite(gled,0);
      analogWrite(rled,255); 
       // Se enciende color azul
    }else if(temp<=4){
        
       digitalWrite(RELAY1,1); //Compresor Apagado
       analogWrite(rled,0);
       analogWrite(gled,255);
      // Se enciende color rojo
      
        
    }

  
   
}
