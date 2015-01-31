#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>


extern void crypt_cesar(char*, int);
extern void crypt_rot13(char*, int);

// Ces deux fonction ne seront pas utilisés
// pas spécifié dans l'énnoncé :/
extern void decrypt_cesar(char*, int); 
extern void decrypt_rot13(char*, int);



static int _lread(struct file *f, char *buffer, size_t len, loff_t *ptr);
static int _lwrite(struct file *f, const char *buffer, size_t len, loff_t *ptr);

struct file_operations fops = {
  owner: THIS_MODULE,
  write: _lwrite,
  read: _lread
};



static int __init load_module(void) {
  printk("module COMM chargé !\n");

  register_chrdev(150, "comm", &fops);

  return 0;
}


static void __exit unload_module(void) {
  printk("module COMM déchargé !\n");

  unregister_chrdev(150, "comm");
}

module_init(load_module);
module_exit(unload_module);


MODULE_AUTHOR("Skander Ben Mahmoud");
MODULE_DESCRIPTION("Pilote Examen");
MODULE_LICENSE("GPL");
