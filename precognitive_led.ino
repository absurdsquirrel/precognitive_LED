volatile bool precog = false;
volatile bool toggle = false;
unsigned int delta = 5000;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B);
  TCCR1A |= (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0);
  TCCR1B |= (1 << CS12);
  OCR1A = delta;
  OCR1B = 31250 + delta;
  TCNT1 = 0;
  attachInterrupt(0, FLASH, FALLING);
  attachInterrupt(1, PRECOG, FALLING);
  interrupts();
}

ISR(TIMER1_COMPA_vect){
  if(toggle){
    digitalWrite(5, HIGH);
    toggle = false;
  }
}

ISR(TIMER1_COMPB_vect){
  digitalWrite(5, LOW);
}

void PRECOG(){
  precog = true;
}

void FLASH(){
  if(!digitalRead(2)){
    if(precog){
      TCNT1 = delta - 1;
      precog = false;
      digitalWrite(13, LOW);
    } else{
      TCNT1 = 0;
    }
    toggle = true;
  }
}

void loop() {
  delay(100);
  if(precog){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  
}
