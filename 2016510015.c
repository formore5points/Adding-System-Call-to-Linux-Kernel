#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>      // Needed by filp
#include <asm/uaccess.h>   // Needed by segment descriptors

/* This function is called when the module is loaded. */
int simple_init(void) { //module entry point
	// Create variables
    struct file *f;
    char buf[128];
    mm_segment_t fs;
    int i;
    // Init the buffer with 0
    for(i=0;i<128;i++)
        buf[i] = 0;
    // To see in /var/log/messages that the module is operating
    printk(KERN_INFO "My module is loaded\n");
    // I am using Fedora and for the test I have chosen following file
    // Obviously it is much smaller than the 128 bytes, but hell with it =)
    f = filp_open("/proc/cpuinfo", O_RDONLY, 0);
    if(f == NULL)
        printk(KERN_ALERT "filp_open error!!.\n");
    else{
        // Get current segment descriptor
        fs = get_fs();
        // Set segment descriptor associated to kernel space
        set_fs(get_ds());
        // Read the file
        f->f_op->read(f, buf, 128, &f->f_pos);
        // Restore segment descriptor
        set_fs(fs);
        // See what we read from file
        printk(KERN_INFO "buf:%s\n",buf);
    }
    filp_close(f,NULL);

	return 0; //represents success and any other value failure.
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	//is the kernel equivalent of printf(),its output is sent to a kernel log buffer
}

/* Macros for registering module entry and exit points. */
module_init(simple_init); //when the module is loaded into the kernel.
module_exit(simple_exit); //when the module is removed from the kernel.

MODULE_LICENSE("GPL"); //software license
MODULE_DESCRIPTION("Simple Kernel Module"); //description of the module
MODULE_AUTHOR("DEUCENG"); //author

