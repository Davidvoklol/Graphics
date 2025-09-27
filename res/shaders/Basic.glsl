#shader vertex
#version 330 core

layout(location = 0) in vec2 Pos;

void main() {
	gl_Position = vec4(Pos, 0.0, 1.0);
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 u_Color;

void main() {
	u_Color = vec4(0.39, 0.58, 0.93, 1.0);
}
