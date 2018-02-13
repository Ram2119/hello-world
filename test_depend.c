
#include <linux/module.h>


static int myFunction(void)
{
	printk("In myFunciton\n");

	return 0;
}
EXPORT_SYMBOL(myFunction);

