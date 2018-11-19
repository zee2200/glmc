#include "matrix/matrix4.h"

mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15){
	mat4 res;
	res.mat[0] = _mm_set_ps(m3, m2, m1, m0);
	res.mat[1] = _mm_set_ps(m7, m6, m5, m4);
	res.mat[2] = _mm_set_ps(m11, m10, m9, m8);
	res.mat[3] = _mm_set_ps(m15, m14, m13, m12);
	return res;
}
mat4 mat4_set1(float x){
	mat4 res;
	res.mat[0] = _mm_set1_ps(x);
	res.mat[1] = res.mat[0];
	res.mat[2] = res.mat[0];
	res.mat[3] = res.mat[0];
	return res;
}
mat4 mat4_add(mat4 a, mat4 b){
	a.mat[0] = _mm_add_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_add_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_add_ps(a.mat[2], b.mat[2]);
	a.mat[3] = _mm_add_ps(a.mat[3], b.mat[3]);
	return a;
}
mat4 mat4_sub(mat4 a, mat4 b){
	a.mat[0] = _mm_sub_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_sub_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_sub_ps(a.mat[2], b.mat[2]);
	a.mat[3] = _mm_sub_ps(a.mat[3], b.mat[3]);
	return a;
}
//thanks harold!
mat4 mat4_mul(mat4 a, mat4 b){
	mat4 res;
	__m128 t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[0][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[0][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[0][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[0][3])));
	res.mat[0] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[1][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[1][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[1][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[1][3])));
	res.mat[1] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[2][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[2][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[2][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[2][3])));
	res.mat[2] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[3][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[3][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[3][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[3][3])));
	res.mat[3] = t;
	return res;
}
mat4 mat4_addScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_add_ps(a.mat[0], scal);
	a.mat[1] = _mm_add_ps(a.mat[1], scal);
	a.mat[2] = _mm_add_ps(a.mat[2], scal);
	a.mat[3] = _mm_add_ps(a.mat[3], scal);
	return a;
}
mat4 mat4_subScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_sub_ps(a.mat[0], scal);
	a.mat[1] = _mm_sub_ps(a.mat[1], scal);
	a.mat[2] = _mm_sub_ps(a.mat[2], scal);
	a.mat[3] = _mm_sub_ps(a.mat[3], scal);
	return a;
}
mat4 mat4_mulScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_mul_ps(a.mat[0], scal);
	a.mat[1] = _mm_mul_ps(a.mat[1], scal);
	a.mat[2] = _mm_mul_ps(a.mat[2], scal);
	a.mat[3] = _mm_mul_ps(a.mat[3], scal);
	return a;
}
mat4 mat4_divScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_div_ps(a.mat[0], scal);
	a.mat[1] = _mm_div_ps(a.mat[1], scal);
	a.mat[2] = _mm_div_ps(a.mat[2], scal);
	a.mat[3] = _mm_div_ps(a.mat[3], scal);
	return a;
}
mat4 mat4_identity(void){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return res;
}
mat4 mat4_translate(float x, float y, float z){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, z, y, x);
	return res;
}
mat4 mat4_scale(float x, float y, float z){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, x);
	res.mat[1] = _mm_set_ps(0.f, 0.f, y, 0.f);
	res.mat[2] = _mm_set_ps(0.f, z, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return res;
}
mat4 mat4_transpose(mat4 a){
	_MM_TRANSPOSE4_PS(a.mat[0], a.mat[1], a.mat[2], a.mat[3]);
	return a;
}
mat4 mat4_swapRow(mat4 a, int R1, int R2){
	vec4 tmp = GLMC_CAST(vec4, _mm_set_ps(a.mat[3][R1], a.mat[2][R1], a.mat[1][R1], a.mat[0][R1]));
	a.mat2D[3][R1] = a.mat2D[3][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[0][R1] = a.mat2D[0][R2];

	a.mat2D[3][R2] = tmp.w;
	a.mat2D[2][R2] = tmp.z;
	a.mat2D[1][R2] = tmp.y;
	a.mat2D[0][R2] = tmp.x;
	return a;
}
mat4 mat4_swapCol(mat4 a, int C1, int C2){
	__m128 tmp = a.mat[C1];
	a.mat[C1] = a.mat[C2];
	a.mat[C2] = tmp;
	return a;
}
