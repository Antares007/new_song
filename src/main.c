#include "oars.h"// abO abA obR rbS
#include <stdio.h>

N(one     ) { Α(7) C(1); }
N(add     ) { R(Q_t, r); R(Q_t, l); Α(l+r) C(1); }
N(ray_not ) { printf("NOT %lu\n", α); }
N(ray_and ) { printf("AND %lu\n", α); }
N(ray_oor ) { printf("OOR %lu\n", α); }


N(nar);
//  დღეს
//    
int main() {
  p_t ο[512];
  Q_t α = 0;
  Q_t ρ = 512;
  p_t σ[512];
  ο[--ρ].c = ray_not;
  ο[--ρ].c = ray_and;
  ο[--ρ].c = ray_oor;

  Α(one, one, 010, nar, add,  010, nar) O;
  Α(one) O;
  return 0;
}
