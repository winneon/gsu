# gsu

gsu (General Screenshot Utility) allows for easy capturing and uploading of images, video, and gifs from your desktop.

## Features

* Screenshot capture.
* Video capture.
* GIF capture.
* Built-in uploading to uguu.se, streamable, and gfycat.
* Custom uploading capability if the above services don't suit your fancy.
* dmenu and rofi integration.
* A clean and easy to understand CLI.

## Usage

```
Usage: gsu [OPTION]... SOURCE
A general screenshot and upload utility for images, video, and gifs.

SOURCE defaults to $XDG_CONFIG_HOME/gsu/imgs if nothing is provided.
The most common location for $XDG_CONFIG_HOME is ~/.config.

GENERAL OPTIONS
  -h, --help                 Show the help menu.
  -v, --version              Show the current version.
  -l, --list-displays        List your current displays and their resolutions.
  -u, --upload               Upload after running the utility.
  --hide                     Minimize the current window while capturing.
                             This is useful when running with --terminal to hide
                             the newly opened term.
  --terminal                 Open interactive commands in a new terminal..
                             SET THIS IF RUNNING FROM ANYTHING OTHER THAN A TERM,
                             i.e. xbindkeys
  --notify                   Send a libnotify notification of the output.

UTILITY OPTIONS
  -r, --dmenu                Select the one of the below options from dmenu or rofi.
  -s, --screenshot           Take a screenshot. (default)
  -m, --video                Record a video of the screen.
  -g, --gif                  Record a video and convert it to the gif format.

CAPTURE OPTIONS
  -n, --nocursor             Hide the cursor.
  -d, --display NUM|TYPE     Set the selection to a specific display.
                             Can read from an argument or from stdin.
                             Values: number of display, 'active', 'all' (default)

VIDEO OPTIONS
  -c, --countdown NUM        Countdown before recording.
```

## Installation

### Arch Linux

Install **[gsu]** or **[gsu-git]** from the AUR.

[gsu]: https://aur.archlinux.org/packages/gsu/
[gsu-git]: https://aur.archlinux.org/packages/gsu-git/

### Manual

To install gsu's required dependencies, run the following command in accordance to your distro.

#### Arch Linux

```
$ sudo pacman -S curl jq xdotool maim slop ffmpeg
```

#### Ubuntu 20.04 LTS/Debian 11

```
$ sudo apt install curl jq xdotool maim slop ffmpeg
```

#### Older Debian-based (Ubuntu 19.10/Debian 10 or prior)

maim, slop, and FFmpeg all have bugs in earlier versions that make gsu unusable in certain scenarios. Therefore, they must all be installed via source.

Afterwards, run the following command to install the remaining required dependencies.

```
$ sudo apt install curl jq xdotool
```

#### Other Linux or BSD

Install `curl`, `jq`, `xdotool`, `maim`, `slop`, and `ffmpeg` via source or your package manager of choice. *If installing by package manager, ensure that the following required versions are met.*

*maim*: 5.x or later  
*slop*: 7.x or later  
*FFmpeg*: 4.2.x or later

---

You can optionally install `xsel` if you want automatic URL clipboard pasting after the utility finishes an upload.

After installing the dependents, run the following commands to install gsu.

```
$ curl -o gsu.tar.gz https://codeload.github.com/winneon/gsu/tar.gz/1.3.2
$ tar xvf gsu.tar.gz && cd gsu-1.3.2
$ sudo make install
```

## Configuration

Run the utility at least once, i.e. `gsu --help`. The configuration file will be generated in `$XDG_CONFIG_HOME/gsu` if it didn't already exist. The most common location is `~/.config/gsu`.

## Troubleshooting

Here are some frequent problems users may face and their respective solutions. If you have more solutions, feel free to send in an issue or pull request.

### The outputted capture is completely black or another solid color.

Make sure that you are running your DE/WM under the latest version of X11. Wayland is untested. To check, run the following command.

```
$ echo $XDG_SESSION_TYPE
```

If you are running X11 and the problem persists, try disabling OpenGL hardware-based acceleration by adding `--no-opengl` to your gsu command.

### The outputted capture has black/white sections or artifacts.

This is a problem with older versions of maim. Upgrade maim to 5.x or later or install via source.

### The capture session won't end when capturing a video or gif.

Versions of FFmpeg prior to 4.2.x have a bug where an `x11grab` capture sessions won't end unless forcibly killed by the system. Upgrade FFmpeg to 4.2.x or install via source.

### There is no audio in the captured video.

PulseAudio is the default audio capture device. If you do not use PulseAudio, adjust your audio capture device in the configuration file.

If you do use PulseAudio, use a program like `pavucontrol` to change the input device to a monitor of your audio output device. If you use PAVUcontrol, the resulting setup should look similar to below.

![pavucontrol example](http://i.imgur.com/qbN5741.png)

## Credits

* [Dalton Nell](https://github.com/naelstrof) for maim and slop, used for screenshot creation and selections
* [The FFmpeg team](https://ffmpeg.org/) for FFmpeg, used for video and gif creation
* [Daniel Stenberg](https://github.com/bagder) for curl, used for uploading
* [Stephen Dolan](https://github.com/stedolan) for jq, used for parsing JSON
