#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef long double f128;


#define OK    			(0u)
#define NOT_OK    		(1u)


#define Null	'\0'
#define NON					 0


/*
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOG_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT) ((REG >> BIT) & 1)

*/
#endif
