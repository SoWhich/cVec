#ifndef __CVEC_H__
#define __CVEC_H__
#include<stdlib.h>

#define CVEC(type)                                                            \
typedef struct {                                                              \
	type * vector;                                                        \
	unsigned int len;                                                     \
} type ## _vec;                                                               \
                                                                              \
type ## _vec* type ## VecInit(unsigned int count) {                           \
	type ## _vec* vec = malloc(sizeof(type ## _vec));                     \
	vec->vector = malloc(sizeof(type) * count);                           \
	vec->len = count;                                                     \
	return vec;                                                           \
}                                                                             \
                                                                              \
void type ## VecRemove(type ## _vec* vec, unsigned int index) {               \
	type* temp = malloc(sizeof(type) * (vec->len -1));                    \
	                                                                      \
	unsigned int i;                                                       \
	for (i = 0; i < index; i++)                                           \
		temp[i] = vec->vector[i];                                     \
	                                                                      \
	for (i = index + 1; i < vec->len; i++)                                \
		temp[i - 1] = vec->vector[i];                                 \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = temp;                                                   \
	vec->len--;                                                           \
}                                                                             \
                                                                              \
void type ## VecPrepend(type ## _vec* vec, type val, unsigned int index) {    \
	type* temp = malloc(sizeof(type) * (vec->len + 1));                   \
	                                                                      \
	unsigned int i;                                                       \
	for (i = 0; i < index; i++)                                           \
		temp[i] = vec->vector[i];                                     \
	                                                                      \
	temp[index] = val;                                                    \
	                                                                      \
	for (i = index; i < vec->len; i++)                                    \
		temp[i + 1] = vec->vector[i];                                 \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = temp;                                                   \
	vec->len++;                                                           \
}                                                                             \
                                                                              \
void type ## VecAppend(type ## _vec* vec, type val, unsigned int index) {     \
	type* temp = malloc(sizeof(type) * (vec->len + 1));                   \
	                                                                      \
	unsigned int i;                                                       \
	for (i = 0; i <= index; i++)                                          \
		temp[i] = vec->vector[i];                                     \
	                                                                      \
	temp[index + 1] = val;                                                \
	                                                                      \
	for (i = index + 1; i < vec->len; i++)                                \
		temp[i + 1] = vec->vector[i];                                 \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = temp;                                                   \
	vec->len++;                                                           \
}                                                                             \
                                                                              \
void type ## VecFinish(type ## _vec* vec) {                                   \
	free(vec->vector);                                                    \
	free(vec);                                                            \
}
#endif
