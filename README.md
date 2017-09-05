# gsu

gsu (General Screenshot Utility) allows for easy capturing and uploading of images, video, and gifs from your desktop.

## Features

* Screenshot capture.
* Video capture.
* GIF capture.
* Built-in uploading to uguu.se, streamable, and gfycat.
* Custom uploading capability if the above services don't suit your fancy.
* A clean and easy to understand CLI.

## Installation

### Arch Linux

Install [**gsu**](https://aur.archlinux.org/packages/gsu/) or [**gsu-git**](https://aur.archlinux.org/packages/gsu-git/) from the AUR.

### Install From Source

gsu depends heavily on maim, slop, FFmpeg, curl, and jq for its functionality. To install gsu's dependencies, run the following commands in accordance to your distro.

#### Arch Linux

```
$ sudo pacman -S tar make maim ffmpeg curl jq
```

#### Debian/Ubuntu 17.04+

```
$ sudo apt-get install tar make maim ffmpeg curl jq
```

---

After installing the dependents, run the following commands to install gsu.

```
$ curl -o gsu.tar.gz https://codeload.github.com/winneon/gsu/tar.gz/1.1.1
$ tar xvf gsu.tar.gz && cd gsu-1.1.1
$ sudo make install
```

## Credits

* [Dalton Nell](https://github.com/naelstrof) for maim and slop, used for screenshot creation and selections
* [The FFmpeg team](https://ffmpeg.org/) for ffmpeg, used for video and gif creation
* [Daniel Stenberg](https://github.com/bagder) for curl, used for uploading
* [Stephen Dolan](https://github.com/stedolan) for jq, used for parsing JSON
