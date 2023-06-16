docker run -it \
       --platform linux/amd64 \
       -p 8080:8080 \
       -p 443:443 \
       --volume $(pwd):/workspaces/re-core \
       --volume root-home:/root \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume $HOME/dotfiles:/workspaces/dotfiles \
       909785973729.dkr.ecr.us-east-1.amazonaws.com/core:latest /bin/bash -c "cd /workspaces/dotfiles; /workspaces/dotfiles/install.sh; cd /workspaces/re-core; $SHELL"
