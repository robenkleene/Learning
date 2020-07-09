# `pshader`

- A shader is a program that runs on the GPU and generates 2D or DD output on the screen based on vertices, colors, textures, lights, etc...
- They're called "shaders" because the first shaders calculated the shading levels for 3D scenes based on the material properties of the objects in the scene.
- Now shaders not only calculate shading and light levels, but also camera transformations down to the color of every pixel in the scene, and everything in between.
- GLSL is the shader language included in OpenGL

## Graphics Pipeline

Vertex Shader > Primitive Assembly > Rasterization and Interpolation > Fragment Shader > Blending, Depth Occlusion

- **Vertex Shader**: Points in 3D space
- **Primitive Assembly**: 3D shapes by connecting points
- **Rasterization and Interpolation**: Convert to pixels.
