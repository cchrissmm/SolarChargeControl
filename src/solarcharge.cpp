#include "solarcharge.h"

//constructor 
Solar::Solar() {
}

//executes the control loop and returns the control value
float Solar::update(float voltage, float current, int dT) {
    float target = Solar::tar(voltage, current); // get the new target
    float error = Solar::err(target, voltage);   // get the new error
    float cv = Solar::PID(error, dT); //control value
    return cv;
}


//calculate the target voltage
float Solar::tar(float voltage, float current)
{
    float target;
    if (current < p_chargeTarAmax)  //just control to a voltage
    {
        target = p_chargeTarV;
    }
    else
    {
        float delta = current - p_chargeTarAmax; // lower the control voltage if the current is too high
        target = p_chargeTarV - delta;
    }
    if (voltage > p_voltageFastReset) {
        integral = 0;
    }

    return target;
}

//calculate the control deviation
float Solar::err(float tar, float cur)
{
    float error = tar - cur;
    return error;
}

//run the controller
float Solar::PID(float error, float dt)
{
    integral += error * dt;

    // Check for windup
    if (integral > p_windupLimit)
    {
        integral = p_windupLimit;
    }
    else if (integral < -p_windupLimit)
    {
        integral = -p_windupLimit;
    }

    float derivative = (error - previousError) / dt;
    float output = p_kp * error + p_ki * integral + p_kd * derivative;
    previousError = error;
    
    return output;
}


// Reset the integral and derivative terms
void Solar::reset()
{
    integral = 0;
    previousError = 0;
}
