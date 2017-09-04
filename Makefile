PREFIX ?= /usr
MANDIR ?= $(PREFIX)/share/man
SYSCONFDIR ?= /etc

all:
	@echo "Run 'make install' to install gsu."

install:
	@echo "Making directories..."
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(MANDIR)/man1
	mkdir -p $(DESTDIR)$(SYSCONFDIR)/gsu

	@echo -e "\nInstalling binaries..."
	sed "s|SYSCONFDIR|$(SYSCONFDIR)/gsu|g" < gsu > $(DESTDIR)$(PREFIX)/bin/gsu
	chmod 755 $(DESTDIR)$(PREFIX)/bin/gsu

	@echo -e "\nInstalling man page and config file..."
	cp -p gsu.1 $(DESTDIR)$(MANDIR)/man1/gsu.1
	cp -p config/config.conf $(DESTDIR)$(SYSCONFDIR)/gsu/config.conf

uninstall:
	@echo "Removing files..."
	rm -rf $(DESTDIR)$(PREFIX)/bin/gsu
	rm -rf $(DESTDIR)$(MANDIR)/man1/gsu.1
	rm -rf $(DESTDIR)$(SYSCONFDIR)/gsu
