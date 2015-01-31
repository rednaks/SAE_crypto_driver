# Global makefile.

CRYPTO_MOD := cryptage/cryptage
COMM_MOD:= comm/comm

all: $(CRYPTO_MOD) $(COMM_MOD)
	@echo "Compilation terminée"

$(CRYPTO_MOD): $(CRYPTO_MOD).c
	@echo "Compilation du module cryptage"
	cd cryptage && make
	@echo "Compilation du module cryptage terminée"

$(COMM_MOD): $(COMM_MOD).c
	@echo "Compilation du module comm"
	cd comm && make
	@echo "Compilation du module comm"



install: $(CRYPTO_MOD) $(COMM_MOD)
	@echo "Installation du module cryptage"
	cd cryptage && make install
	@echo "Installation du module comm"
	cd comm && make install

reload:
	cd comm && make remove
	cd cryptage && make remove
	cd cryptage && make install
	cd comm && make install

clean:
	cd cryptage && make clean
	cd comm && make clean

test:
	@echo "Test crypt_cesar"
	echo -n "AB" > /dev/comm0
	@echo "Test crypt_rot13"
	echo -n "AB" > /dev/comm1
	@echo "vous pouvez vérifier avec la commande |dmesg|"
	@echo "Si vous aurez comme résultat réspectif : 'DE' et 'NO' alors tous va bien :)"
