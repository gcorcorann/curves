# Line Drawing
## Bresenham's Line Algorithm
- Determines points of an *n*-dimensional raster that should be selected in order to form a close approximation to a straight line between a pair of points
- Favours speed and simplicity
- Endpoints of the line are the pixels located at $(x_0, y_0)$ and $(x_1, y_1)$, where the first coordinate of the pair is the column and the second is the row
- Bresenham's algorithm chooses the integer *y* corresponding to the pixel centre which is closest to the fractional *y* for the same *x*
- General equation for line through two endpoints is given as:

$$\frac{(y - y_0)}{ (y_1 - y_0)} = \frac{(x - x_0)}{ (x_1 - x_0)}$$

- Since we know the column, *x*, the pixel's row, *y*, is given by rounding this quantity to the nearest integer:

$$ y = \frac{(y_1 - y_0)}{(x_1 - x_0)} (x - x_0) + y_0$$

- In practice, this devised method only works for positive and bounded slope $(0 <= m < ing)$ and increase *x* $(x_1 > x_0)$

- In order for this to work for all cases, it is important to check for the change in *x* and *y* values and choose the larger of the two

- Whichever value is larger will be your iterable, i.e. if $\delta y > \delta x$, you will step through the values of *y* and solve for the values of *x*
