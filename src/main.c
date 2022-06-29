#include "oars.h"
#include <stdio.h>
// clang-format off
#define Log                                                                    \
  printf("oa%02lu mv%02lu st%03lu nb%03lu %s\n", a, v, t, b, __FUNCTION__)

N(nar);
N(and) { A(010) nar(X); }
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
N(n_ray_not ) { Log; }
N(n_ray_and ) { Log; }
N(n_ray_oor ) { Log; }

N(iam       ) { A(one) O; }

// S = S a | b
N(term) { Log;
  R(const char *, str);
  R(Q_t, pos);
  R(Q_t, len);
  R(const char *, input);
  if (pos < len && input[pos] == str[0])
    A(input, len, pos + 1) C(1);
  else
    A(input, len, pos + 0) C(0);
}
N(S) {
  A("b", term)
  B(S, "b", term, and2) O;
}
N(orelse) { Log; OM; C(1); }
N(sore  ) {
  Log;
  A(
              "o", term,       "a", term, and2,
      orelse, "a", term, and2, "o", term, and2,
      orelse, "b", term, and2, "o", term, and2
  )
  O;
}

N(back    ) { A(1   )              C(1); }
N(example0) { A(sore) B("oooo", 5, 0) O; }
N(example ) { A(iam )         O; }

// clang-format off
int main( ) {
  p_t o[512]; Q_t a = 0;
  p_t s[512]; Q_t t = sizeof(s) / sizeof(*s);
  p_t m[512]; Q_t v = 0;
  p_t n[512]; Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = o_ray_not, s[--t].c = o_ray_and, s[--t].c = o_ray_oor;
  n[--b].c = n_ray_not, n[--b].c = n_ray_and, n[--b].c = n_ray_oor;

  A(example) O;
  return 0;
}
