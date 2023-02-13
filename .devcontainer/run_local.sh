docker run -it \
       -p 8080:8080 \
       -p 443:443 \
       --volume $(pwd):/workspaces/core \
       --volume root-home:/root \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       core-local:latest bash
