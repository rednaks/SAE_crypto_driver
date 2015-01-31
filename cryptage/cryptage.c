#include <linux/module.h>
#include <linux/init.h>

char cesar(char c) {

  char offset = c <= 'Z' ? 'A' : 'a';

  return ((c - offset + 3)%26) + offset;
}

char decesar(char c) {

  char offset = c <= 'Z' ? 'A' : 'a';

  return ((c - offset - 3)%26) + offset;
}

char rot13(char c) {
  return ((c - 97 + 13)%26)+97;
}

char derot13(char c) {
  // car la fonction rot13 est symétrique.
  return rot13(c);
}

/*
   J'ai créé les fonctions cesar, decesar, ro13 et derot13,
   pour garder le code plus lisible.
   Ce n'est pas demandé, vous pouvez directement mettre le code
   dans crypt_cesar, crypt_rot13, ect ...
*/

static void crypt_cesar(char* buffer, int n) {

  int i = 0;

  for(;i<n;i++){
    buffer[i] = cesar(buffer[i]);
  }

}

EXPORT_SYMBOL(crypt_cesar);

static void crypt_rot13(char* buffer, int n) {
  int i = 0;

  for(;i<n;i++){
    buffer[i] = rot13(buffer[i]);
  }
}

EXPORT_SYMBOL(crypt_rot13);

static void decrypt_cesar(char* buffer, int n) {
  int i = 0;

  for(;i<n;i++){
    buffer[i] = decesar(buffer[i]);
  }
}

EXPORT_SYMBOL(decrypt_cesar);

static void decrypt_rot13(char* buffer, int n) {
  int i = 0;

  for(;i<n;i++){
    buffer[i] = derot13(buffer[i]);
  }
}

EXPORT_SYMBOL(decrypt_rot13);

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
