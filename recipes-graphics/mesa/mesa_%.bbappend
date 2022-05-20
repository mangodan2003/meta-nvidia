EXTRA_OEMESON:append_intel-corei7-64 = " -Dglvnd=true"
DEPENDS:append_intel-corei7-64 = " libglvnd"
PROVIDES_intel-corei7-64 = "virtual/mesa virtual/libgbm"

# Workaround for the do_install:append() present in the OE-Core recipe
do_install:prepend_intel-corei7-64() {
    install -d ${D}${includedir}/EGL
    touch ${D}${includedir}/EGL/eglplatform.h
}

do_install:append_intel-corei7-64() {
    rm -rf ${D}${includedir}/EGL
}

FILES:libegl-mesa:append_intel-corei7-64 = " ${libdir}/libEGL_mesa.so.* ${datadir}/glvnd"
FILES:libegl-mesa-dev:append_intel-corei7-64 = " ${libdir}/libEGL_mesa.so"
FILES:libgl-mesa:append_intel-corei7-64 = " ${libdir}/libGLX_mesa.so.*"
FILES:libgl-mesa-dev:append_intel-corei7-64 = " ${libdir}/libGLX_mesa.so"

DRIDRIVERS:remove:x86:class-target = ",r100,r200,nouveau,i965,i915"
DRIDRIVERS:remove:x86-64:class-target = ",r100,r200,nouveau,i965,i915"

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
        d.delVar("RREPLACES:" + fullp)
        d.delVar("RPROVIDES:" + fullp)
        d.delVar("RCONFLICTS:" + fullp)

        # For -dev, the first element is both the Debian and original name
        fullp += "-dev"
        d.delVar("RREPLACES:" + fullp)
        d.delVar("RPROVIDES:" + fullp)
        d.delVar("RCONFLICTS:" + fullp)
}
