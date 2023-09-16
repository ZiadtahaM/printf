#include "main.h"
/**
 * print_int %d
 * @buf: Buffer array
 * @flg: active flags
 * @wid: get width.
 * @pre: Precision specification
 * @siz: Size specifier
 * Return: Number(s) 
 */
int print_int_d_(va_list typ, char buf[],
	int flg, int wid, int pre, int siz)
{
	int nmpr = BUFF_SIZE - 2;
	int negative = 0;
	long int nnn = va_arg(typ, long int);
	unsigned long int num;

	nnn = convert_size_number(nnn, siz);

	if (nnn == 0)
		buf[nmpr--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)nnn;

	if (nnn < 0)
	{
		num = (unsigned long int)((-1) * nnn);
		negative = 1;
	}

	while (num > 0)
	{
		buf[nmpr--] = (num % 10) + '0';
		num /= 10;
	}

	nmpr++;

	return (write_number(negative, nmpr, buf, flg, wid, pre, siz));
}

