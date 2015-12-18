#version 330 core

struct Material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	float shininess;
};

uniform Material mat;
uniform sampler2D tex_map;

uniform mat4 ModelMatrix;
uniform Camera {
    mat4 ViewMatrix;
    mat4 ProjectionMatrix;
};

in Data {
	vec4 EyeVertexPos;
	vec4 VertexPos;
	vec3 Normal;
	vec2 Tex_Coord;
} DataIn;

const vec3 MarbleColor = vec3(0.15,0.15,0.15);
const vec3 VeinColor = vec3(0.25,0.25,0.25);
const float NoiseFactor = 0.5;
const float PositionFactor = 5;
const float IntensityFactor = 50;

out vec4 out_Color;

void main(void) {
    
    vec4 texel = texture(tex_map, DataIn.Tex_Coord);
    out_Color = texel;
}