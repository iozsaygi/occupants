# Occupants

Occupants is a local two-player turn-based game where each player tries to occupy the most amount of a randomly
generated grid map to win.

Currently, the development is focused on macOS, but Windows will also be supported at some point.

<p align="center">
    <img alt="Gameplay Screenshot" src="https://github.com/iozsaygi/occupants/blob/main/Media/Gameplay%20SS.png?raw=true">
</p>

## Preface

Occupants was pretty much a test case to see how I'll come up with an engine design for a basic turn-based game.
Creating and maintaining an engine for the game idea takes tons of effort.
The engine is separated into several subsystems, and the game itself won't even launch if any engine subsystem fails to
initialize. Ensuring the client (game) relies on engine subsystems to function correctly. This idea also ensures
developers fix any issue within the engine or in the game instead of hiding issues for a later time.

Engine is almost cross-platform except for the `asset manager` subsystem. The asset manager has to read the working
directory to fetch assets that are needed to be loaded into memory. To set the working directory, I had to write a bit
of macOS-specific code, but I am pretty sure it won't be an issue if any porting work arises. Please
see [here](https://github.com/iozsaygi/occupants/blob/main/Engine/Subsystems/AssetManager/AssetManager.cpp) for
greater detail.

It would be a mistake if I didn't talk about the build and asset pipeline. Dependencies are fully automated and compiled
with the engine's source code. `SDL` and `SDL_image` are pretty much open source, and we are able to clone specific
release
revisions and build these with the game with the help of `CMake`.

For the asset pipeline, the `Assets` folder is automatically cloned into the working directory of the game during the
post-build process, ensuring the engine and game will work with the latest versions of the available assets.

## Changelog

- v0.2 (July 02, 2025)
    - Removed debug render calls and added textures for gameplay systems.

- v0.1 (May 19, 2025)
    - Gameplay mechanics are finished, and the game needs a decent polish at this point.

## Dependencies

The following dependencies are automatically downloaded, extracted, and linked to builds, which means the end user of
this repository won't have to deal with dependency management:

- [SDL3](https://www.libsdl.org)
- [SDL Image](https://github.com/libsdl-org/SDL_image)

## Building

### macOS

#### Through Homebrew

- `git clone https://github.com/iozsaygi/occupants.git`
- `brew install cmake`
- `chmod +x build.sh`
- `./build.sh`

## Credits

### Art

- [Chris Hamons](https://opengameart.org/content/dungeon-crawl-32x32-tiles)

## License

[MIT License](https://github.com/iozsaygi/occupants/blob/main/LICENSE)