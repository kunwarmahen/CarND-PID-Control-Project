#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double throttle;

  double best_err = 100000;

  double Ks[3] = { 0, 0, 0 };
  double ds[3] = { 1, 1, 1 };

  int twiddle_index = 0;
  bool secondUpdate = false;
  bool startLoop = true;
  //int steps = 0;
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void SetThrottle(double throttle);

  void Twiddle(double cte);

  double sumK(double ds[]);
};

#endif /* PID_H */
