#!/usr/bin/env python3
''' PySoy's compile and install script '''
__credits__ = '''Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program; if not, see http://www.gnu.org/licenses
'''
__author__  = 'Copyleft Games Group'
__version__ = '1.0_beta3'

import os, sys
from distutils.core import setup
from distutils.extension import Extension

# sphinx setup
from sphinx.setup_command import BuildDoc
cmdclass = {'build_docs': BuildDoc}


# PySoy only supports Python 3.1+
# Removing this test will only cause it to fail during build on Python 2.x
# 
if sys.version_info[0] != 3 or sys.version_info[1] == 0 :
    raise RuntimeError('Python 3.1+ is required for this package.')

from subprocess import getstatusoutput


def sources (sources_dir) :
    ''' This is a source list generator

    It scans a sources directory and returns every .c file it encounters.
    '''
    for name in os.listdir(sources_dir) :
        subdir = os.path.join(sources_dir, name)
        if os.path.isdir(subdir) :
            for source in os.listdir(subdir) :
                if os.path.splitext(source)[1] == '.c' :
                    yield os.path.join(subdir, source)
        else :
            if os.path.splitext(subdir)[1] == '.c' :
                yield subdir

    # close the generator
    return


# This uses pkg-config to pull Extension config based on packages needed
def pkgconfig (*pkglist, **kw) :
    flag_map = {'-I': 'include_dirs', '-L': 'library_dirs', '-l': 'libraries'}
    pkgs = ' '.join(pkglist)
    status, output = getstatusoutput("pkg-config --libs --cflags %s" % pkgs)
    if status != 0 :
        raise OSError('Package(s) Not Found\n\n%s' % output)
    for token in output.split() :
        if token[:2] in flag_map :
            kw.setdefault(flag_map.get(token[:2]), []).append(token[2:])
        else :
            kw.setdefault('extra_compile_args', []).append(token)
    return kw

name = 'PySoy'

if __name__ == '__main__' : setup(
  #
  #############################################################################
  #
  # PyPI settings (for pypi.python.org)
  #
  name             = name,
  version          = __version__,
  description      = 'Cloud 3D Game Engine for Python',
  long_description = ''' ''',
  author           = __author__,
  maintainer       = 'Arc Riley',
  url              = 'http://www.pysoy.org/',
  download_url     = 'http://hg.pysoy.org/pysoy',
  license          = 'GNU Affero General Public License version 3 (AGPLv3)',
  classifiers      = [
    'Development Status :: 4 - Beta',
    'Intended Audience :: Developers',
    'License :: OSI Approved :: GNU Affero General Public License v3',
    'Natural Language :: English',
    'Topic :: Education',
    'Topic :: Games/Entertainment',
    'Topic :: Multimedia :: Graphics',
    'Topic :: System :: Distributed Computing',
  ],
  #
  #############################################################################
  #
  # Extension settings
  #
  ext_modules = [ Extension(
      name = 'soy',
      sources = [source for source in sources('src')],
      define_macros = [
          ('PYSOY_VERSION', '"%s"' % __version__),
      ],
      **pkgconfig(
          'soy-1.0', 'x11', 'xi', 'xxf86vm', 'egl',
          include_dirs = ['include'],
          extra_compile_args = ['-g'])
  ) ],  
  cmdclass=cmdclass,
  command_options={
        'build_docs': {
            'source_dir': ('setup.py', 'docs'),
            'build_dir': ('setup.py', os.path.join("docs", "build")),
            'project': ('setup.py', name),
            'version': ('setup.py', __version__),
            },
        },
)
