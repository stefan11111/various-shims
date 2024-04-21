all:
	mkdir -p ${DESTDIR}/usr/bin

vala:
	touch ${DESTDIR}/usr/bin/vala
	chmod 755 ${DESTDIR}/usr/bin/vala

xmlto:
	touch ${DESTDIR}/usr/bin/xmlto
	chmod 755 ${DESTDIR}/usr/bin/xmlto

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
gettext:
	${CC} ${CFLAGS}  gettext/gettext_program.c -o gettext/gettext_program
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/xgettext
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgmerge
	cp -f gettext/gettext_program ${DESTDIR}/usr/bin/msgfmt
	ln -rsf ${DESTDIR}/usr/bin/msgfmt ${DESTDIR}/usr/bin/gmsgfmt

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

.PHONY: all vala xmlto intltool gettext dbus
