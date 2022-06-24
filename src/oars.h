#pragma once
/*                       Notandor / არადანი
                                  o       
                            m           b
                              .   |   .
                                . | .
                           s ----------- t
                                . | .
                              .   |   .
                            n     |     v
                                  a       

  The protocol of "Notandor/არადანი" gives us the power to specify
  everything in the M-words. We need to do so because the M-words
  are the only language we have from the beginning within the CPU.
  We need to start to specify things using language and not data
  structures. */
// clang-format off
#include <stdint.h>
typedef  int8_t  b_t; typedef  int16_t w_t; typedef  int32_t d_t; typedef  int64_t q_t;
typedef uint8_t  B_t; typedef uint16_t W_t; typedef uint32_t D_t; typedef uint64_t Q_t;
typedef struct p_t {
  union {
    struct p_t *p;
    void (*c)(
      struct p_t *o, Q_t a,
      struct p_t *s, Q_t t,
      struct p_t *m, Q_t v,
      struct p_t *n, Q_t b
    );
    void *v;
    const char *cs;
    b_t b; w_t w; d_t d; q_t q;
    B_t B; W_t W; D_t D; Q_t Q;
  };
} p_t;
#define OARS p_t *o, Q_t a, p_t *s, Q_t t, p_t *m, Q_t v, p_t *n, Q_t b
typedef void (*n_t)(OARS);
#define N(n)            void n(OARS)
#define Α(vs)           o[a++].v = (void *)(vs),
#define R(T, nm)        T nm = (T)o[--a].v
#define G(r)            s[t + (r)].c(o,   a, s, t, m, v, n, b)
#define O               o[a -   1].c(o, a-1, s, t, m, v, n, b)
#define C(r)            G(r)
#define ALIGN(O, A)     ((Q_t)(((O) + ((A) - 1)) / (A))) * (A)
#define wordCountOf(T)  ALIGN(sizeof(T), sizeof(void*))
#define CAT_(a, b)      a##b
#define CAT(a, b)       CAT_(a, b)
#include "oars_as.h"
