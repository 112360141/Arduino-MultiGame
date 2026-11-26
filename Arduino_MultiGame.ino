bool a=HIGH;
bool b=HIGH;
bool c=HIGH;
bool d=HIGH;
bool e=HIGH;
int f=0;
int g=0;
int h=0;
int i=0;
int l=0;
bool m=HIGH;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

int ledPin[]={4,5,6,7,8,9,10,11,12};
int shortPin[]={31,32,33,34,35,36,37,38,39};
boolean ledState[]={0,0,0,0,0,0,0,0,0,0};
int ll[9]={};
unsigned long time_now;
unsigned long startTime;
unsigned long ihunTime;
int k,j;
int score=0;
int notes[] = {
  262,
  294,
  330,
  349,
  392,
  440,
  493,
  523,
  587
};
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int n=random(4,7);
int o=random(7,10);
int p=random(10,13);
int q=0;
bool r=HIGH;
bool s=HIGH;
bool t=HIGH;
int u=0;
int v=random(4,10);
int w=random(4,10);
int x=random(4,10);
int y=random(4,10);
int z=random(4,10);
int aa=random(4,10);
bool bb=HIGH;
bool cc=HIGH;
bool dd=HIGH;
bool ee=HIGH;
bool ff=HIGH;
bool gg=HIGH;
int hh=0;
int ii=0;
int jj=0;
int kk=0;





void setup (){
  for(byte i=40;i<45;i++){
  pinMode(i,INPUT);
  }
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  
  for(int i=0;i<9;i++){
    pinMode(ledPin[i], OUTPUT);
    pinMode(shortPin[i], INPUT_PULLUP);
  }
  
  for(int i=0;i<9;i++){
    digitalWrite(ledPin[i],LOW);
  }
  
  time_now=millis();
  }
