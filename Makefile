# Global makefile.

CRYPTO_MOD := cryptage/cryptage

all: $(CRYPTO_MOD)
	@echo "Compilation terminée"

$(CRYPTO_MOD): $(CRYPTO_MOD).c
	@echo "Compilation du module cryptage"
	cd cryptage && make
	@echo "Compilation du module cryptage terminée"

install: $(CRYPTO_MOD)
	@echo "Installation du module cryptage"
	cd cryptage && make install


clean:
	cd cryptage && make clean
