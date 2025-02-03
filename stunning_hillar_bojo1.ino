
const int sensorTemp = A0; 
const int motor = 9;      
const int ledVermelho = 7; 
const int buzina = 8;      

void setup() {
    pinMode(motor, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(buzina, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int leitura = analogRead(sensorTemp); 
    float temperatura = (leitura * 5.0 * 100.0) / 1024.0; 

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    if (temperatura >= 30) {
        digitalWrite(motor, HIGH); 
    } else {
        digitalWrite(motor, LOW); 
    }

    if (temperatura > 50) {
        digitalWrite(ledVermelho, HIGH); 
        digitalWrite(buzina, HIGH);      
    } else {
        digitalWrite(ledVermelho, LOW);  
        digitalWrite(buzina, LOW);       
    }

    delay(1000);
}
