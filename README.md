# bar-decomp
Decompilation of Beetle Adventure Racing!


## Installation

#### 1. Install build dependencies

### Windows

For Windows 10, install WSL and a distribution by following this
[Windows Subsystem for Linux Installation Guide](https://docs.microsoft.com/en-us/windows/wsl/install-win10).
We recommend using Debian or Ubuntu 22.04 Linux distributions.

### Linux (Native or under WSL / VM)

The build process has the following package requirements:

* make
* git
* build-essential
* binutils-mips-linux-gnu
* python3
* pip3
* libpng-dev

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make cmake git build-essential binutils-mips-linux-gnu python3 python3-pip clang-format-14 clang-tidy
```

### MacOS

Install [Homebrew](https://brew.sh) and the following dependencies:
```
brew update
brew install coreutils make pkg-config tehzz/n64-dev/mips64-elf-binutils
```

#### 2. Clone the repository

```bash
git clone https://github.com/synamaxmusic/bar-decomp.git --recursive
```

This will copy the GitHub repository contents into a new folder in the current directory called `bar-decomp`. Change into this directory before doing anything else:

```bash
cd bar-decomp
```

#### 3. Install python dependencies

The build process has a few python packages required that are located in `/tools/requirements-python.txt`.

To install them simply run in a terminal:

```bash
python3 -m pip install -r ./tools/requirements-python.txt
```
* Depending on your python version, you might need to add  --break-system-packages, or use venv.

#### 4. Update submodules & build toolchain

```bash
git submodule update --init --recursive
make dependencies
```

#### 5. Prepare a base ROM
Copy your ROM to the root of this new project directory, and rename the file of the baserom to reflect the version of ROM you are using. ex: `baserom.jp.z64`

#### 6. Make and Build the ROM

To start the extraction/build process, run the following command:

```bash
make extract
```
This will create the build folders, a new folder with the assembly as well as containing the disassembly of nearly all the files containing code.

From now on you should be able to build the rom by running `make`.

this make target will also build the ROM. If all goes well, a new ROM called "beetleadventurerac.jp.z64" should be built and the following text should be printed:

```bash
build/beetleadventurerac.us.rev0.z64: OK
```

If you instead see the following:

```bash
build/beetleadventurerac.us.rev0.z64: FAILED
```

This means that something is wrong with the ROM's contents. Either the base files are incorrect due to a bad ROM, or some of the code is not matching.
