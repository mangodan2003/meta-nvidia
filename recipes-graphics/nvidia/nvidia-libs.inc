# Jesus fuck, this is complicated.
# Read this first: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

do_install:append() {
    mkdir -p ${D}${libdir}/vdpau
    mkdir -p ${D}${libdir}/gbm
    mkdir -p ${D}${libdir}/xorg/modules/extensions/
    mkdir -p ${D}${libdir}/xorg/modules/drivers
    mkdir -p ${D}${libdir}/nvidia/wine/
    mkdir -p ${D}${datadir}/doc/nvidia/
    mkdir -p ${D}${datadir}/nvidia/
    mkdir -p ${D}${datadir}/glvnd/egl_vendor.d/
    mkdir -p ${D}${datadir}/egl/egl_external_platform.d/

    # nvidia-egl
    cp ${NVIDIA_SRC}/10_nvidia.json ${D}${datadir}/glvnd/egl_vendor.d/
    cp ${NVIDIA_SRC}/10_nvidia_wayland.json ${D}${datadir}/egl/egl_external_platform.d/
    cp ${NVIDIA_SRC}/15_nvidia_gbm.json ${D}${datadir}/egl/egl_external_platform.d/

    # nvidia lib
    cp ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so.1

    cp ${NVIDIA_SRC}/libEGL_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0
  
    cp ${NVIDIA_SRC}/libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1

    cp ${NVIDIA_SRC}/libGLESv2_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2

    cp ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0

    #didn't know how t create the symlink, then just copied
    cp ${NVIDIA_SRC}/libglxserver_nvidia.so.${PV} ${D}${libdir}/xorg/modules/extensions/
    cp ${NVIDIA_SRC}/libglxserver_nvidia.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglxserver_nvidia.so
    cp ${NVIDIA_SRC}/libnvidia-allocator.so.${PV} ${D}${libdir}/gbm/nvidia-drm_gbm.so

    cp ${NVIDIA_SRC}/libnvcuvid.so.${PV} ${D}${libdir}/
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so.1
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so

    cp ${NVIDIA_SRC}/libnvidia-allocator.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-allocator.so.${PV} ${D}${libdir}/libnvidia-allocator.so.1
    ln -sf libnvidia-allocator.so.${PV} ${D}${libdir}/libnvidia-allocator.so

    cp ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so.1
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so

    cp ${NVIDIA_SRC}/libnvidia-compiler.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-eglcore.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-egl-gbm.so.1.1.0 ${D}${libdir}/
    ln -sf libnvidia-egl-gbm.so.1.1.0 ${D}${libdir}/libnvidia-egl-gbm.so.1

    cp ${NVIDIA_SRC}/libnvidia-egl-wayland.so.1.1.9 ${D}${libdir}/
    ln -sf libnvidia-egl-wayland.so.1.1.9 ${D}${libdir}/libnvidia-egl-wayland.so.1

    cp ${NVIDIA_SRC}/libnvidia-encode.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-encode.so.${PV} ${D}${libdir}/libnvidia-encode.so.1
    ln -sf libnvidia-encode.so.${PV} ${D}${libdir}/libnvidia-encode.so

    cp ${NVIDIA_SRC}/libnvidia-fbc.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-fbc.so.${PV} ${D}${libdir}/libnvidia-fbc.so.1
    ln -sf libnvidia-fbc.so.${PV} ${D}${libdir}/libnvidia-fbc.so

    cp ${NVIDIA_SRC}/libnvidia-glcore.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-glsi.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-glvkspirv.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-gtk2.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-gtk3.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so.1
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so
    
    cp ${NVIDIA_SRC}/libnvidia-ngx.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ngx.so.${PV} ${D}${libdir}/libnvidia-ngx.so.1

    cp ${NVIDIA_SRC}/libnvidia-nvvm.so.4.0.0 ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1

    cp ${NVIDIA_SRC}/libnvidia-opticalflow.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opticalflow.so.${PV} ${D}${libdir}/libnvidia-opticalflow.so.1
    ln -sf libnvidia-opticalflow.so.${PV} ${D}${libdir}/libnvidia-opticalflow.so
    
    cp ${NVIDIA_SRC}/libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/libnvidia-ptxjitcompiler.so.1
    ln -sf libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/libnvidia-ptxjitcompiler.so

    cp ${NVIDIA_SRC}/libnvidia-rtcore.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-rtcore.so.${PV} ${D}${libdir}/libnvidia-rtcore.so.1
    ln -sf libnvidia-rtcore.so.${PV} ${D}${libdir}/libnvidia-rtcore.so

    cp ${NVIDIA_SRC}/libnvidia-tls.so.${PV} ${D}${libdir}/

    cp ${NVIDIA_SRC}/libnvidia-vulkan-producer.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-vulkan-producer.so.${PV} ${D}${libdir}/libnvidia-vulkan-producer.so
    
    cp ${NVIDIA_SRC}/libnvoptix.so.${PV} ${D}${libdir}/
    ln -sf libnvoptix.so.${PV} ${D}${libdir}/libnvoptix.so.1

    cp ${NVIDIA_SRC}/libOpenCL.so.1.0.0 ${D}${libdir}/

    cp ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/libvdpau_nvidia.so.1
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/libvdpau_nvidia.so

    cp ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/

    # nvidia - bin
    mkdir -p ${D}${bindir}
    install -m 755 -D ${NVIDIA_SRC}/nvidia-bug-report.sh ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-installer ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe
    install -m 755 -D ${NVIDIA_SRC}/nvidia-ngx-updater ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig

    # nvidia-doc
    cp ${NVIDIA_SRC}/LICENSE ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/nvidia-persistenced-init.tar.bz2 ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/nvidia-settings.png ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    cp -r ${NVIDIA_SRC}/supported-gpus ${D}${datadir}/doc/nvidia/

    # nvidia-share
    cp ${NVIDIA_SRC}/nvidia-application-profiles-495.46-key-documentation ${D}${datadir}/nvidia/
    cp ${NVIDIA_SRC}/nvidia-application-profiles-495.46-rc ${D}${datadir}/nvidia/

    #nvidia-gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-installer.1.gz ${D}${mandir}/man1/nvidia-installer.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-modprobe.1.gz ${D}${mandir}/man1/nvidia-modprobe.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    
    #wine
    cp ${NVIDIA_SRC}/_nvngx.dll ${D}${libdir}/nvidia/wine/
    cp ${NVIDIA_SRC}/nvngx.dll ${D}${libdir}/nvidia/wine/

    cp -r ${NVIDIA_SRC}/html ${D}${datadir}/doc/nvidia/
}

do_make_scripts[noexec] = "1"

FILES:${PN} += " \
    ${libdir}/xorg/modules/extensions/ \
    ${libdir}/xorg/modules/drivers \
    ${libdir}/nvidia/wine/ \
    ${libdir}/vdpau \
    ${libdir}/gbm \
    ${libdir}/*.so* \
    ${bindir} \ 
    ${datadir}/glvnd/egl_vendor.d/ \
    ${datadir}/egl/egl_external_platform.d/ \
    ${mandir} \
    ${datadir}/doc/nvidia \
    ${datadir}/nvidia/ \
    /lib64 \
"

RDEPENDS:${PN} += " \
    libvdpau \
"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP:${PN}:append = "ldflags already-stripped"
INSANE_SKIP:libgl-nvidia:append = "ldflags"
