#include "oars.h"
#include <stdio.h>

N(one) { OA(1) C(1); }
N(add) {
  Ro(Q_t, r);
  Ro(Q_t, l);
  o[a++].Q = l + r, C(1);
}
N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n"); }
N(ray_oor) { printf("OOR\n"); }

N(nar);

N(term) {
  Ro(const char *, str);
  (void)str;
  C(1);
}
N(S) {
  OA("b", term, S, "a", term) O;
}
N(example) { 
  NA("baaa", 5, 0) OA(S) O;
}
//  დღეს
//  Act as if ye have faith and faith shall be given to you.
//  Put it another way: fake it 'til you make it
int main() {
  p_t o[61];
  Q_t a = 0;
  p_t s[62];
  Q_t t = sizeof(s) / sizeof(*s);
  p_t m[63];
  Q_t v = 0;
  p_t n[64];
  Q_t b = sizeof(n) / sizeof(*n);

  s[--t].c = ray_not;
  s[--t].c = ray_and;
  s[--t].c = ray_oor;

  ///Α(one, one, 010, nar, add, 010, nar) O;
  OA(example) O;
  return 0;
}
