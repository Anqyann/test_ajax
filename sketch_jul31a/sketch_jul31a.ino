// #include <LCD5110_Basic.h>

// // Піни: SCK, MOSI, DC, RST, CS
// LCD5110 myGLCD(8, 9, 10, 12, 11); 

// extern uint8_t SmallFont[];

// void setup() {
//   myGLCD.InitLCD();            
//   myGLCD.setFont(SmallFont);    

//   myGLCD.clrScr();              
//   myGLCD.print("Hello!", CENTER, 2);

// }

// void loop() {
//  
// }


const int max_size = 50;
int correct[max_size];
//int user_s[max_size]; 
int level = 1; 
int speed = 1000;
int u_s = 0;

void setup() {
  pinMode(2, OUTPUT);//leds
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(14, INPUT);//buttons
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  //   for (int i = 2; i <= 5; i++) {
  //   digitalWrite(i, HIGH);
  //   delay(300);
  //   digitalWrite(i, LOW);
  // }
if (level == 1){
  start();
  show();
  user_seq();
} else if(level < max_size){
  show();
  user_seq();
}else if(level == max_size){
  digitalWrite(4, HIGH);
  delay(1400);
  digitalWrite(4, LOW);
}
}
void start(){
  randomSeed(millis());  
  for (int i = 0; i < max_size; i++)
  { 
  correct[i]  = random(2,6);
  }
  // for (int i = 0; i < level; i++)
  // { 
  // correct[i]  = random(2,6);
}

void show(){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  for(int i = 0; i < level; i++){
    digitalWrite(correct[i], HIGH);
    delay(speed);
    digitalWrite(correct[i], LOW);
    delay(100);
  }
}
void incorrect(){
  // for(int i = 0; i < level; i++){
  //   user_s[i] = 0;
  // }
  for(int i = 2; i < 6; i++){
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for(int i = 2; i < 6; i++){
    digitalWrite(i, LOW);
  }
  speed = 1000;
  u_s = 0;
  level = 1;
  return;
}
void user_seq(){
  int user_s;
  int button_not_pressed = 0;
  for(int i = 0; i < level; i++){
    button_not_pressed = 0;
    while(!button_not_pressed){
      if(digitalRead(14) == LOW){
        digitalWrite(2, HIGH);
        user_s = 2;
        delay(200);
        digitalWrite(2, LOW); 
        button_not_pressed = 1;
      }
      if(digitalRead(15) == LOW){
        digitalWrite(3, HIGH);
        user_s = 3;
        delay(200);
        digitalWrite(3, LOW);
        button_not_pressed = 1;
      } 
      if(digitalRead(16) == LOW){
        digitalWrite(4, HIGH);
        user_s = 4;
        delay(200);
        digitalWrite(4, LOW);
        button_not_pressed = 1;
      } 
      if(digitalRead(17) == LOW){
        digitalWrite(5, HIGH);
        user_s = 5;
        delay(200);
        digitalWrite(5, LOW);
        button_not_pressed = 1;
      }  
       
    }
      if(correct[u_s] == user_s){
          button_not_pressed = 1;
          u_s++;
          if(speed > 50) speed -= 50;
          level++;
        }else {
          incorrect();
         return;
       }
  }
}

