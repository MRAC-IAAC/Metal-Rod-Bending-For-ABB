// defines pins numbers
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
  }

  /*Serial.print(btnStateX);
  Serial.print(" , ");
  Serial.print(btnStateY);
  Serial.print(" , ");
  Serial.println(btnStateZ);*/
  
  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  /*
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepX,HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(stepX,LOW);
    delayMicroseconds(delayTime);
  }
  delay(1000); // One second delay

   for(int x = 0; x < 200; x++) {
    digitalWrite(stepY,HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(stepY,LOW);
    delayMicroseconds(delayTime);
  }

   delay(1000); // One second delay

  for(int x = 0; x < 200; x++) {
    digitalWrite(stepZ,HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(stepZ,LOW);
    delayMicroseconds(delayTime);
  }

   delay(1000); // One second delay
*/
}
