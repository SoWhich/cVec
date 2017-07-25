#ifndef __CVEC_H__
#define __CVEC_H__
#include<stdlib.h>
#include<string.h>

#define CVEC(type)                                                            \
typedef struct {                                                              \
	type * vector;                                                        \
	unsigned int len;                                                     \
} type ## _vec;                                                               \
                                                                              \
type ## _vec* type ## VecInit(unsigned int count) {                           \
	type ## _vec* vec = malloc(sizeof(type ## _vec));                     \
	if (vec != NULL) {                                                    \
		vec->vector = malloc(sizeof(type) * count);                   \
		vec->len = count;                                             \
	}                                                                     \
	return vec;                                                           \
}                                                                             \
                                                                              \
void type ## VecRemove(type ## _vec* vec, unsigned int loc) {                 \
	vec->len--;                                                           \
	type* tmp = malloc(sizeof(type) * (vec->len));                        \
	                                                                      \
	if (tmp != NULL) {                                                    \
		unsigned int i;                                               \
		memcpy(tmp, vec->vector, sizeof(type) * loc);                 \
	                                                                      \
		memcpy(&tmp[loc],                                             \
				&vec->vector[loc + 1],                        \
				sizeof(type) * ((vec->len) - loc));           \
	}                                                                     \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = tmp;                                                    \
}                                                                             \
                                                                              \
void type ## VecPrepend(type ## _vec* vec, type val, unsigned int loc) {      \
	type* tmp = malloc(sizeof(type) * (vec->len + 1));                    \
	                                                                      \
	if (tmp != NULL) {                                                    \
		unsigned int i;                                               \
		memcpy(tmp, vec->vector, sizeof(type) * loc);                 \
		                                                              \
		tmp[loc] = val;                                               \
		                                                              \
		memcpy(&tmp[loc + 1],                                         \
				&vec->vector[loc],                            \
				sizeof(type) * ((vec->len) - loc));           \
	}                                                                     \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = tmp;                                                    \
	vec->len++;                                                           \
}                                                                             \
                                                                              \
void type ## VecAppend(type ## _vec* vec, type val, unsigned int loc) {       \
	type* tmp = malloc(sizeof(type) * (vec->len + 1));                    \
	                                                                      \
	if (tmp != NULL) {                                                    \
		unsigned int i;                                               \
		memcpy(tmp, vec->vector, sizeof(type) * (loc + 1));           \
		                                                              \
		tmp[loc + 1] = val;                                           \
		                                                              \
		memcpy(&tmp[loc + 2],                                         \
				&vec->vector[loc + 1],                        \
				sizeof(type) * (vec->len - loc - 1));         \
	}                                                                     \
	                                                                      \
	free(vec->vector);                                                    \
	vec->vector = tmp;                                                    \
	vec->len++;                                                           \
}                                                                             \
                                                                              \
void type ## VecFinish(type ## _vec* vec) {                                   \
	free(vec->vector);                                                    \
	free(vec);                                                            \
}
#endif
