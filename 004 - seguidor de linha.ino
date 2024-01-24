/*
Programador: Danilo José de Lima
Objetivo: simular um seguidor de linha
A implementação do seguidor real fjoi feita no final de 2023 e pode ser vista aqui: https://www.youtube.com/shorts/JA_QfBgqdV0
O circuito simulado no tinkercad está em https://www.tinkercad.com/things/1q4p5g5VkHn-seguidor-de-linha
*/
/*conexões
3~ led
4 push button
5~ enable 1
6~ input 1
7 input 2

9~ enable 2
10~ input 3
11~ input 4
A0 sensor esquerdo
A1 sendor direito

Alimentação do motor - Vs
5V Arduino - Vss
GND Arduino - GND da ponte H - GND alimentação do motor (todos juntos)

autor: professor danilo (2023)
 */
int ligado = 0,
    velocidade = 250,
    espera = 150,
    led = 3,
    botao = 4,      
    rodaEsquerda = 5,
    inputEsquerdaA = 6,
    inputEsquerdaB = 7,     
    rodaDireita = 9,
    inputDireitaA = 10,
    inputDireitaB = 11, 
    sensorEsquerda = A0,
    sensorDireita = A1;
    
void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(rodaEsquerda, OUTPUT);
  pinMode(inputEsquerdaA, OUTPUT);
  pinMode(inputEsquerdaB, OUTPUT);
  pinMode(rodaDireita, OUTPUT);
  pinMode(inputDireitaA, OUTPUT);
  pinMode(inputDireitaB, OUTPUT);
  pinMode(sensorEsquerda, INPUT);
  pinMode(sensorDireita, INPUT);
  Serial.begin(9600);
  digitalWrite(led, HIGH);
}

void loop() {
  while(ligado == 0){
    if(!digitalRead(botao)){
      ligado = 1;
    }
  }/*
  Serial.print("Sendor da direita: ");  
  Serial.println(digitalRead(sensorDireita));
  Serial.print("Sendor da esquerda: ");  
  Serial.println(digitalRead(sensorEsquerda));   */
  if(!digitalRead(sensorEsquerda) & digitalRead(sensorDireita)){
    esquerda(velocidade);
  }
  else if(digitalRead(sensorEsquerda) & !digitalRead(sensorDireita)){
    direita(velocidade);
  }
  else if(!digitalRead(sensorEsquerda) & !digitalRead(sensorDireita)){
    frente(velocidade);
  }
  else{
    parar();
    digitalWrite(led, LOW);
  }  
}

void frente(int velocidade){
  analogWrite(rodaEsquerda, velocidade);
  digitalWrite(inputEsquerdaA, LOW);
  digitalWrite(inputEsquerdaB, HIGH);
  analogWrite(rodaDireita, velocidade);
  digitalWrite(inputDireitaA, LOW);
  digitalWrite(inputDireitaB, HIGH);
}

void parar(){
  analogWrite(rodaEsquerda, 0);
  digitalWrite(inputEsquerdaA, LOW);
  digitalWrite(inputEsquerdaB, LOW);
  analogWrite(rodaDireita, 0);
  digitalWrite(inputDireitaA, LOW);
  digitalWrite(inputDireitaB, LOW);
}

void re(int velocidade){  
  analogWrite(rodaEsquerda, velocidade);
  digitalWrite(inputEsquerdaA, HIGH);
  digitalWrite(inputEsquerdaB, LOW);
  analogWrite(rodaDireita, velocidade);
  digitalWrite(inputDireitaA, HIGH);
  digitalWrite(inputDireitaB, LOW);
}

void esquerda(int velocidade){
  analogWrite(rodaEsquerda, velocidade);
  digitalWrite(inputEsquerdaA, HIGH);
  digitalWrite(inputEsquerdaB, LOW);
  analogWrite(rodaDireita, velocidade);
  digitalWrite(inputDireitaA, LOW);
  digitalWrite(inputDireitaB, HIGH);
  delay(espera);
}

void direita(int velocidade){
  analogWrite(rodaEsquerda, velocidade);
  digitalWrite(inputEsquerdaA, LOW);
  digitalWrite(inputEsquerdaB, HIGH);
  analogWrite(rodaDireita, velocidade);
  digitalWrite(inputDireitaA, HIGH);
  digitalWrite(inputDireitaB, LOW);
  delay(2*espera);
}
