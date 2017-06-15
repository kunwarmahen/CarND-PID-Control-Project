#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	this->p_error = 0;
	this->d_error = 0;
	this->i_error = 0;

	//this->Ks[0] = Kp;
	//this->Ks[1] = Ki;
	//this->Ks[2] = Kd;

}

void PID::SetThrottle(double throttle) {
	this->throttle = throttle;
}

void PID::UpdateError(double cte) {

	this->d_error = cte - this->p_error;
	this->i_error += cte;
	this->p_error = cte;

	//steps += 1;

}

double PID::TotalError() {
	return Kp * p_error + Kd * d_error + Ki * i_error;
}

void PID::Twiddle(double cte) {

	const double tol_threshold = 0.2;
	if (sumK(ds) > tol_threshold) {
		
		if (startLoop) {
			Ks[twiddle_index] += ds[twiddle_index];
			startLoop = false;
			Kp = Ks[0];
			Ki = Ks[1];
			Kd = Ks[2];
			return;
		}

		double error = TotalError();
		if (error < best_err) {
			best_err = error;
			ds[twiddle_index] *= 1.1;
		} else {
			if (!secondUpdate) {
				Ks[twiddle_index] -= 2 * ds[twiddle_index];
				Kp = Ks[0];
				Ki = Ks[1];
				Kd = Ks[2];

				return;
			} else {
				Ks[twiddle_index] += ds[twiddle_index];
				ds[twiddle_index] *= 0.9;
			}
		}
		
		twiddle_index += 1;
		if (twiddle_index == 3) {
			twiddle_index = 0;
		}

		secondUpdate = false;
		startLoop = true;
	}

	Kp = Ks[0];
	Ki = Ks[1];
	Kd = Ks[2];

}

double PID::sumK(double ds[]) {
	double response = 0;
	for (int i = 0; i < 3; i++) {
		double number = ds[i];
		response += number;
	}

	return response;
}
