# gsu

gsu (General Screenshot Utility) allows for easy capturing and uploading of images, video, and gifs from your desktop.

## Features

* Screenshot capture.
* Video capture.
* GIF capture.
* Built-in uploading to uguu.se, streamable, and gfycat.
* Custom uploading capability if the above services don't suit your fancy.
* A clean and easy to understand CLI.

## Usage

```
Usage: gsu [OPTION]... SOURCE
A general screenshot and upload utility for images, video, and gifs.

GENERAL OPTIONS
  -h, --help                 Show the help menu
  -v, --version              Show the current version

  -u, --upload               Upload after running the utility
  -n, --nocursor             Hide the cursor
  -d, --display NUM|TYPE     Set the selection to a specific display.
                             Values: number of display, 'active', 'all' (default)

  -s, --screenshot           Take a screenshot
  -m, --video                Record a video of the screen
  -g, --gif                  Record a video and convert it to the gif format

VIDEO OPTIONS
  -c, --countdown NUM        Countdown before recording
```

## Installation

### Arch Linux

Install **[gsu]** or **[gsu-git]** from the AUR.

[gsu]: https://aur.archlinux.org/packages/gsu/
[gsu-git]: https://aur.archlinux.org/packages/gsu-git/

### Install From Source

gsu depends heavily on maim, slop, FFmpeg, curl, and jq for its functionality. To install gsu's dependencies, run the following commands in accordance to your distro.

#### Arch Linux

```
$ sudo pacman -S maim slop ffmpeg curl jq
```

#### Debian 8

Be sure that the `unstable` repository is enabled on Debian, or your screenshots may not output properly. This is because Debian 8 has outdated versions of maim and slop.

```
$ sudo apt-get install maim slop ffmpeg curl jq
```

#### Ubuntu 17.04

**Unsupported.** slop and maim both are terribly out of date in Ubuntu's 17.04 repositories, resulting in artifacting and improper screenshots. When Ubuntu 17.10 is released, it will be properly supported.

If you can't wait until then, you can install [slop] and [maim] from source. Afterwards, run the following command.

```
$ sudo apt-get install ffmpeg curl jq
```

[slop]: https://github.com/naelstrof/slop#install-using-cmake-requires-cmake
[maim]: https://github.com/naelstrof/maim#install-using-your-package-manager-preferred

#### Other Linux or BSD

Install `maim`, `slop`, `ffmpeg`, `curl`, and `jq` using your package manager of choice. You could also install each package from source, but who has time for that?

---

After installing the dependents, run the following commands to install gsu.

```
$ curl -o gsu.tar.gz https://codeload.github.com/winneon/gsu/tar.gz/1.1.1
$ tar xvf gsu.tar.gz && cd gsu-1.1.1
$ sudo make install
```

You can optionally install `xclip` if you want automatic URL clipboard pasting after the utility finishes an upload.

## Troubleshooting

Here are some frequent problems users may face and their respective solutions. If you have more solutions, feel free to send in an issue or pull request.

### The outputted screenshot has weird black or white sections.

This is a common problem with older versions of maim. You have a few choices:

* On Debian 8, enable the `unstable` APT repository, and upgrade maim and slop.
* On Ubuntu 17.04 and other distros, install both maim and slop from source.

## Credits

* [Dalton Nell](https://github.com/naelstrof) for maim and slop, used for screenshot creation and selections
* [The FFmpeg team](https://ffmpeg.org/) for ffmpeg, used for video and gif creation
* [Daniel Stenberg](https://github.com/bagder) for curl, used for uploading
* [Stephen Dolan](https://github.com/stedolan) for jq, used for parsing JSON
