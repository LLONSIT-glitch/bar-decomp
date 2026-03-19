#!/usr/bin/env python3

import yaml
import sys
import subprocess
from pathlib import Path

PATCHED_MODULE_FILES_DIR = "patched_modules"

class Module:
    def __init__(self, name: str, done_sections=None):
        self.name = name
        self.done_sections = done_sections or []

    def __repr__(self):
        return f"<Module name={self.name} Done sections={self.done_sections}>"
    

class Disassembler:
    def __init__(self):
        self.args = []
        self.cmd = [sys.executable, "tools/moduleFileDisasm.py"]

    def addArgs(self, arg: str):
        self.args.append(arg)

    def resetArgs(self):
        self.args = []

    def printArgs(self):
        print("Current args:", self.args)

    def execute(self):
        cmd = self.cmd + self.args
        subprocess.run(cmd, check=True)

def load_modules(path):
    with open(path) as f:
        data = yaml.safe_load(f)

    modules = []

    for entry in data["Modules"]:
        name = entry["name"]
        # read done_sections list if it exists
        done_sections = entry.get("done_sections", [])

        modules.append(Module(name, done_sections))

    return modules

def main():
    disassembler = Disassembler()
    if len(sys.argv) < 2:
        print("Usage: module_extract.py modules.yaml")
        sys.exit(1)

    yaml_file = Path(sys.argv[1])

    modules = load_modules(yaml_file)

    print("Modules found:", len(modules))

    for m in modules:
        moduleLnkScriptFiles = "linker_scripts/us/module_files/"
        kernelLnkScriptFiles = "linker_scripts/us/"

        moduleSymAddrs = moduleLnkScriptFiles + m.name + "_symbol_addrs.txt"
        moduleRelAddrs = moduleLnkScriptFiles + m.name + "_reloc_addrs.txt"
        kernelSymAddrs = kernelLnkScriptFiles + "symbol_addrs.txt"

        if "text" in m.done_sections:
            disassembler.addArgs("--dont-split-text")

        if "data" in m.done_sections:
            disassembler.addArgs("--dont-split-data")
            
        if "bss" in m.done_sections:
            disassembler.addArgs("--dont-split-bss")

        if "rodata" in m.done_sections:
            disassembler.addArgs("--dont-split-rodata")

#        disassembler.addArgs("--asm-nm-label")
#        disassembler.addArgs("#")
        disassembler.addArgs("--asm-jtbl-label")
        disassembler.addArgs("glabel")
        disassembler.addArgs("--module-name")
        disassembler.addArgs(m.name)
        disassembler.addArgs("--create-c-file")
        disassembler.addArgs("--symbol-addrs")
        disassembler.addArgs(moduleSymAddrs)
        disassembler.addArgs("--reloc-addrs")
        disassembler.addArgs(moduleRelAddrs)
        disassembler.addArgs("--symbol-addrs")
        disassembler.addArgs(kernelSymAddrs)
        disassembler.addArgs("--no-use-fpccsr")
        disassembler.addArgs(PATCHED_MODULE_FILES_DIR + "/" + m.name + ".uvmo")
        disassembler.addArgs("--split-functions")
        disassembler.addArgs("asm/us/nonmatchings/modules/")
        disassembler.addArgs("asm/us/data/modules")
        disassembler.execute()
        disassembler.resetArgs()


if __name__ == "__main__":
    main()
