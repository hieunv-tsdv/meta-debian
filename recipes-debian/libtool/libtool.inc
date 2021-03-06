#
# base recipe: meta/recipes-devtools/libtool/libtool-2.4.2.inc
# base branch: daisy
# 

SUMMARY = "Generic library support script"
DESCRIPTION = "This is GNU libtool, a generic library support script. \
Libtool hides the complexity of generating special library types \
(such as shared libraries) behind a consistent interface."
HOMEPAGE = "http://www.gnu.org/software/libtool/libtool.html"

INC_PR = "r1"

inherit  debian-package autotools

LICENSE = "GPLv2 & LGPLv2.1"
LIC_FILES_CHKSUM = "\
file://COPYING;md5=751419260aa954499f7abaabaa882bbe \
file://libltdl/COPYING.LIB;md5=e3eda01d9815f8d24aae2dbd89b68b06 \
"

SRC_URI += "\
file://trailingslash.patch \
file://rename-with-sysroot.patch \
file://use-sysroot-in-libpath.patch \
file://fix-final-rpath.patch \
file://avoid_absolute_paths_for_general_utils.patch \
file://fix-rpath.patch \
file://respect-fstack-protector.patch \
file://norm-rpath.patch \
file://dont-depend-on-help2man-edited.patch \
file://fix-resolve-lt-sysroot.patch \
"

EXTRA_AUTORECONF = "--exclude=libtoolize"

DEPENDS = "libtool-native"

do_compile_prepend () {                                                         
        # Sometimes this file doesn't get rebuilt, force the issue              
        rm -f ${S}/libltdl/config/ltmain.sh                                     
        make libltdl/config/ltmain.sh                                           
        ./config.status                                                         
} 

PACKAGES =+ "libltdl libltdl-dev libltdl-dbg libltdl-staticdev"                 
FILES_${PN} += "${datadir}/aclocal"                                             
FILES_${PN}-dev = "${includedir} ${FILES_SOLIBSDEV} ${libdir}/*.la \            
                ${libdir}/*.o ${libdir}/pkgconfig ${datadir}/pkgconfig \        
                ${base_libdir}/*.o ${libdir}/${BPN}/*.la ${base_libdir}/*.la"   
                                                                                
FILES_libltdl = "${libdir}/libltdl${SOLIBS}"                                    
FILES_libltdl-dev = "${libdir}/libltdl${SOLIBSDEV} ${includedir}"               
FILES_libltdl-staticdev = "${libdir}/libltdl.a"                                 
