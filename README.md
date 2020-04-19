[![Build Status](https://travis-ci.com/longuyen97/triangulation.svg?token=skDcu5tZxPtyDMyKnKYN&branch=master)](https://travis-ci.com/longuyen97/triangulation)

# Two dimensional triangulation

Triangulation for terrain modelling is a classical engineering problem.

### [Bowyer Watson Algorithm](https://en.wikipedia.org/wiki/Bowyer%E2%80%93Watson_algorithm)

Following pseudocode inspired the implementation:

```
/*
 * pointList: An array of 2D points
 */
function BowyerWatson (pointList)
   triangulation := []
   find super-triangle which is so big that it encloses every original point
   add super-triangle to triangulation 

   for each point in pointList do 
      badTriangles := []
      for each triangle in triangulation do 
         if point is inside circumcircle of triangle
            add triangle to badTriangles

      polygon := []
      for each triangle in badTriangles do 
         for each edge in triangle do
            if edge is not shared by any other triangles in badTriangles
               add edge to polygon

      for each triangle in badTriangles do 
         remove triangle from triangulation

      for each edge in polygon do 
         newTri := form a triangle from edge to point
         add newTri to triangulation

   remove super-triangle
   return triangulation
```

### Visualization