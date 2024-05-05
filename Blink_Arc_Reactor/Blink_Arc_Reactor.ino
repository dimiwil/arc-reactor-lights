/*
Blink Without Delay - anhand von Beispielen erklärt
fünf parallel laufende, voneinander unabhängige, unterschiedliche Zeiten 

!!! Variablen zum speichern von Zeiten aus millis() und micros() immer 'unsigned long' deklarieren !!!

*/


// Variablen deklarieren in denen die Startzeiten
// der einzelnen Zeitfunktionen gespeichert werden
unsigned long startzeit_1 = 0;
unsigned long startzeit_2 = 0;

// Definitionen der einzelnen Schaltzeiten
int laufzeit_1 = 50;
int laufzeit_2 = 75;

// Die Anschlusspins der einzelnen LEDs festlegen
const int led_1 = 3;
const int led_2 = 5;

long startzeit;
const int duration = 2000;

// Pins als Ausgang
void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

  startzeit = millis();
}

void loop() {

  int faktor = millis() - startzeit;
  if (faktor <= duration) {
    // laufzeit_1 EIN, laufzeit_1 AUS - LED schalten in loop - Schaltzeiten in Millisekunden
    if (millis() - startzeit_1 >= laufzeit_1) {
      startzeit_1 = millis();
      digitalWrite(led_1, digitalRead(led_1) ^ 1);
      laufzeit_1 = random (25, 75) + (faktor / 50);
    }
    // laufzeit_2 EIN, laufzeit_2 AUS - LED schalten in Funktion - Schaltzeiten in Millisekunden
    if (millis() - startzeit_2 >= laufzeit_2) {
      startzeit_2 = millis();
      led2();
      laufzeit_2 = random(50, 100)+ (faktor / 50);
    }
  } else {
    digitalWrite(led_1, digitalRead(led_1) ^ 1);
    digitalWrite(led_2, digitalRead(led_2) ^ 1); 
  }
  


}

// Unterprogramm für Led 2
void led2() {
  digitalWrite(led_2, digitalRead(led_2) ^ 1);  
}