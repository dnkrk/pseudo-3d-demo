# Pseudo 3D demo

Creates a 3D scene rendered entirely using 2D images.

Creating 3D environments using 2D sprites is nothing new - a simple elevation offset combined with a shadow can create the illusion of volume rather easily, widely used in games of the 90's such as Red Alert 2. Parallax scrolling (Street Fighter II), raycasting (Duke Nukem 3D), or raster effects (RoadBlasters) are just some examples of clever tricks collectively referred to as "2.5D", which allow limited hardware to use relatively simple methods to create worlds with perceivable depth.


This demo is using a different technique, one that doesn't appear to have been used in games in the past. It consists of layering rotating sprites atop one another, with a small vertical offset between each layer to create the illusion of a 3D object. If it has a name, or has been used in the past, please shoot me a message as I'd love to find out more.


While it's hard to definitively say why this technique was seemingly never used in the past, there could be two likely reasons. The first is that it uses an excessive amount of sprites per object, requiring video capabilities powerful enough to employ other, more advanced techniques. Second, the nature of the 3D effect is very limited and animation of these objects would be rather expensive, particularly for human and animal shapes. 


Nevertheless, it's a convincing effect that's fascinating in its simplicity, and one that makes for some rather charming retro graphics.


### Feedback
Any feedback regarding this code would be very much appreciated. This project was intended primarily to become reacquainted with the language, but naturally there needs to be feedback in order to avoid cementing bad habits early on. If you see anything that irks you, let me know so I can fix it! :)
