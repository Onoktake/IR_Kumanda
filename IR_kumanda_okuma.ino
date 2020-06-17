#include <IRremote.h> //Kütüphane ekleme

int RECV_PIN = 8; // IR alıcının bağlı olduğu pin
int LED = 6;
IRrecv irrecv(RECV_PIN);
decode_results kodlar;
#define tus 16712445

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // Seri portu çalıştır
  irrecv.enableIRIn(); // Kızılötesi alıcıyı çalıştır
}
void loop() {

  if (irrecv.decode(&kodlar))
  {
    if (kodlar.value == (tus)){
      digitalWrite(LED, HIGH);
      delay(1000);
      digitalWrite(LED, LOW);
      delay(1000);
      
      }
    irrecv.resume();
  }
}
