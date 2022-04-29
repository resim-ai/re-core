FROM ubuntu:jammy

LABEL description="Core development container"

# Install base dependencies
RUN apt-get update && apt-get -y upgrade && apt-get install -y g++ openssh-server
RUN apt-get install -y clang

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd
RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# Install Bazelisk as Bazel
ARG BAZELISK_VERSION="1.11.0"
ADD https://github.com/bazelbuild/bazelisk/releases/download/v${BAZELISK_VERSION}/bazelisk-linux-amd64 /usr/local/bin/bazel
RUN chmod a+x /usr/local/bin/bazel
# Prefetch latest stable Bazel
# This may not be the same version as in .bazelversion, but it's likely to be.
# TODO(austin): Figure out a way to synchronize this with the .bazelversion file.
RUN /usr/local/bin/bazel

# expose port 22 
EXPOSE 22

# mount point for code
VOLUME /src
