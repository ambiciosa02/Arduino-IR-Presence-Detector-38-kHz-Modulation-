const int ledIR = 3;
const int pinRecepteur = 2;

void setup() {
  pinMode(ledIR, OUTPUT);
  pinMode(pinRecepteur, INPUT);
  Serial.begin(9600);
}

void loop() {
  envoyerSignal38kHz(); // envoie un signal IR modulé
  int etat = digitalRead(pinRecepteur);

  if (etat == LOW) {
    Serial.println("🔔 Présence détectée !");
  } else {
    Serial.println("Aucune présence.");
  }

  delay(200);
}

// Fonction pour simuler un signal 38kHz pendant un court moment
void envoyerSignal38kHz() {
  for (int i = 0; i < 100; i++) {
    digitalWrite(ledIR, HIGH);
    delayMicroseconds(13);  // ~13us pour 38kHz
    digitalWrite(ledIR, LOW);
    delayMicroseconds(13);
  }
}
