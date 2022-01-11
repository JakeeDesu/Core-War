# Core-War
This project consist of creating a virtual in which programs will fight against each other, also an assembler to compile champions as well as writing a wining champion to compete and defeat others 

it comes with these features :
- colors in file        -> colors specified in "height map files" are allowed
- rotate                -> all axis (x, y, z)
- translate             -> two axis (x, y)
- scale                 -> (entire object) or (z only)
- color gradient
- fill areas
- color editing         -> colors palette (generated) | resizable brush tool | fill with color

# tools
  * C language  :
    - primitive functions only (write, read, malloc, free, open, close, [ if, else if, else ], [ while, break]).
  * minilibx    :
    - a micro framework that provides : window creation, coloring a pixel on a window, event management, runing loop.
  * makefile    :
    - compiles the program's source code.

# run
  - $> clone repo
  - $> make
  - $> ./fdf [file.fdf] -> "file.fdf" contains height values

# controls
  - rotation        -> press (left_k , right_k, up_k, down_k, 1, 0) keys to rotate (y+, y-, x+, x-, z+, z-).
  - translate       -> press (a, d, w, s) keys to move (left, right, up, down).
  - scale           -> press (z) key to switch between (scale all and scale z only) mode then (+ or scroll up, - or scroll down) to zoom (in, out).
  - color gradient  -> press (c) to activate/deactivate the "gradient rainbow colors"
  - fill areas      -> press (f) to fill/erase the empty areas 
  - color editing   -> click on brush 'the first rect' then select color form palette, choose your brush size (+ or scroll up, - or scroll down)
