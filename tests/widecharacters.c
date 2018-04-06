#include <wchar.h>
#include <stdio.h>

int main(void)
{
	wchar_t *strw = L"wide str";
	printf("my wide str:%l010s\n", strw);
	return (0);
}
