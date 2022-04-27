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

You can still modify the files outside of the container and the changes you make will show up in the container.  However, any build/run/etc will have to be done in the container.  The expected workflow is that you modify code in your own environment and build/test in the container.  However, you can do everything from within the container if you prefer.

Best practice is to rebuild the container every time you pull.  It may have been modified since your previous pull, and you may not notice it.  This workflow will be smoothed out in the future.

## Handling dotfiles
If you'd like to have your own dotfiles for use in the development environment, you'll want to create a dotfiles repository, modify the above command to add `--volume <dotifles repo>:/dotfiles`, and then have a script that moves the dotfiles into the appropriate places in the container.  I'm working on a cleaner solution to this but that's what we have for now.

## TODO
### Automatic container building
We wil have a continuous deployment hook in CircleCI that will automatically rebuild the Dockerfile whenever a change is landed and push it to a repository.  At that point, we will update this workflow to specify that you should pull the latest version of the container rather than build it yourself, and we will update the scripts to refer to `latest`.  This way, everybody should get the latest container automatically.

### VSCode support
VSCode has excellent support for developing inside a docker container, including automating the dotfiles process and the build/run stage.

### Shell script
For non-VSCode users, we'll add a shell script to automate the above process.