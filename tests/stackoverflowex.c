#include <locale.h>
#include <unistd.h>

int     main(void)
{
	   setlocale(LC_ALL, "en_US.UTF-8");
		    char uni[3] = {0x41, 0x41, 0x41};
			    write(1, uni, 3);
				    return (0);
}
