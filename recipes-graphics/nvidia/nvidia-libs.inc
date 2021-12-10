# Jesus fuck, this is complicated.
# Read this first: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

do_install_append() {
	mkdir -p ${D}${libdir}/vdpau

	cp ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so.1
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so

	cp ${NVIDIA_SRC}/libEGL_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0
  
    cp ${NVIDIA_SRC}/libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1

	cp ${NVIDIA_SRC}/libGLESv2_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2

	cp ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0

	cp ${NVIDIA_SRC}/libnvcuvid.so.${PV} ${D}${libdir}/
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so.1
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so

	cp ${NVIDIA_SRC}/libnvidia-allocator.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-allocator.so.${PV} ${D}${libdir}/libnvidia-allocator.so.1
    ln -sf libnvidia-allocator.so.${PV} ${D}${libdir}/libnvidia-allocator.so

	cp ${NVIDIA_SRC}/libnvidia-cbl.so.${PV} ${D}${libdir}/

	cp ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so.1
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so

	cp ${NVIDIA_SRC}/libnvidia-compiler.so.${PV} ${D}${libdir}/
	cp ${NVIDIA_SRC}/libnvidia-eglcore.so.${PV} ${D}${libdir}/

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

	cp ${NVIDIA_SRC}/libnvidia-ifr.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ifr.so.${PV} ${D}${libdir}/libnvidia-ifr.so.1
    ln -sf libnvidia-ifr.so.${PV} ${D}${libdir}/libnvidia-ifr.so

	cp ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so.1
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so

	cp ${NVIDIA_SRC}/libnvidia-ngx.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ngx.so.${PV} ${D}${libdir}/libnvidia-ngx.so.1

	cp ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1

	cp ${NVIDIA_SRC}/libnvidia-opticalflow.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opticalflow.so.${PV} ${D}${libdir}/libnvidia-opticalflow.so.1
    ln -sf libnvidia-opticalflow.so.${PV} ${D}${libdir}/libnvidia-opticalflow.so
    
	cp ${NVIDIA_SRC}/libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/libnvidia-ptxjitcompiler.so.1
    ln -sf libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/libnvidia-ptxjitcompiler.so

	cp ${NVIDIA_SRC}/libnvidia-rtcore.so.${PV} ${D}${libdir}/
	cp ${NVIDIA_SRC}/libnvidia-tls.so.${PV} ${D}${libdir}/
	
    cp ${NVIDIA_SRC}/libnvoptix.so.${PV} ${D}${libdir}/
    ln -sf libnvoptix.so.${PV} ${D}${libdir}/libnvoptix.so.1

	cp ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/vdpau/libvdpau_nvidia.so.1
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/libvdpau_nvidia.so



    # xf86-video-nvidia
	#cp -r ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/
	#cp -r ${NVIDIA_SRC}/libglxserver_nvidia.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglxserver_nvidia.so

    # nvidia
	mkdir -p ${D}${bindir}
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe
    install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-ngx-updater ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-installer ${D}${bindir}/nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-bug-report.sh ${D}${bindir}/nvidia-persistenced

    # nvidia-doc
	mkdir -p ${D}${datadir}/doc/nvidia ${D}${mandir}/man1
    cp -r ${NVIDIA_SRC}/html ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/nvidia-settings.png ${D}${datadir}/doc/nvidia/
    cp -r ${NVIDIA_SRC}/supported-gpus ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/nvidia-persistenced-init.tar.bz2 ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/LICENSE ${D}${datadir}/doc/nvidia/


    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-installer.1.gz ${D}${mandir}/man1/nvidia-installer.1.gz
}

do_make_scripts[noexec] = "1"

FILES_${PN} += " \
    ${libdir}/vdpau \
    ${libdir}/*.so* \
	${bindir} \
"

FILES_${PN}-doc += " \
	${mandir} \
	${datadir}/doc/nvidia \
"

RDEPENDS_${PN} += " \
    libvdpau \
"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN}_append = "ldflags already-stripped"
INSANE_SKIP_libgl-nvidia_append = "ldflags"
