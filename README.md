# Chess Game
A little practice of C, with a chess game.

### Graphical Engine

Uses Raylib as dynamic lib (https://github.com/raysan5/raylib),
Raylib is a third-party dependency that is under ZLib License.

### Assets
It uses assets pixels from lila (https://github.com/lichess-org/lila),
Lila pixel assets is under AGPLv3+ License.

### Build
mkdir -p build && \
cc main.c -o build/chess \
-I/usr/local/include -L/usr/local/lib -lraylib && \
build/chess

### License
Except for the third-parties, this code is under UNLICENSE License.