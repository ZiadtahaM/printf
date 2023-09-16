#include "main.h"
/**
 * print_binary%i
 * @typ: List of arguments
 * @buf: Buffer array
 * @flg: active flags
 * @wid: get width
 * @pre: Precision specification
 * @siz: Size specifier
 * Return: Number(s)
 */
int print_binary(va_list typ, char buf[],
	int flg, int wid, int pre, int siz)
{
	unsigned int num1, num2, num3,  sum;
	unsigned int a[32];
	int count;

	UNUSED(buf);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(pre);
	UNUSED(siz);

	num1 = va_arg(typ, unsigned int);
	num2 = 2147483648;
	a[0] = num1 / num2;
	for (num3 = 1; num3 < 32; num3++)
	{
		num2 /= 2;
		a[num3] = (num1 / num2) % 2;
	}
	for (num3 = 0, sum = 0, count = 0; num3 < 32; num3++)
	{
		sum += a[num3];
		if (sum || num3 == 31)
		{
			char z = '0' + a[num3];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

