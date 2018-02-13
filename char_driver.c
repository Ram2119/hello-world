#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Ram");
MODULE_DESCRIPTION("Sample char driver");
MODULE_VERSION("1.0");


/** Constants **/
#define FIRST_MINOR	10
#define NR_DEVS 1		//Number of device numbers

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
static ssize_t myRead(struct file *, char *, size_t, loff_t *);
static ssize_t myWrite(struct file *, const char *, size_t, loff_t *);
//InitiaLIZATION ROUTINES
static int myInit(void);
static void myExit(void);

static int myFunction(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.write = myWrite,
	.read = myRead,
	.release = myRelease
};

/*Global variables */
char *devname;			//contains device name
int majNo;
static dev_t mydev;		// encodes major number and minor number 
struct cdev *my_cdev;		// holds character device driver descriptor
static char   message[256] = {0};           // Memory for the string that is passed from userspace

/* To accept input from command line */
module_param(devname, charp, 0000);

// class and device structures 

static struct class *mychar_class;
static struct device *mychar_device;

/* 
 * myopen: open function of the pseudo driver  *
 */

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO"Open succesful\n");

	myFunction();	//defined in another module

	return 0;
}

/*
 * mywrite: write function of the pseudo driver
 *
 */
static ssize_t myWrite(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
	int ret = copy_from_user(message, buffer, len);
	if (ret < 0)
		printk("Failed to copy data from user\n");
	else
		printk(KERN_INFO "Data from user = %s\n", message);

	return ret;
}

/*
 * myRead: read function of the pseudo driver
 *
 */
static ssize_t myRead(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
   int count = copy_to_user(buffer, message, len);

   if (count >= 0) {            // if true then have success
	printk(KERN_INFO "data to user=%s\n", buffer); 
     	return count;  // clear the position to the start and return 0
   }
   else {
      printk(KERN_INFO "Failed to send %d characters to the user\n", count);
      return 0;             
   }
}

/* myRelease : close function of the pseudo driver 
 *
 */

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

/* myInit : init function of the kernel module 
 *
 */
static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Character Device\n");

	//Allocating Device NUmbers 
	//
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if (status < 0) {
		printk(KERN_NOTICE "Device numbers allocation failed %d \n",
		       status);
		goto err;

	}
	printk("mydev====>%d\n", mydev);
	printk(KERN_INFO "Major number allocated = %d \n ", MAJOR(mydev));
	my_cdev = cdev_alloc();	//Allocate memory for my_cdev;
	if (my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc failed\n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);	// Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
	if (status) {
		printk(KERN_ERR "cdev_add failed\n");
		goto err_cdev_add;
	}

	// create class and entry in sysfs 
	mychar_class = class_create(THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}
	//creates mychar_device in sysfs and an
	//device entry willl be made in /dev directory
	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed\n");
		goto err_device_create;
	}
	return 0;

 err_device_create:
	class_destroy(mychar_class);

 err_class_create:
	cdev_del(my_cdev);
 err_cdev_add:
	kfree(my_cdev);

 err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

 err:
	return ret;
}

/*
 * myExit:cleanup function of the kernel module
 */
static void myExit(void)
{
	printk(KERN_INFO "Exiting the Character Driver\n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);

