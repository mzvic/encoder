//Slave code (Arduino NANO)

//Serial Communication Between Two Arduinos using RS-485

//Circuit Digest

int enablePin = 8; 

int ledpin = 10;

void setup() 

{

  delay(3000);

  Serial.begin(9600);                   // initialize serial at baudrate 9600:

  pinMode(ledpin,OUTPUT);

  pinMode(enablePin, OUTPUT);

  delay(10);

  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)

  

}

void loop() 

{                                                  

  while (Serial.available())                   //While have data at Serial port this loop executes

     {

        int pwmval = Serial.parseInt();            //Receive INTEGER value from Master throught RS-485

        int convert = map(pwmval,0,1023,0,255);    //Map those value from (0-1023) to (0-255)

        analogWrite(ledpin,convert);               //PWM write to LED 

        delay(100);

    }

 } 