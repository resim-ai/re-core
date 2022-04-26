FROM ubuntu:jammy

LABEL description="Core development container"

RUN apt-get update && apt-get upgrade && apt-get install -y g++ openssh-server
RUN apt-get install -y clang

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# expose port 22 
EXPOSE 22