// Functions for Battery Monitoring

int batterySensor = 34; // Battery Sensor is located to GPIO 34
float bHigh = 905.0;      // Analog Value read at 5.0 volts
float bLow = 450.0;       // Analog Value read at 3.0 volts
float vHigh = 5.0;      // Test volts at 5.0 volts
float vLow = 3.0;       // Test volts at 3.0 volts
float chargeMax = 4.2;  // Fully Charged Battery
float chargeMin = 3.2;  // Fully Depleted Battery
int lastCharge = 100;   // Keep Track of Last Charge

/* initBattery */
void initBattery(){
  pinMode(batterySensor, INPUT); //declares the battery sensor as an input
}

/* voltsBattery */
float voltsBattery(){ //reads the battery sensor and returns the voltage of the battery
  float curVolts = mapFloat(batterySensor, bLow, bHigh, vLow, vHigh); //reads the battery sensor and maps the values bHigh to bLow, to vHigh to vLow
  return curVolts; //This mapped value is returned as a floating number
}

/* percentBattery */
float percentBattery(){ //reads the battery sensor and returns the % remaining in the battery
  float curVolts = voltsBattery(); //sets curVolts to the returned value given in voltsBattery()
  float curCharge = mapFloat(curVolts, chargeMin, chargeMax, 0.0, 100.0); //calls the voltsBattery function and maps its value chargeMin to chargeMax, to 0.0 to 100.0
  return curCharge; //This mapped value is returned as a floating number
}

/* updateBattery */
void updateBattery(){ //updates the charge of the battery
  float curCharge = percentBattery(); //sets curCharge to the returned value given in percentBattery()
  if(curCharge != lastCharge){ //compares the current battery charge to the last battery charge
    lastCharge = curCharge; //if they are different, it updates the last known charge to the current charge
    bleKeyboard.setBatteryLevel(curCharge); //updates the bleKeyboard library
  }
}

// The normal Arduino float( ) function only works with integers. 
// This special function works with floating numbers for more precision
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
