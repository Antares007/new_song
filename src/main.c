#include "oars.h"
#include <stdio.h>
#include <uv.h>

N(on_new_connection) {
//  R(int,  status);
//  R(p_t*, server);
}
N(n_tcp_init) {
//  uv_tcp_t server;
//  uv_tcp_init(loop, &server);
//  Α() O;
}
N(n_main) {
//  Α(on_new_connection, 
//    n_tcp_init,
//    "0.0.0.0", DEFAULT_PORT, n_ip4_addr, and3,
//    n_tcp_bind, and,
//    1, n_listen, and2)
}
//  uv_loop_t *loop = uv_default_loop();
//  printf("Default loop.\n");
//  uv_run(loop, UV_RUN_DEFAULT);
//  uv_loop_close(loop);

N(ray_not) { printf("NOT\n"); }
N(ray_and) { printf("AND\n"); }
N(ray_oor) { printf("OOR\n"); }
N(god) { C(1); }
N(nar);

int main() {
  p_t ο[512];
  Q_t α = 0;
  Q_t ρ = 512;
  p_t σ[512];
  σ[--ρ].c = ray_not;
  σ[--ρ].c = ray_and;
  σ[--ρ].c = ray_oor;

  Α(god, god, 010, nar) O;
  
  return 0;
}
