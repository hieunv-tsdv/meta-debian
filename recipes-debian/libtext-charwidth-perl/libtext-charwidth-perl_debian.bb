# base recipe: not base recipe
# base branch:

PR = "r0"
inherit debian-package

LICENSE = "GPLv1+ & Artistic-1.0"
LIC_FILES_CHKSUM = "file://README;beginline=50;md5=e3cf8a40071097069c8423fef7600df2"

DEPENDS = "perl"
inherit cpan