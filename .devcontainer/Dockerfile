FROM ubuntu:jammy

LABEL description="Core development container"

# Install base dependencies
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y ca-certificates curl gnupg lsb-release software-properties-common
RUN apt-get install -y g++ clang lcov clang-format clang-tidy clangd
RUN apt-get install -y openssh-server unzip groff man
RUN apt-get install -y emacs vim zsh tmux
RUN apt-get install -y uuid-dev
RUN apt-get install -y cgdb
RUN apt-get install -y libcurl4-openssl-dev

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
RUN apt-get update && apt-get -y install bazel=5.4.0
# Prevent automatically upgrading bazel version
RUN apt-mark hold bazel  

# Install Buildifier
RUN wget -O /usr/local/bin/buildifier https://github.com/bazelbuild/buildtools/releases/download/5.1.0/buildifier-linux-amd64 && chmod a+x /usr/local/bin/buildifier

# Install Pip and Python Dependencies 
RUN apt install -y python3-pip 
COPY requirements.txt /tmp/
RUN pip install --requirement /tmp/requirements.txt

# Install Go
RUN wget https://go.dev/dl/go1.19.3.linux-amd64.tar.gz
RUN rm -rf /usr/local/go && tar -C /usr/local -xzf go1.19.3.linux-amd64.tar.gz
ENV PATH "${PATH}:/usr/local/go/bin:/root/go/bin"

# Install go tools
RUN go install -v golang.org/x/tools/gopls@v0.10.1
RUN go install -v github.com/go-delve/delve/cmd/dlv@v1.9.1
RUN go install -v github.com/haya14busa/goplay/cmd/goplay@v1.0.0
RUN go install -v github.com/fatih/gomodifytags@v1.16.0
RUN go install -v github.com/josharian/impl@v1.1.0
RUN go install -v github.com/cweill/gotests/gotests@v1.6.0
RUN go install -v honnef.co/go/tools/cmd/staticcheck@v0.3.3

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
