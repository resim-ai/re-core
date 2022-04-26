# core
Core simulation code

# Developing
Development in this repository takes place in a Docker container.  To build the container, run:

```bash
docker build -t dev .
```

To run the container:

```bash
docker run -it --volume $(pwd):/src dev bash
```

## Handling dotfiles
If you'd like to have your own dotfiles for use in the development environment, you'll want to create a dotfiles repository, modify the above command to add `--volume <dotifles repo>:/dotfiles`, and then have a script that moves the dotfiles into the appropriate places in the container.  I'm working on a cleaner solution to this but that's what we have for now.

## TODO
### VSCode support
VSCode has excellent support for developing inside a docker container, including automating the dotfiles process and the build/run stage.

### Shell script
For non-VSCode users, we'll add a shell script to automate the above process.