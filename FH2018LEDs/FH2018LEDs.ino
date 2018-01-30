//#define ch3blue   0
//#define ch3green  0
//#define ch3red    0

#define ch5blue   4
#define ch5green  5
#define ch5red    3

#define ch4blue   10
#define ch4green  11
#define ch4red    9

//#define ch6blue   0
//#define ch6green  0
//#define ch6red    0

//#define ch7blue   0
//#define ch7green  0
//#define ch7red    0
//
//#define ch8blue   0
//#define ch8green  0
//#define ch8red    0

unsigned long previousMillis[18]; //[x] = number of leds

//int ch3bluefreq   = 0;
//int ch3greenfreq  = 0;
//int ch3bredfreq   = 0;

int ch5bluefreq   = 5000;
int ch5greenfreq  = 5000;
int ch5bredfreq   = 5000;

int ch5bluefreqSF   = 50;
int ch5greenfreqSF  = 50;
int ch5bredfreqSF   = 50;

int ch5bluefreqF   = 100;
int ch5greenfreqF  = 100;
int ch5bredfreqF   = 100;

int ch5bluefreqM   = 500;
int ch5greenfreqM  = 500;
int ch5bredfreqM   = 500;

int ch5bluefreqS   = 1000;
int ch5greenfreqS  = 1000;
int ch5bredfreqMS  = 1000;

int ch5bluefreqSS   = 5000;
int ch5greenfreqSS  = 5000;
int ch5bredfreqMSS  = 5000;


int ch4bluefreq   = 0;
int ch4greenfreq  = 0;
int ch4bredfreq   = 0;

//int ch6bluefreq   = 0;
//int ch6greenfreq  = 0;
//int ch6bredfreq   = 0;

//int ch7bluefreq   = 0;
//int ch7greenfreq  = 0;
//int ch7bredfreq   = 0;
//
//int ch8bluefreq   = 0;
//int ch8greenfreq  = 0;
//int ch8bredfreq   = 0;

void setup() { 
  Serial.begin(9600);

//  pinMode(ch3blue, OUTPUT);   
//  pinMode(ch3green, OUTPUT); 
//  pinMode(ch3red, OUTPUT); 
  
  pinMode(ch5blue, OUTPUT);   
  pinMode(ch5green, OUTPUT); 
  pinMode(ch5red, OUTPUT); 

  pinMode(ch4blue, OUTPUT);   
  pinMode(ch4green, OUTPUT); 
  pinMode(ch4red, OUTPUT); 

//  pinMode(ch6blue, OUTPUT);   
//  pinMode(ch6green, OUTPUT); 
//  pinMode(ch6red, OUTPUT); 

//  pinMode(ch7blue, OUTPUT);   
//  pinMode(ch7green, OUTPUT); 
//  pinMode(ch7red, OUTPUT); 
//
//  pinMode(ch8blue, OUTPUT);   
//  pinMode(ch8green, OUTPUT); 
//  pinMode(ch8red, OUTPUT); 

}
void loop() {
 if (Serial.available() > 0) {
  char input = Serial.read();
  Serial.println(input);
  if(input == 'a'){
    ch5bluefreq = ch5bluefreqS;
    ch5greenfreq = ch5bluefreqS;
    ch5bredfreq = ch5bluefreqS;

    ch4bluefreq = ch5bluefreqS;
    ch4greenfreq = ch5bluefreqS;
    ch4bredfreq = ch5bluefreqS;
    
  } else if(input == 's') {
    ch5bluefreq = ch5bluefreqM;
    ch5greenfreq = ch5bluefreqM;
    ch5bredfreq = ch5bluefreqM;

    ch4bluefreq = ch5bluefreqM;
    ch4greenfreq = ch5bluefreqM;
    ch4bredfreq = ch5bluefreqM;
  } else if(input == 'd') {
    ch5bluefreq = ch5bluefreqF;
    ch5greenfreq = ch5bluefreqF;
    ch5bredfreq = ch5bluefreqF;

    ch4bluefreq = ch5bluefreqF;
    ch4greenfreq = ch5bluefreqF;
    ch4bredfreq = ch5bluefreqF;
  } else if(input == 'f') {
    
    ch5bluefreq = ch5bluefreqSF;
    ch5greenfreq = ch5bluefreqSF;
    ch5bredfreq = ch5bluefreqSF;
    
    ch4bluefreq = ch5bluefreqSF;
    ch4greenfreq = ch5bluefreqSF;
    ch4bredfreq = ch5bluefreqSF;
  }  else if(input == 'q') {
    
    ch5bluefreq = ch5bluefreqSS;
    ch5greenfreq = ch5bluefreqSS;
    ch5bredfreq = ch5bluefreqSS;
    
    ch4bluefreq = ch5bluefreqSS;
    ch4greenfreq = ch5bluefreqSS;
    ch4bredfreq = ch5bluefreqSS;
  }
 }
 BlinkLed(ch5blue, ch5bluefreq, 0);   //BlinkLed( which led, interval, one of the stored prevMillis
 BlinkLed(ch5green, ch5greenfreq, 1);  //last parameters must be different for each led
 BlinkLed(ch5red, ch5bredfreq, 2);

 BlinkLed(ch4blue, ch4bluefreq, 3);   //BlinkLed( which led, interval, one of the stored prevMillis
 BlinkLed(ch4green, ch4greenfreq, 4);  //last parameters must be different for each led
 BlinkLed(ch4red, ch4bredfreq, 5);
}

void BlinkLed (int led, int interval, int array){   
  
  //(long) can be omitted if you dont plan to blink led for very long time I think
   if (((long)millis() - previousMillis[array]) >= interval){ 
   
    previousMillis[array]= millis(); //stores the millis value in the selected array
   
    digitalWrite(led, !digitalRead(led)); //changes led state
  }
 }
