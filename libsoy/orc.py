#!/usr/bin/env python
# encoding: utf-8
# Arc Riley, 2010

import os.path, shutil
from waflib import Context, Task, Runner, Utils, Logs, Build, Node, Options, Errors
from waflib.TaskGen import extension, after_method, before_method
from waflib.Configure import conf

class orc (Task.Task) :
    before = ("cc", "cxx")

    def run (self) :
        # target needs to be made changeable, but for now assume SSE
        target = 'sse'
        cmd_s = '%s --assembly --target %s ' % (self.env['ORCC'], target)
        cmd_h = '%s --header ' % (self.env['ORCC'])

        for input in self.inputs :
            # generate assembly (.s)
            result = self.generator.bld.exec_command(cmd_s + input)
            if result != 0 :
                return result

            # generate header (.h)
            result = self.generator.bld.exec_command(cmd_h + input)
            if result != 0 :
                return result

        # if it gets this far, everything went well
        return 0      


@extension('.orc')
def orc_file(self, node):
    orctask = getattr(self, "orctask", None)

    if not orctask :
        orctask = self.create_task('orcc')
        self.orctask = orctask
        orctask.target = self.target

        vapi_dirs = Utils.to_list(getattr(self, 'vapi_dirs', []))
        includes =  []

    env = orctask.env

    output_nodes = []

    s_node = node.change_ext('.s')
    output_nodes.append(s_node)
    self.allnodes.append(s_node)

    if not 'cprogram' in self.features:
        output_nodes.append(self.path.find_or_declare('%s.h' % self.target))

    orctask.inputs.append(node)
    orctask.outputs.extend(output_nodes)

@conf
def check_orc(self):
    orcc = self.find_program('orcc', var='ORCC', mandatory=True)

def configure(self):
	self.load('gnu_dirs')
	self.check_orc()
