# Blackbox
Literally a black box. Designed to block subtitles on videos with embedded subtitles. Works best with tiling WMs.

Example i3 config for more streamlined experience:
```
for_window [title="BLACKBOX"] floating enable
for_window [title="BLACKBOX"] move position center
```

# Dependencies
libX11

# Installation
```shell
sudo make install
```

# Usage guide

1. Start the program.
2. Place the box over subtitles.
3. Press ESC to destroy the box when it's no longer needed.


# Screenshots
![scrot.png]()
_Black bar in the subtitles area_

