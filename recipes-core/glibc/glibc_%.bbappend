FILES:${PN}:append = " /lib64"

do_install:append () {
    mkdir -p ${D}/lib64
    install -d ${D}/lib64
    ln -s -r ${D}${libdir}/ld-linux-x86-64.so.2 ${D}/lib64/ld-linux-x86-64.so.2 
}