void loop (){
  a=digitalRead(40);
  b=digitalRead(41);
  c=digitalRead(42);
  d=digitalRead(43);
  e=digitalRead(44);
    if(a==LOW){
    f=1;
    g=0;
    h=0;
    i=0;
    l=0;
    }
    if(b==LOW){
    g=1;
    f=0;
    h=0;
    i=0;
    l=0;

    }
    if(c==LOW){
    h=1;
    f=0;
    g=0;
    i=0;
    l=0;
    }
    if(d==LOW){
    i=1;
    f=0;
    g=0;
    h=0;
    l=0;
    }
    if(e==LOW){
      f=0;
      g=0;
      h=0;
      i=0;
      l=1;
    }
      if(f==1){
        play_1();
      }
      if(g==1){
        play_2();
      }
      if(h==1){
        play_3();
      }
      if(i==1){
        play_4();
      }
      if(l==1){
        play_5();
        }
  }
  void play_1(){
  if(millis()>=time_now+1500){
    
    for(byte i=0;i<9;i++){
      digitalWrite(ledPin[i],LOW);
    }
    
    time_now=millis();
    
  
      for(k=0; k<1; k++){
      do{
        ll[k]=random(9);
        for(j=0; j<k; j++){
          if(ll[k]==ll[j]){
            break;
          }
        }      
      }while(j!=k);
      digitalWrite(ledPin[ll[k]],HIGH);
      ledState[k]=HIGH;
    }
  }

 if(millis()>=time_now+500&&score>=10){
    
    for(k=0;k<9;k++){
      digitalWrite(ledPin[k],LOW);
    }
    
    time_now=millis();
    
  
      for(k=0; k<1; k++){
      do{
        ll[k]=random(9);
        for(j=0; j<k; j++){
          if(ll[k]==ll[j]){
            break;
          }
        }      
      }while(j!=k);
      digitalWrite(ledPin[ll[k]],HIGH);
      ledState[k]=HIGH;
    }
  }
  for(k=0;k<1;k++){
    if(digitalRead(shortPin[ll[k]])==LOW&&ledState[k]==HIGH){
      digitalWrite(ledPin[ll[k]],LOW);
      ledState[k]=LOW;
      score++;
      tone(13, notes[6]);
      ihunTime=millis();
    }
  }
  if(ihunTime-millis()>=800){
        noTone(13);
    }

  
  Serial.println(score);
  lcd.setCursor(2, 0);
  lcd.print("score:");
  lcd.print(score); 
    }
    
  void play_2(){
  buttonState1 = digitalRead(31);
  buttonState2 = digitalRead(32);
  buttonState3 = digitalRead(33);
  buttonState4 = digitalRead(34);
  buttonState5 = digitalRead(35);
  buttonState6 = digitalRead(36);
  buttonState7 = digitalRead(37);
  buttonState8 = digitalRead(38);
  buttonState9 = digitalRead(39);

  if (buttonState9 == LOW) {
    tone(13, notes[0]);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    
  }
  else  if (buttonState8 == LOW) {
    tone(13, notes[1]);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  else  if (buttonState7 == LOW) {
    tone(13, notes[2]);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  else  if (buttonState6 == LOW) {
    tone(13, notes[3]);
    digitalWrite(9, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  else if (buttonState5 == LOW) {
    tone(13, notes[4]);
    digitalWrite(8, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  else  if (buttonState4 == LOW) {
    tone(13, notes[5]);
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  else  if (buttonState3 == LOW) {
    tone(13, notes[6]);
    digitalWrite(6, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
else  if (buttonState2 == LOW) {
    tone(13, notes[7]);
    digitalWrite(5, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
  }
  else  if (buttonState1 == LOW) {
    tone(13, notes[8]);
    digitalWrite(4, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(12, LOW);
  }
  else {
    noTone(13);
  }
    }
    
  void play_3(){
     if(q==0){
    digitalWrite(n,HIGH);
    digitalWrite(o,HIGH);
    digitalWrite(p,HIGH);
    q++;
  }
  if(q==1){
  r=digitalRead(37);
  s=digitalRead(38);
  t=digitalRead(39);
    if(r==HIGH&&s==HIGH&&t==HIGH){
    u=0;
    }
    if(r==LOW&&p==10||s==LOW&&p==11||t==LOW&&p==12){
      if(u==0){
      do {
      digitalWrite(n,LOW);
    digitalWrite(o,LOW);
    digitalWrite(p,LOW);
    r=digitalRead(37);
    s=digitalRead(38);
    t=digitalRead(39);
    p=o+3;
    o=n+3;
    n=random(4,7);
  
    digitalWrite(n,HIGH);
    digitalWrite(o,HIGH);
    digitalWrite(p,HIGH);
        u++;
        score++;
        tone(13, notes[0]);
              ihunTime=millis();

    }while(u==0);
    }
    }
  }
  if(ihunTime-millis()>=800){
        noTone(13);
    }

  Serial.println(score);
  lcd.setCursor(2, 0); 
  lcd.print("score:");
  lcd.print(score); 
    }
    
  void play_4(){
     if(hh==0){
      if(kk==0){
            startTime=millis();
            kk++;
        }

   if(millis()-startTime<1000){
  digitalWrite(v,HIGH);
   }
if(millis()-startTime>=1000&&millis()-startTime<2000){
  digitalWrite(v,LOW);
  digitalWrite(w,HIGH);
}
  if(millis()-startTime>=2000&&millis()-startTime<3000){
  digitalWrite(w,LOW);
  digitalWrite(x,HIGH);
  }
 if(millis()-startTime>=3000&&millis()-startTime<4000){
  digitalWrite(x,LOW);
  digitalWrite(y,HIGH);
 }
if(millis()-startTime>=4000&&millis()-startTime<5000){
digitalWrite(y,LOW);
digitalWrite(z,HIGH);
}
if(millis()-startTime>=5000&&millis()-startTime<6000){  
digitalWrite(z,LOW);
  digitalWrite(aa,HIGH);
}if(millis()-startTime>=6000){
  digitalWrite(aa,LOW);
  jj=1;
  hh=1;
  }
  }
if(jj==1){
  bb=digitalRead(v+27);
  cc=digitalRead(w+27);
  dd=digitalRead(x+27);
  ee=digitalRead(y+27);
  ff=digitalRead(z+27);
  gg=digitalRead(aa+27);
  


  if(bb==LOW&&ii==0){
    ii=1;
    digitalWrite(v,HIGH);
    
  }
  
  if(cc==LOW&&ii==1){
    ii=2;
    digitalWrite(v,LOW);
    digitalWrite(w,HIGH);
    
  }
   if(dd==LOW&&ii==2){
    ii=3;
    digitalWrite(w,LOW);
    digitalWrite(x,HIGH);
    
  }
   if(ee==LOW&&ii==3){
    ii=4;
    digitalWrite(x,LOW);
    digitalWrite(y,HIGH);
    
  }
   if(ff==LOW&&ii==4){
    ii=5;
    digitalWrite(y,LOW);
    digitalWrite(z,HIGH);
    
  }
   if(gg==LOW&&ii==5){
    digitalWrite(z,LOW);
    digitalWrite(aa,HIGH);
   
    delay(1000);
    digitalWrite(aa,LOW);
    ii=0;
    kk=0;
    jj=0;
    hh=0;
     v=random(4,10);
     w=random(4,10);
     x=random(4,10);
     y=random(4,10);
     z=random(4,10);
     aa=random(4,10);
  }
}
    }
  void play_5(){
    for(int i=0;i<9;i++){
    digitalWrite(ledPin[i],LOW);
    }
    f=0;
    g=0;
    h=0;
    i=0;
    l=0;
    q=0;
    u=0;
    hh=0;
    ii=0;
    jj=0;
    kk=0;
    score=0;
    lcd.clear();
    Serial.println(score);
  lcd.setCursor(2, 0);
  lcd.print("score:");
  lcd.print(score);
  }
