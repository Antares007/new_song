#include "oars.h"
#include <stdio.h>

N(nar);
N(and ) { A(010) nar(X); }
N(and2) { A(020) nar(X); }
N(and3) { A(030) nar(X); }
N(and4) { A(040) nar(X); }

N(one) { printf("one\n"); A(1) C(1); }
N(two) { printf("two\n"); A(2) C(1); }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  o[a++].Q = l + r, C(1);
}
N(o_ray_not) { printf("O NOT\n"); }
N(o_ray_and) { printf("O AND\n"); }
N(o_ray_oor) { printf("O OOR\n"); }
N(n_ray_not) { printf("N NOT\n"); }
N(n_ray_and) { printf("N AND\n"); }
N(n_ray_oor) { printf("N OOR\n"); }


N(tick) {
  p_t*o_; Q_t a_;
  o_ = o; o = m; m = o_;
  a_ = a; a = v; v = a_;

  p_t*s_; Q_t t_;
  s_ = s; s = n; n = s_;
  t_ = t; t = b; b = t_;

  O;
}
N(iam) { A(one, tick, and) B(two) O; }

N(S) { //A("b", term) A(S, "b", term) B(1) C(1);
}
N(back) { A(1) C(1); }
N(example ) { A(iam) O; }

// clang-format off
int main( ) {
  p_t o[61]; Q_t a = 0;
  p_t s[62]; Q_t t = sizeof(s) / sizeof(*s);
  p_t m[63]; Q_t v = 0;
  p_t n[64]; Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = o_ray_not, s[--t].c = o_ray_and, s[--t].c = o_ray_oor;
  n[--b].c = n_ray_not, n[--b].c = n_ray_and, n[--b].c = n_ray_oor;

  A(example) O;
  return 0;
}
