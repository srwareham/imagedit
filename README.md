imagedit
========

Command line photo editing utility

imagedit is a command line photo editing tool designed for unix-based systems.

Warning: sparse documentation.  More thorough notes can be found in code comments.

From the command line, one can perform operations sequentially or individually on input images.

This utility is designed to have high degrees of extensiblity.  New commands to modify an image simply need: .cpp and .h files that extend
the Command class and a Factory that defines parameters and their inputs.  Command operate by modifying an input bitmap.
See FlipCommand.cpp for a simple example

Current operations supported:
BilinearScale
  Scales the image by a percentage or by setting new width and height values
Colorizing
  Changes an image to grayscale, cartoony, negative, or to a flexiblly requested color scheme
Convolve
  Convolves an image
Crop
  Crops an image
Flip
  Inverts an image
