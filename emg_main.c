#include <stdio.h>
#include <Arduino.h>
#include "emg_proc.h"
#include "emg_proc.c"


void setup() {
    Serial.begin(115200);  
}

void loop() {
    float sensorValue = analogRead(PIN_NUM);
    
    float voltage = sensorValue * (3.3 / 4095.0);  
    
    ProcessedEMG result = processEMGSample(voltage);
    
    Serial.print(voltage);
    Serial.print(",");
    Serial.print(result.rectified);
    Serial.print(",");
    Serial.println(result.envelope);
    
    delay(1);  
}