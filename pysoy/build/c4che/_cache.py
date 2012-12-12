AR = '/usr/bin/ar'
ARFLAGS = 'rcs'
BINDIR = '/usr/local/bin'
CC = ['/usr/bin/gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_PYEMBED = ['-fwrapv', '-fstack-protector', '-fno-strict-aliasing']
CFLAGS_PYEXT = ['-pthread', '-fwrapv', '-fstack-protector', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing']
CFLAGS_SOY = ['-pthread', '-pthread']
CFLAGS_cshlib = ['-fPIC']
COMPILER_CC = 'gcc'
CPPPATH_ST = '-I%s'
CXXFLAGS_PYEMBED = ['-fwrapv', '-fstack-protector']
CXXFLAGS_PYEXT = ['-pthread', '-fwrapv', '-fstack-protector', '-fwrapv', '-fstack-protector']
CXXFLAGS_SOY = ['-pthread', '-pthread']
DEFINES = ['PYTHONDIR="/usr/local/lib/python3/dist-packages"', 'PYTHONARCHDIR="/usr/local/lib/python3/dist-packages"', 'HAVE_PYTHON_H=1']
DEFINES_EGL = ['HAVE_EGL=1']
DEFINES_PYEMBED = ['NDEBUG']
DEFINES_PYEXT = ['NDEBUG', 'NDEBUG']
DEFINES_SOY = ['HAVE_SOY=1']
DEFINES_ST = '-D%s'
DEFINES_X11 = ['HAVE_X11=1']
DEFINES_XI = ['HAVE_XI=1']
DEFINES_XXF86VM = ['HAVE_XXF86VM=1']
DEST_BINFMT = 'elf'
DEST_CPU = 'x86'
DEST_OS = 'linux'
INCLUDES_EGL = ['/usr/include/libdrm']
INCLUDES_PYEMBED = ['/usr/include/python3.3m', '/usr/include/i386-linux-gnu/python3.3m']
INCLUDES_PYEXT = ['/usr/include/python3.3m', '/usr/include/i386-linux-gnu/python3.3m']
INCLUDES_SOY = ['/usr/local/include/soy-1', '/usr/include/glib-2.0', '/usr/lib/i386-linux-gnu/glib-2.0/include', '/usr/include/gee-1.0', '/usr/include/dbus-1.0', '/usr/include/librsvg-2.0', '/usr/include/nice', '/usr/lib/i386-linux-gnu/dbus-1.0/include', '/usr/include/gdk-pixbuf-2.0', '/usr/include/cairo', '/usr/include/libpng12', '/usr/include/pixman-1', '/usr/include/freetype2', '/usr/include/loudmouth-1.0']
LIBDIR = '/usr/local/lib'
LIBPATH_PYEMBED = ['/usr/lib/python3.3/config-3.3m-i386-linux-gnu']
LIBPATH_PYEXT = ['/usr/lib/python3.3/config-3.3m-i386-linux-gnu']
LIBPATH_PYTHON3.3 = ['/usr/lib/python3.3/config-3.3m-i386-linux-gnu']
LIBPATH_SOY = ['/usr/local/lib']
LIBPATH_ST = '-L%s'
LIB_EGL = ['EGL']
LIB_PYEMBED = ['python3.3']
LIB_PYEXT = ['python3.3']
LIB_PYTHON3.3 = ['python3.3']
LIB_SOY = ['soy', 'gee', 'dbus-glib-1', 'rsvg-2', 'm', 'bluetooth', 'loudmouth-1', 'idn', 'nice', 'gthread-2.0', 'rt', 'dbus-1', 'gio-2.0', 'gdk_pixbuf-2.0', 'cairo', 'gobject-2.0', 'glib-2.0']
LIB_ST = '-l%s'
LIB_X11 = ['X11']
LIB_XI = ['Xi']
LIB_XXF86VM = ['Xxf86vm']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_PYEMBED = ['-Wl,-Bsymbolic-functions', '-Wl,-z,relro']
LINKFLAGS_PYEXT = ['-Wl,-Bsymbolic-functions', '-Wl,-z,relro', '-pthread', '-Wl,-O1', '-Wl,-Bsymbolic-functions', '-Wl,-Bsymbolic-functions', '-Wl,-z,relro']
LINKFLAGS_SOY = ['-pthread', '-pthread']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['/usr/bin/gcc']
LINUX = 1
PACKAGE = 'pysoy'
PKGCONFIG = '/usr/bin/pkg-config'
PREFIX = '/usr/local'
PYC = 1
PYCMD = '"import sys, py_compile;py_compile.compile(sys.argv[1], sys.argv[2])"'
PYFLAGS = ''
PYFLAGS_OPT = '-O'
PYO = 1
PYTHON = ['/usr/bin/python3']
PYTHONARCHDIR = '/usr/local/lib/python3/dist-packages'
PYTHONDIR = '/usr/local/lib/python3/dist-packages'
PYTHON_CONFIG = '/usr/bin/python3-config'
PYTHON_VERSION = '3.3'
RPATH_ST = '-Wl,-rpath,%s'
SHLIB_MARKER = '-Wl,-Bdynamic'
SONAME_ST = '-Wl,-h,%s'
SPHINX_BUILD = '/usr/bin/sphinx-build'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = '-Wl,-Bstatic'
STLIB_ST = '-l%s'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
define_key = ['PYTHONDIR', 'PYTHONARCHDIR', 'HAVE_PYTHON_H']
macbundle_PATTERN = '%s.bundle'
pyext_PATTERN = '%s.cpython-33m.so'
