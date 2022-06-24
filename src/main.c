#include "oars.h"
#include <stdio.h>

N(one) { A(1) C(1); }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  o[a++].Q = l + r, C(1);
}
N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n"); }
N(ray_oor) { printf("OOR\n"); }

N(nar);

N(tick) {
  p_t*o_; Q_t a_;
  o_ = o; o = m; m = o_;
  a_ = a; a = v; v = a_;

  p_t*s_; Q_t t_;
  s_ = s; s = n; n = s_;
  t_ = t; t = b; b = t_;

  C(1);
}
N(example ) {
  A(1) C(1);
}
// დღეს
// Act as if ye have faith and faith shall be given to you.
// Put it another way: fake it 'til you make it
// clang-format off
int main( ) {
  p_t o[61]; Q_t a = 0;
  p_t s[62]; Q_t t = sizeof(s) / sizeof(*s);
  p_t m[63]; Q_t v = 0;
  p_t n[64]; Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = ray_not, s[--t].c = ray_and, s[--t].c = ray_oor;

  // Α(one, one, 010, nar, add, 010, nar) O;
  A(example) O;
  return 0;
}
