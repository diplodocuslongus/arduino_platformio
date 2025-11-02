# Arduino coding with platformIO

Most happens in 2 files:
platformio.ini
src/main.cpp (or other source)

## boards

### esplora

Run a given environment (code)

    pio run -e esplora 

If a build error is returned about a header that is unknown or couldn't be found:

    platformio lib search "header:Esplora.h"

Install it:

    pio pkg install --library "arduino-libraries/Esplora@^1.0.4"

    pio pkg install --library "arduino-libraries/TFT@^1.0.6"

Upload code:

    pio run -e esplora -t upload

