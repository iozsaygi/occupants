# Occupants

Occupants is a local two-player turn-based game where each player tries to occupy the most amount of a randomly
generated grid map to win.

Currently, the development is focused on macOS, but Windows will also be supported at some point.

## Dependencies

The following dependencies are automatically downloaded, extracted, and linked to builds, which means the end user of
this repository won't have to deal with dependency management:

- [SDL3](https://www.libsdl.org)

## Building

### macOS

#### Through Homebrew

- `git clone https://github.com/iozsaygi/occupants.git`
- `brew install cmake`
- `chmod +x .build.sh`
- `./build.sh`

## License

[MIT License](https://github.com/iozsaygi/occupants/blob/main/LICENSE)