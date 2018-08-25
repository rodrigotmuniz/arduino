#define POT_PIN A0

int qtdeAmostras;
int somaAmostras;

int saidaFinal;
int saidaParcial;
int saidaAvaliada;

int qtdeAcertos;

void setup() {

  qtdeAmostras = 50;
  somaAmostras = 0;
  qtdeAcertos = 0;
  saidaFinal = analogRead(POT_PIN);
  saidaAvaliada = 0;
  Serial.begin(115200);

}

void loop() {
  for(int i = 0; i < qtdeAmostras; i++) {
    somaAmostras += analogRead(POT_PIN);
    delay(1);
  };
  saidaParcial = somaAmostras / qtdeAmostras;

  if(saidaAvaliada == 0) {
    saidaAvaliada = saidaParcial;
  };

  if(saidaAvaliada == saidaParcial) {
    qtdeAcertos++;
  }
  else {
    qtdeAcertos = 0;
    saidaAvaliada = 0;
  };
  
  if(qtdeAcertos > 10) {
    if(saidaFinal * 1.03 > saidaAvaliada || saidaFinal * .97 < saidaAvaliada) {
      saidaFinal = saidaAvaliada;
    }
    saidaAvaliada = 0;
    qtdeAcertos = 0;
//    Serial.println("------------------");
  };

  
//  Serial.print("Parcial: ");
//  Serial.print(saidaParcial);
//  Serial.print(" - Acertos: ");
//  Serial.print(qtdeAcertos);
//  Serial.print(" - Avaliada: ");
//  Serial.print(saidaAvaliada);
//  Serial.print(" - Final: ");
  Serial.println(saidaFinal);
//  Serial.println(saidaParcial);
  somaAmostras = 0;

}

void media() {
  
}

