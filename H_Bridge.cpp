#include <Arduino.h>
#include <H_Bridge.h>

//set the paramiters to where pins are located.
//set all 3 pins to output
H_Bridge::H_Bridge(int IN1, int IN2, int EN){
    this->IN1 = IN1;
    this->IN2 = IN2;
    this->EN = EN;
    pinMode(this->IN1, OUTPUT);
    pinMode(this->IN2, OUTPUT);
    pinMode(this->EN, OUTPUT);
}

H_Bridge::H_Bridge(int IN1, int IN2){
    this->IN1 = IN1;
    this->IN2 = IN2;
    pinMode(this->IN1, OUTPUT);
    pinMode(this->IN2, OUTPUT);
    
}

//set both in pins low
void H_Bridge::stop(){
    this->start(STOP);
}

//should spin the motor if derection is -1 (H_Bridge.BACK) or 1 (H_Bridge.FORWARd
//when a derection is selected the opisite derection should be turned off first
//if 0(H_Bridge.STOP)is selected for derection call function H_Bridge.stop()
// setting the in1 high should spin motor one way, in2 high schould spin the motor the other way
//only one in pin can be high at a time the other must be pulled low first
void H_Bridge::start(int derection){
    if(derection == STOP){
        digitalWrite(this->IN1, LOW);
        digitalWrite(this->IN2, LOW);
    }else if(derection == FORWARD){
        digitalWrite(this->IN1, HIGH);
        digitalWrite(this->IN2, LOW);
    }else if(derection == BACK){
        digitalWrite(this->IN1, LOW);
        digitalWrite(this->IN2, HIGH);
    }
}

void H_Bridge::start(int derection, int speed){
    analogWrite(this->EN, speed);
    this->start(derection);
}
