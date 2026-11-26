#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
constexpr byte LED_PINS[9] = {4,5,6,7,8,9,10,11,12};
constexpr byte BUTTON_PINS[9] = {31,32,33,34,35,36,37,38,39};
constexpr byte MODE_PINS[5] = {40,41,42,43,44};
constexpr byte BUZZER_PIN = 13;
constexpr int NOTES[9] = {262,294,330,349,392,440,493,523,587};

enum Mode : byte { NONE=0, WHACK=1, PIANO=2, ZOMBIE=3, MEMORY=4, RESET=5 };
Mode mode = NONE;
unsigned long lastTick=0;
unsigned long stageStart=0;
unsigned long lastBeep=0;
bool beeping=false;
int score=0;
int litIndex=-1;
byte zombieIndex[3]={0,4,8};
byte memorySteps[6]={0};
byte memoryProgress=0;
bool showingMemory=false;
byte currentShowStep=0;

void allLedsOff() {
  for (byte i=0;i<9;i++) digitalWrite(LED_PINS[i],LOW);
}
void beep(unsigned int hz,unsigned long durationMs=180) {
  tone(BUZZER_PIN,hz);
  beeping=true;
  lastBeep=millis()+durationMs;
}
void updateBeep() {
  if(beeping && (long)(millis()-lastBeep)>=0) {
    noTone(BUZZER_PIN); beeping=false;
  }
}
void showScore() {
  lcd.setCursor(0,0); lcd.print("Score:          ");
  lcd.setCursor(7,0); lcd.print(score);
}
bool pressed(byte index) { return digitalRead(BUTTON_PINS[index]) == LOW; }
Mode readMode() {

  for(byte i=0;i<5;i++) if(digitalRead(MODE_PINS[i])==LOW) return (Mode)(i+1);
  return mode;
}
void enterMode(Mode newMode) {
  mode=newMode; allLedsOff(); noTone(BUZZER_PIN); beeping=false;
  lcd.clear(); lastTick=millis(); stageStart=millis(); litIndex=-1;
  if(newMode==RESET){score=0;showScore();return;}
  if(newMode==MEMORY){
    for(byte i=0;i<6;i++) memorySteps[i]=random(9);
    memoryProgress=0; currentShowStep=0; showingMemory=true;
  }
  if(newMode==ZOMBIE){
    for(byte i=0;i<3;i++) zombieIndex[i]=i*3+random(3);
  }
  if(newMode!=PIANO) showScore();
}
void setup() {
  Serial.begin(9600);
  lcd.init(); lcd.backlight();
  for(byte i=0;i<9;i++){
    pinMode(LED_PINS[i],OUTPUT);
    pinMode(BUTTON_PINS[i],INPUT_PULLUP);
  }
  for(byte i=0;i<5;i++) pinMode(MODE_PINS[i],INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);
  allLedsOff(); randomSeed(analogRead(A0));
  lcd.setCursor(0,0); lcd.print("Arduino Games");
  lcd.setCursor(0,1); lcd.print("Select a mode");
}
void playWhack() {
  unsigned long interval=(score>=10)?500:1500;
  if(litIndex<0 || millis()-lastTick>=interval){
    allLedsOff(); litIndex=random(9);
    digitalWrite(LED_PINS[litIndex],HIGH); lastTick=millis();
  }
  if(litIndex>=0 && pressed(litIndex)){
    digitalWrite(LED_PINS[litIndex],LOW);
    score++; showScore();beep(NOTES[6]);litIndex=-1;
    delay(70); 
  }
}
void playPiano() {
  int active=-1;

  for(int i=8;i>=0;i--) if(pressed(i)){active=i;break;}
  allLedsOff();
  if(active<0){noTone(BUZZER_PIN);beeping=false;return;}
  digitalWrite(LED_PINS[active],HIGH);
  tone(BUZZER_PIN,NOTES[8-active]);
}
void playZombie() {
  for(byte lane=0;lane<3;lane++){
    byte index=zombieIndex[lane];
    digitalWrite(LED_PINS[index],HIGH);
    if(pressed(index)){
      digitalWrite(LED_PINS[index],LOW);
      zombieIndex[lane]=lane*3+random(3);
      score++;showScore();beep(NOTES[0]);delay(70);
    }
  }
}
void playMemory() {
  if(showingMemory){
    unsigned long elapsed=millis()-stageStart;
    byte step=elapsed/1000;
    allLedsOff();
    if(step<6){
      if((elapsed%1000)<650) digitalWrite(LED_PINS[memorySteps[step]],HIGH);
    }else{
      showingMemory=false;allLedsOff();lcd.setCursor(0,1);lcd.print("Your turn       ");
    }
    return;
  }
  if(memoryProgress<6 && pressed(memorySteps[memoryProgress])){
    digitalWrite(LED_PINS[memorySteps[memoryProgress]],HIGH);
    beep(NOTES[3]);delay(100);
    digitalWrite(LED_PINS[memorySteps[memoryProgress]],LOW);
    memoryProgress++;
    if(memoryProgress==6){
      score++;showScore();lcd.setCursor(0,1);lcd.print("Well done!      ");
      for(byte i=0;i<6;i++) memorySteps[i]=random(9);
      memoryProgress=0;showingMemory=true;stageStart=millis();
    }
  }
}
void loop() {
  Mode selected=readMode();
  if(selected!=mode) enterMode(selected);
  updateBeep();
  switch(mode){
    case WHACK: playWhack();break;
    case PIANO: playPiano();break;
    case ZOMBIE: playZombie();break;
    case MEMORY:playMemory();break;
    case RESET: break;
    default: break;
  }
}
