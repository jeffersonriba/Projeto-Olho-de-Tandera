#include <Ultrasonic.h>
#include <Keyboard.h>

// chamadas dos sensores ultrassonicos
Ultrasonic ultraEsquerdo(13, 12); //13 triger  12echo
Ultrasonic ultraCentral(10, 9); //11 triger  10echo
Ultrasonic ultraDireito(6, 5); // 7 triger 6 echo


//valor inicial
long microSegundosEsquerdo = 0; // valor inicial em segundos do lado esquerdo
long microSegundosCentral = 0; // valor incial em segundos do lado central
long microSegundosDireito = 0; // valor incicial em segundos do lado direito


//distancia inicial
float distanciaCentimetrosEsquerdo = 0; // valor inicial em centimetros lado esquerdo
float distanciaCentimetrosCentral = 0; // valor inicial em centimetros lado central
float distanciaCentimetrosDireito = 0; // valor inicial em centimetros lado direito

//vibracalls
int vibraesquerdo = 11;
int vibracentral = 8;
int vibradireito = 4;

char dadoRecebido; // VariÃ¡vel para a informaÃ§Ã£o recebida
// distancia
float distancia = 10; // distancia em cm para verificaÃ§Ã£o

// vibracalls ativado
char vibrae = 'a';
char vibrac = 'a';
char  vibrad = 'a';
char vibra = 'a';

//sensor ativado
char ultrad = 'a';
char ultrac = 'a';
char ultrae = 'a';
char ultra = 'a';


