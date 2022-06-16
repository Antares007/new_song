#include "oars.h"
#include <stdio.h>
#include <stdlib.h>

#define DESTRUCTJ                                                              \
  nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0)
#define DESTRUCT                                                               \
  ρ += 3;                                                                      \
  Q_t j = σ[ρ++].Q, DESTRUCTJ
S(nar_not) {
  DESTRUCT, f = nc;
  while (nc)
    nc--, σ[α++].v = σ[ρ++].v;
  ρ += ac + oc;
  f ? O : C(2);
}
S(nar_and) {
  DESTRUCT, f = ac;
  ρ += nc;
  while (ac)
    ac--, σ[α++].v = σ[ρ++].v;
  ρ += oc;
  f ? O : C(1);
}
S(nar_oor) {
  DESTRUCT, f = oc;
  ρ += nc + ac;
  while (oc)
    oc--, σ[α++].v = σ[ρ++].v;
  f ? O : C(0);
}
N(nar) {
  Q_t j = σ[--α].Q, DESTRUCTJ, tc = nc + ac + oc;
  while (tc)
    tc--, σ[--ρ].v = σ[--α].v;
  σ[--ρ].Q = j;
  σ[--ρ].c = nar_not, σ[--ρ].c = nar_and, σ[--ρ].c = nar_oor;
  O;
}
#undef DESTRUCT
#undef DESTRUCTJ
