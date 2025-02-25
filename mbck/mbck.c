#include "mbck.h"
#include <stdio.h>

struct mbck_t {
  Texture2D b;
  float scroll_b;
  int width;
  int height;
  bool rotate;
};

mbck_t *init_mbck(const char *b, int width, int height, bool rotate) {
  mbck_t *m = malloc(sizeof *m);
  if (m == nullptr) {
    return nullptr;
  }
  m->b = LoadTexture(b);
  m->scroll_b = 0;
  m->width = width;
  m->height = height;
  m->rotate = rotate;
  return m;
}

void dispose_mbck(mbck_t **m) {
  if (*m == nullptr) {
    return;
  }
  UnloadTexture((*m)->b);
  free(*m);
  *m = nullptr;
}

void update_mbck_scale(mbck_t *m, int width, int height) {
  m->width = width;
  m->height = height;
}

void mbck_physics_process(mbck_t *m, float delta) {
  m->scroll_b -= delta;
  if (m->scroll_b <= -m->width * (m->rotate ? 2 : 1)) {
    m->scroll_b = 0;
  }
  DrawTexturePro(m->b,
      (Rectangle){ 0, 0, m->b.width, m->b.height },
      (Rectangle){ m->scroll_b, 0, m->width, m->height },
      (Vector2){ 0, 0 },
      0.0f, WHITE);
  if (m->rotate) {
    DrawTexturePro(m->b,
        (Rectangle){ m->b.width, 0, -m->b.width, m->b.height },
        (Rectangle){ m->scroll_b + m->width, 0, m->width, m->height },
        (Vector2){ 0, 0 },
        0.0f, WHITE);
  }
  DrawTexturePro(m->b,
      (Rectangle){ 0, 0, m->b.width, m->b.height },
      (Rectangle){ m->scroll_b + m->width * (m->rotate ? 2 : 1), 0, m->width,
                   m->height },
      (Vector2){ 0, 0 },
      0.0f, WHITE);
}
