#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>


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

static int _lread(struct file *f, char *buffer, size_t len, loff_t *ptr) {
  // Pas implémenté car le comportement n'est pas spécifié dans
  // l'énnoncé :/
  return 0;
}


static int _lwrite(struct file *f, const char *buffer, size_t len, loff_t *ptr) {

  if(len > 256) {
    printk("Erreur dépassement de la taille du buffer :( \n");
    return len;
  }

  /* On récupérer le numéro mineur pour décider
     quel algorithme on va utiliser */
  int minor = MINOR(f->f_dentry->d_inode->i_rdev);

  // Allocation du buffer de taille ne dépassant pas 256
  char buf[len];

  unsigned long res = copy_from_user(buf, buffer, len);
  if(res){
    printk("COMM : Copy not successfull : Aborting :( ...\n");
    return len;
  }


  if(minor == 0){
    // cesar !!
    crypt_cesar(buf, len);
  }else if (minor == 1)
  {
    // rot13
    crypt_rot13(buf, len);
  }

  buf[len] = '\0';
  printk("%s\n", buf);

  return len;
}


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