void setup()
{
  // put your setup code h
  Serial.begin(9600); //Iniciamos a porta serial com Baud Rate de 9600B (velocidade de trasnferÃªncia)
  pinMode(vibraesquerdo, OUTPUT);
  pinMode(vibracentral , OUTPUT);
  pinMode(vibradireito, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  
  digitalWrite(vibraesquerdo, LOW);
  digitalWrite(vibracentral, LOW);
  digitalWrite(vibradireito, LOW);

  ///////// funçao de leitura do android
  if (Serial.available() > 0)
  {
    dadoRecebido = Serial.read(); // Leitura da informaÃ§Ã£xo recebida do android
    // desligar ultrassonico
    if (dadoRecebido == '1')
    {
      ultra = 'd';
      Serial.println("                                ultrassonico desligado");
    }
    // desligar vibracall
    else if (dadoRecebido == '2')
    {

      vibra =  'd';
      Serial.println("                                vibracall desligado ");
    }
    // ligar ultrassonico
    else if (dadoRecebido == '3')
    {

      ultra = 'a';
      Serial.println("                                ultrassonico Ativado");
    }
    // ligar vibracall
    else if (dadoRecebido == '4')
    {
      vibra =  'a';
      Serial.println("                                vibracall Ativado ");
    }

    ///********************************configuraÃ§Ã£o do modos residencial e urbano *****************************************************
    // ligar modo urbano
    else if (dadoRecebido == '5')
    {
      distancia = 100;
      Serial.println("                                Modo Urbano Ativado ");
    }
    // ligar modo residencial
    else if (dadoRecebido == '6')
    {
      distancia = 30;
      Serial.println("                                Modo Residencial Ativado ");
    }

    ///********************************Desativar e ativar lados do ultrassonico e vibracall *****************************************************
    // desativar ultrassonico esquerdo
    else if (dadoRecebido == 'q')
    {
      ultrae = 'd';
      Serial.println("                                Sensor Esquerdo Desativado ");
    }
    // desativar ultrassonico central
    else if (dadoRecebido == 'w')
    {
      ultrac = 'd';
      Serial.println("                                Sensor Central Desativado ");
    }
    // desativar ultrassonico direito
    else if (dadoRecebido == 'e')
    {
      ultrad = 'd';
      Serial.println("                                Sensor Direito Desativado ");
    }
    // desativar vibracall esquerdo
    else if (dadoRecebido == 'r')
    {
      vibrae =  'd';
      Serial.println("                                Vibracall Esquerdo Desativado ");
    }
    // desativar vibracall central
    else if (dadoRecebido == 't')
    {
      vibrac =  'd';
      Serial.println("                                Vibracall Central Desativado");
    }
    // desativar vibracall direito
    else if (dadoRecebido == 'y')
    {
      vibrad =  'a';
      Serial.println("                                Vibracall Direito Desativado ");
    }

    // Ativar ultrassonico esquerdo
    else if (dadoRecebido == 'a')
    {
      ultrae = 'd';
      Serial.println("                                Sensor Esquerdo Ativado ");
    }
    // Ativar ultrassonico central
    else if (dadoRecebido == 's')
    {
      ultrac = 'd';
      Serial.println("                                Sensor Central Ativado ");
    }
    // Ativar ultrassonico direito
    else if (dadoRecebido == 'd')
    {
      ultrad = 'd';
      Serial.println("                                Sensor Direito Ativado ");
    }
    // Ativar vibracall esquerdo
    else if (dadoRecebido == 'f')
    {
      vibrae =  'd';
      Serial.println("                                Vibracall Esquerdo Ativado ");
    }
    // Ativar vibracall central
    else if (dadoRecebido == 'g')
    {
      vibrac =  'd';
      Serial.println("                                Vibracall Central Ativado");
    }
    // Ativar vibracall direito
    else if (dadoRecebido == 'h')
    {
      vibrad =  'a';
      Serial.println("                                Vibracall Direito Ativado ");
    }
  }

  //////////******************************************************funÃ§oes  de detecÃ§Ã£o**************************************************
  // pega os valores
  microSegundosEsquerdo = ultraEsquerdo.timing();
  microSegundosCentral = ultraCentral.timing();
  microSegundosDireito = ultraDireito.timing();

  // define a distancia
  distanciaCentimetrosEsquerdo = ultraEsquerdo.convert(microSegundosEsquerdo, Ultrasonic::CM);
  distanciaCentimetrosCentral = ultraCentral.convert(microSegundosCentral, Ultrasonic::CM);
  distanciaCentimetrosDireito = ultraDireito.convert(microSegundosDireito, Ultrasonic::CM);

  // verifica se o ultrassonico esta liberado
  if (ultra != 'd')
  {

    // verifica se a distanca e menor que o estipulado
    if (distanciaCentimetrosEsquerdo < distancia && distanciaCentimetrosEsquerdo > 0)
    {
      if (vibra != 'd')
      {
        if ( vibrae != 'd')
        {
          digitalWrite(vibraesquerdo, HIGH);
        }
      }
      Serial.println("                  Objeto Detectado a equerda a:" + (String)distanciaCentimetrosEsquerdo + " Cm");
      delay(500);
      digitalWrite(vibraesquerdo, LOW);
    }

    // verifica se a distancia e menor que o estipulado
    if (distanciaCentimetrosCentral < distancia && distanciaCentimetrosCentral > 0)
    {
      if (vibra != 'd')
      {
        if ( vibrac != 'd')
        {
          digitalWrite(vibracentral, HIGH);
        }
        Serial.println("                Objeto Detectado no centro a: " + (String)distanciaCentimetrosCentral + " Cm");
        delay(500);
        digitalWrite(vibracentral, LOW);
      }

    }

    // verifica se a distancia e menor que o estipulado
    if (distanciaCentimetrosDireito < distancia && distanciaCentimetrosDireito > 0)
    {
      if (vibra != 'd')
      {
        if ( vibrad != 'd')
        {
          digitalWrite(vibradireito, HIGH);
        }
        Serial.println("                Objeto Detectado a direita a: " + (String)distanciaCentimetrosDireito + " Cm");
        delay(500);
        digitalWrite(vibradireito, LOW);


      }

    }

  }

}


