#include <Ultrasonic.h> // Inclui biblioteca para usar o sensor ultrassônico
Ultrasonic ultrasonic(11,10); // Passa pinos 12 e 13 como emissor e receptor

void setup(){
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
   
  int dist = ultrasonic.read(CM);
  delay(200);
  Serial.print("DIST.: "); //printa no monitor serial a distancia
  Serial.print(dist);
  Serial.println(" cm.");

 if(dist > 15)
  {
      digitalWrite(3, LOW); 
      digitalWrite(4,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      
  }else{ if(dist < 15)
  {
      digitalWrite(3,HIGH);
      digitalWrite(4, LOW); 
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      delay(500);
  }
      
  }
}
