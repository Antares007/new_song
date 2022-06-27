#include "oars.h"
#include <stdio.h>
#define Log printf("a%lu v%lu %s\n", a, v, __FUNCTION__)

N(nar);
N(and) { A(010) nar(X); }
N(and2) { A(020) nar(X); }
N(and3) { A(030) nar(X); }
N(and4) { A(040) nar(X); }

N(two);
N(one) { Log; A(1) B(two) C(1); }
N(two) { Log; A(2) B(one) C(1); }
N(add) { Log; R(Q_t, r); R(Q_t, l); o[a++].Q = l + r, C(1); }

N(tick) { Log;
  p_t *o_; Q_t a_;
  o_ = o, o = m, m = o_;
  a_ = a, a = v, v = a_ - 1;
  p_t *s_; Q_t t_;
  s_ = s, s = n, n = s_;
  t_ = t, t = b, b = t_;
  O;
}
N(o_ray_not) { Log; }
N(o_ray_and) { Log; if (v) tick(X); }
N(o_ray_oor) { Log; }
N(n_ray_not) { Log; }
N(n_ray_and) { Log; if (a) tick(X); }
N(n_ray_oor) { Log; }

N(iam) { A(one) O; }

// S = S a | b
N(term) {
  R(const char *, str);
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, input);
  if (pos < len && input[pos] == str[0]) {
    A(input, len, pos + 1) C(1);
  } else {
    A(input, len, pos + 0) C(0);
  }
}
N(S) {
  A("b", term)
  B(S, "b", term, and2) O;
}
N(orelse) { Log; C(1); }
N(sore) { Log;
  A("s", term, "a", term, and2, orelse, "a", term, and2, "s", term, and2,
    orelse, "b", term, and2, "o", term, and2

    )
  O;
}

N(back    ) { A(1) C(1); }
N(example0) { A(sore) B("ssss", 5, 0) O; }
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
