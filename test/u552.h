#ifndef U552_H
#define U552_H

#include <stdint.h>

//69byte type
typedef struct{
	uint8_t front[38];
	uint32_t mid;
	uint8_t back[27];
} __attribute__((packed)) test_u552_t;

#endif //U552_H
