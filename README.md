# Line Drawing
## Bresenham's Line Algorithm
- Determines points of an *n*-dimensional raster that should be selected in order to form a close approximation to a straight line between a pair of points
- Favours speed and simplicity
- Endpoints of the line are the pixels located at *x0*, *y0* and *x1*, *y1*, where the first coordinate of the pair is the column and the second is the row
- Bresenham's algorithm chooses the integer *y* corresponding to the pixel centre which is closest to the fractional *y* for the same *x*
- General equation for line through two endpoints is given as:

>> *(y - y0) / (y1 - y0) = (x - x0) / (x1 - x0)*

- Since we know the column, *x*, the pixel's row, *y*, is given by rounding this quantity to the nearest integer:

>> *y = ((y1 - y0) / (x1 - x0)) (x - x0) + y0*

- In practice, this devised method only works for positive and bounded slope *(0 <= m < inf)* and increase *x* *(x1 > x0)*

- In order for this to work for all cases, it is important to check for the change in *x* and *y* values and choose the larger of the two

- Whichever value is larger will be your iterable, i.e. if *dy > dx*, you will step through the values of *y* and solve for the values of *x*

- Additionally, you need to ensure that you are stepping in increase values of *x* or *y*

- To do this, you can flip the order of the points

# Curve Drawing
## Chaikin's Curve Algorithm
- Given a set of control points, this algorithm determines the points needed to draw a curve

- Finds the vectors between a set of ordered points, and creates new control points using *1/4* and *3/4* the distance along the vectors

- This algorithm is then repeated with the new control points

# Images
Bresenham's Line

![alt text](https://github.com/gcorcorann/curves/blob/master/lines.png)

Chaikin's Curve

![alt text](https://github.com/gcorcorann/curves/blob/master/curves.png)

# TODO
- Add B-splines
- Operator overloading for img, i.e. img[i, j]
- Address float -> int casting
