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