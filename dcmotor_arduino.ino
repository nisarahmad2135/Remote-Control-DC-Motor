#define IN1 9

#define IN2 10

#define IN3 11

#define IN4 12

int speed1=0;

int speed2=0;

int direction1=0;

int direction2=0;

void setup()

{

// Set all the motor control pins to outputs

  pinMode(IN1, OUTPUT);

  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);

//configure pin 6, 7 as an input and enable the internal pull-up resistor

  pinMode(6, INPUT_PULLUP);

  pinMode(7, INPUT_PULLUP);

}

void loop()

{

// Read the values from the potentiometers (0 – 1023)

  speed1=analogRead(A0);

  speed2=analogRead(A1);

// Convert to range of 0-255 (duty cycle)

  speed1=speed1/4;

  speed2=speed2/4;

//********Controlling the dicrection and speed of DC Motor1 *********//

  if( digitalRead(6)==0){ //Read the value of the direction switch

    if( direction1 != digitalRead(6) ){

    // Now turn off motors 500ms before reversing

      digitalWrite(IN1, LOW);

      digitalWrite(IN2, LOW);

      delay(500);

      direction1=0;

    }

    // Control speed and reverse direction

    digitalWrite(IN2, LOW);

    analogWrite(IN1,speed1);

  }

  if( digitalRead(6)==1){

    if( direction1 != digitalRead(6) ){

     // Now turn off motors 500ms before reversing

       digitalWrite(IN1, LOW);

       digitalWrite(IN2, LOW);

       delay(500);

       direction1=1;

    }

   // Control speed and forward direction

    digitalWrite(IN2, HIGH);

    analogWrite(IN1,speed1);

  }

//********Controlling the dicrection and speed of DC Motor2 *********//

  if( digitalRead(7)==0){ //Read the value of the direction switch

    if( direction2 != digitalRead(7) ){

    // Now turn off motors 500ms before reversing

      digitalWrite(IN3, LOW);

      digitalWrite(IN4, LOW);

      delay(500);

      direction2=0;

    }

    // Control speed and reverse direction

    digitalWrite(IN4, LOW);

    analogWrite(IN3,speed2);

    }

  if( digitalRead(7)==1){ //chạy nghịch

    if( direction2 != digitalRead(7) ){

    // Now turn off motors 500ms before reversing

       digitalWrite(IN3, LOW);

       digitalWrite(IN4, LOW);

       delay(500);     

       direction2=1;

    }

    // Control speed and forward direction

    digitalWrite(IN4, HIGH);

    analogWrite(IN3,speed2);

  }

}