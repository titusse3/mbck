#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "mbck.h"

#define BASE_SCREEN_WIDTH 1400
#define BASE_SCREEN_HEIGHT 820

int main(void) {
  InitWindow(BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT, "Exemple mbck");
  SetTargetFPS(60);
  mbck_t *m = init_mbck("../ressources/1.png", BASE_SCREEN_WIDTH,
      BASE_SCREEN_HEIGHT, true);
  mbck_t *f = init_mbck("../ressources/2.png", BASE_SCREEN_WIDTH,
      BASE_SCREEN_HEIGHT, false);
  mbck_t *k = init_mbck("../ressources/3.png", BASE_SCREEN_WIDTH,
      BASE_SCREEN_HEIGHT, false);
  if (m == nullptr || f == nullptr || k == nullptr) {
    fprintf(stderr, "init_mbck failed\n");
    CloseWindow();
    return EXIT_FAILURE;
  }
  while (!WindowShouldClose()) {
    if (IsWindowResized()) {
      int width = GetScreenWidth();
      int height = GetScreenHeight();
      update_mbck_scale(m, width, height);
      update_mbck_scale(f, width, height);
      update_mbck_scale(k, width, height);
    }
    BeginDrawing();
    mbck_physics_process(m, 5.0f);
    mbck_physics_process(f, 2.0f);
    mbck_physics_process(k, 3.0f);
    EndDrawing();
  }
  dispose_mbck(&m);
  dispose_mbck(&f);
  dispose_mbck(&k);
  CloseWindow();
  return EXIT_SUCCESS;
}
