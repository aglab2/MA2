#pragma once

#include "types.h"

void guRotateX(Mtx* m, u16 a);
void guRotateY(Mtx* m, u16 a);
void guRotateZ(Mtx* m, u16 a);

void guRotateYF(float mf[4][4], u16 a);
u16 guPerspectiveA(Mtx *m, u16 fovy, float aspect, float near, float far, float scale);
