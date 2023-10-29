#include <stdio.h>
#include <unistd.h>

int main()
{
	const char *file = "/proc/stat";
	FILE *ptr = fopen(file, "r");
	float a[12], b[12], suma, sumb;
	float per;
	fscanf(ptr, "%*s %f %f %f %f %f %f %f %f %f %f",
		&a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], 
		&a[7], &a[8], &a[9]);
	fclose(ptr);
	usleep(450000);
	fopen(file, "r");
	fscanf(ptr, "%*s %f %f %f %f %f %f %f %f %f %f",
		&b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], 
		&b[7], &b[8], &b[9]);
	fclose(ptr);
	for(int n=0;n<10;n++){
		suma += a[n];
		sumb += b[n];
	}
	per=100*(1-(b[3]-a[3])/(sumb-suma));
	printf("%.0f%\n",per);
	return 0;
}
