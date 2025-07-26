int ledPinR1 = 9;  // You can connect the LED to any PWM pin (3, 5, 6, 9, 10, 11)
int ledPinR2 = 10;
int ledPinL1 = 11;  // You can connect the LED to any PWM pin (3, 5, 6, 9, 10, 11)
int ledPinL2 = 6;
void setup() {
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinL1, OUTPUT);
  pinMode(ledPinL2, OUTPUT);

        analogWrite(ledPinR1, 255);
        analogWrite(ledPinR2, 255);
        analogWrite(ledPinL1, 255);
        analogWrite(ledPinL2, 255);
    Serial.begin(9600);
}

void loop() {
    // Check if data is available to read
    if (Serial.available() > 0) {
        char command = Serial.read(); // Read the incoming byte
        
        // Control the LED based on the received command
        if (command == 'L') {
        analogWrite(ledPinL1, 70); //set low beam value here
        analogWrite(ledPinL2, 70);    
        analogWrite(ledPinR1, 255); //set low beam value here
        analogWrite(ledPinR2, 255 );    
        } else if (command == 'R') {
        analogWrite(ledPinR1, 70); //set low beam value here
        analogWrite(ledPinR2, 70);
        analogWrite(ledPinL1, 255); //set low beam value here
        analogWrite(ledPinL2, 255 ); 
          
        }
        else if (command == 'N') {
        analogWrite(ledPinR1, 255);
        analogWrite(ledPinR2, 255);
        analogWrite(ledPinL1, 255);
        analogWrite(ledPinL2, 255);
          
        }

    }
}


int ledPinR1 = 9;  // You can connect the LED to any PWM pin (3, 5, 6, 9, 10, 11)
int ledPinR2 = 10;
int ledPinL1 = 11;  // You can connect the LED to any PWM pin (3, 5, 6, 9, 10, 11)
int ledPinL2 = 6;
void setup() {
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinL1, OUTPUT);
  pinMode(ledPinL2, OUTPUT);

        analogWrite(ledPinR1, 255);
        analogWrite(ledPinR2, 255);
        analogWrite(ledPinL1, 255);
        analogWrite(ledPinL2, 255);
    Serial.begin(9600);
}

void loop() {
    // Check if data is available to read
    if (Serial.available() > 0) {
        char command = Serial.read(); // Read the incoming byte
        
        // Control the LED based on the received command
        if (command == 'L') {
        analogWrite(ledPinL1, 70); //set low beam value here
        analogWrite(ledPinL2, 70);    
        analogWrite(ledPinR1, 255); //set low beam value here
        analogWrite(ledPinR2, 255 );    
        } else if (command == 'R') {
        analogWrite(ledPinR1, 70); //set low beam value here
        analogWrite(ledPinR2, 70);
        analogWrite(ledPinL1, 255); //set low beam value here
        analogWrite(ledPinL2, 255 ); 
          
        }
        else if (command == 'N') {
        analogWrite(ledPinR1, 255);
        analogWrite(ledPinR2, 255);
        analogWrite(ledPinL1, 255);
        analogWrite(ledPinL2, 255);
          
        }

    }
}
