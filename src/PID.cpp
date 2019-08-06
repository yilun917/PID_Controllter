#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // assign the coefficients to the instance variable
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  int_cte = 0.0;  // accumulated cte

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // for first run, assign current cte to prev_cte
  if(!prev_cte) prev_cte = cte;

  // cte difference
  double diff_cte = cte - prev_cte;
  prev_cte = cte; // update the prev_cte value
  // integration of cte
  int_cte += cte;
  
  // valvulate the 3 errprs
  p_error = Kp * cte;
  i_error = Ki * int_cte;
  d_error = Kd * diff_cte;
  

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // sum the 3 errors together
  //double totalError =  p_error + i_error + d_error;
  return p_error + i_error + d_error;  // TODO: Add your total error calc here!
}