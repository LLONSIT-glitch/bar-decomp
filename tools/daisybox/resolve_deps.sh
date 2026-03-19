#https://ftp.gnu.org/gnu/binutils/binutils-2.46.0.tar.xz

BINUTILS_MIRROR=https://ftp.gnu.org/gnu/binutils/

BINUTILS_VERSION=2.46.0

echo "Downloading binutils version $BINUTILS_VERSION from $BINUTILS_MIRROR"

curl -L -o binutils.tar.xz $BINUTILS_MIRROR/binutils-$BINUTILS_VERSION.tar.xz
tar -xJf binutils.tar.xz

cd binutils-$BINUTILS_VERSION 
./configure --target=mips-linux-gnu --disable-nls \
             --disable-gprofng \
             --disable-binutils \
             --disable-gas \
             --disable-ld \
             --disable-gold \
             --disable-gprof \
             --disable-sim && make -j$(nproc)

echo "Copying the required libraries to the lib directory"

# Copy the headers first
cp -r bfd/bfd.h include/bfdlink.h opcodes/config.h ../include && cp  bfd/.libs/libbfd.a libiberty/libiberty.a opcodes/libopcodes.a libsframe/.libs/libsframe.a zlib/libz.a ../libs/

cd .. && rm -fr binutils.tar.xz binutils-$BINUTILS_VERSION

# Now compile cjson
echo "Downloading cjson"
curl -L -o cjson.zip "https://github.com/DaveGamble/cJSON/archive/refs/tags/v1.7.19.zip"
unzip cjson.zip
cd cJSON-1.7.19
make    
cp libcjson.a ../libs/ && cp cJSON.h ../include
cd ..
rm -fr cjson.zip cJSON-1.7.19

echo "All dependencies have been downloaded and compiled"
