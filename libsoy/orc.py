#!/usr/bin/env python
# encoding: utf-8
#
#   Waf tool for orc
#   Copyright (C) 2010,2011,2012 Copyleft Games Group
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

import os.path, shutil
from waflib import Context, Task, Runner, Utils, Logs, Build, Node, Options, Errors
from waflib.TaskGen import extension
from waflib.Configure import conf


class orcc (Task.Task) :
    ext_out = ['.s']

    def run (self) :
        # generate command string for targets
        arch_targets = ' --target '.join(self.arch_targets)
        if arch_targets :
            arch_targets = '--target ' + arch_targets

        # generate .s file for every .orc input file
        for input in self.inputs :
            # generate assembly (.s)
            ret = self.exec_command('%s --assembly %s -o %s %s' % (
                                    self.env['ORCC'],
                                    arch_targets,
                                    input.change_ext('.s').abspath(),
                                    input.abspath()))

            # return error code if not successful
            if ret != 0 :
                return ret

        # if it gets this far, everything went well
        return 0


@extension('.orc')
def orc_file (self, node) :
    orctask = getattr(self, "orctask", None)

    if not orctask :
        orctask = self.create_task('orcc')
        self.orctask = orctask
        orctask.arch_targets = getattr(self, 'arch_targets', ['mmx', 'sse'])
        orctask.target = self.target

    env = orctask.env
    output_nodes = []

    s_node = node.change_ext('.s')
    output_nodes.append(s_node)
    self.source.append(s_node)

    orctask.inputs.append(node)
    orctask.outputs.extend(output_nodes)


@conf
def check_orc (self) :
    orcc = self.find_program('orcc', var='ORCC', mandatory=True)

def configure (self) :
	self.load('gnu_dirs')
	self.check_orc()

