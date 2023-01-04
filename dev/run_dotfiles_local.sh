docker run -it \
       -p 8080:8080 \
       -p 443:443 \
       --volume $(pwd):/workspaces/core \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume $HOME/dotfiles:/workspaces/dotfiles \
       core-local:latest /bin/bash -c "cd /workspaces/dotfiles; /workspaces/dotfiles/install.sh; cd /workspaces/core; $SHELL"