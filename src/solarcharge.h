#ifndef SOLARCHARGE_H
#define SOLARCHARGE_H

static float p_chargeTarAmax = 6; //max allowed charge current
static float p_chargeTarVred = 0.2; //the target voltage will reduce by this much for each amp over TarAmax
static float p_chargeTarV = 13.8; //target charging voltage 
static float p_voltageFastReset = 15; //reset the I part to 0 over this voltage
static float p_windupLimit = 255;

static float p_kp = 1;
static float p_ki = 1;
static float p_kd = 1;

class Solar {
public:

// Constructor
Solar(); 

//run each cycle 
float update(float voltage, float current, int dT);

//reset the controller
void reset();

private:
float err(float tar, float cur);
float tar(float voltage, float current);
float PID(float error, float dt);

private:
float integral;
float previousError;
};

#endif