/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:59:40 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/15 19:07:09 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//typedef void (*ptrfonct[10])(void);


void fonct0(void)
{
	printf("0\n");
}
void fonct1(void)
{
	printf("1\n");
}
void fonct2(void)
{
	printf("2\n");
}
void fonct3(void)
{
	printf("3\n");
}
void fonct4(void)
{
	printf("4\n");
}
void fonct5(void)
{
	printf("5\n");
}
void fonct6(void)
{
	printf("6\n");
}
void fonct7(void)
{
	printf("7\n");
}
void fonct8(void)
{
	printf("8\n");
}
void fonct9(void)
{
	printf("9\n");
}

int main(int ac, char **av)
{

	void *tmp;

	void (*ptrfonct[11])(void);

	ptrfonct[0] = fonct0;
	ptrfonct[1] = fonct1;
	ptrfonct[2] = fonct2;
	ptrfonct[3] = fonct3;
	ptrfonct[4] = fonct4;
	ptrfonct[5] = fonct5;
	ptrfonct[6] = fonct6;
	ptrfonct[7] = fonct7;
	ptrfonct[8] = fonct8;
	ptrfonct[9] = fonct9;
	ptrfonct[atoi(av[1])]();
	return (0);
}














