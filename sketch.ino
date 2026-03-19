const int PINO_TRIG = 25; //Pino trigger
const int PINO_ECHO = 27; // Pino retorno
const int PINO_LED_INTRUSO = 26; // Led indicador


float obter_distancia();

void setup() {
  Serial.begin(115200);

  pinMode(PINO_TRIG, OUTPUT); // TRIGGER ENVIA O PULSO
  pinMode(PINO_ECHO, INPUT); // ECHOD QUE RECEDBE O PULSO
  pinMode(PINO_LED_INTRUSO, OUTPUT);
  digitalWrite(PINO_TRIG, LOW);
}

void loop() {

  float dist = obter_distancia();
  Serial.println("Distancia: ");
  Serial.println(dist);
  Serial.println(" cm");

  if (dist > 0 && dist<= 10){
    
    Serial.println("Ambiente inseguro!!");
    digitalWrite(PINO_LED_INTRUSO, HIGH);
  
  delay(1000);
  }
  else{
    Serial.println("Ambiente Seguro");
    digitalWrite(PINO_LED_INTRUSO, LOW);
  }
  delay(2000);
}


float obter_distancia(){
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
    digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
    digitalWrite(PINO_TRIG, LOW);
 

  long duracao = pulseIn(PINO_ECHO, HIGH, 30000);
 
  float distancia = (duracao/2.0) * 0.0343;
  return distancia;

}