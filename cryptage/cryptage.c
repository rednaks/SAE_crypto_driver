#include <linux/module.h>
#include <linux/init.h>



static int __init load_module(void) {
  printk("module cryptage chargé!");

  return 0;
}

static void __exit unload_module(void) {
  printk("module cryptage déchargé!");
}


module_init(load_module);
module_exit(unload_module);

MODULE_AUTHOR("Skander Ben Mahmoud");
MODULE_DESCRIPTION("Examen");
MODULE_LICENSE("GPL");
