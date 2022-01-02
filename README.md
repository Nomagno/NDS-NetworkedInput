NDS-NetworkedInput
===============
Use your NDS or 3DS as a controller for any device.

Tools for both users and developers to use their DS and 3DS lineup consoles to control other software.
[This is a hard fork of Louisvh's repo](https://github.com/Louisvh/NDS-controller)

## Purpose
The original project is so compact and elegant I found myself making servers without much issue, so I thought I might as well just make this into a defacto library. I'll try to make as many input servers as possible in due time.

## Features
- If you want to help add new features and fix bugs, check out the following list: 
- [x] NDS Version
- [x] 3DS Version
- [x] Example, (mostly) portable debug server
- [X] (Mostly) portable C library
  - Successfully verified it's correct compilation and functioning on Linux, \*BSD, Mac, and Windows (Windows requires adding `-lws2_32` to the linker arguments)
- [X] Replace all in-app references to the old name
- [X] Linux UInput server (Also works in Android under Termux, requires root)
  - Still needs proper rebinding, the source code is a good enough config file at the moment
- [X] Windows WinUser server
  - Experimental support is here! Same rebinding issue
- [ ] MacOS Quartz server
- [ ] Rewrite Android server as an AccessibilityService
## Get started
*Example Server:*
Build the example server (nds_debug_server.c) using your favorite C-compliant compiler. Feel free to use it as a template!

*Library:*
Include the library (nds_server_library.h) in your project and look at the example server for usage.

*Linux Server:*
Build the Linux server using your favorite C-compliant compiler, but make sure it is in a Linux system or with a cross-compile toolchain for Linux.

*Windows Server:*
Build the Windows server using your favorite C-compliant compiler.

*NDS:*
Build the client into a .nds file using devkitARM or download it __[here](https://github.com/Nomagno/NDS-NetworkedInput/releases/download/v1.5.0-alpha/NDS-NetworkedInput.nds)__.
Run it using the compatible homebrew/flashcard of your choice.

*3DS:*
Build the client using devkitARM or download it from __[here](https://github.com/Nomagno/NDS-NetworkedInput/releases/download/v1.5.0-alpha/3DS-NetworkedInput.cia)__. Install it
using your preferred method.

*Android:*
Is currently not buildable because of outdated libraries (Source __[here](https://github.com/Louisvh/NDS-controller-android-host)__ if you want to help), and has been pulled from the Play Store by the author, however I have made a binary available __[here](https://github.com/Nomagno/NDS-NetworkedInput/releases/download/v1.5.0-alpha/OLD_NDS_ANDROID_SERVER.apk)__.

## LICENSE

BY CONTRIBUTING TO THIS PROJECT, YOU AGREE TO LICENSE ALL CODE YOU PROVIDE UNDER THE MIT LICENSE

This project's license:

[MIT LICENSE](LICENSE)
