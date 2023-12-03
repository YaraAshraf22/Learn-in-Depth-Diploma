/*
 * main.c
 *
 *  Created on: Dec 2, 2023
 *      Author: HP
 */

#include "stdio.h"
/* Adding 2 complex numbers using structures*/

struct Scomplex {
	float m_R;
	float m_I;
};

struct Scomplex Addcomplex(struct Scomplex A, struct Scomplex B)
{
	struct Scomplex C;
	C.m_R=A.m_R + B.m_R;
	C.m_I=A.m_I + B.m_I;
	return C;
}

struct Scomplex Readcomplex(char*order)
{
	struct Scomplex C;
	printf("For %s complex number\n", order);
	printf("Enter real and imaginary numbers respectively:");
	fflush(stdin); fflush(stdout);
	scanf("%f\n%f", &C.m_R, &C.m_I);
	return C;
}

void Printcomplex (struct Scomplex c)
{
	printf("Sum = %g + %gi", c.m_R, c.m_I);
}

int main ()
{
	struct Scomplex n1,n2,sum;
	n1=Readcomplex("1st");
	n2=Readcomplex("2nd");
	sum=Addcomplex(n1,n2);
	Printcomplex(sum);
	return 0;
}

