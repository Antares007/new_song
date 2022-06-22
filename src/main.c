#include "oars.h"
#include <stdio.h>

N(one     ) { Α(7) C(1); }
N(add     ) { R(Q_t, r); R(Q_t, l); Α(l+r) C(1); }
N(ray_not ) { printf("NOT\n"); }
N(ray_and ) { printf("AND\n"); }
N(ray_oor ) { printf("OOR\n"); }


N(nar);
//  დღეს
//    
int main() {
  p_t o[61]; Q_t a = 0;
  p_t s[62]; Q_t t = sizeof(s) / sizeof(*s);
  p_t m[63]; Q_t v = 0;
  p_t n[64]; Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = ray_not;
  s[--t].c = ray_and;
  s[--t].c = ray_oor;

  Α(one, one, 010, nar, add,  010, nar) O;
//  Α(one) O;
  return 0;
}
