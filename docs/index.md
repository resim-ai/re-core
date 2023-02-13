# core
Core simulation code

# Developing
Development in this repository takes place in a Docker container.  To build the container, run:

```bash
.devcontainer/build.sh
```

To run the container:

```bash
.devcontainer/run.sh
```

You can still modify the files outside of the container and the changes you make will show up in the container.  However, any build/run/etc will have to be done in the container.  The expected workflow is that you modify code in your own environment and build/test in the container.  However, you can do everything from within the container if you prefer.

Best practice is to rebuild the container every time you pull.  It may have been modified since your previous pull, and you may not notice it.  This workflow will be smoothed out in the future.

## Handling dotfiles
If you'd like to have your own dotfiles for use in the development environment, you'll want to create a dotfiles repository, modify the above command to add `--volume <dotifles repo>:/dotfiles`, and then have a script that moves the dotfiles into the appropriate places in the container.  I'm working on a cleaner solution to this but that's what we have for now.
