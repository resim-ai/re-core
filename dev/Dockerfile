FROM ubuntu:jammy

LABEL description="Core development container"

# Install base dependencies
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y ca-certificates curl gnupg lsb-release software-properties-common
RUN apt-get install -y g++ clang lcov clang-format clang-tidy clangd
RUN apt-get install -y openssh-server unzip groff man
RUN apt-get install -y emacs vim zsh tmux
RUN apt-get install -y uuid-dev
RUN apt-get install -y libgoogle-glog-dev
RUN apt-get install -y cgdb

# Install Docker
RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/docker.list > /dev/null
RUN apt-get update
RUN apt-get install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin

# Install Github CLI
RUN curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | tee /etc/apt/sources.list.d/github-cli.list > /dev/null
RUN apt-get update
RUN apt-get install -y gh

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd
RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
  ssh-keygen -A 

# Install bash completion
RUN apt-get install -y bash-completion
RUN echo "source /etc/bash_completion" >> /root/.bashrc

# Install Bazel
RUN apt install -y apt-transport-https curl gnupg
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
RUN mv bazel-archive-keyring.gpg /usr/share/keyrings
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get -y install bazel=5.1.1
# Prevent automatically upgrading bazel version
RUN apt-mark hold bazel  

# Install Buildifier
RUN wget -O /usr/local/bin/buildifier https://github.com/bazelbuild/buildtools/releases/download/5.1.0/buildifier-linux-amd64 && chmod a+x /usr/local/bin/buildifier

# Install AWS CLI v2.6.1
# TODO: Verify signature of zip file.  This requires having a local gpg key and signing
# the AWS CLI key.
RUN wget -O awscliv2.zip https://awscli.amazonaws.com/awscli-exe-linux-x86_64-2.6.1.zip
RUN unzip awscliv2.zip && aws/install && rm -rf aws awscliv2.zip

# Install Amazon ECR Credential Helper
RUN apt install -y amazon-ecr-credential-helper

# Install Pip and Python Dependencies 
RUN apt install -y python3-pip 
COPY requirements.txt /tmp/
RUN pip install --requirement /tmp/requirements.txt

# Install Terraform
RUN curl -fsSL https://apt.releases.hashicorp.com/gpg | apt-key add -
RUN apt-add-repository "deb [arch=amd64] https://apt.releases.hashicorp.com $(lsb_release -cs) main"
RUN apt-get update && apt-get -y install terraform

# Install USD
# Install dependencies.
RUN apt -y install build-essential cmake python3-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev
RUN pip3 install PyOpenGL
RUN pip3 install PySide6

# Build USD
COPY ./build_usd.sh ./build_usd.sh
RUN ./build_usd.sh

# Install usdview dependencies
RUN pip3 install numpy
RUN apt -y install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev

# Add live-server (https://github.com/tapio/live-server)
RUN apt -y install npm
RUN npm install -g live-server

# Install pymdown extensions
RUN pip install pymdown-extensions

# Install Valgrind
RUN apt -y install valgrind

# Unminimize to get docs
RUN yes | unminimize

# expose port 22 
EXPOSE 22

# expose port 8080 for local rendering of docs when testing.
EXPOSE 8080

# expose 443 for WebSockets for auto-update of local rendering
EXPOSE 443
