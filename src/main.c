#include "oars.h"
#include <stdio.h>

N(nar);
N(and ) { A(010) nar(X); }
N(and2) { A(020) nar(X); }
N(and3) { A(030) nar(X); }
N(and4) { A(040) nar(X); }
N(two);
N(one) { printf("one\n"); A(1) B(two) C(1); }
N(two) { printf("two\n"); A(2) B(one) C(1); }
N(add) {
  R(Q_t, r);
  R(Q_t, l);
  o[a++].Q = l + r, C(1);
}
N(tick);
N(o_ray_not) { printf("O NOT\n"); }
N(o_ray_and) { printf("O AND %lu\n", v); if(v) tick(X); }
N(o_ray_oor) { printf("O OOR\n"); }
N(n_ray_not) { printf("N NOT\n"); }
N(n_ray_and) { printf("N AND %lu\n", a); if(a) tick(X); }
N(n_ray_oor) { printf("N OOR\n"); }


N(tick) {
  //printf("tick\n");
  p_t*o_; Q_t a_;
  o_ = o; o = m; m = o_;
  a_ = a; a = v; v = a_ - 1;

  p_t*s_; Q_t t_;
  s_ = s; s = n; n = s_;
  t_ = t; t = b; b = t_;
  O;
}

N(iam) {
  A(one) O;
}

// S = S a | b
N(term) {
  R(const char*, str);
  R(Q_t, pos);
  R(Q_t, len);
  R(const char*, input);
  if (pos<len && input[pos] == str[0]) {
    
  } else {

  }
}
// tik tok
N(S) {
  A(   "b", term)
  B(S, "b", term, and2) O;
}
N(sore) {
  A("s", term, "a", term, and2)
  B("a", term, "s", term, and2) O;
}

N(back   ) { A(1) C(1); }
N(example0) { A("ssss", 5, 0, sore) O; }
N(example) { A(iam) O; }

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
