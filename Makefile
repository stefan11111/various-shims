all:
	mkdir -p ${DESTDIR}/usr/bin

vala:
	touch ${DESTDIR}/usr/bin/vala
	chmod 755 ${DESTDIR}/usr/bin/vala
	touch ${DESTDIR}/usr/bin/valac
	chmod 755 ${DESTDIR}/usr/bin/valac

xmlto:
	touch ${DESTDIR}/usr/bin/xmlto
	chmod 755 ${DESTDIR}/usr/bin/xmlto

itstool:
	${CC} ${CFLAGS}  itstool/itstool.c -o itstool/itstool
	cp -f itstool/itstool ${DESTDIR}/usr/bin/itstool

intltool:
#	touch ${DESTDIR}/usr/bin/intltool-update
#	chmod 755 ${DESTDIR}/usr/bin/intltool-update
#	touch ${DESTDIR}/usr/bin/intltool-merge
#	chmod 755 ${DESTDIR}/usr/bin/intltool-merge
#	touch ${DESTDIR}/usr/bin/intltool-extract
#	chmod 755 ${DESTDIR}/usr/bin/intltool-extract

	${CC} ${CFLAGS}  intltool/intltool_program.c -o intltool/intltool_program
	cp -f intltool/intltool_program ${DESTDIR}/usr/bin/intltool-update
	cp -f intltool/intltool_program ${DESTDIR}/usr/bin/intltool-merge
	cp -f intltool/intltool_program ${DESTDIR}/usr/bin/intltool-extract
	touch ${DESTDIR}/usr/bin/intltool-prepare
	chmod 755 ${DESTDIR}/usr/bin/intltool-prepare
	touch ${DESTDIR}/usr/bin/intltoolize
	chmod 755 ${DESTDIR}/usr/bin/intltoolize
gettext:
	${CC} ${CFLAGS}  gettext/gettext_program.c -o gettext/gettext_program
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/xgettext
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgmerge
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgfmt
	ln -rsf ${DESTDIR}/usr/bin/msgfmt ${DESTDIR}/usr/bin/gmsgfmt
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msginit
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgattrib
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgcat
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgcomm
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgconv
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgen
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgfilter
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msggrep
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgunfmt
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msguniq
	${CC} ${CFLAGS}  gettext/gettext.c -o gettext/gettext
	cp -f gettext/gettext ${DESTDIR}/usr/bin/gettext
	ln -rsf ${DESTDIR}/usr/bin/gettext ${DESTDIR}/usr/bin/ngettext
	${CC} ${CFLAGS} -fPIC -nostdlib gettext/libgettextpo.c -o gettext/libgettextpo.so.0.5.10 ${LDFLAGS}-shared -Wl,-soname,libgettextpo.so.0
	mkdir -p ${DESTDIR}/usr/lib64
	cp -f gettext/libgettextpo.so.0.5.10 ${DESTDIR}/usr/lib64/libgettextpo.so.0.5.10
	ln -rsf ${DESTDIR}/usr/lib64/libgettextpo.so.0.5.10 ${DESTDIR}/usr/lib64/libgettextpo.so.0
	touch ${DESTDIR}/usr/bin/autopoint
	chmod 755 ${DESTDIR}/usr/bin/autopoint
	touch ${DESTDIR}/usr/bin/envsubst
	chmod 755 ${DESTDIR}/usr/bin/envsubst
	touch ${DESTDIR}/usr/bin/gettextize
	chmod 755 ${DESTDIR}/usr/bin/gettextize
	touch ${DESTDIR}/usr/bin/msgcmp
	chmod 755 ${DESTDIR}/usr/bin/msgcmp
	touch ${DESTDIR}/usr/bin/msgexec
	chmod 755 ${DESTDIR}/usr/bin/msgexec
	touch ${DESTDIR}/usr/bin/recode-sr-latin
	chmod 755 ${DESTDIR}/usr/bin/recode-sr-latin

dbus:
	touch ${DESTDIR}/usr/bin/dbus-cleanup-sockets
	chmod 755 ${DESTDIR}/usr/bin/dbus-cleanup-sockets
	touch ${DESTDIR}/usr/bin/dbus-daemon
	chmod 755 ${DESTDIR}/usr/bin/dbus-daemon
	touch ${DESTDIR}/usr/bin/dbus-launch
	chmod 755 ${DESTDIR}/usr/bin/dbus-launch
	touch ${DESTDIR}/usr/bin/dbus-monitor
	chmod 755 ${DESTDIR}/usr/bin/dbus-monitor
	touch ${DESTDIR}/usr/bin/dbus-run-session
	chmod 755 ${DESTDIR}/usr/bin/dbus-run-session
	touch ${DESTDIR}/usr/bin/dbus-send
	chmod 755 ${DESTDIR}/usr/bin/dbus-send
	touch ${DESTDIR}/usr/bin/dbus-test-tool
	chmod 755 ${DESTDIR}/usr/bin/dbus-test-tool
	touch ${DESTDIR}/usr/bin/dbus-update-activation-environment
	chmod 755 ${DESTDIR}/usr/bin/dbus-update-activation-environment
	touch ${DESTDIR}/usr/bin/dbus-uuidgen
	chmod 755 ${DESTDIR}/usr/bin/dbus-uuidgen

.PHONY: all vala xmlto itstool intltool gettext dbus
