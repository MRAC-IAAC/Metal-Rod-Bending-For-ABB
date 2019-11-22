# 4-Motors-Bending-Robot-Tool

**Description**
Robot tool for bending metal rods composed by 4 stepper motors moving 4 metal rollers (actuators) independently in one axis movement.

**Requirements**
 Format: ![Alt Text](url)
 ![Tool Dimensions Top View](D:\Roberto\01 Projects\02 IAAC\02 Curso\Hardware I\Week 6\4-motors-bending-robot-tool-master\4-motors-bending-robot-tool-master\doc folder\Tool dimensions 1.jpg)
 Format: ![Alt Text](url)
 
**Electronics**
* [Arduino Uno](https://www.amazon.es/Longruner-Tarjeta-Expansi%C3%B3n-Controlador-LK75/dp/B072N4FMRN/ref=sr_1_8?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=grbl&qid=1573215919&sr=8-8&th=1)
* [CNC shield GBRL](https://www.amazon.es/Longruner-Tarjeta-Expansi%C3%B3n-Controlador-LK75/dp/B072N4FMRN/ref=sr_1_8?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=grbl&qid=1573215919&sr=8-8&th=1)
* [4 Nema 17 Stepper Motors 1.8° 200 steps per revolution](https://www.amazon.es/Longruner-Tarjeta-Expansi%C3%B3n-Controlador-LK75/dp/B072N4FMRN/ref=sr_1_8?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=grbl&qid=1573215919&sr=8-8&th=1)
* [4 Ramps 1.4 Endstop switch](https://www.amazon.es/Longruner-Tarjeta-Expansi%C3%B3n-Controlador-LK75/dp/B072N4FMRN/ref=sr_1_8?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=grbl&qid=1573215919&sr=8-8&th=1)
* [4 DRV8825](https://www.amazon.es/Longruner-Tarjeta-Expansi%C3%B3n-Controlador-LK75/dp/B072N4FMRN/ref=sr_1_8?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=grbl&qid=1573215919&sr=8-8&th=1)


**Software**
Arduino Software (IDE)

**Getting Started:**
`<// defines pins numbers
const int stepX = 2;
const int dirX  = 5;
const int limitX = 9;
int btnStateX;

const int stepY = 3;
const int dirY  = 6;
const int limitY = 10;
int btnStateY;

const int stepZ = 4;
const int dirZ  = 7;
const int limitZ = 11;
int btnStateZ;

const int enPin = 8;

int delayTime = 1000;

bool isHome = false;

//12 step
//13 dir

void setup() {

  // Sets the two pins as Outputs
  pinMode(stepX,OUTPUT);
  pinMode(dirX,OUTPUT);
  pinMode(limitX, INPUT_PULLUP);

  pinMode(stepY,OUTPUT);
  pinMode(dirY,OUTPUT);
  pinMode(limitY, INPUT_PULLUP);

  pinMode(stepZ,OUTPUT);
  pinMode(dirZ,OUTPUT);
  pinMode(limitZ, INPUT_PULLUP);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);

  digitalWrite(dirX,HIGH);
  digitalWrite(dirY,HIGH);
  digitalWrite(dirZ,HIGH);

  Serial.begin(9600);
}
void loop() {

  btnStateX = digitalRead(limitX);
  btnStateY = digitalRead(limitY);
  btnStateZ = digitalRead(limitZ);

  if(!isHome){
    if(btnStateX==1){
      digitalWrite(stepX,HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(stepX,LOW);
      delayMicroseconds(delayTime);
    }

    if(btnStateY==1){
      digitalWrite(stepY,HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(stepY,LOW);
      delayMicroseconds(delayTime);
    }

    if(btnStateZ==1){
      digitalWrite(stepZ,HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(stepZ,LOW);
      delayMicroseconds(delayTime);
    }

    if(btnStateX==0 && btnStateY==0 && btnStateZ==0){
      isHome = true;
    }
  }else{
    Serial.println("ok to RUN");
  }>`

**References:**

**Credits**
Based on IAAC publishing guidelines:
(4 Motors Bending Robot Tool) is a project of IaaC, Institute for Advanced Architecture of Catalonia. developed at Master in Robotics and Advanced Construction in 2019-2020 by:
Students: (Alexandros Michail Varvantakis, Cedric Droogmans, Roberto Vargas Calvo, Beril Serbes)
Faculty: (Angel Muñoz)
