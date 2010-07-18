/*
 * Alithia Engine
 * Copyright (C) 2009-2010 Kostas Michalopoulos
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Kostas Michalopoulos <badsector@runtimeterror.com>
 */

#ifndef __MATHSTUFF_H_INCLUDED__
#define __MATHSTUFF_H_INCLUDED__

typedef struct _vector_t
{
    float x, y, z;
} vector_t;

typedef struct _triangle_t
{
    vector_t v[3];
} triangle_t;

typedef struct _plane_t
{
    float nx, ny, nz, d;
} plane_t;

#define vec_dot(a,b) ((a)->x*(b)->x + (a)->y*(b)->y + (a)->z*(b)->z)
#define vec_lensq(a) vec_dot(a, a)
#define vec_len(a) sqrtf(vec_lensq(a))
void vec_normalize(vector_t* v);
void vec_sub(vector_t* a, vector_t* b);
void vec_makedir(vector_t* d, vector_t* a, vector_t* b);
float vec_distsq(vector_t* a, vector_t* b);
float vec_dist(vector_t* a, vector_t* b);
int plane_from_three_points(plane_t* p, vector_t* a, vector_t* b, vector_t* c);
int ray_plane_intersection(plane_t* p, vector_t* a, vector_t* b, vector_t* ip);
int ray_tri_intersection(triangle_t* t, vector_t* a, vector_t* b, vector_t* ip);

#endif