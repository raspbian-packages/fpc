FPC_VERSION=$(shell ${PP} -iV)

all:	de

clean:
	@rm -f *.mo *.pot

de:
	msgfmt fpdoc.de.po dwriter.de.po -o fpdoc.de.mo
	msgfmt dglobals.de.po -o dglobals.de.mo
	msgfmt makeskel.de.po -o makeskel.de.mo
	msgfmt fpdocmk.de.po -o fpdocmk.de.mo

pot:
	rstconv -i ../dglobals.rst -o dglobals.pot
	rstconv -i ../dwriter.rst -o dwriter.pot
	rstconv -i ../fpdoc.rst -o fpdoc.pot
	rstconv -i ../makeskel.rst -o makeskel.pot
	rstconv -i ../fpdocmk.rst -o fpdocmk.pot

install: de
	install -D -m 0644 fpdoc.de.mo ${INSTALL_PREFIX}/share/locale/de/LC_MESSAGES/fpdoc-${FPC_VERSION}.mo
	install -D -m 0644 dglobals.de.mo ${INSTALL_PREFIX}/share/locale/de/LC_MESSAGES/dglobals-${FPC_VERSION}.mo
	install -D -m 0644 makeskel.de.mo ${INSTALL_PREFIX}/share/locale/de/LC_MESSAGES/makeskel-${FPC_VERSION}.mo
	install -D -m 0644 fpdocmk.de.mo ${INSTALL_PREFIX}/share/locale/de/LC_MESSAGES/fpdocmk-${FPC_VERSION}.mo
