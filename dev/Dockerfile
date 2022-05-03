FROM ubuntu:jammy

LABEL description="Core development container"

# Install base dependencies
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y g++ clang
RUN apt-get install -y openssh-server unzip groff

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd
RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# Install bash completion
RUN apt-get install -y bash-completion
RUN echo "source /etc/bash_completion" >> /root/.bashrc

# Install Bazel
RUN apt-get -y install apt-transport-https curl gnupg
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
RUN mv bazel.gpg /etc/apt/trusted.gpg.d/
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get -y install bazel

# Install AWS CLI v2.6.1
# TODO: Verify signature of zip file.  This requires having a local gpg key and signing
# the AWS CLI key.
RUN wget -O awscliv2.zip https://awscli.amazonaws.com/awscli-exe-linux-x86_64-2.6.1.zip
RUN unzip awscliv2.zip && aws/install && rm -rf aws awscliv2.zip

# Install Amazon ECR Credential Helper
RUN apt install -y amazon-ecr-credential-helper

# expose port 22 
EXPOSE 22

# mount point for code
VOLUME /src
WORKDIR /src
