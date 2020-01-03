#include <Servo.h>

const int mic=A0;
int sens_mic;
const int led0=3;
const int led1=2;
const int led2=4;
const int led3=5;
const int led4=6;
const int led5=7;
const int led6=8;

int pot=A1;
int pot_1;

int x=0;
int y=0;

Servo myservo;
const int  s_mov=9;
const int M1=10;
int PIR;

long tiempo;
int disparador = 12;   // triger
int entrada = 13;      // echo
float distancia;
const int buzz= 11;

void setup() {
  Serial.begin(9600);
  pinMode(mic,INPUT);
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);


  pinMode(s_mov,INPUT);
  pinMode(M1,OUTPUT);  
  myservo.attach(M1);
  myservo.write(90);

  pinMode(disparador, OUTPUT);
  pinMode(entrada, INPUT);
  pinMode(buzz, OUTPUT);

}

void loop() {
for(y==0; y<=4999; y++){

sens_mic=digitalRead(mic);
if(sens_mic == HIGH){
  Serial.print("Microfono   =");
  Serial.println(sens_mic);
  for(x==0; x<=100; x++ )
{
  pot_1=analogRead(pot);
  analogWrite(led0,random(0,255));
  int switch_pot= map(pot_1, 0, 1023, 0, 6);
  Serial.println(pot_1);
  switch_led(switch_pot);
  delay(100);  
  
}
digitalWrite(led0,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
digitalWrite(led5,LOW);
digitalWrite(led6,LOW);
x=0;
}

} y=0;

//Termina Sensor VOZ


PIR= digitalRead(s_mov);
  Serial.println(PIR);

  if(PIR==HIGH)
  {   
   for(x==0; x<3; x++)
   {
  myservo.write(160);
  delay(800);
  myservo.write(90);
  delay(300);
    }
    x=0;
    delay(1000);
    
}
//Termina Sensor PIR

// lanzamos un pequeño pulso para activar el sensor
  digitalWrite(disparador, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador, LOW);
  
  // medimos el pulso de respuesta
  tiempo = (pulseIn(entrada, HIGH)/2); 
  distancia = float(tiempo * 0.0343);
  
  // y lo mostramos por el puerto serie una vez por segundo
  Serial.println(distancia);
  //delay(1000);

  if(distancia <= 50){
      int switch_sonar= map(distancia, 0, 50, 0, 7);
      switch_buzz(switch_sonar);   
    }
//Termina Sensor Ultrasónico


}

// FUNCIONES

void switch_led(int var)
{
  switch (var) {
    case 0:
      {
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);     
      }
      break;

         case 1:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);     
      }
      break;

         case 2:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);     
      }
      break;

      case 3:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);     
      }
      break;

      case 4:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);     
      }
      break;

     case 5:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, LOW);     
      }
      break; 

     case 6:
      {
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);     
      }
      break; 
      
    default: 
      break;
  }
  }


void switch_buzz(int var)
{
  switch (var) {
    case 0:
      {
     tone(buzz, 261);     
     delay(50);
     noTone(buzz);
     Serial.println(261);
      }
      break;

         case 1:
      {
    tone(buzz, 294);     
     delay(50);
     noTone(buzz);  
     Serial.println(294);  
      }
      break;

         case 2:
      {
  tone(buzz, 329);     
     delay(50);
     noTone(buzz);   
     Serial.println(329); 
      }
      break;

      case 3:
      {
       tone(buzz, 349);     
     delay(50);
     noTone(buzz);   
     Serial.println(349);
      }
      break;

      case 4:
      {
       tone(buzz, 392);     
     delay(50);
     noTone(buzz);  
     Serial.println(392);
      }
      break;

     case 5:
      {
      tone(buzz, 440);     
     delay(50);
     noTone(buzz);    
     Serial.println(440);
      }
      break; 

     case 6:
      {
       tone(buzz, 493);     
     delay(50);
     noTone(buzz);     
     Serial.println(493);
      }
      break; 

      
     case 7:
      {
       tone(buzz, 523);     
     delay(50);
     noTone(buzz);     
     Serial.println(523);
      }
      break; 
      
    default: 
      break;
  }
  }

  


  


