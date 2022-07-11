#include "oars.h"
#include <stdio.h>
// clang-format off
#define Log                                                                    \
  printf("oa%02lu mv%02lu st%03lu nb%03lu %s\n", a, v, t, b, __FUNCTION__)

N(nar );
N(dot ) { O; }
N(and ) { A(010) nar(X); }
N(and2) { A(020) nar(X); }
N(and3) { A(030) nar(X); }
N(and4) { A(040) nar(X); }

#define OM p_t *o_; o_ = o, o = m, m = o_; \
           Q_t  a_; a_ = a, a = v, v = a_
#define SN p_t *s_; s_ = s, s = n, n = s_; \
           Q_t  t_; t_ = t, t = b, b = t_

N(tok       ) { Log; OM; SN; O;   }

N(two);
N(one) { Log; A(tok) B(two) O; }
N(two) { Log; A(tok) B(one) O; }
N(add) { Log; R(Q_t, r); R(Q_t, l); o[a++].Q = l + r, C(1); }

N(o_ray_not ) { Log; }
N(o_ray_and ) { Log; }
N(o_ray_oor ) { Log; }

N(iam       ) { A(one) O; }

N(term    ) { Log;
  R(const char *, str);
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, input);
  if (pos < len && input[pos] == str[0])
    A(input, len, pos + 1) C(1);
  else
    A(input, len, pos + 0) C(0);
}


N(bT      ) { A("b", term) O; }
N(aT      ) { A("a", term) O; }
N(xT      ) { A("x", term) O; }

N(cT      ) { A("c", term) O; }

N(thenS   ) {}
N(orelse3 ) {}
N(variable) {}

N(Ba      ) {
  A(bT,
    Ba, aT, thenS, orelse3,
    Ba, variable) O;
}
N(Bax     ) {
  A(Ba, xT, thenS, Bax, variable) O;
}

N(example ) { A(iam )         O; }

N(nar_and);
N(nar_not);
N(nar_oor);

// clang-format off
int main( ) {
  p_t o[512]; Q_t a = 0;
  p_t s[512]; Q_t t = sizeof(s) / sizeof(*s);
  p_t m[512]; Q_t v = 0;
  p_t n[512]; Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = o_ray_oor;
  s[--t].c = o_ray_and;
  s[--t].c = o_ray_not;
  s[--t].Q = 0111;

  A(nar_and) O;
  return 0;
}
