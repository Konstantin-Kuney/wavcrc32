
[Russian](#Russian) / [English](#English)

## Russian
----------

В вопросе копирования аудионосителей важно всё. Правильно скопировать, правильно распаковать, правильно проверить, и правильно записать.

Данный репозиторий создан в помощь любителям музыки. В первую очередь, пользователям самых популярных дистрибутивов Linux и MacOS, для которых мной были собраны установочные пакеты, и написан мануал. Windows версия скомпилирована автором исходного кода.

О трудностях проверки контрольной суммы аудиоданных можно почитать [здесь](https://rutracker.org/forum/viewtopic.php?t=357895).

## wavcrc32
-----------
Программа для проверки CRC контрольной суммы аудиоданных.

## О wavcrc32:
--------------

**wavcrc32** - программа для проверки CRC контрольной суммы аудиоданных, полученных с помощью EAC (Exact Audio Copy) в Windows, Rubyripper в Linux, XLD (X Lossless Decoder) в macOS и т.д.

**Перед проверкой необходимо распаковать FLAC APE WAVPACK в формат WAV.** По крайней мере одна из контрольных сумм, полученных с помощью wavcrc32, должна совпадать с контрольными суммами из LOG-файла рипа.

## Содержимое:
--------------

* Linux/v0.22/amd64/md5sum.txt - контрольные суммы
* Linux/v0.22/amd64/wavcrc32.1.gz - справочная страница (man-page)
* Linux/v0.22/amd64/wavcrc32-0.22-2.x86_64.rpm - 64-х битный rpm-пакет для дистрибутивов на базе RedHat Linux
* Linux/v0.22/amd64/wavcrc32_0.22-1_amd64.deb - 64-х битный deb-пакет для дистрибутивов на базе Debian Linux
* Linux/v0.22/amd64/wavcrc32_v0.22_linux_amd64 - 64-х битный бинарный файл для Linux

* Linux/v0.22/i386/md5sum.txt - контрольные суммы
* Linux/v0.22/i386/wavcrc32.1.gz - справочная страница (man-page)
* Linux/v0.22/i386/wavcrc32-0.22-2.i386.rpm - 32-х битный rpm-пакет для дистрибутивов на базе RedHat Linux
* Linux/v0.22/i386/wavcrc32_0.22-1_i386.deb - 32-х битный deb-пакет для дистрибутивов на базе Debian Linux
* Linux/v0.22/i386/wavcrc32_v0.22_linux_i386 - 32-х битный бинарный файл для Linux

* MacOS/v0.22/md5sum.txt - контрольные суммы
* MacOS/v0.22/wavcrc32.1 - справочная страница (man-page)
* MacOS/v0.22/wavcrc32-0.22.pkg - 64-х битный установочный пакет для MacOS
* MacOS/v0.22/wavcrc32_v0.22_macos_x86_64 - 64-х битный бинарный файл для MacOS

* Windows/v0.11-v0.22/md5sum.txt - контрольные суммы
* Windows/v0.11-v0.22/t-357895.rar - консольная версия 0.22, GUI 0.11 для Windows

* src/md5sum.txt - контрольные суммы
* src/wavcrc32v0.22.cpp - исходный код wavcrc32 v0.22 на языке программирования C++ (C Plus Plus)

* ChangeLog - история изменений
* README.md - данный файл описания

## Windows
----------

Оригинальный rar-архив со [страницы](https://rutracker.net/forum/viewtopic.php?t=357895) разработчика. Содержит консольную версию v0.22, и GUI-версию v0.11 для Windows.

**Коментарий автора:**
> В приложении к данному посту имеются архивы с обеими версиями программы для Windows (бинарники + четыре dll-ки, которые нужно кинуть в %WINDIR%\System32, если их там ещё нету + исходник для сборки под *nix).

> Возможные проблемы при запуске консольной версии: если не запускается программа wavcrc32.exe, попробуйте wavcrc32-watcom.exe. Если есть MSVC и опыт работы в нём, можете попробовать пересобрать программу под Windows (исходник кросплатформенный, проблем при компиляции быть не должно).

## Linux
--------

## Установка/Удаление wavcrc32 с помощью пакетного менеджера:
-------------------------------------------------------------

### 1.Клонируйте GitHub репозиторий wavcrc32:
```
$ cd /tmp/
$ git clone https://github.com/Konstantin-Kuney/wavcrc32.git
```

### 2.Перейдите в папку, соответствующую архитектуре вашего дистрибутива Linux:
Для 64-бит:
```
$ cd wavcrc32/Linux/v0.22/amd64/
```
Для 32-бит:
```
$ cd wavcrc32/Linux/v0.22/i386/
```
**Далее на примере 64-бит**.

### 3.Установите пакет wavcrc32 с помощью пакетного менеджера:

Debian/Ubuntu:
```
sudo dpkg -i wavcrc32_0.22-1_amd64.deb
```

RedHat/Fedora:
```
sudo dnf install wavcrc32-0.22-2.x86_64.rpm
```

### 4.Удаление wavcrc32 с помощью пакетного менеджера:

Debian/Ubuntu:
```
$ sudo apt-get purge wavcrc32
```

RedHat/Fedora:
```
$ sudo dnf remove wavcrc32
```

## Установка/Удаление wavcrc32 вручную:
---------------------------------------

### 1.Клонируйте GitHub репозиторий wavcrc32, и перейдите в папку, соответствующую архитектуре вашего дистрибутива Linux. (см.выше).

### 2.Сделайте бинарный файл wavcrc32 исполняемым:
```
$ chmod +x wavcrc32_v0.22_linux_amd64
```

### 3.Скопируйте его в папку для хранения основных исполняемых файлов:
```
$ sudo cp -f wavcrc32_v0.22_linux_amd64 /usr/bin/wavcrc32
```

### 4.Скопируйте мануал в папку для хранения справочных страниц (man-pages):
```
$ sudo cp -f wavcrc32.1.gz /usr/share/man/man1/
```

### 5.Удаление wavcrc32 вручную:
```
$ sudo rm /usr/bin/wavcrc32
$ sudo rm /usr/share/man/man1/wavcrc32.1.gz
```

## Использование wavcrc32:
--------------------------

Например, вы хотите проверить файл **filename.wav**, просто введите:
```
wavcrc32 filename.wav
```

## О распаковке FLAC APE WAVPACK:
------------------------------------

>FLAC, APE (Monkey's Audio) и WavPack (.wv) - это форматы сжатия звука без потерь (lossless), которые уменьшают размер аудиофайлов без потери качества звука. Они обеспечивают 100% точное восстановление оригинала, идеальны для архивирования.

**Важно!** Не конвертировать, а **распаковывать** их.

## Авторы:
----------

**dmvn \]DichlofoS\[ Systems** - **Автор**. Создание исходных кодов на C++, компиляция консольной версии и версии с GUI (с Графическим Интерфейсом Пользователя) для Windows. Публикация и обсуждение на форуме.

**BakLAN, siro. и DrStandBy** - замечания, предложения и тестирование Windows версий.

**Konstantin Kuney** - Компиляция программы и сборка пакетов для Linux и MacOS, создание мануала, создание этого GitHub репозитория и описания.

## Дополнительная информация:
-----------------------------

[Официальная страница разработчика проекта](https://rutracker.net/forum/viewtopic.php?t=357895)

[Страница форума для обсуждения проекта](https://rutracker.net/forum/viewtopic.php?t=1955422)

[Данный GitHub репозитроий](https://github.com/Konstantin-Kuney/wavcrc32)








## English
----------

When copying audio media, everything is important. Copy it correctly, unpack it correctly, verify it correctly, and burn it correctly.

This repository was created to help music lovers. Primarily, it's for users of the most popular Linux distributions and MacOS, for which I've compiled installation packages and written a manual. The Windows version is compiled by the source code author.

You can read about the difficulties of verifying audio data checksums [here](https://rutracker.org/forum/viewtopic.php?t=357895).

## wavcrc32
-----------
A program for checking CRC audio data

## About wavcrc32:
------------------

**wavcrc32** a program for checking CRC audio data obtained using EAC (Exact Audio Copy) on Windows, Rubyripper on Linux, XLD (X Lossless Decoder) on macOS, etc.

**Before checking, the FLAC APE WAVPACK should be unpacked to WAV.** At least one of the checksums obtained using wavcrc32 must match the checksums from the rip LOG file.

## Content:
-----------

* Linux/v0.22/amd64/md5sum.txt - checksums
* Linux/v0.22/amd64/wavcrc32.1.gz - man-page
* Linux/v0.22/amd64/wavcrc32-0.22-2.x86_64.rpm - 64-bit RPM package for RedHat based Linux
* Linux/v0.22/amd64/wavcrc32_0.22-1_amd64.deb - 64-bit DEB package for Debian based Linux
* Linux/v0.22/amd64/wavcrc32_v0.22_linux_amd64 - 64-bit binary for Linux

* Linux/v0.22/i386/md5sum.txt - checksums
* Linux/v0.22/i386/wavcrc32.1.gz - man-page
* Linux/v0.22/i386/wavcrc32-0.22-2.i386.rpm - 32-bit RPM package for RedHat based Linux
* Linux/v0.22/i386/wavcrc32_0.22-1_i386.deb - 32-bit DEB package for Debian based Linux
* Linux/v0.22/i386/wavcrc32_v0.22_linux_i386 - 32-bit binary for Linux

* MacOS/v0.22/md5sum.txt - checksums
* MacOS/v0.22/wavcrc32.1 - man-page
* MacOS/v0.22/wavcrc32-0.22.pkg - 64-bit installation package for MacOS
* MacOS/v0.22/wavcrc32_v0.22_macos_x86_64 - 64-bit binary for MacOS

* Windows/v0.11-v0.22/md5sum.txt - checksums
* Windows/v0.11-v0.22/t-357895.rar - console version 0.22, GUI 0.11 for Windows

* src/md5sum.txt - checksums
* src/wavcrc32v0.22.cpp - wavcrc32 v0.22 source code in C++ (C Plus Plus)

* ChangeLog - change history
* README.md - this description file

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
sudo dpkg -i wavcrc32_0.22-1_amd64.deb
```

RedHat/Fedora:
```
sudo dnf install wavcrc32-0.22-2.x86_64.rpm
```

### 4.Uninstalling wavcrc32 using package manager:

Debian/Ubuntu:
```
$ sudo apt-get purge wavcrc32
```

RedHat/Fedora:
```
$ sudo dnf remove wavcrc32
```

## Installing/Uninstalling wavcrc32 manually:
---------------------------------------------

### 1.Clone the wavcrc32 GitHub repository and navigate to the folder corresponding to the architecture of your Linux distribution. (see above).

### 2.Make the wavcrc32 binary executable:
```
$ chmod +x wavcrc32_v0.22_linux_amd64
```

### 3.Copy it to the folder where you store the main executable files:
```
$ sudo cp -f wavcrc32_v0.22_linux_amd64 /usr/bin/wavcrc32
```

### 4.Copy the manual to the man-pages folder:
```
$ sudo cp -f wavcrc32.1.gz /usr/share/man/man1/
```

### 5.Manually removing wavcrc32:
```
$ sudo rm /usr/bin/wavcrc32
$ sudo rm /usr/share/man/man1/wavcrc32.1.gz
```

## Using wavcrc32:
------------------

Say you want to check the file **filename.wav**, just type:
```
wavcrc32 filename.wav
```

## About unpacking FLAC APE WAVPACK:
------------------------------------

> FLAC, APE (Monkey's Audio), and WavPack (.wv) are lossless audio compression formats that reduce the size of audio files without sacrificing quality. They provide 100% faithful restoration of the original and are ideal for archiving.

**Important!** Don't convert them, but **decompress** them.

## Authors:
-----------

**dmvn \]DichlofoS\[ Systems** - **Author**. Making C++ source code, compiling console and GUI versions for Windows. Publishing and discussing on the forum.

**BakLAN, siro. and DrStandBy** - comments, suggestions and testing of Windows versions.

**Konstantin Kuney** - Compiling the program and building packages for Linux and MacOS, creating a manual, creating this GitHub repository and description.

## Additional information:
--------------------------

[Official webpage of the project developer](https://rutracker.net/forum/viewtopic.php?t=357895)

[Forum page for discussing the project](https://rutracker.net/forum/viewtopic.php?t=1955422)

[This GitHub repository](https://github.com/Konstantin-Kuney/wavcrc32)

---

[Go up / Вверх](#Russian)

