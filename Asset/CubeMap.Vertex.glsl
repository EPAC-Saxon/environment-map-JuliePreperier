#version 330 core
layout (location = 0) in vec3 in_position;

out vec3 out_texcoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    mat4 pvm = projection * view * model;

    out_texcoord = in_position;
    gl_Position = pvm * vec4(in_position, 1.0);

}  