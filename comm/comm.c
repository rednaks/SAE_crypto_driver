#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>



static int __init load_module(void) {
  printk("module COMM chargé !\n");
  return 0;
}


static void __exit unload_module(void) {
  printk("module COMM déchargé !\n");
}

module_init(load_module);
module_exit(unload_module);


MODULE_AUTHOR("Skander Ben Mahmoud");
MODULE_DESCRIPTION("Pilote Examen");
MODULE_LICENSE("GPL");
