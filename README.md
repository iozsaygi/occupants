# Occupants

Occupants is a local two-player turn-based game where each player tries to occupy the most amount of a randomly
generated grid map to win.

Currently, the development is focused on macOS, but Windows will also be supported at some point.

## Changelog

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