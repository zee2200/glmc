#ifndef GLMC_DEFS
#define GLMC_DEFS

#ifdef __cplusplus
#define GLMC_CAST(TYPE, DATA) TYPE{DATA}
extern "C"{
#else
#define GLMC_CAST(TYPE, DATA) (TYPE) DATA
#endif

#include <smmintrin.h>

typedef union vec2{
	__m128 vec;
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	__m128 vec;
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union mat2{
	__m128 mat;
	float mat2D[2][2];
	float mat1D[4];
	struct{
		float m0, m1, m2, m3;
	};
} mat2;

//need padding in certain spots
typedef union mat3{
	__m128 mat[3];
	float mat2D[4][4];
	float mat1D[16];
	struct{
		float m0, m1, m2, pad1, m3, m4, m5, pad2, m6, m7, m8, pad3;
	};
} mat3;

typedef union mat4{
	__m128 mat[4];
	float mat2D[4][4];
	float mat1D[16];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
	};
} mat4;

#ifdef __cplusplus
}
#endif

#endif
