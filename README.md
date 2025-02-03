# Projeto de Circuitos Eletrônicos - IoT

Este projeto implementa um sistema de monitoramento de temperatura utilizando **Arduino Uno** e um **sensor LM35**. O circuito inclui um **motor (ventilador), um LED vermelho e uma buzina** para alertas.

## 📌 Funcionalidade
- Leitura da temperatura em tempo real através do **sensor LM35**.
- **Acionamento do motor (ventilador)** se a temperatura for igual ou maior que **30°C**.
- **Acionamento do LED vermelho e da buzina** se a temperatura ultrapassar **50°C**.
- Exibição da temperatura via **Serial Monitor** do Arduino.

## 🛠 Componentes Utilizados
- **1x Arduino Uno**
- **1x Sensor de Temperatura LM35**
- **1x Motor (Ventilador)**
- **1x LED Vermelho**
- **1x Buzina (Buzzer Passivo ou Ativo)**
- **Resistores e Jumpers**
- **Protoboard**

## 📜 Código-fonte (C++)
```cpp
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
```

## 🔌 Esquema de Ligação
O sensor **LM35** deve ser conectado ao pino **A0** do Arduino. O **motor (ventilador)**, **LED vermelho** e **buzina** são conectados aos pinos digitais definidos no código.

## 🚀 Como Usar
1. **Monte o circuito** conforme o esquema.
2. **Carregue o código no Arduino Uno** utilizando a IDE do Arduino.
3. **Abra o Serial Monitor** para visualizar a temperatura em tempo real.
4. O **motor** ligará automaticamente quando a temperatura for **≥ 30°C**.
5. O **LED vermelho e a buzina** serão acionados em caso de temperatura **> 50°C**.

## 🔗 Simulação Online
Para testar o código sem hardware físico, utilize o **TinkerCad**: [TinkerCad](https://www.tinkercad.com/)

## 🏗 Possíveis Melhorias
- Utilizar um display LCD para exibir a temperatura.
- Implementar um sistema de controle via Wi-Fi com ESP8266.
- Adicionar um relé para acionar dispositivos de maior potência.


