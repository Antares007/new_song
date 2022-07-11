#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

N(nar_not) {
  Q_t j = s[t++].Q, nc = j >> 6 & 7, ac = j >> 3 & 7, oc = j >> 0 & 7;
  for (Q_t i = 0; i < nc; i++) o[a++].v = s[t++].v;
  t += ac + oc;
  nc ? O : nar_not(X);
}
N(nar_and) {
  Q_t j = s[t++].Q, nc = j >> 6 & 7, ac = j >> 3 & 7, oc = j >> 0 & 7;
  t += nc;
  for (Q_t i = 0; i < ac; i++) o[a++].v = s[t++].v;
  t += oc;
  ac ? O : nar_and(X);
}
N(nar_oor) {
  Q_t j = s[t++].Q, nc = j >> 6 & 7, ac = j >> 3 & 7, oc = j >> 0 & 7;
  t += nc + ac;
  for (Q_t i = 0; i < oc; i++) o[a++].v = s[t++].v;
  oc ? O : nar_oor(X);
}
N(nar) {
  Q_t j = o[--a].Q, nc = j >> 6 & 7, ac = j >> 3 & 7, oc = j >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++) s[--t].v = o[--a].v;
  s[--t].Q = j;
  O;
}
