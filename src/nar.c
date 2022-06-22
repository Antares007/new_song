#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  t += 3;                                                                      \
  Q_t j = s[t++].Q, DESTRUCTJ
static N(nar_not) {
  DESTRUCT, f = nc;
  while (nc) nc--, o[a++].v = s[t++].v;
  t += ac + oc;
  f ? O : C(2);
}
static N(nar_and) {
  DESTRUCT, f = ac;
  t += nc;
  while (ac) ac--, o[a++].v = s[t++].v;
  t += oc;
  f ? O : C(1);
}
static N(nar_oor) {
  DESTRUCT, f = oc;
  t += nc + ac;
  while (oc) oc--, o[a++].v = s[t++].v;
  f ? O : C(0);
}
N(nar) {
  Q_t j = o[--a].Q, DESTRUCTJ, tc = nc + ac + oc;
  while (tc) tc--, s[--t].v = o[--a].v;
  s[--t].Q = j;
  s[--t].c = nar_not;
  s[--t].c = nar_and;
  s[--t].c = nar_oor;
  O;
}
#undef DESTRUCT
#undef DESTRUCTJ
