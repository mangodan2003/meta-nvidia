LICENSE = "BSD-3-Clause"
DESCRIPTION = "Device Create the nvidia nodes"
LIC_FILES_CHKSUM = "file://ub-device-create.c;md5=8b0b11ed56735e748b6a58665546123f"

DEPENDS = "libpciaccess kmod"

SRC_URI = "file://ub-device-create.c \
           file://71-nvidia.rules \
		   "

inherit pkgconfig

do_compile() {
	${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/ub-device-create.c -o ub-device-create `pkg-config --cflags --libs pciaccess libkmod`
}

do_install() {
	install -d ${D}${bindir}
    install -d ${D}${sysconfdir}/udev/rules.d
	install -m 0755 ub-device-create ${D}${bindir}
	install -m 0644 ${WORKDIR}/71-nvidia.rules ${D}${sysconfdir}/udev/rules.d/
}

S = "${WORKDIR}"

NATIVE_INSTALL_WORKS = "1"

BBCLASSEXTEND = "native nativesdk"