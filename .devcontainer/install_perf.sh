#!/bin/bash
# Installs perf - this requires manual building in the case of Windows/MacOS.

# Update apt
apt update

# Try to install perf from apt source
apt -y install linux-tools-aws linux-tools-common linux-tools-generic linux-tools-`uname -r`

# Otherwise, download from scratch.
if [[ $? > 0 ]]
then
    pushd /tmp
    echo "apt of perf failed, trying manual install."
    export WERROR=0
    export LINUX_NUM=$(uname -r | cut -d'.' -f1)
    export LINUX_VER=$(uname -r | cut -d'.' -f1-3 | cut -d'-' -f1 | sed 's/\.0$//')
    wget "https://cdn.kernel.org/pub/linux/kernel/v$LINUX_NUM.x/linux-$LINUX_VER.tar.xz"
    tar -xf "./linux-$LINUX_VER.tar.xz"
    cd "linux-$LINUX_VER/tools/perf/"
    apt -y install python3-dev flex bison ocaml libelf-dev libdw-dev systemtap-sdt-dev libunwind-dev libperl-dev binutils-dev libzstd-dev libcap-dev libnuma-dev libbabeltrace-dev
    make -C .
    make install 
    cp perf /usr/local/bin
    cd ../../..
    popd
fi
