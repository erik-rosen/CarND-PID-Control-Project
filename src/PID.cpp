#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;
   i_error = 0;
   number_of_iterations = 0;
   squared_errors = 0;
}

void PID::UpdateError(double cte) {
   if(number_of_iterations == 0){
     d_error = 0;
   } else {
     d_error = cte - p_error;
   }
   p_error = cte;
   i_error = i_error + cte;
   number_of_iterations = number_of_iterations + 1;
   squared_errors = squared_errors + cte * cte;
}

double PID::GetOutput(){
  return - Kp * p_error - Kd * d_error - Ki * i_error;
}

double PID::TotalError() {
  return squared_errors/number_of_iterations;
}