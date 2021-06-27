NDS-NetworkedInput
===============
Tools for both users and developers to use their DS and 3DS lineup consoles to control other devices.
[This is a hard fork of Louisvh's repo](https://github.com/Louisvh/NDS-controller)

## Purpose
The original project is so compact and elegant I found myself making clients without much issue, so I thought I might as well just make this into a defacto library. I'll try to make as many input servers as possible in due time.

## Features
- [x] NDS Version
- [x] 3DS Version
- [x] Example, (mostly) portable debug server.
- [ ] Replace all in-app references to the old name
- [ ] Linux UInput server
- [ ] Windows.Gaming.Input server
- [ ] Reimplement the Android input server
- [ ] Make the 3DS version pretty, or the NDS version ugly ;)

## Usage
*Server:*
Build the example server using your favorite C-compliant compiler.

*NDS:*
Build the client into a .nds file using devkitARM or download it __[here](https://github.com/Louisvh/NDS-controller/releases/download/v1.2.0/NDS-controller.nds)__.
Run it using the compatible homebrew-/flashcard of your choice.

*3DS:*
Build the client using devkitARM or download it from __[here](https://github.com/Louisvh/NDS-controller/releases/download/v1.2.0/NDS-controller.cia)__. Install it 
using your preferred method. 

3DS .cia link, scan in FBI to install:  
[cia QR](https://user-images.githubusercontent.com/6605273/31919870-b90b7636-b865-11e7-8b23-934e8c221887.png)


## LICENSE
:[MIT LICENSE](LICENSE)
