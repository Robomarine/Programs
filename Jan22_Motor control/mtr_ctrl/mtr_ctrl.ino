#include <math.h>

class Vect {
  public:
    double x;
    double y;
    Vect (double vx, double vy) {
      x = vx;
      y = vy;
    }

    void normalize() {
      double l = sqrt(x*x + y*y);
      x = x/l;
      y = y/l;
    }
};

double norm_dot_prod(Vect a, Vect b) {
  a.normalize();
  b.normalize();
  double v = a.x*b.x + a.y*b.y;
  return v;
}

Vect mot_a_norm = new Vect(0.707, 0.707);
Vect mot_b_norm = new Vect(-0.707, 0.707);
Vect mot_c_norm = new Vect(0.707, -0.707);
Vect mot_d_norm = new Vect(-0.707, -0.707);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
