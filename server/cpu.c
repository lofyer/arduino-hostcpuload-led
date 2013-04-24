#include <stdio.h>
#include <unistd.h>
#include <glibtop.h>
#include <glibtop/cpu.h>

glibtop_cpu cpu1;
glibtop_cpu cpu2;

char cacl_cpu(){
	glibtop_init();
	glibtop_get_cpu (&cpu1);
	sleep(2);
	glibtop_get_cpu (&cpu2);
	//printf("%u\n",(cpu2.user+cpu2.sys)-(cpu1.user+cpu1.sys));
	//printf("%u\n",(cpu2.total)-(cpu1.total));
	float avg=(float)(10*((cpu2.user+cpu2.sys)-(cpu1.user+cpu1.sys))/(cpu2.total-cpu1.total));
	//printf("%d\n",((int)avg)+48);
	return (char)((int)avg+48);
}

/*
int main(){

	printf("CPU TYPE INFORMATIONS \n\n");
	while(1) printf("cpu usage: %c\n",cacl_cpu());

}
*/
