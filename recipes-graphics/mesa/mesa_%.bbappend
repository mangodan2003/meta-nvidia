EXTRA_OEMESON_append_intel-corei7-64 = " -Dglvnd=true"
DEPENDS_append_intel-corei7-64 = " libglvnd"
PROVIDES_intel-corei7-64 = "virtual/mesa virtual/libgbm"

# Workaround for the do_install_append() present in the OE-Core recipe
do_install_prepend_intel-corei7-64() {
    install -d ${D}${includedir}/EGL
    touch ${D}${includedir}/EGL/eglplatform.h
}

do_install_append_intel-corei7-64() {
    rm -rf ${D}${includedir}/EGL
}

FILES_libegl-mesa_append_intel-corei7-64 = " ${libdir}/libEGL_mesa.so.* ${datadir}/glvnd"
FILES_libegl-mesa-dev_append_intel-corei7-64 = " ${libdir}/libEGL_mesa.so"
FILES_libgl-mesa_append_intel-corei7-64 = " ${libdir}/libGLX_mesa.so.*"
FILES_libgl-mesa-dev_append_intel-corei7-64 = " ${libdir}/libGLX_mesa.so"

DRIDRIVERS_remove_x86_class-target = ",r100,r200,nouveau,i965,i915"
DRIDRIVERS_remove_x86-64_class-target = ",r100,r200,nouveau,i965,i915"

python __anonymous() {
    if "intel-corei7-64" not in d.getVar('OVERRIDES').split(':'):
        return
    pkgconfig = (d.getVar('PACKAGECONFIG') or '').split();
    for p in (("egl", "libegl", "libegl1"),
              ("dri", "libgl", "libgl1"),
              ("gles", "libgles1", "libglesv1-cm1"),
              ("gles", "libgles2", "libglesv2-2"),
              ("gles", "libgles3",)):
        if not p[0] in pkgconfig:
            continue
        fullp = p[1] + "-mesa"
        d.delVar("RREPLACES_" + fullp)
        d.delVar("RPROVIDES_" + fullp)
        d.delVar("RCONFLICTS_" + fullp)

        # For -dev, the first element is both the Debian and original name
        fullp += "-dev"
        d.delVar("RREPLACES_" + fullp)
        d.delVar("RPROVIDES_" + fullp)
        d.delVar("RCONFLICTS_" + fullp)
}
