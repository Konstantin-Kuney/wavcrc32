
[Russian](./README.md) / [English](#English)

## English
----------

When copying audio media, everything is important. Copy it correctly, unpack it correctly, verify it correctly, and burn it correctly.

This repository was created to help music lovers. Primarily, it's for users of the most popular Linux distributions and MacOS, for which I've compiled installation packages and written a manual. The Windows version is compiled by the source code author.

You can read about the difficulties of verifying audio data checksums [here](https://rutracker.org/forum/viewtopic.php?t=357895).

## wavcrc32 & allwavcrc32
-------------------------
wavcrc32 - A program for checking CRC audio data.

allwavcrc32 - Script that uses the wavcrc32 program to check the CRC of audio data of any number of wav files in the current folder.

## About wavcrc32 and allwavcrc32:
----------------------------------

**wavcrc32** a program for checking CRC audio data obtained using EAC (Exact Audio Copy) on Windows, Rubyripper on Linux, XLD (X Lossless Decoder) on macOS, etc.

**Before checking, the FLAC APE WAVPACK should be unpacked to WAV.** At least one of the checksums obtained using wavcrc32 must match the checksums from the rip LOG file.

Using **wavcrc32** to check the CRC of audio data in a **track-by-track rip** is very inconvenient because it can only work with a single wav file.

For example, if you enter the command **"wavcrc32 \*.wav"** in your music folder, which contains more than one wav file, the program will exit with the error **"\*\*\* invalid cmdline arguments!"**.

To calculate the checksum of all files in the current folder, I wrote a simple script - **allwavcrc32**.

## Content:
-----------

* Linux/v0.22/amd64/allwavcrc32.1.gz - man page for the allwavcrc32 script
* Linux/v0.22/amd64/allwavcrc32.sh - allwavcrc32 script
* Linux/v0.22/amd64/allwavcrc32-0.22-2.x86_64.rpm - 64-bit RPM package allwavcrc32 + wavcrc32 for RedHat based Linux
* Linux/v0.22/amd64/allwavcrc32_0.22-1_amd64.deb - 64-bit DEB package allwavcrc32 + wavcrc32 for Debian based Linux
* Linux/v0.22/amd64/md5sum.txt - checksums
* Linux/v0.22/amd64/wavcrc32.1.gz - man-page for wavcrc32
* Linux/v0.22/amd64/wavcrc32-0.22-2.x86_64.rpm - 64-bit RPM package wavcrc32 for RedHat based Linux
* Linux/v0.22/amd64/wavcrc32_0.22-1_amd64.deb - 64-bit DEB package wavcrc32 for Debian based Linux
* Linux/v0.22/amd64/wavcrc32_v0.22_linux_amd64 - 64-bit wavcrc32 binary for Linux
---
* Linux/v0.22/i386/allwavcrc32.1.gz - man page for the allwavcrc32 script
* Linux/v0.22/i386/allwavcrc32.sh - allwavcrc32 script
* Linux/v0.22/i386/allwavcrc32-0.22-2.i386.rpm - 32-bit RPM package allwavcrc32 + wavcrc32 for RedHat based Linux
* Linux/v0.22/i386/allwavcrc32_0.22-1_i386.deb - 32-bit DEB package wavcrc32 for Debian based Linux
* Linux/v0.22/i386/md5sum.txt - checksums
* Linux/v0.22/i386/wavcrc32.1.gz - man-page for wavcrc32
* Linux/v0.22/i386/wavcrc32-0.22-2.i386.rpm - 32-bit RPM package for RedHat based Linux
* Linux/v0.22/i386/wavcrc32_0.22-1_i386.deb - 32-bit DEB package for Debian based Linux
* Linux/v0.22/i386/wavcrc32_v0.22_linux_i386 - 32-bit wavcrc32 binary for Linux
---
* MacOS/v0.22/allwavcrc32.1 - man page for the allwavcrc32 script
* MacOS/v0.22/allwavcrc32.sh - allwavcrc32 script
* MacOS/v0.22/allwavcrc32-0.22.pkg - 64-bit allwavcrc32 + wavcrc32 installation package for MacOS
* MacOS/v0.22/md5sum.txt - checksums
* MacOS/v0.22/wavcrc32.1 - man-page for wavcrc32
* MacOS/v0.22/wavcrc32-0.22.pkg - 64-bit installation package wavcrc32 for MacOS
* MacOS/v0.22/wavcrc32_v0.22_macos_x86_64 - 64-bit wavcrc32 binary for MacOS
---
* Windows/v0.11-v0.22/md5sum.txt - checksums
* Windows/v0.11-v0.22/t-357895.rar - console version 0.22, GUI 0.11 for Windows
---
* src/md5sum.txt - checksums
* src/wavcrc32v0.22.cpp - wavcrc32 v0.22 source code in C++ (C Plus Plus)
---
* ChangeLog - change history
* README.md - this description file

## About installation packages:
-------------------------------

The **allwavcrc32** installation packages for Linux and macOS contain not only the allwavcrc32 script but also the wavcrc32 program itself, so it is **recommended** to install them.

The wavcrc32 installation packages contain only the wavcrc32 program itself.

## Windows
----------

The original RAR archive from the developer's [page](https://rutracker.net/forum/viewtopic.php?t=357895). Contains the console version v0.22 and the GUI version v0.11 for Windows.

**Author's comment:**
> Attached to this post are archives with both versions of the program for Windows (binaries + four dlls that need to be placed in %WINDIR%\System32 if they are not already there + source code for building under *nix).

> Potential issues when launching the console version: If wavcrc32.exe fails to launch, try wavcrc32-watcom.exe. If you have MSVC and experience with it, you can try rebuilding the program for Windows (the source code is cross-platform, so compilation should be straightforward).

## Linux
--------

## Installing/Uninstalling wavcrc32 using a package manager:
------------------------------------------------------------

### 1.Clone the wavcrc32 GitHub repository:
```
$ cd /tmp/
$ git clone https://github.com/Konstantin-Kuney/wavcrc32.git
```

### 2.Navigate to the folder corresponding to the architecture of your Linux distribution:
For 64-bit:
```
$ cd wavcrc32/Linux/v0.22/amd64/
```
For 32-bit:
```
$ cd wavcrc32/Linux/v0.22/i386/
```
**Next, using the example of 64-bit**.

### 3.Install the wavcrc32 package using package manager:

Debian/Ubuntu:
```
sudo dpkg -i allwavcrc32_0.22-1_amd64.deb
```

RedHat/Fedora:
```
sudo dnf install allwavcrc32-0.22-2.x86_64.rpm
```

### 4.Uninstalling wavcrc32 using package manager:

Debian/Ubuntu:
```
$ sudo apt-get purge allwavcrc32
```

RedHat/Fedora:
```
$ sudo dnf remove allwavcrc32
```

## Installing/Uninstalling wavcrc32 manually:
---------------------------------------------

### 1.Clone the wavcrc32 GitHub repository and navigate to the folder corresponding to the architecture of your Linux distribution. (see above).

### 2.Make the wavcrc32 binary and the allwavcrc32 script executable:
```
$ chmod +x wavcrc32_v0.22_linux_amd64
$ chmod +x allwavcrc32.sh
```

### 3.Copy them to the folder where you store the main executable files:
```
$ sudo cp -f wavcrc32_v0.22_linux_amd64 /usr/bin/wavcrc32
$ sudo cp -f allwavcrc32.sh /usr/bin/allwavcrc32
```

### 4.Copy the manuals to the man-pages folder:
```
$ sudo cp -f wavcrc32.1.gz /usr/share/man/man1/
$ sudo cp -f allwavcrc32.1.gz /usr/share/man/man1/
```

### 5.Manually removing wavcrc32:
```
$ sudo rm /usr/bin/wavcrc32
$ sudo rm /usr/share/man/man1/wavcrc32.1.gz
$ sudo rm /usr/bin/allwavcrc32
$ sudo rm /usr/share/man/man1/allwavcrc32.1.gz
```

## MacOS (Intel)
----------------

## Installing/Uninstalling the wavcrc32 installation package via the GUI:
-------------------------------------------------------------------------

**1. Double-click the downloaded allwavcrc32-0.22.pkg file**

**2. The installer window will open. Click "Continue" and follow the on-screen instructions.**

**3. Enter the administrator password when prompted to confirm the installation.**

## Installing the wavcrc32 installation package in the terminal:
-----------------------------------------------------------------------------
```
$ sudo installer -pkg /path/to/package/allwavcrc32-0.22.pkg -target /
```

## Installing wavcrc32 manually:
---------------------------------------------

### 1.Make the wavcrc32 binary and the allwavcrc32 script executable:
```
$ chmod +x wavcrc32_v0.22_macos_x86_64
$ chmod +x allwavcrc32.sh
```

### 2.Copy them to the folder where you store the main executable files:
```
$ sudo cp -f wavcrc32_v0.22_macos_x86_64 /usr/bin/wavcrc32
$ sudo cp -f allwavcrc32.sh /usr/bin/allwavcrc32
```

### 3.Copy the manuals to the man-pages folder:
```
$ sudo cp -f wavcrc32.1 /usr/share/man/man1/
$ sudo cp -f allwavcrc32.1 /usr/share/man/man1/
```

### Manually removing wavcrc32:
```
$ sudo rm /usr/bin/wavcrc32
$ sudo rm /usr/share/man/man1/wavcrc32.1
$ sudo rm /usr/bin/allwavcrc32
$ sudo rm /usr/share/man/man1/allwavcrc32.1
```

## Using wavcrc32 and allwavcrc32:
----------------------------------

For example, you want to check all the wav files in your music folder. Go to it and run the script:
```
$ cd /tmp/music
$ allwavcrc32
```

You can output the check results to a file:
```
$ allwavcrc32 > wavcrc32.txt
```

For example, if you want to check only one file, **filename.wav**, simply enter:
```
$ wavcrc32 filename.wav
```

For more details, see the manuals:
```
$ man allwavcrc32
$ man wavcrc32
```

## About decompressing FLAC APE WAVPACK:
----------------------------------------

> FLAC, APE (Monkey's Audio), and WavPack (.wv) are lossless audio compression formats that reduce the size of audio files without sacrificing quality. They provide 100% faithful restoration of the original and are ideal for archiving.

**Important!** Don't convert them, but **decompress** them.

## Decompressing FLAC APE WAVPACK on Debian Linux:
--------------------------------------------------

Installing codecs for decompressing:
```
$ sudo apt-get install flac wavpack monkeys-audio
```

To install the `monkeys-audio` package, add the `www.deb-multimedia.org` multimedia repository to /etc/apt/sources.list!

Decompressing:

APE
```
$ mac filename.ape filename.wav -d
```

FLAC
```
$ flac -d filename.flac
```

WavPack
```
$ wvunpack filename.wv
$ wvunpack filename.iso.wv
```

## Decompressing FLAC APE WAVPACK on macOS:
-------------------------------------------

Installing codecs for decompressing:
```
$ brew install flac wavpack mac
```

[Homebrew](https://brew.sh/) must be installed to install codecs!

Decompressing is similar to Linux. See above.

## Authors:
-----------

**dmvn \]DichlofoS\[ Systems** - **Author**. Making C++ source code, compiling console and GUI versions for Windows. Publishing and discussing on the forum.

**BakLAN, siro. and DrStandBy** - comments, suggestions and testing of Windows versions.

**Konstantin Kuney** - Compiling the program and building packages for Linux and MacOS, creating a manuals, creating the allwavcrc32 script, creating this GitHub repository and description.

## Additional information:
--------------------------

[Official webpage of the project developer](https://rutracker.net/forum/viewtopic.php?t=357895)

[Forum page for discussing the project](https://rutracker.net/forum/viewtopic.php?t=1955422)

[This GitHub repository](https://github.com/Konstantin-Kuney/wavcrc32)

---

[Go up / Вверх](#Russian)

