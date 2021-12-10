SRC_URI_remove_intel-corei7-64 = " file://0001-Add-EGL-and-GLES2-extensions-for-Tegra.patch \
    "
COMPATIBLE_MACHINE = "(tegra|intel-corei7-64)"

DEPENDS_remove_intel-corei7-64 = "l4t-nvidia-glheaders"
