# MIDIScanner

MIDIScanner - A small utility to grab note/velocity/CC data from MIDI devices in real time. Originally designed to be used with Mixxx for controller mapping, but there are all sorts of practical applications!

Currently this has been tested to work on Linux (tested with armv8 and x86/x86_64) and macOS, but it SHOULD work on Windows as it supports RTMidi (building for Windows is currently unsupported).

![](screenshot.png)

## Dependencies:
- RTMidi ("brew install rtmidi" on macOS w/ homebrew installed, "sudo apt install librtmidi-dev" on Debian/Ubuntu, "sudo pacman -S rtmidi" on Arch, etc.)

## How to Build:
- Open your Terminal application
- Go to the directory where MIDIScanner is saved and type "./midiscanner" into the terminal (you may have to type "chmod +x midiscanner" first if you get permission issues).
- Select your MIDI device and you're ready to start pressing buttons/knobs and mapping out their values!

## How to Build:
### Linux:
- Install RTMidi dependencies (librtmidi-dev on Ubuntu, rtmidi on Arch Linux, etc.)
- Clone this repository
- Open the repository folder in your Terminal and run "make" 

### macOS:
- Install Homebrew
- Install RTMidi dependencies (brew install rtmidi)
- Clone this repository
- Open the repository folder in your Terminal and run "make" 

### Windows:
- TBA

## To Do:
- Add an LED-locating helper function
- Check error handling
- Port to Python using python-rtmidi
